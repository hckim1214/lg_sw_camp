#include <iostream>
#include<algorithm>
using namespace std;

#define MAX (100)
int M, N, K;//����ũ��, ����ũ��, ���簢�� ����
int sx[MAX + 10];
int sy[MAX + 10];
int ex[MAX + 10];
int ey[MAX + 10];
int map[MAX][MAX] = { 0, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int nx, ny;
int area;

int sol[MAX * MAX];//�� ���� ���� �����

void InputData() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
        for (int y = sy[i]; y <= ey[i] - 1; y++)
        {
            for (int x = sx[i]; x <= ex[i] - 1; x++)
            {
                map[y][x] = 1;
            }
        }
    }
}
void Flood_fill(int y, int x)
{
    map[y][x] = 1;  // ������� 1 ó��
    area++;
    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (nx < 0 || nx>N - 1) continue;
        if (ny < 0 || ny>M - 1) continue;
        if (map[ny][nx] == 0) Flood_fill(ny, nx);
    }
}
int Solve()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[j][i] == 0)
            {
                area = 0;
                Flood_fill(j, i);
                sol[cnt] = area;
                cnt++;
            }
        }
    }
    sort(sol, sol + cnt );
    return cnt;
}
void OutputData(int ans) {
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

int main(void) {
    int ans = -1;
    InputData();//�Է¹޴� �κ�

    ans = Solve();

    OutputData(ans);//����ϴ� �κ�
    return 0;
}