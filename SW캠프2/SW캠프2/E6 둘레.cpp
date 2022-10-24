// ��� ���� ���� ���ǿ� N(1��N��10,000)���� ���� ���̸� ������ �Ѵ�. ������ 1*1 ũ���� �簢������ ������ 100*100 ũ���̰�, ���� ���̵��� ���� 1*1 ũ���� �簢�� �� ĭ�� �����Ѵ�. (�� ĭ�� �� ���� ���� ���̰� ���̴� ���� ����)
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

    InputData();// �Է¹޴� �κ�

    ans=Solve();

    cout << ans << endl;// ����ϴ� �κ�

    return 0;
}