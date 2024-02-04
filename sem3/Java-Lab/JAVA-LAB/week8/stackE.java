import java.lang.*;
import java.util.*;
interface stackOperations{
    static int max = 3;
    int arr[]= new int[max];
    void push(int x) throws stackFullException;
    int pop() throws stackEmptyException;
    boolean isFull();
    boolean isEmpty();
    void display();
    
}
class stackFullException extends Exception {
    public stackFullException(){
        System.out.println("The stack is full !!");
    }
    void remede(){
        System.out.println("pop a few elemets first");
    }
}
class stackEmptyException extends Exception{
    public stackEmptyException(){
        System.out.println("THe stack is empty !!");
    }
    void remede(){
        System.out.println("push a few elemets first");
    }
} 
class stack implements stackOperations{
    int top = -1;
    public void push(int x) throws stackFullException{

            if(!isFull()){
                arr[++top] = x;
            }  
    }
    public int pop() throws stackEmptyException{
        return arr[--top];
    }
    public boolean isEmpty(){
        if(top==0){
            return true;

        }else{
            return false;
        }
    }
    public boolean isFull(){
        if(top==max-1){
            return true;
        }else{
            return false;
        }
    }
    public void display(){
        System.out.println("-----------------------------------");
        for(int i = 0;i<= top;i++){
            System.out.println(arr[i]);
        }
    }
}
class Demo{
    public static void main(String[] args) {
        stack s = new stack();
        int n;
        int ch ;
        Scanner sc = new Scanner(System.in);
        
        do{
            System.out.println("\n1.push\n2.pop\n3.display\n4.exit: ");
            ch = sc.nextInt();
            switch(ch){
                case 1:
                try{
                    System.out.println("\nEnter the number : ");
                    n = sc.nextInt();
                    if(!s.isFull())
                        s.push(n);
                    else
                    throw new stackFullException();
                }catch(stackFullException e){
                    e.remede();
                }
                break;
                case 2:
                try {
                    if(!s.isEmpty())
                        s.pop();
                    else
                        throw new stackEmptyException();
                } catch (stackEmptyException e) {
                    e.remede();
                }
                break;
                case 3:
                    s.display();
                    break;
                case 4: 
                    System.out.println("You are about to exit!!");
                    break;
                default: 
                    System.out.println("\nInvalid choise!!\nplese try again.");
                    break;
            }
        } while(ch!=4);  
    }
}
