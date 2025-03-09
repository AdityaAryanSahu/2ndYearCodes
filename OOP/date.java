import java.util.Scanner;

import static java.lang.System.exit;

class dayException extends Exception{
    dayException(){
        super("exception:day invalid");
    }
}
class monthException extends Exception{
    monthException(){
        super("exception:month invalid");
    }
}

public class date {
    static Scanner s=new Scanner(System.in);
    int day;
    int month;
    int year;
    void createDate()throws dayException,monthException{
        System.out.println("enter day(1-30)");
        day=s.nextInt();
        if(day<1 || day>30){
            throw new dayException();
            }
        System.out.println("enter month(1-12)");
        month=s.nextInt();
        if(month<1||month>12){
            throw new monthException();
            }
        System.out.println("enter year");
        year=s.nextInt();
    }
    void display() {
            System.out.println("date: "+day+"/"+month+"/"+year);
    }

    public static void main(String[] args) {
        date d=new date();
     while(true){
        try{
            d.createDate();
           break;
        }catch(dayException e){
            e.printStackTrace();
            System.out.println("enter date again");
        }
        catch(monthException q){
            q.printStackTrace();
            System.out.println("enter date again");
        }
    }
        d.display();
 }
}
