import java.util.Scanner;
    public class lab5q2 {
        String names;
        static String extract(String name){            String name2="";
            name2=name2+name.charAt(0);
            for(int i=0;i<name.length();i++){
                if(name.charAt(i)==' '){
                    name2=name2+name.charAt(i+1);
                }
            }
            name2=name2.toUpperCase();
            return name2;
        }
        static String whitespace(String name){
            String name2=name.replace(" ","");
            return name2;
        }
        static boolean list(String name,String sub){
            return name.contains(sub);
        }

        public static void main(String[] args) {
            String name;
            Scanner s=new Scanner(System.in);
            System.out.println("enter a name");
            name=s.nextLine();
            System.out.println("input name is: "+name);
            String initials=extract(name);
            System.out.println("the initial are: "+initials);
            String trimmed=whitespace(name);
            System.out.println("name w/o spaces is: "+trimmed);
            System.out.println("enter no of names");
            int n=s.nextInt();
            System.out.println("enter a substring to be serched");
            String sub=s.next();
            //s.nextLine();
            lab5q2[] ob=new lab5q2[n];
            for(int i=0;i<n;i++){
                ob[i]=new lab5q2();
                System.out.println("enter name "+(i+1));
                ob[i].names=s.next();
                //s.nextLine();
                if(list(ob[i].names,sub))
                    System.out.println("name "+ob[i].names+" has substring");
                else
                    System.out.println("name "+ob[i].names+" does not have substring");
            }
            System.out.println("after sorting:");
            for(int j=0;j<n-1;j++) {
                for (int i = 0; i < n - 1; i++) {
                    if (ob[i].names.compareTo(ob[i + 1].names) > 0) {
                        String temp = ob[i].names;
                        ob[i].names = ob[i + 1].names;
                        ob[i + 1].names = temp;
                    }
                }
            }
            for(int i=0;i<n;i++){
                System.out.println(ob[i].names);
            }
        }
    }

