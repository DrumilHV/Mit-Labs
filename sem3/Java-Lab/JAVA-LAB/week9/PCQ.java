class Q{
	int n;
		boolean cntl = true;
	synchronized void put(int n){
		if(!cntl){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Error in put's wait!");

			}
		}
		this.n = n;
		System.out.println("Put : "+n);
		cntl = false;
		notify();
	}
	synchronized int  get(){
		// boolean cntl = true;
		if(cntl){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Error in get's wait!");

			}
		}
		System.out.println("Got : "+n);
		cntl = true;
		notify();
		return n;
	}
}
class Producer implements Runnable{
	 Q q;
	 Producer(Q q){
	 	this.q  = q;
	 	new Thread(this).start();
	 }
	 public void run(){
	 int i=0;

	 while(i<10){
	 	q.put(i++);
	 }	
	 }
}
class Consumer implements Runnable{
	Q q;
	Consumer( Q q){
		this.q = q;
		new Thread(this).start();
	}
	public void run(){
		int i=0;
		do{
			i = q.get();
		}while(i!=9);
	}
}
class Demo{
	public static void main(String[] args) {
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
	}
}