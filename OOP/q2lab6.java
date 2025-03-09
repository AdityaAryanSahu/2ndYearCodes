import java.util.Scanner;
class employee {
    String name;
    int eid;
    int basic;
    double da;
    double net_sal;
    double gross_sal;

    employee(String name,int basic,int eid,double da,double gross_sal,double net_sal){
        this.name=name;
        this.eid=eid;
        this.basic=basic;
        this.da=da;
        this.gross_sal=gross_sal;
        this.net_sal=net_sal;

    }
    void calsal(){
        this.da=0.52*this.basic;
        this.gross_sal=this.da+this.basic;
        this.net_sal=0.3*this.gross_sal;
    }
    void display(){
        System.out.println("name is: "+this.name);
        System.out.println("eid is: "+this.eid);
        System.out.println("basic sal is: " +this.basic);
        System.out.println("da is: "+this.da);
        System.out.println("gross_sal is: "+this.gross_sal);
        System.out.println("net_sal is: "+this.net_sal);
    }
}
class partime extends employee {
    int hours;
    static final double rate_hr = 20.5;

    partime(String name, int basic, int eid, double da, double gross_sal, double net_sal, int hours) {
        super(name, basic, eid, da, gross_sal, net_sal);
        this.hours = hours;
        //this.rate_hr=rate_hr;
    }

    void calsal() {
        this.basic = (int) ((int) this.hours * rate_hr);
       super.calsal();
    }

    void display() {

        System.out.println("hours worked: " + this.hours + " rate_hr: " + rate_hr);
        super.display();
    }
}

class fulltime extends employee{
    double bonus;
    double ded;
    fulltime(String name,int basic,int eid,double da,double gross_sal,double net_sal,double bonus,double ded){
        super(name,basic,eid,da,gross_sal,net_sal);
        this.bonus=bonus;
        this.ded=ded;
    }
    void calsal(){
        this.basic+=(this.bonus-this.ded);
        super.calsal();
    }
    void display(){

        System.out.println("bonus: "+this.bonus+" deductions: "+this.ded);
        super.display();
    }
}
public class q2lab6{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enter details for test employee:");
        String name=s.nextLine();
        int basic=s.nextInt();
        int eid=s.nextInt();
        employee ob=new employee(name,basic,eid,0,0,0);
        ob.calsal();
        ob.display();

        System.out.println("enter details for aprtime employee:");
        s.nextLine();
         name=s.nextLine();
         eid=s.nextInt();
         int hours=s.nextInt();
        partime ob1=new partime(name,0,eid,0,0,0,hours);
        ob1.calsal();
        ob1.display();

        System.out.println("enter details for fulltime employee:");
        s.nextLine();
         name=s.nextLine();
        basic=s.nextInt();
         eid=s.nextInt();
         double bonus=s.nextDouble();
         double ded=s.nextDouble();
        fulltime ob2=new fulltime(name,basic,eid,0,0,0,bonus,ded);
        ob2.calsal();
        ob2.display();
    }
}
