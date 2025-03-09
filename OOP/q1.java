import java.util.Scanner;

 class Student2{

   String sname;
   int [] marks;
   int total;
   float avg;

   Student2(String name, int[] marks, int total, float avg){
    this.sname=name;
    this.marks=marks;
    this.total=total;
    this.avg=avg;
   }
   void display(){
   System.out.println("\nthe name of the student is: "+ this.sname);
   System.out.println("the marks of the student is: ");
   for(int i:this.marks)
   System.out.print(i+" ");
   System.out.println();
   System.out.println("the total is: "+this.total);
   System.out.println("the avg is: "+this.avg);
   
   }
   void compute(Student2 ob, int n){
   for(int i=0;i<n;i++)
   ob.total=ob.total+ob.marks[i];
   ob.avg=ob.total/n;
   }
   }
   
   class sciencestudent extends Student2{
   private int pracmarks;
   sciencestudent(String name, int[] marks, int total, float avg,int pracmarks){
   super(name,marks,total,avg);
   this.pracmarks=pracmarks;
   }
   void compute( sciencestudent ob, int n){
   for(int i=0;i<n;i++)
   ob.total=ob.total+ob.marks[i]+this.pracmarks;
   ob.avg=(float) ob.total/n;
   }
   void displaypracmarks(){
   System.out.println("prac marks is: "+this.pracmarks);
   }
   }

   class artstudent extends Student2{
   private String course;
   artstudent(String name, int[] marks, int total, float avg,String course){
   super(name,marks,total,avg);
   this.course=course;
   }
   void displaycourse(){
   System.out.println("extra coyse is: "+this.course);
   }
   }
   
   public class q1{
	public static void main(String[] args){
	Scanner s=new Scanner(System.in);
	System.out.println("Enter details for base stduent");
     
     String name=s.nextLine();
     int n=s.nextInt();
     int [] marks=new int[n];
     for(int i=0;i<n;i++)
     marks[i]=s.nextInt();
 Student2 s1=new Student2(name,marks,0,0);
     s1.compute(s1,n);
     s1.display();
     System.out.println();
     
     System.out.println("Enter details for science stduent");
     s.nextLine();
     String name2=s.nextLine();
     int n2=s.nextInt();
     int [] marks2=new int[n2];
     for(int i=0;i<n2;i++)
     marks2[i]=s.nextInt();
     int pracmarks=s.nextInt();
 sciencestudent s2=new sciencestudent(name2,marks2,0,0,pracmarks);
     s2.compute(s2,n2);
     s2.display();
     s2.displaypracmarks();
     System.out.println();
     
     System.out.println("Enter details for art stduent");
     s.nextLine();
     String name3=s.nextLine();
     int n3=s.nextInt();
     int [] marks3=new int[n3];
     for(int i=0;i<n3;i++)
     marks3[i]=s.nextInt();
     s.nextLine();
     String course=s.nextLine();
 artstudent s3=new artstudent(name3,marks3,0,0,course);
     s3.compute(s3,n3);
     s3.display();
     s3.displaycourse();
	}
}
