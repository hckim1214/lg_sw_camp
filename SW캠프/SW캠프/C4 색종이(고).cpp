#include <iostream>
using namespace std;

int N;//색종이 수
int X[100 + 10];
int Y[100 + 10];
int map[100 + 10][100 + 10];


void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                map[Y[i] + j ][X[i] + k ] = 1;
            }
        }
    }
}
void Map_added()
{
    for (int i = 100; i > 0; i--)
    {
        for (int j = 100; j > 0; j--)
        {
            if ((map[j][i] != 0) &&(map[j-1][i] !=0))
            {
                map[j - 1][i] = map[j][i] + map[j - 1][i];
            }
        }
    }
}
int Find_Max()
{
    int underbar = 0;// 밑변
    int max_rect = 0;
    for (int j = 0; j <= 100; j++)
    {
        for (int i = 0; i <= 100; i++)
        {
            underbar = map[j][i];
            for (int length = 0; length <= 100 - i; length++)
            {
                underbar = min(underbar, map[j][i + length]);
                max_rect = max((length + 1) * underbar, max_rect);
                if (underbar == 0) break;
            }

        }
    }
    return max_rect;
}
int Solve()
{
    int ans = 0;
    Map_added();
    ans=Find_Max();
    return ans;
}

int main() {
    int ans = -1;
    InputData();//입력받는 부분

    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}