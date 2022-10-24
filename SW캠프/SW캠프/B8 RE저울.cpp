#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[1000 + 10];
void InputData() {
    cin >> N;
    int i = 0;
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }
}
int Solve()
{
    sort(A, A+N);
    int ans = A[0];
    if ((A[0] != 1)) { return 1; }
    for (int i = 1; i <= N; i++)
    {
        if (ans+1  < A[i])
        {
            break;
        }
        ans += A[i];
    }
    return ++ans;
}
int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}