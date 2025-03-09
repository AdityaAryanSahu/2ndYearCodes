import java.util.Scanner;

public class lab5q6 {
    static String inse(String name,char ch,int n){
        StringBuilder sb = new StringBuilder(name);
        for (int i = n-3; i > 0;) {
            sb.insert(i, ",");
            i-=3;
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
        int n=name.length();
        char ch=',';
        String name2=inse(name,ch,n);
        System.out.println(name2);
    }
}
