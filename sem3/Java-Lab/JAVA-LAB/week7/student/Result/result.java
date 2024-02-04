package student.Result;
import java.util.Scanner;

// import student.*;
import student.academics.Amarks;
import student.sports.sports;
public class result extends Amarks implements sports {
    int sMark;
    public void getSMarks(int m){
        this.sMark = m;
    }
    public int putGrade(){
        return sMark;
    }
   public int FinalMarks(){
    return getMarks()+ putGrade();
   }
}
class Demo{
    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        int n;
        int  marks;
        System.out.println("enrer the number of students: ");
        n = sc.nextInt();
        result[] r = new result[n];
        for(int i=0;i<n;i++){
            r[i] = new result();
            System.out.println("Enter name: ");
            r[i].setNmae(sc.next());
            System.out.println("enter rollNo: ");
            r[i].setRollNum(sc.nextInt());
            System.out.println("Enter total marks subjects: ");
                marks = sc.nextInt();
            r[i].putMarks(marks);
            System.out.println("enter sports marks: ");
            r[i].getSMarks(sc.nextInt());

        }
        System.out.println("--------------------------------------------------------------------------------------------------------");
        for(int i=0;i<n;i++){
            System.out.println("\nName: "+r[i].getName()+"\nroll No: "+r[i].getRollNo()+"\nSport marks: "+r[i].putGrade()+"\nacademic makrks: "+r[i].getMarks()+"\nfinal grade: "+r[i].FinalMarks());
        }
        sc.close();
    }
}
