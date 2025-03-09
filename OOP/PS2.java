
import java.util.Scanner;
public class PS2 {
    public static void main(String[] args) {
        //q2
        //encryp
//        char g1='A';
//        g1=(char) (g1+8);
//        System.out.println("The grade is "+ g1);
//        //decrypt
//        g1=(char) (g1-8);
//        System.out.println("the correct grade is "+g1);

        //q3
        Scanner sc=new Scanner(System.in);
//        int a=sc.nextInt();
//        boolean b1=a>22;
//        System.out.println("The answer is "+ b1);
        //q4
//        int v=100, u=90, a=1, s=3;
//        float exp=((v*v-u*u)/(2*(float) a*s));
//        System.out.println(exp);
//        int as=7*49/5+35/7;
//        System.out.printf("The input values were %d, %d, %d, %d\n",v,u,a,s);
//        System.out.printf("The value is %d",as);



        //Strings
        String str="    My aduta is";
        String str2=str.trim();//trim removes spaces from start and end
        System.out.println(str);
        System.out.println(str2);

        String str3=str2.substring(5); //substring starts a string from given index no.
        System.out.println(str3);

        String str4=str2.substring(2,7);//starts string from index 2 but doesnt include 7(stops at 6)
        System.out.println(str4);

        String str5=str2.replace('a','o');//replaces a with o in the strig
        System.out.println(str5);

        String str6=str2.replace("uta","itya");//replaces uta with itya in the string
        System.out.println(str6);

        System.out.println(str2.endsWith("to"));//boolean checks if string ends with "to"
        System.out.println(str2.startsWith("My"));//boolean checks if string strats with "My"
    }
}
