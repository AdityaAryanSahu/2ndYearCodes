import java.util.Scanner;
class seatsfilledException extends Exception{
    seatsfilledException(){
    super("nigga seat filled");
    }
}
class notuniqueException extends Exception{
    notuniqueException (){
    super("not unique");
    }
}
public class q3 {
    static Scanner s=new Scanner(System.in);
    int regno;
    String name;
    short semester;
    float gpa;
    float cgpa;
    int year,month,day;
    static int flag=1;

    //constructor
    q3(int regno, String name, short semester, float gpa, float cgpa, int year, int day, int month){
        this.regno=regno;
        this.name=name;
        this.semester=semester;
       this.gpa=gpa;
       this.cgpa=cgpa;
       this.year=year;
        this.month=month;
       this.day=day;
    }
    //method to calc regno
    static int reg(int year,int n1,int posi) throws seatsfilledException{
    int threshold;
        int temp=year%100;
        int count=0;
        while(n1>0){
            count++;
            n1/=10;
        }
        int regno=((int) (temp*Math.pow(10,count)+posi));
         threshold=((int) (temp*Math.pow(10,count)+25));
        if(regno>threshold){
        flag=0;
        throw new seatsfilledException();
        }
        else{
       flag=1;
        return regno;
        }
    }
    static void compare(q3[] ob,int i,int regno) throws notuniqueException{
        for(int j=0;j<i;j++){
            if(ob[j].regno==regno){
                throw new notuniqueException();
            }
        }

    }
    //method for display
     void display(){
        System.out.println("regno is: "+this.regno);
        System.out.println("name: "+this.name);
        System.out.println("sem: "+this.semester);
        System.out.println("gps: "+this.gpa);
        System.out.println("cg: "+this.cgpa);
        System.out.println("date of joining: "+this.day+"/"+this.month+"/"+this.year);
        System.out.println();
    }

    public static void main(String[] args) {
System.out.println("enter no of students (min 5)");
        int n=s.nextInt();
        q3[] ob=new q3[n];
        int regno,posiiton;
        String name;
        short semester;
        float gpa;
        float cgpa;
        int year,month,day;
        int count=0;

        for(int i=0;i<n;i++){
            System.out.println("enter details of student "+(i+1));
             System.out.println("enter day month year of joining");
            day=s.nextInt();
            month=s.nextInt();
            year=s.nextInt();
           
            System.out.println("enter posiiton");
            while(true){
            posiiton=s.nextInt();
            int n1=posiiton;          
            try{
            regno=reg(year,n1,posiiton);

                compare(ob,i,regno);
                break;
            }
            catch(notuniqueException e){
                System.out.println("not uniquw");
                System.out.println("enter posiiton again");
            }

            catch(seatsfilledException e){
            e.printStackTrace();
            System.out.println("enter posiiton again");
            regno=-1;
             }
        }
    
    System.out.println("regno: "+regno);
            
            s.nextLine();
            System.out.println("enter name ");
            name=s.nextLine();

            System.out.println("enter sem ");
            semester=s.nextShort();
            System.out.println("enter gpa & cgpa");
            gpa=s.nextFloat();
            cgpa =s.nextFloat();

            ob[i]=new q3(regno,name,semester,gpa,cgpa,year,day,month);

    }
        for(int i=0;i<n;i++) {
            System.out.println("\ndetails of student " + (i + 1) + ":");
            ob[i].display();
        }
    }
}
