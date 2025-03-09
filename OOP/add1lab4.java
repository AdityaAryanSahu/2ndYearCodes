import java.util.Scanner;
class Intarr {
    int[] a;
    Intarr(){
        System.out.println("default works");
    }
    Intarr(int[] arr){
      this.a=arr;
    }
    void display(){
        for(int i:this.a)
            System.out.print(i+" ");
        System.out.println();
    }
    void search(int el,int n){
        for(int i=0;i<n;i++) {
            if (this.a[i] == el)
                System.out.println("posi is " + (i + 1));
        }
    }
    static int compare(Intarr ob1, Intarr ob2,int n){
        int flag=1;
        for(int i=0;i<n;i++)
            if(ob1.a[i]!=ob2.a[i])
                flag=0;

        return flag;

    }
}
public class add1lab4 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enter size of array");
        int n=s.nextInt();
        System.out.println("enter elemebt to be searched");
        int el=s.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=s.nextInt();
        Intarr ob1=new Intarr();
        ob1=new Intarr(arr);
        ob1.display();
        ob1.search(el,n);
        Intarr ob2=new Intarr();
        System.out.println("enter 2nd array");
        int[] arr2=new int[n];
        for(int i=0;i<n;i++)
            arr2[i]=s.nextInt();
        ob2=new Intarr(arr2);
        int flag=Intarr.compare(ob1,ob2,n);
        if(flag==0)
            System.out.println("not eqaul");
        else
            System.out.println("equal");

    }
    }

