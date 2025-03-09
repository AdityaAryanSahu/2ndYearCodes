
class thr extends Thread{
    int num;
    thr(int num){
        this.num=num;
    }
    public void run(){
        System.out.println("table for "+this.num+":");
        for(int i=1;i<11;i++)
            System.out.println(this.num*i);
    }
}
public class lab8q1 {
    public static void main(String[] args) {
        thr t1=new thr(5);
        thr t2=new thr(7);
        //thr t11 = t1;
        t1.start();
        try{
            t1.join();
        }catch(InterruptedException e){
            System.out.println(e);
        }
        t2.start();
    }
}
