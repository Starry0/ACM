import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    int k,n=1;
    double sum=0l;
    k = cin.nextInt();
    while(true){
      sum+=1.0/n;
    //  System.out.println(sum);
      if(sum>=k){
        System.out.println(n);
        break;
      }
      else n++;
    }
  }
}
