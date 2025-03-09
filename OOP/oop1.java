import java.util.Scanner;


public class oop1 {

    static int revi(int n){
        int dig,sum=0;
        int i;
        for(i=0;n>0;i++){
            dig=n%10;
            sum=sum*10+dig;
            n/=10;
        }
        return sum;
    }
    public static void main(String[] args) {
        int n;
        System.out.println("enetr a number: ");
        Scanner sc= new Scanner(System.in);
        n=sc.nextInt();
        int reverse= revi(n);
        System.out.println(n);
    }
}
