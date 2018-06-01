import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    String s = cin.next();
    char c = s.charAt(0);
    if(c == 'M'){
      System.out.println("Married");
    }
    if(c == 'S')
      System.out.println("single");
    if(c == 'D')
      System.out.println("Divorced");
    if(c == 'W')
      System.out.println("Widowed");
  }
}
