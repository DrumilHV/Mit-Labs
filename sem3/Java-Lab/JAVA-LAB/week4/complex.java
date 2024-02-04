import java.util.*;
class Complex{ int real;
int imag; Complex(){
real = 0;
imag = 0; }
Complex(int real,int imag){ this.real = real;
this.imag = imag; }
Complex add(Complex C){ int r,i;
r = this.real + C.real;
i = this.imag + C.imag; return new Complex(r,i);
}
Complex diff(Complex C){
int i, r;
r= this.real- C.real;
i = this.imag -C.imag; return new Complex(r,i);
}
void display(){
if(this.imag < 0)
System.out.print("Complex no: "+this.real +" "+ this.imag+"i" );
else
System.out.println("Complex no: "+this.real +" + "+ this.imag+"i" );
} }
class complexDemo{
public static void main(String[] args) {
int i1,r1,r2,i2;
Scanner sc = new Scanner(System.in);
System.out.print("Enter the real and imagenary parts for Complex Number 1:\n"); r1 = sc.nextInt();
i1 = sc.nextInt();
System.out.print("Enter the real and imagenary parts for Complex Number 2:\n"); r2 = sc.nextInt();
i2 = sc.nextInt();
Complex C1= new Complex(r1,i1);
Complex C2= new Complex(r2,i2);
Complex C3= new Complex(); System.out.println("sum is: ");
C3 = C1.add(C2);
C3.display(); System.out.println("difference is: "); C3= C1.diff(C2);
C3.display(); }
}