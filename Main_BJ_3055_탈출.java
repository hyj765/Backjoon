import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_BJ_3055_탈출 {
	
	static int R,C, fastTime = -1;
	
	static Queue<Point> hedgehogQueue = new LinkedList<>();
	static Queue<Point> waterQueue = new LinkedList<>();

	static char[][] map;//지도
	static boolean[][] hVisited, wVisited; //고슴도치와 물의 방문체크

	static int[] dy = { -1, 1 , 0 ,0 };
	static int[] dx = {  0 ,0 ,-1, 1 };
	                   //상 하 좌 우
	
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		map = new char[R][C];
		hVisited = new boolean[R][C];
		wVisited = new boolean[R][C];

		//데이터 입력
		for(int i=0; i<R; i++) {
			map[i] = br.readLine().toCharArray();
		}
		
//		for(int i=0; i<R; i++) {
//			System.out.println(Arrays.toString(map[i]));
//		}
		
		
		//최초 물 정보와 고슴도치 정보를 큐에 담기
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
			    if(map[i][j]=='*')
                   waterQueue.offer(new Point(i,j,0));
			    else if(map[i][j]=='S') 
			       hedgehogQueue.offer(new Point(i,j,0));			    
			}
				
		}
		
		//이동하기 시작
		queueStart();
		
		//정답출력
		System.out.println(fastTime == -1 ? "KAKTUS" : fastTime);
		br.close();
	}//main
	
	static void queueStart() {

		while(!hedgehogQueue.isEmpty()) { //고슴도치 이동이 가능한 동안
			
			//===================== 1. 물의 확산 =========================
			int waterSize = waterQueue.size();
			for(int t=0; t<waterSize; t++) {
				Point water = waterQueue.poll();
		
				for(int i=0; i<4; i++) { //사방으로 물이동
					int ny = water.row +dy[i];
					int nx = water.col +dx[i];
					
					if(isRange(ny, nx) && !wVisited[ny][nx]) { 
						if(map[ny][nx] == '.') {
							wVisited[ny][nx] = true;
							waterQueue.offer(new Point(ny,nx,0));
						}
					}
				}
			}//for
			
			//================== 2. 고슴도치의 안전한 이동 ====================
			int size = hedgehogQueue.size();
			for(int t=0; t<size; t++) {
				Point hedgehog = hedgehogQueue.poll();
				int moveTime = hedgehog.moveTime;
				
				//고슴도치의  사방 이동
				for(int i=0; i<4; i++) {
					int ny = hedgehog.row +dy[i];
					int nx = hedgehog.col +dx[i];
					
				 if(isRange(ny, nx) && !hVisited[ny][nx]) { //지도내에서 고슴도치가 이동하지 않은 곳이 있다면
					
					//비버의 굴(최종목적지)에 도착 
					if(map[ny][nx] == 'D') {
						fastTime = moveTime+1; //이동한 시간 1을 최종시간에 전달
						return; //solve 종료
					}
					
					if(map[ny][nx] == '.' && !wVisited[ny][nx]) {//이동가능하고 아직 물이 차지 않았다면
						hVisited[ny][nx] = true;
						hedgehogQueue.offer(new Point(ny,nx,moveTime+1)); //이동한 시간 1 추가
					}
					
				  }//배열범위에 있고 고슴도치가 방문하지 않았을때
			    }//사방탐색
				
		    }//for
		}//while
		
	}//solve
	
	static boolean isRange(int y, int x) {
	   if(y>=0 && y<R && x>=0 && x<C) return true;
	   return false;
	}//isRange
	
	static class Point{ //위치 클래스
		int row;
		int col;
		int moveTime; //이동시간
		
		public Point(int row, int col, int moveTime) {
			super();
			this.row = row;
			this.col = col;
			this.moveTime = moveTime;
		}		
	}//Point
}
