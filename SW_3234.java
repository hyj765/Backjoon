import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SW_3234 {
	static int cnt;
	static int ar[];
	static int count;
	static void process_function(int left,int right,int depth,int n) {
		if(left < right) return;
		if(depth == n) {
			cnt++;
			for(int i=0; i<n; i++) {
				System.out.print(ar[i] + " ");
			}
			System.out.println();
			return;
		}
		process_function(left+ar[depth],right,depth+1,n);
		process_function(left,right+ar[depth],depth+1,n);
	}
	
	static void solution(int depth,int n,int arr[],boolean visit[]) {
		if(depth == n) {
			process_function(0,0,0,n);
			System.out.println(++count);
			return;
		}
		
		for(int i=0;i<n; i++) {
			if(!visit[i]) {
				visit[i]= true;		
				ar[depth] = arr[i];
				solution(depth+1,n,arr,visit);
				visit[i]=false;
			}
	}
		
		
		
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for(int k = 0; k < tc; k++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int []arr = new int[n];
			ar = new int[n];
			cnt =0;
			boolean []visit = new boolean[n];
			for(int i=0; i<n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			solution(0,n,arr,visit);
			System.out.println("#"+k+" "+cnt);
		}
	}
}
