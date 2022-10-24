#include <iostream>
using namespace std;
#define MAXH (5)
#define MAXW (9)
char map[MAXH + 2][MAXW + 2];
int solremain = 123456;
int solmove;
int pin;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int pin_ori;
//void print_map()
//{
//    cout << endl;
//    for (int height = 1; height <= MAXH; height++)
//    {
//        for (int width = 1; width <= MAXW; width++)
//        {
//            cout << map[height][width];
//        }
//        cout << endl;
//    }
//    cout << "---------------" << endl;
//}
void InputData() {
    pin = 0;
    for (int h = 1; h <= MAXH; h++)
    {
        cin >> &map[h][1];
        for (int w = 1; w <= MAXW; w++)
        {
            //           cin >> map[h][w];
            if (map[h][w] == 'o') pin++;
        }
    }
    pin_ori = pin;
}
bool Check()
{
    int ans = 0;
    for (int q = 1; q <= MAXH; q++)
    {
        for (int p = 1; p <= MAXW; p++)
        {
            if (map[q][p] == 'o')
            {
                for (int k = 0; k < 4; k++)
                {
                    int mx = p + dx[k], my = q + dy[k];
                    int mmx = p + 2 * dx[k], mmy = q + 2 * dy[k];
                    if (mx < 1 || mx > MAXW) continue;
                    if (my < 1 || my > MAXH) continue;
                    if (mmx<1 || mmx>MAXW) continue;
                    if (mmy<1 || mmy>MAXH) continue;
                    if (map[mmy][mmx] != '.') continue;
                    if (map[my][mx] != 'o') continue;
                    ans = 1;
                }
            }
        }
    }
    return ans;
}
void DFS(int pin)
{
    //    if (pin > solremain) return;
    if (!Check())
    {
        solremain = min(pin, solremain);
        solmove = max(pin_ori - solremain, solmove);
        return;
    }

    // �� �� �ִ� ����: ��� ������ �Űܺ���
    for (int j = 1; j <= MAXH; j++)
    {
        for (int i = 1; i <= MAXW; i++)
        {
            if (map[j][i] == 'o')
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i, y = j;
                    int nx = x + dx[k], ny = y + dy[k];
                    int nnx = x + 2 * dx[k], nny = y + 2 * dy[k];
                    if (nx<1 || nx>MAXW) continue;
                    if (ny<1 || ny>MAXH) continue;
                    if (nnx<1 || nnx>MAXW) continue;
                    if (nny<1 || nny>MAXH) continue;
                    if (map[ny][nx] != 'o') continue;
                    if (map[nny][nnx] != '.') continue;
                    map[y][x] = '.';    // ������ǥ =>.
                    map[ny][nx] = '.';    // �Ѿ ��ǥ =>.
                    map[nny][nnx] = 'o';  // �Ѿ �� ǥ��
                    //print_map();
                    DFS(pin - 1);
                    map[nny][nnx] = '.';  // ���� �� ���󺹱�
                    map[ny][nx] = 'o';    // �������� ��ǥ =>o
                    map[y][x] = 'o';    // �������� ��ǥ =>o
                }
            }
        }
    }
}
void Initialize()
{
    solremain = 123456;
    solmove = 0;
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        InputData();//�Է¹޴� �κ�
        Initialize();
        DFS(pin_ori);

        cout << solremain << " " << solmove << endl;//����ϴ� �κ�
    }
    return 0;
}