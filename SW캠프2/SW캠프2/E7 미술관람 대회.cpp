// 해마다 열리는 꿀꿀이 올림피아드에는 여러 종목들이 있는데, 요즘에는 꿀꿀이들의 교양을 겨루는 ‘미술관람 대회’가 인기를 끌고 있다. 이 대회는 사회자가 빨강, 초록, 파랑으로 이루어진 N × N 픽셀의 그림을 보여주면 그 그림에 포함된 영역의 수를 빠르고 정확하게 맞추는 것이 목표이다. 동일한 색깔이 네 방향(상, 하, 좌, 우) 중 한 곳이라도 연결되어 있으면 하나의 영역으로 간주한다.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

#define MAXN (100)
int N;//그림크기(정사각형)
char map[MAXN + 10][MAXN + 10];
char map2[MAXN + 10][MAXN + 10];
//int visited1[MAXN + 10][MAXN + 10] = { 1, };
//int visited2[MAXN + 10][MAXN + 10] = { 1, };
int sol1, sol2;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int nx, ny;
char type;

void InputData() {
    cin >> N;
    for (int h = 0; h < N; h++) {
        cin >> map[h];
        strcpy(map2[h], map[h]);
    }
}
void Setting()
{
    for (int h = 0; h < N; h++) {
        for (int w = 0; w < N; w++)
        {
            if (map2[h][w] == 'G')
            {
                map2[h][w] = 'R';
            }
        }
    }
}
void Flood_Fill1(int y,int x)
{
    type=map[y][x];
    map[y][x] = '0';
    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (nx < 0 || nx>N - 1) continue;
        if (ny < 0 || ny>N - 1) continue;
        if (map[ny][nx] == type) Flood_Fill1(ny, nx);
    }
}

void Flood_Fill2(int y, int x)
{
    type = map2[y][x];
    map2[y][x] = '0';
    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (nx < 0 || nx>N - 1) continue;
        if (ny < 0 || ny>N - 1) continue;
        if (map2[ny][nx] == type) Flood_Fill2(ny, nx);
    }
}
void Solve()
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (map[j][i] !='0')
            {
				Flood_Fill1(j,i);
                sol1++;
            }
            if (map2[j][i] != '0')
            {
                Flood_Fill2(j,i);
                sol2++;
            }
        }
    }
}
int main() {
    InputData();// 입력받는 부분
    Setting();
    Solve();

    cout << sol1 << " " << sol2 << endl;// 출력하는 부분
    return 0;
}