import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    int n,sum=0;
    n = cin.nextInt();
    for(int i=1;i<=n;i++){
      if(i%2!=0)
        sum+=i;
    }
    System.out.println(sum);
  }
}
