import java.util.*;

class Complex {


	int real;
    int imaginary;

	Complex(int real, int imaginary)
	{
		this.real = real;
		this.imaginary = imaginary;
	}
	Complex addComp(Complex C1, Complex C2)
	{
		Complex temp = new Complex(0,0);
		temp.real = C1.real + C2.real;
		temp.imaginary = C1.imaginary + C2.imaginary;
		return temp;
	}

	Complex subtractComp(Complex C1, Complex C2)
	{
		Complex temp = new Complex(0,0);
		temp.real = C1.real - C2.real;
		temp.imaginary = C1.imaginary - C2.imaginary;

		return temp;
	}

	void printComplexNumber()
	{	if(imaginary>0)
		System.out.println("Complex number: "+ real + " + "+ imaginary + "i");
		else if(imaginary<0)
		System.out.println("Complex number: "+ real + " "+ imaginary + "i");
	}
}

class ComplexDemo {

	public static void main(String[] args)
	{
        int r1,i1,r2,i2;
        Scanner sc = new Scanner(System.in);
        System.out.print("enter real and imagenary part of complex no:1");
        r1 = sc.nextInt();
        i1 = sc.nextInt();
        System.out.print("enter real and imagenary part of complex no:2");
        r2 = sc.nextInt();
        i2 = sc.nextInt();

		Complex C1 = new Complex(r1, i1);
		C1.printComplexNumber();
		Complex C2 = new Complex(r2,i2);
		C2.printComplexNumber();
		Complex C3 = new Complex(0,0);
		C3 = C3.addComp(C1, C2);
		System.out.print("Sum of ");
		C3.printComplexNumber();
		C3 = C3.subtractComp(C1, C2);
		System.out.print("Difference of ");
		C3.printComplexNumber();
	}
}
