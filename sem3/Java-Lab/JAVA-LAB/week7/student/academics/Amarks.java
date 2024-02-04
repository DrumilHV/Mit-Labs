package student.academics;

public class Amarks {
    private String name;
    private int rollNo;
    private int marks;
    public void setNmae(String name){
        this.name  = name;
    }
    public String getName(){
        return name;

    }
    public void setRollNum(int rollNo){
        this.rollNo = rollNo;
    }
    public int getRollNo(){
        return rollNo;
    }
    public void putMarks(int  marks){
        this.marks = marks;
    }
    public int  getMarks(){
        return marks;
    }
}
