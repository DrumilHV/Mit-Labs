#include <stdio.h>

#define MASK_WIDTH 3 // Define the mask dimensions (e.g., 3x3 mask)

__global__ void convolution2D(int* input, int* mask, int* output, int width, int height) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    int sum = 0;

    for (int i = 0; i < MASK_WIDTH; i++) {
        for (int j = 0; j < MASK_WIDTH; j++) {
            int mask_row = i - (MASK_WIDTH / 2);
            int mask_col = j - (MASK_WIDTH / 2);

            int image_row = row + mask_row;
            int image_col = col + mask_col;

            // Check if the pixel is within the image bounds
            if (image_row >= 0 && image_row < height && image_col >= 0 && image_col < width) {
                sum += input[image_row * width + image_col] * mask[i * MASK_WIDTH + j];
            }
        }
    }

    output[row * width + col] = sum;
}

int main() {
    int width = 4;   // Width of the input and output arrays
    int height = 4;  // Height of the input and output arrays

    int input[width][height]; // Input array
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            input[i][j] = i*width+j;
        }
    }
    printf("the matrix A: \n");
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            printf("%2d ", input[i][j]);
        }
        printf("\n");
    }

    int mask[3][3] = {{-1, -1, -1},
                      {-1,  8, -1},
                      {-1, -1, -1}}; // 3x3 convolution mask
    printf("the Mask: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%2d ", mask[i][j]);
        }
        printf("\n");
    }


    int output[width][height]; // Output array

    int *d_input, *d_mask, *d_output; // Device pointers

    // Allocate memory on the device
    cudaMalloc((void**)&d_input, width * height * sizeof(int));
    cudaMalloc((void**)&d_mask, MASK_WIDTH * MASK_WIDTH * sizeof(int));
    cudaMalloc((void**)&d_output, width * height * sizeof(int));

    // Copy data from host to device
    cudaMemcpy(d_input, input, width * height * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_mask, mask, MASK_WIDTH * MASK_WIDTH * sizeof(int), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 dimGrid(width, height); // 2D grid
    dim3 dimBlock(1, 1);        // 2D block with one thread in each dimension

    // Launch the convolution kernel
    convolution2D<<<dimGrid, dimBlock>>>(d_input, d_mask, d_output, width, height);

    // Copy the result back from device to host
    cudaMemcpy(output, d_output, width * height * sizeof(int), cudaMemcpyDeviceToHost);

    // Print the output array
    printf("THe output Matrix :\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", output[i][j]);
        }
        printf("\n");
    }

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_mask);
    cudaFree(d_output);

    return 0;
}
