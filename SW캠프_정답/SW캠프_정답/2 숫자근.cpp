#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;//정수개수
int A[MAXN + 10];//입력 정수
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}
int Digitsum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int DigitRoot(int num)
{
    while (num >= 10)
    {
        num=Digitsum(num);
    }
    return num;
}
int Solve()
{
    int maxdigit = 0;
    int maxv = 5000;
    for (int i = 0; A[i]; i++)
    {
        int r=DigitRoot(A[i]);
        if ((maxdigit < r) || ((maxdigit == r) && maxv > A[i]))
        {
            maxv = A[i];
            maxdigit = r;
        }
    }
    return maxv;
}
int main() {
    int ans = -1;
    InputData();//입력 받는 부분
    ans = Solve();
    cout << ans << endl;//출력하는 부분
    return 0;
}