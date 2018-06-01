import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    int n,sum=0;
    n = cin.nextInt();
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(i==j||i==n+1-j)
          System.out.print("Y");
        else System.out.print("O");
      }
      System.out.println();
    }
  }
}
