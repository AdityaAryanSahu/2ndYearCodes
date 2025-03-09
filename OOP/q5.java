import java.util.Scanner;
abstract class figure{
 abstract void area(int a,int b);
 }
 
 class rectangle extends figure{
 public void area(int a,int b){
 System.out.println("area is: "+(a*b));
 }
 }
 class square extends figure{
 public void area(int a,int b){
 if(a==b)
 System.out.println("area is: "+(a*b));
 else
 System.out.println("incorrect input for square");
 }
 }
 class triangle extends figure{
 public void area(int a,int b){
 System.out.println("area is: "+(0.5*a*b));
 }
 }
 
 public class q5{
 public static void main(String[] args){
 Scanner s=new Scanner(System.in);
 int x,y;
 System.out.println("enter dimensions of rectangle");
 x=s.nextInt();
  y=s.nextInt();
  figure f1=new rectangle();
  f1.area(x,y);
  
  System.out.println("enter dimensions of square");
 x=s.nextInt();
  y=s.nextInt();
  figure f2=new square();
  f2.area(x,y);
  
  System.out.println("enter dimensions of triangle");
 x=s.nextInt();
  y=s.nextInt();
  figure f3=new triangle();
  f3.area(x,y);
  }
  }
