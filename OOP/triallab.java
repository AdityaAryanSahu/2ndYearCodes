/* import java.util.Scanner;
class trye{
    int section;
    String name;
    trye(){
        System.out.println("works");
    }
    trye(int section,String name){
        this.section=section;
        this.name=name;
        }
    void display(){
        System.out.println(this.section);
        System.out.println(this.name);

    }
}
public class triallab {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int section;
        String name;
        trye[] ob=new trye[n];
       // char a;
        //a=s.next().charAt(0);
       // System.out.println(a);
        for(int i=0;i<n;i++){
            ob[i]=new trye();
            ob[i].name=s.next();
            s.nextLine();
            ob[i].section=s.nextInt();
            ob[i]=new trye(ob[i].section,ob[i].name);
            ob[i].display();
        }
    }
}*/

import java.util.Scanner;
public class triallab {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter suze");
        int n=s.nextInt();
        System.out.println("Enter target");
        int target=s.nextInt();
        int [] a=new int[n];
        for(int i=0;i<n;i++)
            a[i]=s.nextInt();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]+a[j]==target)
                    System.out.println("the indices are:"+i+" "+j);

            }
        }

    }
}
