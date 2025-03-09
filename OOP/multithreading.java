

import java.util.Scanner;

//class thread implements Runnable{
//    int num;
//    thread(int num){
//        this.num=num;
//    }
//    @Override
//    public void run(){
//        for(int i=0;i<11;i++){
//            System.out.println(this.num +" * "+i +"= "+(i*this.num));
//            try {
//                thread1.sleep(1000);
//            } catch (InterruptedException e) {
//                throw new RuntimeException(e);
//            }
//        }
//    }
//}
//
//class row_sum implements Runnable{
//    int []row;
//   static int i=0;
//     static int[] rowsum=new int[100];
//    row_sum(int []row){
//        this.row=row;
//    }
//    @Override
//    public void run(){
//        int sum=0;
//        for(int i:row)
//            sum+=i;
//        System.out.println(sum);
//        rowsum[i++]=sum;
//    }
//
//}
class thread22 extends Thread{

    Counter c;
    thread22(Counter c){
        this.c=c;
    }
    @Override
    public void run(){
        int i=0;
        while(i<20){
           c.increment();i++;
            try {
                thread22.sleep(400);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

class thread23 extends Thread{

    Counter c;
    thread23(Counter c){
        this.c=c;
    }
    @Override
    public void run(){
        int i=0;
        while(i<20){
            c.decrement();i++;
            try {
                thread23.sleep(500);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
class Counter{
    private  int count=0;
    synchronized void increment(){
        if(count==3) {
            try {
                System.out.println("waiting bcoz count already 3");
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
else {
            count++;
            System.out.println("count++, new value: " + count);
            notifyAll();
        }


    }
    synchronized void decrement(){
        if(count==0) {
            try {
                System.out.println("waiting bcoz count already 0");
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
  else {
            count--;
            System.out.println("count--, new value: " + count);
            notifyAll();
        }

    }
}
public class multithreading {
    public static void main(String[] args) throws InterruptedException {
        Scanner s=new Scanner(System.in);
//        int [][]mat={{1,2,3},{2,3,4},{4,5,6}};
//        row_sum t=new row_sum(mat[0]);
//        Thread t1=new Thread(t);
//      t=new row_sum(mat[1]);
//        Thread t2=new Thread(t);
//        t=new row_sum(mat[2]);
//        Thread t3=new Thread(t);
//        t1.start();
//        t1.join();
//        t2.start();
//        t2.join();
//        t3.start();
//        t3.join();
//
//        int sum=0;
//        for(int i:row_sum.rowsum){
//            sum+=i;
//        }
//        System.out.println(sum);
        Counter c=new Counter();
        thread22 t1=new thread22(c);
        thread22 t3=new thread22(c);
        thread23 t2=new thread23(c);
        thread23 t4=new thread23(c);
        t1.start();
        t2.start();
    }
}
