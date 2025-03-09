import java.util.Scanner;
class customer {
    private int cusid;
    private String name;
    private int credli;

    customer() {
        System.out.println("works");
    }

    customer(int cusid, String name, int credli) {
        this.cusid = cusid;
        this.name = name;
        this.credli = credli;
    }

    static void display(customer ob) {
        System.out.println();
        System.out.println("name is:" + ob.name);
        System.out.println("cusid is: " + ob.cusid);
        System.out.println("credli is: " + ob.credli);
        System.out.println();
    }
}
public class add2lab4 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        customer[] ob=new customer[5];

        for(int i=0;i<5;i++){
            int id=0;
            String name="null";
            int credli=0;
            System.out.println("Enter details of customer "+(i+1));
            name=s.nextLine();
            credli=s.nextInt();
            id=s.nextInt();
            s.nextLine();
            ob[i]=new customer();
            ob[i]=new customer(id,name,credli);
            customer.display(ob[i]);
        }
        s.close();
    }
}

