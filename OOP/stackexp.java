import java.util.Scanner;
 class pushException extends Exception{
     void isfull(){
             System.out.println("exception occured:stack full");
     }
 }
class popException extends Exception{
    void isempty(){
            System.out.println("exception occured:stack empty");
    }
}

public class stackexp {
     int top=-1;
     int[] ele;
    stackexp(int[] ele){
        this.ele=ele;
    }
   static void push(stackexp s,int e,int max) throws pushException{
        if(s.top!=max-1) {
            s.top += 1;
            s.ele[s.top] = e;
        }
        else{
            throw new pushException();
        }
    }
    static void pop(stackexp s) throws popException {
        if(s.top!=-1) {
            int e = s.ele[s.top];
            s.top -= 1;
            System.out.println("deleted ele is " + e);
        }
        else
            throw new popException();
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("enter max ele");
        int n = s.nextInt();
        int[] ele = new int[n];
        stackexp ob = new stackexp(ele);
        int ch;
        do {
            System.out.println("1.push 2.pop 3.exit\n");
             ch = s.nextInt();

            switch (ch) {
                case 1:
                    try {
                        int e = s.nextInt();
                        push(ob, e, n);
                    } catch (pushException e) {
                        e.isfull();
                        //e.printStackTrace();
                    }
                    break;
                case 2:
                    try {
                        pop(ob);
                    } catch (popException e3) {
                        e3.isempty();
                        e3.printStackTrace();
                    }
                    break;

            }
        } while (ch!= 3);
    }
}
