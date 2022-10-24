#include <iostream>
using namespace std;

int N, D, K, C;
int A[3000000 + 10];
struct check_overlap
{
    int num;
    int check;
};
struct check_overlap O[3000 + 10];

void InputData() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}
void initialize()
{
    for (int i = 0; i < 3000 + 10; i++)  // O initialize
    {
        O[i].num = i;
        O[i].check = 0;
    }
}
int Solve()
{
    int max = 0;
    int cnt = 0;
    initialize();
    for (int j = 0; j < K; j++) // 0~500 번째 초밥
    {
        if (O[A[(j)]].check >= 1)     
        {
            O[A[(j)]].check++;
            continue;
        }
        O[A[(j)]].check++;
        cnt++;
    }
    O[C].check++;
    if (O[C].check == 1) cnt++;
    max = cnt;
    for (int i = 0; i <= N; i++) //
    {
        if (O[A[(i + K) % N]].check == 0) cnt++;//추가된 초밥이 새로운 초밥
        O[A[(i + K) % N]].check++;
        if (O[A[i%N]].check == 1) cnt--;// 맨 앞에 초밥이 유일했다면 -1 처리
        O[A[i%N]].check--;
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