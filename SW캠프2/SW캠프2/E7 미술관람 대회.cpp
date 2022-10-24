// �ظ��� ������ �ܲ��� �ø��ǾƵ忡�� ���� ������� �ִµ�, ���򿡴� �ܲ��̵��� ������ �ܷ�� ���̼����� ��ȸ���� �α⸦ ���� �ִ�. �� ��ȸ�� ��ȸ�ڰ� ����, �ʷ�, �Ķ����� �̷���� N �� N �ȼ��� �׸��� �����ָ� �� �׸��� ���Ե� ������ ���� ������ ��Ȯ�ϰ� ���ߴ� ���� ��ǥ�̴�. ������ ������ �� ����(��, ��, ��, ��) �� �� ���̶� ����Ǿ� ������ �ϳ��� �������� �����Ѵ�.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

#define MAXN (100)
int N;//�׸�ũ��(���簢��)
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
    InputData();// �Է¹޴� �κ�
    Setting();
    Solve();

    cout << sol1 << " " << sol2 << endl;// ����ϴ� �κ�
    return 0;
}