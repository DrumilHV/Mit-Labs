import random

def f(x):
    # Define the function f(x) to be minimized
    return x**3 - 4*x**2 + 3*x + 1

def hill_climbing(start_x, step_size, max_iterations):
    current_x = start_x
    for i in range(max_iterations):
        # neighbor_x = current_x + random.uniform(-step_size, step_size)
        neighbor_x = current_x + step_size
        if f(neighbor_x) < f(current_x):
            current_x = neighbor_x
    return current_x

start_x = random.uniform(-10, 10)
# step_size = 0.1
step_size = 1
max_iterations = 1000

print("Starting x:", start_x)
print("Starting f(x):", f(start_x))

min_x = hill_climbing(start_x, step_size, max_iterations)

print("Minimum x found:", min_x)
print("Minimum f(x) found:", f(min_x))
