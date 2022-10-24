// 농부 존은 그의 들판에 N(1≤N≤10,000)개의 건초 더미를 놓으려 한다. 들판은 1*1 크기의 사각형으로 구성된 100*100 크기이고, 건초 더미들은 각각 1*1 크기의 사각형 한 칸을 차지한다. (한 칸에 두 개의 건초 더미가 놓이는 일은 없다)
#include <iostream>
#define MAXN (100+10)
using namespace std;

int N;
int X;
int Y;
int map[MAXN][MAXN] = { 0, };
int max_x;
int max_y;
int min_x=1000;
int min_y=1000;

void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        map[Y][X] = 1;
    }
}
void Flood_Fill(int y, int x)
{
    int dx[] = { -1,1,0,0 };
    int dy[] = { 0,0,1,-1 };
    int nx;
    int ny;

    map[y][x] = 0;

    max_x = max(max_x, x);
    max_y = max(max_y, y);
    min_x = min(min_x, x);
    min_y = min(min_y, y);

    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (nx < 0 || nx>100) continue;
        if (ny < 0 || ny>100) continue;
        if(map[ny][nx]==1) Flood_Fill(ny, nx);
    }
}

int Solve()
{
    int outline = 0;

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (map[j][i] == 1)
            {
                outline = 0;
                Flood_Fill(j, i);
                outline = (max_x - min_x + max_y - min_y + 2) * 2;
            }
        }
    }
    return outline;
}
int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans=Solve();

    cout << ans << endl;// 출력하는 부분

    return 0;
}