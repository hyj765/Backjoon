import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_17836 {
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	static int min_ = Integer.MAX_VALUE;
	static int [][] map;
	static boolean bfs(int limit) {
		boolean visit[][][] = new boolean[map.length][map[0].length][2];
		Queue<int[]> q = new LinkedList<>();
		map[map.length-1][map[0].length-1] = 9;
		visit[0][0][0] = true;
		
		q.offer(new int[] {0,0,0,0});
		
		while(!q.isEmpty()) {
			int cx = q.peek()[0];
			int cy = q.peek()[1];
			int flag = q.peek()[2];
			int time = q.poll()[3];
			if(limit < time) break;
			if(map[cx][cy] == 9) {			
				min_ = min_ > time ?  time : min_;
				return true;
			}
		
			for(int i=0; i<4; i++) {
				int nx = cx+dx[i];
				int ny = cy+dy[i];
				if(nx < 0 || ny <0 || nx >= map.length || ny >= map[0].length ) continue;	
				if(flag == 1) {
					if(!visit[nx][ny][1]) {
					visit[nx][ny][1] = true;
					q.offer(new int[] {nx,ny,flag,time+1});
					}
				}else {
					if(map[nx][ny] == 1) continue;
					if(!visit[nx][ny][0]) {							
							visit[nx][ny][0] = true;
							flag = map[nx][ny] == 2 ? 1 : 0;
							
							q.offer(new int[] {nx,ny,flag,time+1});
					}
				}
			}
		}
		
		return false;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int limit = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j <m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		boolean f = bfs(limit);
		if(f) System.out.println(min_);
		else System.out.println("Fail");	

	}

}
