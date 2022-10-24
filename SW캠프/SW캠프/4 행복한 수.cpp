#include <iostream>
#include <vector>
using namespace std;
#define MAXN ((int)1e3)
int N;
int ans= -1;
int used[MAXN + 10];

void InputData() {
    cin >> N;
}

int happy(int num)
{
    int num_ori = num;
    int cnt = 0;
    int state = -1;
    while (num != 1)
    {
        int iter = 0;
        int used[MAXN + 10] = { 0, };
        while (num > 0)
        {
            if (num % 10 == 0)
            {  
                num /= 10;
                continue;
            }
            used[iter] = num % 10;
            num /= 10;
            iter++;
        }
        num = 0;
        for (int i = 0; used[i]; i++)
        {
            num += (used[i] * used[i]);
        }

        if (0.5 < num &&  num < 1.5)
        {
            ans= num_ori;
            state = 1;
            break;
        }
        if (cnt > 50)
        {
            break;
        }
        cnt++;
    }
    return state;
}
void Solve()
{
    for (int i = N; i > 0; i--)
    {
        if (happy(i) != -1)
        {
            ans = i;
            break;
        }
    }
}
int main() {
    InputData();//입력받는 부분

    Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}