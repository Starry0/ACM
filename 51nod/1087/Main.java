import java.util.Scanner;
import java.math.*;

public class Main{
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		String str = cin.next();
		int n = cin.nextInt();
		BigDecimal bd = new BigDecimal(str.toCharArray());
		while(n-- > 0) {
			//System.out.println(bd);
			bd = bd.multiply(bd);
		}
		System.out.println(bd);
	}
}