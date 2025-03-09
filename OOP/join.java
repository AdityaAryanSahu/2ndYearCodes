import java.util.Scanner;
import java.util.Arrays;


public class join{
    int[] arr;
    void accept(int[] arr){
        this.arr =arr;
        Arrays.sort(this.arr);
    }
    static join mix(join m1,join m2){
        int n1=m1.arr.length;
        int n2=m2.arr.length;
        int[] merge=new int[n1+n2];
        System.arraycopy(m1.arr,0,merge,0,n1);
        System.arraycopy(m2.arr,0,merge,n1,n2);
        join m=new join();
        m.accept(merge);
        return m;
    }
    void display(){
        for(int i:this.arr)
        System.out.print(i+" ");
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enter size of ar1:");
        int n1=s.nextInt();
       int[] a1=new int[n1];
       for(int i=0;i<n1;i++)
           a1[i]=s.nextInt();
        System.out.println("enter size of ar2:");
        int n2=s.nextInt();
        int[] a2=new int[n2];
        for(int i=0;i<n2;i++)
            a2[i]=s.nextInt();
        //Arrays.sort(a2);
        join m1=new join();
        m1.accept(a1);
        join m2=new join();
        m2.accept(a2);
        join m=new join();
        m=mix(m1,m2);
        m.display();


    }
}