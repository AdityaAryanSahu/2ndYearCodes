
class thread1 extends Thread {
    int[][] arr;

    thread1(int[][] arr) {
        this.arr = arr;
    }

    public void run() {
        int flag = 1;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {

                for (int k = 0; k < arr.length; k++) {
                    for (int p = 0; p < arr[k].length; p++) {
                        if(p==j && k==i) {
                            continue;
                        }
                    if (arr[i][j] == arr[k][p]) {
                        flag = 0;
                        System.out.println("matrix elelmnets not unique");
                        return;
                        }
                     }
                    }
                }
            }
        if(flag==1) System.out.println("unique");

            }
        }
class thread2 extends Thread{
    int[][] arr;
   static int[] row=new int[4];
    thread2(int [][] arr){
        this.arr=arr;
    }
    public void run(){
        int sum;
        for(int i=0;i<arr.length;i++) {
            sum = 0;
            for (int j = 0; j < arr[i].length; j++) {
               sum+=arr[i][j];
            }
            row[i]=sum;
            System.out.println("sum of row "+(i+1)+": "+sum);
        }
    }
}
class thread3 extends Thread{
    int[][] arr;
    static int[] col=new int[4];
    static int sum2;
    thread3(int [][] arr){
        this.arr=arr;
    }
    public void run(){
        int sum;
        for(int i=0;i<arr[0].length;i++) {
            sum = 0;
            for (int j = 0; j < arr.length ; j++) {
                sum+=arr[j][i];
            }
            col[i]=sum;
            System.out.println("sum of cloumn "+(i+1)+": "+sum);
        }
    }
}
class thread4 extends Thread{
    int[][] arr;
    static int sum1;
    thread4(int [][] arr){
        this.arr=arr;
    }
    public void run(){
         sum1=0;
        for(int i=0;i<arr.length;i++) {
            //sum = 0;
            for (int j = 0; j < arr[i].length ; j++) {
                if(i==j)
                    sum1+=arr[i][j];
            }
        }
        System.out.println("sum of princ diag: "+sum1);
    }
}
class thread5 extends Thread{
    int[][] arr;
    static int sum2;
    thread5(int [][] arr){
        this.arr=arr;
    }
    public void run(){
        sum2=0;
        for(int i=0;i<arr.length;i++) {
            //sum = 0;
            for (int j = arr[i].length-1; j>=0 ; j--) {
                if(i+j==arr.length-1 )
                    sum2+=arr[i][j];
            }
        }
        System.out.println("sum of sec diag: "+sum2);
    }
}


public class lab8_add1 {
    public static void main(String[] args) {
        int[][] arr={{1,14,15,4},{12,7,6,9},{8,11,10,5},{13,2,3,16}};


        thread1 th1=new thread1(arr);
        th1.start();
        try{
            th1.join();
        }catch(InterruptedException e){}


        thread2 th2=new thread2(arr);
        System.out.println();
        th2.start();
        try{
            th2.join();
        }catch(InterruptedException e){}


        System.out.println();
        thread3 th3=new thread3(arr);
        th3.start();
        try{
            th3.join();
        }catch(InterruptedException e){}


        System.out.println();
        thread4 th4=new thread4(arr);
        th4.start();
        try{
            th4.join();
        }catch(InterruptedException e){}


        thread5 th5=new thread5(arr);
        th5.start();
        try{
            th5.join();
        }catch(InterruptedException e){}


        System.out.println();
        int flag=0;
        if(thread4.sum1==thread5.sum2) {
            for (int i = 0; i < thread2.row.length; i++) {
                for (int j = 0; j < thread3.col.length; j++) {
                    if (thread2.row[i] == thread3.col[i]) {
                        flag = 1;
                    }
                }
            }
            int k=0;
            for (int i = 0; i < thread2.row.length; i++) {
                if (flag == 1) {
                    if (thread4.sum1 == thread2.row[i])
                        k=1;
                }
            }
            if(k==1)
                System.out.println("magic");
            else System.out.println("gay");
        }
        else System.out.println("not magic");
    }
}
