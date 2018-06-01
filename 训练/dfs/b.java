import java.util.*;
class Main{
	public static void main(String args[]){
		String s;
		Scanner cin = new Scanner(System.in);
		int res = 0, ans = 0;
		for(int i = 0; i < 8; i ++){
			s = cin.next();
			int k = 0;
			for(int j = 0; j < 8; j ++){
				if(s.charAt(j) == 'B') k++;
			}
			if(k == 8) ans ++;
			else res = k;
		}
		if(ans == 8) System.out.println(ans);
		else System.out.println(ans+res);
	}
}