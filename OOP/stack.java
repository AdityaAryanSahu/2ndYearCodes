import java.util.Scanner;
public class stack {
    int [] arr;
    //int ele;
    int top=-1;
     static void read(stack m,int[] arr){
         m.arr=arr;

    }
    static void push(stack m,int max,int ele){
        if(m.top==max-1)
            System.out.println("cant push full satck");
        else
            m.top=m.top+1;
            m.arr[m.top]=ele;

    }
    static void pop(stack m,int n){
         int p=m.arr[m.top];
         m.top=m.top-1;
        System.out.println(p);
    }
    static void display(int max, stack ob,int n) {
            for(int i=max-n-1;i>=0;i--)
                System.out.println(ob.arr[i]);
    }

    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enter no of element to be pushed");
        int max=s.nextInt();
       int[] arr=new int[max];
       stack ob=new stack();
        read(ob,arr);
        for(int i=0;i<max;i++){
            int ele=s.nextInt();
           push(ob,max,ele);

        }
        System.out.println("the stack is:");
        for(int i=max-1;i>=0;i--)
            System.out.println(arr[i]);
        //System.out.println();
        System.out.println("enter no of elements to be popped");
        int n2=s.nextInt();
        for(int i=0;i<n2;i++) {
            System.out.println("popped element " + (i + 1) + " is");
            pop(ob, n2);
        }

        System.out.println("after push and pop final statck is");
        display(max,ob,n2);
    }
}
