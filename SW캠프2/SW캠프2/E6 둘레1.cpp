#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN (100+5)
int N;
int X[10000 + 10];
int Y[10000 + 10];
int x_min, x_max, y_min, y_max;
int map[MAXN][MAXN] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int nx;
int ny;
int ans;

void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        map[Y[i]][X[i]] = 1;
    }
    sort(X, X + N);
    sort(Y, Y + N);
    x_min = X[0]; 
    x_max = X[N - 1];
    y_min = Y[0]; 
    y_max = Y[N - 1];
}
void Flood_Fill(int y, int x)
{
    map[y][x] = 2;
    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (nx < 0 || nx>x_max+1) continue;
        if (ny < 0 || ny>y_max+1) continue;
        if (map[ny][nx] == 0) Flood_Fill(ny, nx);
    }
}
void count()
{
    for (int i = x_max+1; i >= x_min-1; i--)
    {
        for (int j = y_max+1; j >= y_min-1; j--)
        {
            if (map[j][i] == 2)
            {
                for (int k = 0; k < 4; k++)
                {
                    nx = i + dx[k];
                    ny = j + dy[k];
                    if (nx < 0 || nx>101) continue;
                    if (ny < 0 || ny>101) continue;
                    if (map[ny][nx] == 1) ans++;

                }
            }
        }
    }
}
void Solve()
{
    if (map[y_max + 1][x_max + 1] == 0)
    {
        Flood_Fill(y_max + 1, x_max + 1);
    }
    count();
}
int main() {
//    int ans = -1;

    InputData();// 입력받는 부분

    Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}