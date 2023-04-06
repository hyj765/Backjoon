import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static class edge implements Comparable<edge>{
		int start ;
		int end;
		int weight;
		public edge(int src,int dst , int wt) {
			this.start = src;
			this.end = dst;
			this.weight = wt;
		}
		@Override
		public int compareTo(edge o) {
			return this.weight - o.weight;
		}
	}
	
	static int find(int[]parents,int x) {
		if(x == parents[x]) return x;
		
		return parents[x] = find(parents,parents[x]);
	}
	
	static boolean union(int[] parents, int x ,int y) {
		x = find(parents,x);
		y = find(parents,y);
		if(x == y) return false;
		
		parents[y] = x;
		return true;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken());
		int n_edge = Integer.parseInt(st.nextToken());
		int [] parents = new int[v+1];
		edge[] edges = new edge[n_edge];
		for(int i=1; i<=v; i++) parents[i] = i;
		for(int i=0; i<n_edge; i++) {
			st = new StringTokenizer(br.readLine());
			int src = Integer.parseInt(st.nextToken());
			int dst = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			edges[i] = new edge(src,dst,weight);
		}
		
		Arrays.sort(edges);
		int count =0;
		int result =0;
		for(edge s:edges) {
			if(union(parents,s.start, s.end)) {
				result+= s.weight;
				if(++count == v-1) {
					break;
				}
			}
		}
		
		System.out.println(result);
	}

}
