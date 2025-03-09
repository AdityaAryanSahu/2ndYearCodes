import java.util.Scanner;
public class arrays_PS6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        int [] marks=new int [100];
//        System.out.println("Enter total number of elements");
//        int n=sc.nextInt();
//        for(int i=0;i<n;i++){
//           marks[i]=sc.nextInt();
//        }
//        for(int i=0;i<n;i++){
//            System.out.println(marks[i]);
//        }

        //printing 2d array
//        int [][] marks=new int [100][100];
//        System.out.println("Enter number of rows and columns");
//        int m=sc.nextInt();
//        int n=sc.nextInt();
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                marks[i][j]=sc.nextInt();
//            }
//        }
//        System.out.println("The 2d matrix is:");
//        for(int i=0;i<m;i++) {
//            for (int j = 0; j < n; j++) {
//                System.out.print(marks[i][j]);
//                System.out.print("\t");
//            }
//            System.out.print("\n");
//        }

        //q1
//        float []val=new float [100];
//        for(int i=0;i<5;i++){
//            val[i]=sc.nextFloat();
//        }
//        float sum=0;
//        for(int i=0;i<5;i++){
//            sum+=val[i];
//        }
//        System.out.println("The sum is "+sum);

        //q2

//        int [] marks={1,2,3,4,5,6,7,8,8,1,2};
//        System.out.println("Enter the number to be searched");
//        int n=sc.nextInt();
//        boolean b1=false;
//        for(int i=0;i<11;i++) {
//            if (n == marks[i]) {
//                b1 = true;
//                System.out.println("Number is there");
//                break;
//            }
//        }
//            if(b1==false){
//                System.out.println("The number is not there");
//            }

        //q4
//        int[][] mat1 = new int[100][100];
//        int[][] mat2 = new int[100][100];
//        int[][] mat3 = new int[100][100];
//        System.out.println("Enter the rows and column for mat1");
//        int m1 = sc.nextInt();
//        int n1 = sc.nextInt();
//        System.out.println("Enter the rows and column for mat2");
//        int m2 = sc.nextInt();
//        int n2 = sc.nextInt();
//        if (m1 == m2 && n1 == n2) {
//            System.out.println("Enetr the mat1");
//            for (int i = 0; i < m1; i++) {
//                for (int j = 0; j < n1; j++) {
//                    mat1[i][j] = sc.nextInt();
//                }
//            }
//            System.out.println("Enetr the mat2");
//            for (int i = 0; i < m1; i++) {
//                for (int j = 0; j < n1; j++) {
//                    mat2[i][j] = sc.nextInt();
//                }
//            }
//            for (int i = 0; i < m1; i++) {
//                for (int j = 0; j < n1; j++) {
//                    mat3[i][j] = mat1[i][j] + mat2[i][j];
//                }
//            }
//            System.out.println("new mat is");
//            for (int i = 0; i < m1; i++) {
//                for (int j = 0; j < n1; j++) {
//                    System.out.print(mat3[i][j]);
//                    System.out.print("\t");
//                }
//                System.out.print("\n");
//            }
//
//
//        }
//        else {
//            System.out.println("Sum is not possible");
//        }

        //q5
        int []mat1=new int [100];
        System.out.println("Enter the number of elements");
        int n=sc.nextInt();
        System.out.println("Enter the arrray");
        for(int i=0;i<n;i++){
            mat1[i]=sc.nextInt();
        }
//        System.out.println("unreversed array is");
//        for(int i=0;i<n;i++){
//            System.out.print(mat1[i]);
//            System.out.print("\t");
//        }
//        for(int i=0;i<n/2;i++){
//            int temp=mat1[i];
//            mat1[i]=mat1[n-i-1];
//            mat1[n-i-1]=temp;
//        }
//        System.out.println(" ");
//        System.out.println("reversed array is");
//        for(int i=0;i<n;i++){
//            System.out.print(mat1[i]);
//            System.out.print("\t");
//        }

        //q6
//        int max=mat1[0];
//        boolean b1=false;
//        for(int i=0;i<n-1;i++){
//            if(max>mat1[i+1]){
//               b1=true;
//            }
//            else{
//                max=mat1[i+1];
//            }
//        }
//            System.out.println("Max is "+max);
//        }

        boolean b1=false;
       // for(int i=0;i<n/2;i++){
            for(int j=0;j<n-1;j++) {
                if (mat1[j] <= mat1[j + 1]) {
                    b1 = true;
                }
                else {
                    b1 = false;
                    break;
                }
            }
        //}
            if(b1==true){
                System.out.println("soretd");}
                else{
                    System.out.println("not sorted");
                }

        }



    }

