import java.util.*;
class multiply extends Thread{
	int n;
	
	multiply(String name,int n){
		super(name);
		this.n  = n;
		start();

	}
	public void run(){
		try{
			for(int i=1;i<=3;i++){
				System.out.println(getName()+" "+ n+" * " + i +" = "+ n*i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			System.out.println(getName()+" is inturrpted!");
		}
	System.out.println(this.getName()+" is Exiting !");
	}
	
}
class Tables{
	public static void main(String[] args) {
		multiply m7 = new multiply("7Table",7);
		multiply m5 = new multiply("5Table",5);
		Thread t = new Thread() ;
		try{
			for(int i =0;i<3;i++){
				System.out.println("Main "+1+" * " + i +" = "+1*i);
				t.sleep(1500);
			}
		}catch(InterruptedException e){
			System.out.println("main Thread is inturrpted!");
		}
		System.out.println("MAIN is exiting ");
	}
}