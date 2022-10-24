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
int Digit(int num)
{
    int ans = num;
    int sum = 0;
    while (ans > 0)
    {
        sum = sum + ans % 10;
        ans /= 10;
    }
    if (sum >= 10)
    {
        sum= Digit(sum);
    }
    return sum;
}

int Solve() 
{
    int max = 0;
    int max_index = 1000;
    int value = 0;
    for (int i = 0; i < N; i++)
    {
        value = Digit(A[i]);
        if ((max == value) && (A[max_index] > A[i]))
        {
            max = value;
            max_index = i;
        }
        if (max < value )
        {
            max = value;
            max_index = i;
        }
    }
    return A[max_index];
}
int main() {
    int ans = -1;
    InputData();//입력 받는 부분

    ans = Solve();
    cout << ans << endl;//출력하는 부분
    return 0;
}