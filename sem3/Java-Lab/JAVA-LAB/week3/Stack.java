import java.util.Scanner;

class Stack {
    int[] array;
    int top ;
    int maxStackSize;
    Stack(int maxStackSize){
        top = -1;
        array = new int[maxStackSize];
        this.maxStackSize = maxStackSize;
    }
    int stackOverflow(){
        if(top > maxStackSize){
            return 1;
        }else{
            return 0;
        }
    }
    void push(int element){
        if(stackOverflow()==1){
            System.out.println("Stack Overflow!!");
            return ;
        }else{

            array[++top] = element;
        }
    }
    int srackUnderflow(){
        if(top<0){
            return 1;
        }else{
            return 0;
        }
    }
    void pop(){
        if(srackUnderflow()==1){
            System.out.println("Stack underflow!!");
            return;
        }else{
            --top;
        }
    }
    void displayStack(){
        if(srackUnderflow()==1){
            System.out.println("Stack underflow!!");
            return;
        }else if(stackOverflow()==1){
            System.out.println("Stack Overflow!!");
            return ;
        }else {

            for(int i =0;i<=top;i++){
                System.out.println(array[i]+"\t");
            }
        }
    }
}

class StackDemo{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the max size of array:\n");
        int size = sc.nextInt();
        Stack s1= new Stack(size);
        int ch = 'y';
        do{
                System.out.println("\n(1)Push\n(2)pop\n(3)display");
                ch = sc.nextInt();
                switch (ch){
                    case 1:
                        System.out.println("enter the element to push:\n");
                        int element = sc.nextInt();
                        s1.push(element);
                        break;
                    case 2:
                        s1.pop();
                        break;
                    case 3:
                        s1.displayStack();
                        break;
                    default:
                        System.out.println("invalid choise");
                }
                System.out.println("enter to continue (y/n)");
                ch = sc.next().charAt(0);
            }while(ch=='y');
    }
}
