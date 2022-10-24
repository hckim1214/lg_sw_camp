#include <iostream>
using namespace std;

int N, D, K, C;
int A[3000000 + 10];
struct check_overlap
{
    int num;
    int check;
};
struct check_overlap O[2000+10];

void InputData() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}
void initialize()
{
    for (int i = 0; i < 2000 + 10; i++)  // O initialize
    {
        O[i].num = i;
        O[i].check = 0;
    }
}
int Solve()
{
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        initialize();
        int cnt = 0;
        for (int j = 0; j < K; j++)
        {
            if (O[A[(i + j)%N]].check == 1)     // 중복으로 인한 종료 또는 루프를 다 돌고난 후 종료
            {
                continue;
            }
            O[A[(i + j)%N]].check = 1;
            cnt++;
        }
        if (O[C].check == 0) cnt++;
        if (max < cnt) max = cnt;
    }
    return max;
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}