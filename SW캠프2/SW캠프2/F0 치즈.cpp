#include <iostream>
#include<vector>
using namespace std;

#define MAXN (100)
int N, M;
int map[MAXN + 10][MAXN + 10];
int hour, sol;
int dx[]={ 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int nx, ny;
int left_one=0;
int evap_ch=0;
vector<int> cheese;

void InputData() {
    cin >> M >> N;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            cin >> map[j][i];
            if (map[j][i] == 1) left_one++;
        }
    }
}
void Flood_Fill(int x,int y,int i)
{
    map[y][x] = i+2;
    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (nx<0 || nx>N - 1) continue;
        if (ny<0 || ny>M - 1) continue;
        if ( (map[ny][nx] != 1) && (map[ny][nx]!=(i+2)) ) Flood_Fill(nx,ny,i);
    }
}

void Melt(int n)
{
    for (int j = n; j < M - n; j++)
    {
        for (int i = n; i < N - n; i++)
        {
            if (map[j][i] == n+2)
            {
                for (int k = 0; k < 4; k++)
                {
                    nx = i + dx[k];
                    ny = j + dy[k];
                    if (map[ny][nx] == 1)
                    {
                        evap_ch++;
                        map[ny][nx] = 0; //n+1로 바꾸게 되면 치즈 안쪽 공기로는 확산 불가
                    }
                }
            }
        }
    }
}
void Solve()
{
    int i = 0;
    while (1)
    {
        Flood_Fill(i,i,i);
        Melt(i);
        i++;
        if (left_one <= evap_ch)
        {
            hour = i;
            break;
        }
        cheese.push_back(left_one - evap_ch);
    }
}
int main() {
    InputData();// 입력받는 부분

    Solve();
    sol = cheese.back();
    cout << hour << endl;
    cout << sol << endl;
    return 0;
}