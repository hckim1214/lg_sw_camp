#include <iostream>
#include<algorithm>
using namespace std;

int N;
int A[14 + 10];
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}
int cont(int* arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum * 10 + arr[i];
    }
    return sum;
}
int Solve()
{
    int B[10], C[10];
    int bcnt = 0, ccnt = 0;
    sort(A, A + N);
    if (A[0] == 0)
    {
        int i = 0;
        for (i; i < N; i++)
        {
            if (A[i] != 0) break;
        }
        A[0] = A[i]; A[i] = 0;
        if (A[1] == 0) { A[1] = A[i + 1]; A[i + 1] = 0; }
    }
    for (int j = 0; j < N; j++)
    {
        if ((j % 2) == 0) B[bcnt++] = A[j];
        else C[ccnt++] = A[j];
    }
    return cont(B, bcnt) + cont(C, ccnt);
}
int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}