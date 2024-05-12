import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static class pair{
		int x;
		int y;
		public pair(int x,int y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public String toString() {
			return "pair [x=" + x + ", y=" + y + "]";
		}
		
		
		
	}
	static int [][] map;
	static int max_count;
	static pair [] f = new pair[3];
	static int[] dx = {0,1,-1,0};
	static int[] dy = {1,0,0,-1};
	static void spread(int x, int y, int [][] map,boolean visit[][]) {
		Queue<pair> virus = new LinkedList<>();
		visit[x][y] = true;
		virus.add(new pair(x,y));
		while(!virus.isEmpty()) {
			int cx = virus.peek().x;
			int cy = virus.poll().y;
			for(int i=0; i<4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if(nx <0 || ny <0 || nx >= map.length || ny>= map[0].length) continue;
				if(!visit[nx][ny] && map[nx][ny] == 0) {
					visit[nx][ny] = true;
					map[nx][ny] = 2;
					virus.offer(new pair(nx,ny));
				}
			}
			
		}
		
	}
	static List<pair> every = new ArrayList<>();
	static int simulate(int [][] map) {
		boolean[][] visit = new boolean[map.length][map[0].length];
		int zero=0;
		for(int i=0; i<3; i++) {
			map[f[i].x][f[i].y] = 1;
		}
		
		
		for(int i=0; i<map.length; i++) {
			for(int j=0; j<map[0].length; j++) {
				if(!visit[i][j] && map[i][j] == 2) {
					spread(i,j,map,visit);
				}
			}
		}
		
		for(int i=0; i<map.length; i++) {
			for(int j=0; j<map[0].length; j++) {
				zero += map[i][j] == 0 ? 1 : 0;
			}
		}
		return zero;
	}
	
	static void choose(int start,int depth) {
		if(depth == 3) {
			int[][] tempmap = new int[map.length][map[0].length];
			for(int i=0; i<map.length; i++) {
				for(int j=0; j<map[0].length; j++) {
					tempmap[i][j]= map[i][j];
				}
			}
			int r = simulate(tempmap);

			
			max_count = max_count < r ? r : max_count;
			
			
			
			return;
		}
		
		
		for(int i= start; i<every.size(); i++) {
			f[depth] = every.get(i);
			choose(i+1,depth+1);
		}
		
	}
	
	public static void main(String[] args) throws  Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 0) {
					every.add(new pair(i,j));
				}
			}
		}
		
		choose(0,0);
		
		System.out.println(max_count);
		
	}

}
