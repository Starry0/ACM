import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    int[] a = new int[12];
    for(int i=0;i<11;i++){
      a[i] = cin.nextInt();
    }
    int maxn = a[0];
    for(int i=1;i<11;i++){
      if(a[i]>maxn)
        maxn = a[i];
    }
    System.out.println(maxn);
  }
}
