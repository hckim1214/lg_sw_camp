#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
#define INF (10000000000000)
#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
struct info
{
    int y;
    int x;
};

queue<info> q;

info P;
void Start_Point()
{
    for (int i = 0; i <= N+1; i++)
    {
        for(int j = 0; j <= N+1; j++)
        {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
            {
                P.x = i;
                P.y = j;
                q.push(P);
                map[i][j] = 0;
            }
            else 
            {
                visited[i][j] = INF;
            }
        }
    }
}
void InputData() {
    cin >> N;
    cin >> eh >> ew;
    for (int h = 1; h <= N; h++) {
        for (int w = 1; w <= N; w++) {
            cin >> map[h][w];
        }
    }
}

int Solve()
{

    info cur;
    info temp;
    int ntime;
    //for (int i = 0; i <= N+1; i++)        display
    //{
    //    for (int j = 0; j <= N+1; j++)
    //    {
    //        cout << visited[i][j]<<" ";
    //    }
    //    cout << endl;
    //}

    int dx[] = { -1,1,0,0 };
    int dy[] = { 0,0,1,-1 };
    Start_Point(); // initilize 포함
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
            for (int k = 0; k < 4; k++)
            {
                int ny = cur.y + dy[k];
                int nx = cur.x + dx[k];

                if (nx<=0 || nx>=N + 1) continue;
                if (ny<=0 || ny>=N + 1) continue;
                //if (ny == 0 || ny == N + 1 || nx == 0 || nx == N + 1) continue; 위에 합쳐
                ntime = 0;
                if (map[ny][nx] > map[cur.y][cur.x])  // 
                {
                    ntime = pow(map[ny][nx] - map[cur.y][cur.x], 2);
                }
                else if (map[ny][nx] == map[cur.y][cur.x])
                {    
                    ntime = 0;
                }
                else if (map[ny][nx] < map[cur.y][cur.x])
                {
                    ntime = map[cur.y][cur.x] - map[ny][nx];
                }
                if (visited[ny][nx] <= visited[cur.y][cur.x] + ntime) continue;
                visited[ny][nx] = visited[cur.y][cur.x] + ntime;

                temp.y = ny;
                temp.x = nx;
                q.push(temp);
            }
    }
    return visited[eh][ew];
        /*for (ey = 1; ey <= N; ey++)
        {
            for (ex = 1; ex <= N; ex++)
            {
                
            }
        }*/
}

int main() {
    int ans = -1;
    InputData();//입력 받는 부분
    ans=Solve();
    

    cout << ans << endl;//출력하는 부분
    return 0;
}