import java.util.Scanner;

abstract class StringOperation{
    abstract void operate();
}

class ReverseString extends StringOperation implements Runnable{
    String str;
    static String reverssed;
    ReverseString(String str){
        this.str=str;
        reverssed="";
    }
    void operate(){
        for(int i=str.length()-1;i>=0;i--)
            reverssed+=str.charAt(i);
        Result<String> r=new Result<>(reverssed);
        System.out.println(r.get());
    }
    @Override
    public void run(){
       operate();
    }

}

class Palin extends StringOperation implements Runnable{
    String str;
    static String reverssed;
    Palin(String str){
        this.str=str;
        reverssed="";
    }
    void operate(){
        for(int i=str.length()-1;i>=0;i--)
            reverssed+=str.charAt(i);
        boolean flag=str.equals(reverssed);
        Result<Boolean> r=new Result<>(flag);
        System.out.println(r.get());
    }
    @Override
    public void run(){
        operate();
    }

}

class Concate extends StringOperation implements Runnable{
    String str;
    static String reverssed;
    String newString="";
    Concate(String str){
        this.str=str;
        reverssed="";
    }
    void operate(){
        for(int i=str.length()-1;i>=0;i--)
            reverssed+=str.charAt(i);
        boolean flag=str.equals(reverssed);
        newString+=str+reverssed;
        Result<String> r=new Result<>(newString);
        System.out.println(r.get());
    }
    @Override
    public void run(){
        operate();
    }

}
class Result<T>{
    T stt;
   Result(T stt){
       this.stt=stt;
   }
   T get(){
       return stt;
   }
}

class EmptyException extends Exception{
    EmptyException(){
        super("nigga empty string");
    }
}
public class ITD_Q {
  public static void main(String[] args) throws EmptyException,InterruptedException {
        Scanner s=new Scanner(System.in);
        String str;
      while(true) {
          try {
               str = s.nextLine();
              if (str.equals(""))
                  throw new EmptyException();
              else break;
          } catch (EmptyException e) {
              e.printStackTrace();
              System.out.println("enter again properly");
          }
      }
        int ch;
        do{
            System.out.println("1.Reverse 2.Palin 3.concate 4.exit");
            ch=s.nextInt();
            switch (ch){
                case 1:ReverseString t1=new ReverseString(str);
                       Thread th1=new Thread(t1);
                       th1.start();
                       th1.join();
                   break;
                case 2:  Palin t2=new Palin(str);
                    Thread th2=new Thread(t2);
                    th2.start();
                    th2.join();
                    break;
                case 3:Concate t3=new Concate(str);
                     Thread th3=new Thread(t3);
                     th3.start();
                     th3.join();
                    break;

            }
        }while(ch!=4);
    }
}
