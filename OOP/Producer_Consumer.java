
class Producer implements Runnable{
    obj c;
      int i=0;
    Producer(obj c){
        this.c=c;
    }
    public void run(){
       while(true) {
           c.set(i++);
           try {
               Thread.sleep(1000);
           } catch (InterruptedException e) {
               throw new RuntimeException(e);
           }
       }
    }

}
class Consumer implements Runnable {
    obj c;

    Consumer(obj c) {
        this.c = c;
    }

    public void run() {
        while (true) {
            c.get();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
class obj{
    int num;
     boolean flag=false;
   synchronized void set(int num){
       if(flag) {
           try {
               wait();
           } catch (InterruptedException e) {
               throw new RuntimeException(e);
           }
       }
        this.num=num;
       System.out.println("Producer: "+this.num);
        flag=true;
        notify();
    }
   synchronized void get(){
       if(!flag){
           try {
               wait();
           } catch (InterruptedException e) {
               throw new RuntimeException(e);
           }
       }
       System.out.println("Consumer: "+this.num);
        flag=false;
        notify();
    }
}


public class Producer_Consumer {
    public static void main(String[] args) {
        obj o=new obj();
        Thread t1=new Thread( new Producer(o));
        Thread t2=new Thread( new Consumer(o));
        t1.start();
        t2.start();
    }
}
