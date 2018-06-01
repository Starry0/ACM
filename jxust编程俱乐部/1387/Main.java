import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    int x,n;
    while(cin.hasNext()){
      long sum = 0;
      n = cin.nextInt();x = cin.nextInt();
      int a,b;
      for(int i = 1;i <= n; i++){
        int flag = 1;
        a = i;
        while(a > 0){
          b = a % 10;
          if(b == x){
            flag = 0;
            break;
          }
          a /= 10;
        }
        if(flag==1)
          sum += (long)i;
      }
      System.out.println(sum);
    }
  }
}
