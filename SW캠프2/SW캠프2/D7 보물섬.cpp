///////////// �޸� ����

#include <iostream>
#include <queue>
using namespace std;


#define MAXN (50)
int H, W;//���� ����, ���� ũ��
char map[MAXN + 10][MAXN + 10];//��������(W:�ٴ�, L:����)
bool visited[MAXN + 10][MAXN + 10];//�湮ǥ��
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
    }// �ʱ�ȭ
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
            if (map[j][i] == 'L')   // ��� �������� �õ� i�� ����, j�� ����
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
    InputData();//�Է¹޴� �κ�

    Solve();

    //cout << ans << endl;//����ϴ� �κ�
    return 0;
}