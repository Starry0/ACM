import java.util.*;
class Main{
    public static void factorial(int n){
        int[] a = new int[10000];
        a[0] = 1;
        int res = 0;
        for(int i = 1; i <= n; i ++){
            int flag = 0;
            for(int j = 0; j <= res; j ++){
                a[j] = a[j]*i + flag;
                flag = a[j]/10000;
                a[j]%=10000;
            }
            if(flag > 0){
                a[++res] = flag;
            }
        }
        System.out.print(a[res]);
        for(int i = res-1; i >= 0; i --){
            int k = 1, b = 10;
            while(a[i]/b > 0){
                k++;
                b*=10;
            }
            switch(k){
                case 1:System.out.print("000");
                    break;
                case 2:System.out.print("00");
                    break;
                case 3:System.out.print("0");
                    break;
                default:
                    break;
            }
            System.out.print(a[i]);
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        while (cin.hasNext()){
			n = cin.nextInt();
            factorial(n);
		}
    }
}
