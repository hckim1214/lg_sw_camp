#include <iostream>
using namespace std;

#define MAXN ((int)1e3)

int N, P;
int used[MAXN + 10];
void InputData() {
    cin >> N >> P;
}
int Solve()
{
    int i, next = N, sol = 0;
    used[next] = 1;
    for (int i = 1;; i++)
    {
        next = next * N % P;
        if (used[next]==1)
        {
            sol = i - used[next];
            break;
        }
        return sol;s
    }
}

int main() {
    int ans = -1;
    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}