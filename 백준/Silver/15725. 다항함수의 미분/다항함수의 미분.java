import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int idx = str.indexOf('x');
        String ans="";

        if(str.contains("x")){
            if(idx==0) System.out.println('1');
            else {
                for(int i=0;i<idx;i++){
                    ans+=str.charAt(i);
                }
            }
            if(ans.equals("-")) ans+='1';
            System.out.println(ans);
        } else {
            System.out.println('0');
        }


    }
}