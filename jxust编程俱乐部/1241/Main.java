import java.io.*;
import java.util.Scanner;

public class Main{
  static void f(int a,int b){
    System.out.println(b + " " + a);
  }
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    int a,b;
    a = cin.nextInt();b = cin.nextInt();
    f(a,b);
  }
}
