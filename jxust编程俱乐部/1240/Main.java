import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    int[] a = new int[12];
    for(int i=0;i<10;i++){
      a[i] = cin.nextInt();
    }
    int temp;
    for(int i=0;i<10;i++){
      for(int j=i+1;j<10;j++){
        if(a[i]<a[j]){
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
      }
    }
    for(int i=0;i<10;i++){

      System.out.print(a[i] + " ");
    //  System.out.print(" ");
    }
  }
}
