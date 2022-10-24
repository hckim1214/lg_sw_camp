#include <iostream>
#include <queue>
using namespace std;
#define MAXN (1000)
int H, W;
char map[MAXN + 10][MAXN + 10];
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };
int nx, ny;
int cnt;
struct info
{
    int y;
    int x;
    int cnt;
};
info P;
queue<info> q;
int N_M;

void InputData() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> map[i];
        for (int j = 0; j < W; j++)
        {
            if ((map[i][j]) == '.')
            {
                P.y = i;
                P.x = j;
                P.cnt = 0;
                q.push(P);
            }
        }
    }
}

int Solve()
{
    while (!q.empty())
    {
        P = q.front();
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            nx = P.x + dx[k], ny = P.y + dy[k], cnt = P.cnt + 1;
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (map[ny][nx] == '.') continue;
            map[ny][nx] = (char)(--map[ny][nx]);        // 만약 숫자라면 하나씩 깍기
            if (map[ny][nx] <= '0')
            {
                map[ny][nx] = '.';
                N_M = cnt;
                q.push({ ny,nx,cnt });
            }
        }
    }
    return N_M;
}
int main() {
    int ans = -1;

    InputData();//입력받는 부분

    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}
