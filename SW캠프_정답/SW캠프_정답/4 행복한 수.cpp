#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;
int used[MAXN + 10];
void InputData() {
    cin >> N;
}
int Split(int num)
{
    int sum=0;
    while (num > 0)
    {
        sum += (num % 10) * (num % 10);
        num /= 10;
    }
    return sum;
}
int happyNum(int x)
{
    used[x] = 1;
    while (x != 1)
    {
        x = Split(x);
        if (used[x] >= 1) return 0;
        used[x]++;
    }
    return 1;
}

int Solve()
{
    int i;
    for (i = N; i > 0; i--)
    {
        if (used[i]) continue;      // used[i] �� �߰��Ǹ鼭 used[i]�� �ݺ��Ǵ� �� ���ĺκ� ���� �ʿ�X
        if (happyNum(i) == 1) break;
    }
    return i;
}

int main() {
    int ans = -1;
    InputData();//�Է¹޴� �κ�
    ans = Solve();
    cout << ans << endl;//����ϴ� �κ�
    return 0;
}