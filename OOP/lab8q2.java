
class thre extends Thread{
    int[] arr;
    static int[] partial=new int[3];
    static int j=0;
    thre(int[] arr){
        this.arr=arr;
    }
    public  void run(){
       int sum=0;
        for(int i:arr){
            sum+=i;
        }
        partial[j++]=sum;
    }
}
public class lab8q2 {
    public static void main(String[] args) {
        int[][] a={{1,2,30},{2,3,20},{50,5,6}};
        thre[] th=new thre[a.length];
        for(int i=0;i<a.length;i++){
            th[i]=new thre(a[i]);
            th[i].start();
            try{
                th[i].join();
            }catch (InterruptedException e){
                System.out.println(e);
            }
        }
        int sum=0;
        for(int i=0;i<thre.partial.length;i++){
            System.out.println("the sum of row "+(i+1)+": "+thre.partial[i]);
            sum+=thre.partial[i];
        }
        System.out.println("the total sum is: "+sum);
    }
}
