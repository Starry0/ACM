import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner  cin = new Scanner(System.in);
        int[] a = new int[9];
        int n;
        n = cin.nextInt();
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < 9; j ++){
                a[j] = cin.nextInt();
            }
            for(int j = 1; j < 9; j ++){
                if(a[j] < a[0]){
                    System.out.print(a[j] + " ");
                }
            }
            System.out.print(a[0]);
            for(int j = 1; j < 9; j ++){
                if(a[j] > a[0]){
                    System.out.print(" " + a[j]);
                }
            }
            System.out.println();
        }
    }
}
