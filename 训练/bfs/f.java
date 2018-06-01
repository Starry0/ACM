import java.util.*;

class F{
	//int[][] d = new int[500][500];
	static int[][] knight = new int[8][8];
	static int[] dx = {1, 2, 1, 2, -1, -2, -1, -2};
	static int[] dy = {2, 1, -2, -1, 2, 1, -2, -1};
	static int n, sx, sy, gx, gy;
	static void dfs(int si, int sj, int moves){
		if(si < 0 || sj < 0 || si >= 8 || sj >= 8 || moves >= knight[si][sj]){
			return;
		}
		knight[si][sj] = moves;
		for(int i = 0; i < 8; i ++){
			dfs(si+dx[i], sj+dy[i], moves+1);
		}
	}
	public static void main(String args[]){
		char[] a = new char[10];
		char[] b = new char[10];
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			String s = cin.next();
			String s1 = cin.next();
			a[0] = s.charAt(0);
			a[1] = s.charAt(1);
			b[0] = s1.charAt(0);
			b[1] = s1.charAt(1);
			for(int i = 0; i < knight.length; i ++){
				for(int j = 0; j < knight.length; j ++){
					knight[i][j] = 10;
				}
			}
			int aa = (int)a[0];
			int aaa = (int)a[1];
			int bb = (int)b[0];
			int bbb = (int)b[1];
			dfs(aa-97, aaa-49, 0);
			System.out.println("To get from "+s+" to "+s1+" takes "+knight[bb -97][bbb - 49]+" knight moves.");
		}
	}
}
