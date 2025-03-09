import java.util.Scanner;
public class lab5 {
    static Scanner s=new Scanner(System.in);
    int regno;
    String name;
    short semester;
    float gpa;
    float cgpa;
    int year,month,day;

    //constructor
    lab5(int regno, String name, short semester, float gpa, float cgpa, int year, int day, int month){
        this.regno=regno;
        this.name=name;
        this.semester=semester;
       this.gpa=gpa;
       this.cgpa=cgpa;
       this.year=year;
        this.month=month;
       this.day=day;
    }
    //method for array of students
    static void objects(){
        System.out.println("enter no of students (min 5)");
        int n=s.nextInt();
        lab5[] ob=new lab5[n];
        int regno,posiiton;
        String name;
        short semester;
        float gpa;
        float cgpa;
        int year,month,day;

        for(int i=0;i<n;i++){
            System.out.println("enter details of student "+(i+1));
            System.out.println("enter posiiton");
            posiiton=s.nextInt();
            int n1=posiiton;
            System.out.println("enter day month year of joining");
            day=s.nextInt();
            month=s.nextInt();
            year=s.nextInt();
           regno=reg(year,n1,posiiton);
            System.out.println("regno is: "+regno);
            s.nextLine();
            System.out.println("enter name ");
            name=s.nextLine();

            System.out.println("enter sem ");
            semester=s.nextShort();
            System.out.println("enter gpa & cgpa");
            gpa=s.nextFloat();
            cgpa =s.nextFloat();

            ob[i]=new lab5(regno,name,semester,gpa,cgpa,year, day,month);


        }
        for(int i=0;i<n;i++) {
            System.out.println("\ndetails of student " + (i + 1) + ":");
            ob[i].display();
        }
        q4a(ob,n);
        q4b(ob,n);
        q5a(ob,n);
        q5b(ob,n);
        q5c(ob,n);
        for(int i=0;i<n;i++){
        ob[i].display();}
    }
   static void q4a(lab5[] ob,int n){

            System.out.println("1.sort wrt sem 2.sort wrt cg 3.neither");
            int ch=s.nextInt();
            switch(ch){
                case 1:for(int j=0;j<n-1;j++) {
                    for (int i = 0; i < n - 1; i++) {
                        if (ob[i].semester < ob[i + 1].semester) {
                            lab5 temp = ob[i];
                            ob[i] = ob[i + 1];
                            ob[i + 1] = temp;
                        }
                    }
                }
                break;
                case 2:for(int j=0;j<n-1;j++) {
                    for (int i = 0; i < n - 1; i++) {
                        if (ob[i].cgpa < ob[i + 1].cgpa) {
                            lab5 temp = ob[i];
                            ob[i] = ob[i + 1];
                            ob[i + 1] = temp;
                        }
                    }
                }
                break;
            }
   }
    static void q4b(lab5[] ob, int n){
        for(int j=0;j<n-1;j++) {
            for (int i = 0; i < n - 1; i++) {
                if (ob[i].name.compareTo(ob[i + 1].name) > 0) {
                    lab5 temp = ob[i];
                    ob[i] = ob[i + 1];
                    ob[i + 1] = temp;
                }
            }
        }
    }
    static void q5a(lab5[] ob, int n){
        System.out.println("\nq5a:");
        System.out.println("enter a charater");
        String st= String.valueOf(s.next().charAt(0));
        for(int i=0;i<n;i++){
            if(ob[i].name.startsWith(st))
                System.out.println(ob[i].name);
        }
    }
    static void q5b(lab5[] ob, int n) {
        System.out.println("\nq5b:");
        System.out.println("enter substrng to be searcehd");
        String sub = s.nextLine();
        s.nextLine();
        for (int i = 0; i < n; i++) {
            if (ob[i].name.contains(sub))
                System.out.println(ob[i].name);
        }
    }
    static void q5c(lab5[] ob, int n) {
        String name2="";
        for (lab5 sr:ob) {
             name2 = "";
            String[] str = sr.name.split(" ");
            int l;
            l=str.length;
           // int j=0;
            for(int j=0;j<l-1;j++) {
                name2 = name2 + Character.toUpperCase(str[j].charAt(0))+". ";
                j++;
            }
           // Character.toUpperCase(str[l-1].charAt(0));
            name2=name2+str[l-1];
            sr.name=name2;

        }
    }
    //method to calc regno
    static int reg(int year,int n1,int posi){
        int temp=year%100;
        int count=0;
        while(n1>0){
            count++;
            n1/=10;
        }
        int regno=((int) (temp*Math.pow(10,count)+posi));
        return regno;
    }
    //method for display
     void display(){
        System.out.println("regno is: "+this.regno);
        System.out.println("name: "+this.name);
        System.out.println("sem: "+this.semester);
        System.out.println("gps: "+this.gpa);
        System.out.println("cg: "+this.cgpa);
        System.out.println("date of joining: "+this.day+"/"+this.month+"/"+this.year);
    }

    public static void main(String[] args) {

        int regno,posiiton;
        String name;
        short semester;
        float gpa;
        float cgpa;
        int year,month,day;
        System.out.println("enter details of teat student ");
        System.out.println("enter posiiton");
        posiiton=s.nextInt();
        int n1=posiiton;
        System.out.println("enter day month year of joining");
        day=s.nextInt();
        month=s.nextInt();
        year=s.nextInt();
        regno=reg(year,n1,posiiton);
        System.out.println("regno is: "+regno);
        s.nextLine();
        System.out.println("enter name ");
        name=s.nextLine();

        System.out.println("enter sem ");
        semester=s.nextShort();
        System.out.println("enter gpa & cgpa");
        gpa=s.nextFloat();
        cgpa =s.nextFloat();

        lab5 ob=new lab5(regno,name,semester,gpa,cgpa,year, day,month);
        ob.display();
       objects();
        }
    }

