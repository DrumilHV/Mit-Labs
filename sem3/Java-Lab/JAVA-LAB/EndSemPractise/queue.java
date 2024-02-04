interface queue<T>{
   public boolean isFull() ;
    public boolean isEmpty() ;
    public void put(T n)throws isFullException;
    public T get()throws isEmptyException;
}
class isFullException extends Exception{
isFullException(){
    super("isFullException");
}
String message(){
    return "The queue is Full. \nTry to empty few elemetns before adding new ones";
}
}
class isEmptyException extends Exception{
    isEmptyException(){
        super("isEmptyException");

    }
    String message(){
        return "The queue is Empty. \nTry to add few elemetns before deleting old ones";
    }
}
class Production<T> implements queue<T>{
    int maxSize  = 10;
    T Num[];
    static int front = -1;
    static int rear = -1;
    Production(T n[]){
        Num = (T[]) new Object[maxSize];
        front = 0;
        rear = n.length-1;
        // Num  = n;
        for(int i =0 ;i<n.length;i++){
            Num[i] = n[i];
        }
    }
   public boolean isFull() {
        if (front == maxSize-1 || rear == maxSize -1)   
            return true;
        return false;
    }
    public boolean isEmpty() {
        if(rear == -1||front>rear)
            return true;
        return false;
    }   
    public void put(T newE)throws isFullException{
        if(isFull()){
            throw new isFullException();
        }
       
        Num[++rear] = newE;
    }
    public T get() throws isEmptyException{
        if(isEmpty()){
            throw new isEmptyException();
        }
        return (T) Num[front++];
    }

}
class demo{
    public static void main(String[] args) {
        Integer []iList = {1,2,3,4,5,6,7,8};
        Double []dList = {1.0,2.5,3.5,4.5,5.5,6.5,7.5,8.5};
        String []sList = {"Drumil","Ankith" };
        try {
            Production<Integer> Io = new Production<>(iList);
            Io.put(9);
            System.out.println(Io.get());
            Io.put(99);
            Io.put(99);
            Io.put(99);
            Io.put(99);
           
        } catch (isFullException e) {
            System.out.println("Caugth: "+e+"\nMessage: "+e.message());
        }catch(isEmptyException o){
            System.out.println("Caugth: "+o+"\nMessage: "+o.message());
        }
        try {
            Production<Double> Do = new Production<>(dList);
            Do.put(9.5);
            System.out.println(Do.get());
            Do.put(99.5);
        } catch (isFullException e) {
            System.out.println("Caugth: "+e+"\nMessage: "+e.message());
        }catch(isEmptyException o){
            System.out.println("Caugth: "+o+"\nMessage: "+o.message());
        }try {
            Production<String> So = new Production<>(sList);
            System.out.println(So.get());
            System.out.println(So.get());
            So.put("Druimil Again");
            System.out.println(So.get());
            System.out.println(So.get());
        } catch (isFullException e) {
            System.out.println("Caugth: "+e+"\nMessage: "+e.message());
        }catch(isEmptyException o){
            System.out.println("Caugth: "+o+"\nMessage: "+o.message());
        }
    }
}