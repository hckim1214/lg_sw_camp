#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int W, H;//������ ���� ���� ũ��
char map[MAXN + 10][MAXN + 10];//���� ����('1':���۸�, '0':���)
int sw, sh;//������ġ ���� ���� ��ǥ
int zerg= 0;
int die = 0;
int t = 0;
int depth = 0;
int i = 0;
struct Ma
{
    int y;
    int x;
    int t;
};
Ma M;
Ma temp;
queue<Ma> q;

void InputData() {
    cin >> W >> H;
    for (int i = 1; i <= H; i++) {
        cin >> &map[i][1];
        for (int j = 0; j <= W; j++)
        {
            if (map[i][j] == '1') zerg++;
        }
    }
    cin >> sw >> sh;
}

void Solve()
{
    M.y = sh;
    M.x = sw;
    q.push(M);
    map[M.y][M.x] = '0';

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0,0,1,-1 };
    while (!q.empty())
    {
        temp = q.front();
        
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ny = temp.y + dy[k];
            int nx = temp.x + dx[k];
            if (ny<1 || ny>H) continue;
            if (nx< 1 || nx> W) continue;

            if (map[ny][nx] == '0') continue;
            map[ny][nx] = '0'; // �Ǻ� ���۸��� 0���� �ٲ��ش�.
            M.y = ny;
            M.x = nx;
            M.t = temp.t + 1;
            t = max(t, M.t);
            q.push(M);
        }
        die++;
    }

    t += 3;

    cout << t << endl << zerg - die;
}

int main() {
    InputData();//�Է� �޴� �κ�

    Solve();

    return 0;
}