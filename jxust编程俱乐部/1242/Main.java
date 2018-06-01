import java.io.*;
import java.util.Scanner;
import java.text.DecimalFormat;
public class Main{
  public static void main(String[] args){
    //Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    Scanner cin = new Scanner(System.in);
    DecimalFormat df = new DecimalFormat("0.000000");
    float[] a = new float[4];
    a[0] = cin.nextFloat();
    a[1] = cin.nextFloat();
    a[2] = cin.nextFloat();
    float temp;
    for(int i=0;i<3;i++){
      for(int j=0;j<2-i;j++){
        if(a[j]>a[j+1]){
          temp = a[j];
          a[j] = a[j+1];
          a[j+1] = temp;
        }
      }
    }
    float db;
    for(int i=0;i<3;i++)
      db = df.format(a[i]);
      System.out.print(db + " ");
  }
}
