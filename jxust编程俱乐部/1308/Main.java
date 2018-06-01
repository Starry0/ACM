import java.io.*;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner((new BufferedInputStream(System.in)));
    String s = cin.next();
    char cc = s.charAt(0);
    if(cc >='A'&& cc <='Z'){
      cc = (char)(cc + 32);
    }
      System.out.println(cc);
  }
}
