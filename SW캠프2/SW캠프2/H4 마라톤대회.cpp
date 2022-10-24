#include <iostream>
#include <cmath>
using namespace std;
#define MAXN ((int)1e5)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];
long long presum;
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
}
void Make_presum()
{
    int dx, dy;
    for (int i = 0; i < N-1; i++)
    {
        dx = abs(X[i + 1] - X[i]);
        dy = abs(Y[i + 1] - Y[i]);
        presum += (long long)dx + dy;
    }
}
int Solve()
{
    Make_presum();
    long long min_sum = 123456789132465;
    long long temp = 0;
    int diff_x1, diff_x2, diff_y1, diff_y2;
    int diff_minus;
    int ch_diff_x, ch_diff_y;
    int diff_plus;
    for (int iter = 2-1; iter <= N - 1-1; iter++)   // 배열은 0부터 시작하기 때문에 -1 씩 해줬음
    {
        diff_x1 = abs(X[iter] - X[iter - 1]), diff_y1 = abs(Y[iter] - Y[iter - 1]);
        diff_x2 = abs(X[iter+1] - X[iter]), diff_y2 = abs(Y[iter+1] - Y[iter]);
        diff_plus = diff_x1 + diff_x2 + diff_y1 + diff_y2;
        ch_diff_x = abs(X[iter + 1] - X[iter - 1]), ch_diff_y = abs(Y[iter + 1] - Y[iter - 1]);
        diff_minus = ch_diff_x + ch_diff_y;
        temp = presum - diff_plus + diff_minus;
        min_sum = min(min_sum, temp);
    }
    return min_sum;
}
int main() {
    int ans = -1;

    InputData();//입력받는 부분

    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}