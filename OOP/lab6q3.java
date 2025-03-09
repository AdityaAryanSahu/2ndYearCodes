import java.util.Scanner;
class person{
    private String name;
    private String birthdate;
    person(){
    }
    person(String name,String birthdate){
        this.name=name;
        this.birthdate=birthdate;
    }
     void display(){
        System.out.println("name is "+this.name);
        System.out.println("birth is "+this.birthdate);
    }
}
class college_graduate extends person{
    private float gpa;
    private int year_gard;
    college_graduate(String name,String birthdate,float gpa,int year){
        super(name,birthdate);
        this.year_gard=year;
        this.gpa=gpa;
    }
    void display(){
        super.display();
        System.out.println("year of grad is:"+this.year_gard);
        System.out.println("gpa was:"+this.gpa);
    }
}
public class lab6q3 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enetr details of etst person");
        String name=s.nextLine();
        String birthdate=s.nextLine();
        person ob=new person(name,birthdate);
        System.out.println("enter detais of graduate");
        name=s.nextLine();
         birthdate=s.nextLine();
        float gpa=s.nextFloat();
        int year=s.nextInt();
        college_graduate ob2=new college_graduate(name,birthdate,gpa,year);
        System.out.println("\ndetails of test person are");
        ob.display();
        System.out.println("\ndetails of studetn is");
        ob2.display();
    }
}
