    import java.util.Scanner;
    class Student1 {
        int[] marks;
        int avg;
        int total;
        String name;

        public Student1(String name, int id) {
        }

        public Student1(int[] marks, int total, int avg, String name) {
            this.marks = marks;
            this.total = total;
            this.avg = avg;
            this.name = name;
        }

        void display() {
            for(int i:marks)
            System.out.println(i);
            System.out.println(  total+" "+avg+" "+name);
        }
    }

    public class q1lab4 {
        static int total1(int[] a,int n){
            int total=0;
            for(int i=0;i<n;i++)
                total=total+a[i];
            return total;
        }
        public static void main(String[] args) {
         Scanner s=new Scanner(System.in);
         q1lab4 o=new q1lab4();
         int [] arr=new int[5];
         for(int i=0;i<5;i++)
             arr[i]=s.nextInt();
         //Student s=new Student();
         int total=total1(arr,5);
            Student1 student=new Student1(arr, total, 78, "Adi");
            student.display();


        }
    }
