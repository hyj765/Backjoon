import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Map<Integer,Integer> f = new HashMap<>();
		int n = sc.nextInt();
		for(int i=0; i<n; i++) {
			int temp = sc.nextInt();
			f.put(temp, 1);
		}
		int n2 = sc.nextInt();
		for(int i=0; i<n2; i++) {
			int temp = sc.nextInt();
			if(f.containsKey(temp)) System.out.println(1);
			else System.out.println(0);
		}
		
	}
}
