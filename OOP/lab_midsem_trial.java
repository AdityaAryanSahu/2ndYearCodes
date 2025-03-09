import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Arrays;
import java.util.Scanner;
class em{
    String name;
    String proj;
    String stadate;
    String enddate;
    static Scanner s=new Scanner(System.in);
    em(){}
    em(String name,String proj,String stadate,String enddate){
        this.name=name;
        this.proj=proj;
        this.stadate=stadate;
        this.enddate=enddate;
    }
    void display(){
        System.out.println("name: "+this.name);
        System.out.println("project name: "+this.proj);
        System.out.println("start date: "+this.stadate);
        System.out.println("enddate: "+this.enddate);
    }

}
class emi extends em{
    static String[] names;
    static void names(em[] ob, int n){
      names=new String[n];
        System.out.println("enter some names");
        for(int i=0;i<n;i++)
            names[i]=s.nextLine();
    }
    static void sort(int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(names[i].compareTo(names[i+1])>0){
                    String temp=names[i];
                    names[i]=names[i+1];
                    names[i+1]=temp;
                }
            }
        }
    }

}
public class lab_midsem_trial {
    static Scanner s=new Scanner(System.in);
    /* String name;
    int classno;

    void read(){
        name=s.nextLine();
        classno=s.nextInt();
        s.nextLine();
    }
    void display(){
        System.out.println("name: "+name);
        System.out.println("class: "+classno);
    }*/
    public static void main(String[] args) {
       /* String[] months={"Jan","Feb","march","april","may","june","july","august","sep","oct","nov","dec"};
        int year;
        GregorianCalendar o=new GregorianCalendar();
        System.out.println("Time:");
        System.out.println(o.get(Calendar.HOUR)+":"+o.get(Calendar.MINUTE)+":"+o.get(Calendar.SECOND));
        //System.out.print();
        //System.out.println();

        System.out.println("date:");
        System.out.print((o.get((Calendar.MONTH))+1)+" ");
        System.out.print(o.get(Calendar.DATE)+" ");
        System.out.println(year=o.get(Calendar.YEAR));

        if(o.isLeapYear(year)){
            System.out.println("hehehehe");
        }
        else System.out.println("nonoonono");*/

       /* int [] arr={1,3,67,2,1,0};
        int[] arr2={1,2,3};
        Arrays.sort(arr);
        Arrays.sort(arr2);
        int[] merge=new int[arr.length+arr2.length];
        System.arraycopy(arr,0,merge,0,arr.length);
        System.arraycopy(arr2,0,merge,arr.length,arr2.length);
        Arrays.sort(merge);
        for(int i:merge)
            System.out.print(i+" ");*/

       /* String s="name aditya";
        //String regex=" ";
        System.out.println(Character.toUpperCase(s.charAt(0))+"."+Character.toUpperCase(s.charAt(5)));
        System.out.println(s.replaceAll(" ",""));
        StringBuffer sb=new StringBuffer(s);
        sb.insert(4,',');
        sb.reverse();

        s=sb.toString();
        System.out.println(s);*/

       /* String[] arr=new String[5];
        for(int i=0;i<5;i++){
            arr[i]=s.nextLine();
        }
        String temp="";
        for(int j=0;j<4;j++) {
            for (int i = 0; i < 4-j; i++) {
                if (arr[i].compareTo(arr[i + 1]) < 0) {
                    temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
        }
        for(String i:arr)
            System.out.println(i);*/
       /* lab_midsem_trial ob1=new lab_midsem_trial();
        lab_midsem_trial ob2=new lab_midsem_trial();

        ob1.read();
        ob2.read();
        ob1.display();

        ob2.display();*/
       /* System.out.println("enter a string");
        String trs=s.nextLine();
        String */
        int n=s.nextInt();
        s.nextLine();
        em[] ob=new em[n];
        for(int i=0;i<n;i++){
            String name=s.nextLine();
            String proj=s.nextLine();
            String stadate=s.nextLine();
            String enddate=s.nextLine();
            ob[i]=new em(name,proj,stadate,enddate);
        }
        for(int i=0;i<n;i++){
            ob[i].display();
        }
        emi.names(ob,n);
        emi.sort(n);
        emi o=new emi();
        for(String i:o.names)
            System.out.println(i);

    }
}
