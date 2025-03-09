import java.util.Scanner;
public class lab3add1 {
    int sideup;
    void getSideup(int sideup){
        this.sideup=sideup;

    }
    void roll(){
        sideup=(int)((Math.random()*5)+1);
        System.out.println(sideup);
    }
    /*long code;
    static Scanner s=new Scanner(System.in);
     void read(){
        System.out.println("enter 10 digit code");
        code=s.nextLong();
        s.nextLine();
    }
     void check() {
        int i;
        int count = 0;
        int sum = 0;
        long n = code;
        long n2 = n;
        while (n > 0) {
            count++;
            n = n / 10;
        }
        System.out.println("count is "+count);
        if (count != 10) {
            System.out.println("code should be 10 digits");
        } else {
            int mul=10;
            while (n2 > 0) {
                int dig =(int) n2 % 10;
                sum = sum + mul*dig;
                mul--;
                n2 = n2 / 10;
            }
            System.out.println("sum is "+sum);
            if (sum % 11 == 0) {
                System.out.println("valid");
            } else
                System.out.println("illlegal");

        }
    }*/

    public static void main(String[] args) {
        lab3add1 ob=new lab3add1();
        ob.getSideup(6);
        ob.roll();
        lab3add1 ob1=new lab3add1();
        ob1.getSideup(4);
        ob1.roll();
        System.out.println(ob1.sideup+ob.sideup);
    }
}
