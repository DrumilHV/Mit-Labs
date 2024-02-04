import java.util.Scanner;

import student.Result.result;

interface Series{
    int getNext();
    void reset();
    void setStart(int n);
}
public class ByTwo implements Series {
    int n;
    ByTwo(int n){
        this.n = n;
    }
    public int getNext(){
        n +=2; 
        return n;
    }
    public void reset(){
        n=0;
    }
    public void setStart(int n){
        this.n = n;
    }
}
class Demo{
    public static void main(String[] args) {
        int n;
        int ch ;
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter the number u want to start series with: ");
        n = sc.nextInt();
        ByTwo b = new ByTwo(n);
        do{
            System.out.println("\n1.get next\n2.reset\n3.change start\n4.exit");
            ch = sc.nextInt();
            switch(ch){
                case 1:
                    System.out.println("\nn: "+b.getNext());
                    break;
                case 2: 
                    b.reset();
                    break;
                case 3: 
                    System.out.println("\nEnter the number u want to start series with: ");
                    n = sc.nextInt();
                    b.setStart(n);
                    break;
                case 4: 
                    System.out.println("You are about to exit!!");
                    break;
                default: 
                    System.out.println("\nInvalid choise!!\nplese try again.");
                    break;
            }
        }while(ch!= 4);
        
    }
}
