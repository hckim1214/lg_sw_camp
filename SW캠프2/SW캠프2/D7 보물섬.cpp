///////////// 메모리 문제

#include <iostream>
#include <queue>
using namespace std;


#define MAXN (50)
int H, W;//지도 세로, 가로 크기
char map[MAXN + 10][MAXN + 10];//지도정보(W:바다, L:육지)
bool visited[MAXN + 10][MAXN + 10];//방문표시
struct path
{
    int y;
    int x;
    int t;
};
queue<path> q;
path location;
path temp;
int M_T;
void InputData() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        cin >> &map[i][1];
    }
}
void initialize()
{
    for (int i = 1; i <= W+5; i++)
    {
        for (int j = 1; j <= H + 5; j++)
        {
            visited[j][i] = 0;
        }
    }// 초기화
    location.y = 0;
    location.x = 0;
    location.t = 0;
    //while (!q.empty())   q.pop();
    q = queue<path>();
}
void Solve()
{
    int i;
    int j;
    int dx[] = { -1,1,0,0 };
    int dy[] = { 0,0,-1,1 };
    int nx;
    int ny;
    for (j=1; j <= H; j++)
    {
        for (i = 1; i <= W; i++)
        {
            if (map[j][i] == 'L')   // 모든 육지마다 시도 i는 세로, j는 가로
            {
                initialize();

                location.y = j;
                location.x = i;
                visited[location.y][location.x] = 1;
                q.push(location);
                while (!q.empty())
                {
                    location = q.front();
                    temp = location;
                    q.pop();
                    int k = 0;
                    for (k; k < 4; k++)
                    {
                        nx = temp.x + dx[k];
                        ny = temp.y + dy[k];

                        if (nx<1 || nx>W) continue;                         ///
                        if (ny<1 || ny>H) continue;

                        if (map[ny][nx] == 'W' || visited[ny][nx] == 1) continue;
                        visited[ny][nx] = 1;
                        location.y = ny;
                        location.x = nx;
                        location.t = temp.t + 1;
                        M_T = max(M_T, location.t);
                        q.push(location);
                    }
                }
            }
        }
    }
    cout << M_T;
}
int main(void) {
    int ans = -1;
    InputData();//입력받는 부분

    Solve();

    //cout << ans << endl;//출력하는 부분
    return 0;
}