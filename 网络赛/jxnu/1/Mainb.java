import java.util.*;

public class Mainb{
    public static void main(String[] args) {
        String s;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            s = cin.next();
            int ans = 0, flag = 0;
            int len = s.length();
            for(int i = 0; i < len-1; i ++){
                if(s.charAt(i) == 'Y' && s.charAt(i+1) == 'S'){
                    ans ++;
                }
            }
            for(int i = 0; i < len-2; i ++){
                if(s.charAt(i) == 'Y' && s.charAt(i+1) == 'Y' && s.charAt(i+2) =='Y'){
                    flag = 1;
                }
                if(s.charAt(i) == 'S' && s.charAt(i+1) =='S' && s.charAt(i+2) == 'S'){
                    flag = 1;
                }
            }
            if(flag == 1) ans++;
            System.out.println(ans);
        }
    }
}
