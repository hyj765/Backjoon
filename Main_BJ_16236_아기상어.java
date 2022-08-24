import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_BJ_16236_아기상어{
    // 사방탐색용 배열
//    static int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static int[] dy = {-1, 1,  0,  0};
    static int[] dx = {0,  0, -1,  1};
                     //상     하     좌     우
    
    static int N;// 공간의 크기 N(2 ≤ N ≤ 2O) 행열 사이즈

    static int[][] map;//데이터 입력배열  0:빈칸   1~6:물고기 크기   9:아기상어
    static boolean[][] visited;

    
    static int moveCnt;//정답 (물고기를 잡아먹을 수 있는 시간, 이동거리)

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine()); // 공간의 크기 N(2 ≤ N ≤ 20)

        map = new int[N][N];

        Shark shark = null;
        StringTokenizer tokens = null;

        //물고기, 아기상어 정보 입력
        for (int r = 0; r < N; r++) {
            tokens = new StringTokenizer(br.readLine());
            for (int c = 0; c < N; c++) {
                map[r][c] = Integer.parseInt(tokens.nextToken());
                // 상어가 있던 지점은 상어를 표시하고 상어는 여기를 다시 지나갈 수 있다.
                if (map[r][c] == 9) {
                	shark = new Shark(r, c, 2, 0, 0);// 처음 상어의 크기는 2
                                 //상어의 위치,크기(처음크기는 2), 이동횟수, 먹은횟수
                	
                    map[r][c] = 0; //상어의 좌표를 얻었다면 앞으로 이동 가능하게 만들어 주어야 함 
                    
                }
            }
        }//for
        
        /*// 입력값 확인
        for (int[] row : map) {
            System.out.println(Arrays.toString(row));
        }*/
        
        bfs(shark);//아기상어의 물고기 탐색 시작

        System.out.println(moveCnt);

    }//main

    // 상어가 범위을 확장해가며 물고기를 찾는다.
    static void bfs(Shark shark) {
        Queue<Shark> queue = new LinkedList<>();
        queue.offer(shark);
        
        visited = new boolean[N][N];
        visited[shark.row][shark.col] = true; //상어가 이동한 경로 표시

        // 상어와 가장 가까운 물고기의 거리
        int targetDistance = -1;

        // 상어와 가장 가까운 depth에 있는 물고기들
        PriorityQueue<Fish> targetFishList = new PriorityQueue<>();

        Shark front = null;

        // 처음 희생양이 발견된 depth 다음 depth는 돌 필요가 없다.
        findFish: 
        while (!queue.isEmpty()) {
            front = queue.poll();

            for (int d = 0; d < 4; d++) {
            	
            	//사방으로 이동해 보기
                int nr = front.row + dy[d];
                int nc = front.col + dx[d];

                if (isRange(nr, nc) && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    
                    // 크기가 상어와 같거나 0이면 이동/통과 가능
                    if (map[nr][nc] == 0 || map[nr][nc] == front.size) {
                        queue.offer(new Shark(nr, nc, front.size, front.depth + 1, front.eatCnt));
                                                                  //이동한 거리 추가
                    }
                    // 먹을 수 있는 물고기가 발견되었다면 해당 물고기를 담아놓자. - 먹이 후보
                    else if (map[nr][nc] < front.size) {
                        // 처음 발견한 물고기여서 targetDistance가 -1이거나 depth가 처음 잡은 (후보)물고기와 같으면 관심 있다.
                        if (targetDistance == -1 || targetDistance == front.depth + 1) {
                            Fish fish = new Fish(nr, nc, map[nr][nc], front.depth + 1);//상어의 이동거리를 물고기에 전달
                            targetFishList.offer(fish);      //먹이후보에 등록
                            targetDistance = fish.distance;  //다음 물고기와의 비교를 위해 저장
                        }
                        // 이미 먹을 물고기가 선택되었으므로 현재 위치의 상어에서 더이상 탐색을 할 필요가 없음
                        else {
                            break findFish;
                        }
                    }
                }
                
            }//사방탐색 for
        }//while

        // 먹을 물고기가 없으면 종료
        if (targetFishList.isEmpty()) {
            return;
        }
        // 물고기가 있으면 먹으러 가자.
        else {
            // PriorityQueue이므로 맨 위의 물고기가 목표
            Fish forEat = targetFishList.poll();

            // System.out.println("먹은놈: " + forEat);
            front.eat();
            map[forEat.row][forEat.col] = 0;// 이제 그 지점에 물고기 먹었음을 표시
            
            moveCnt += forEat.distance;// 이동 회수는 (물고기의 거리만큼)업데이트 해주기
            
            // 이 지점이 새로운 BFS 시점
            bfs(new Shark(forEat.row, forEat.col, front.size, 0, front.eatCnt));
        }
    }//bfs


    static boolean isRange(int r, int c) {//배열 범위 체크
        return 0 <= r && 0 <= c && r < N && c < N;
    }

    
    static class Fish implements Comparable<Fish> {
        int row, col; //물고기 위치
        int size;     //물고기 크기
        int distance; //상어와의 거리

        public Fish(int row, int col, int size, int distance) {
            super();
            this.row = row;
            this.col = col;
            this.size = size;
            this.distance = distance;
        }

        // 1순위 distance, 2순위 세로 위쪽, 3순위 가로 왼쪽
        @Override
        public int compareTo(Fish o) {
            if (distance == o.distance) {//1순위
                if (row == o.row) {      //2순위
                    return col-o.col;    //3순위 //Integer.compare(col, o.col);
                } else {
                    return row-o.row;//Integer.compare(row, o.row);
                }
            } else {
                return distance-o.distance;//Integer.compare(distance, o.distance);
            }
        }
    }//Fish

    static class Shark {
        int row, col; //상어의 위치
        int size;     //상어의 크기
        int depth;    //이동 횟수(거리)
        int eatCnt;   //먹은 횟수

        public Shark(int row, int col, int size, int depth, int eatCnt) {
            super();		
            this.row = row;
            this.col = col;
            this.size = size;
            this.depth = depth;
            this.eatCnt = eatCnt;
        }

        // 한번에 한 마리씩 먹고 몸집만큼 먹으면 크기 변경
        public void eat() {
            // System.out.print("변경 전: 먹은 수: "+eatCnt+", 크기: "+size);
            eatCnt++;
            
            if (eatCnt == size) {
                // eatCnt-=size;
                eatCnt = 0;
                size++;
            }
        }
    }//class Shark
    
}//end class
