#include <iostream>
using namespace std;

int N;
int W[20];
int sol;
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
}
bool check(int a, int b)
{
    while (a && b)        // a와 b 둘중 하나라도 값이 있으면 루프 돈다
    {
        if ((a % 10 + b % 10) >= 10) return 0;
        a /= 10;
        b /= 10;
    }
    return 1;
}
void DFS(int n, int sum, int cnt)
{
    if (n >= N)
    {
        sol = max(sol, cnt);
        return;
    }

    if (sol > cnt + N - n) return;

    // 소를 태우는 경우
    if (check(sum,W[n]))
    {
        DFS(n + 1, sum + W[n], cnt + 1);
    }
    // 소를 태우지 않는 경우
    // 태우지 않을 때는 별다른 조건이 필요 없다
    DFS(n + 1, sum, cnt);
}
int main() {

    InputData();// 입력받는 부분

    DFS(0,0,0);

    cout << sol << endl;//출력하는 부분
    return 0;
}