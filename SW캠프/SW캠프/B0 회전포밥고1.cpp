#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

int N, D, K, C;
int A[3000000 + 10];

void InputData() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

int Solve()
{
    int max = 0;
    set<int> sushi;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < K; j++)
        {
            sushi.insert(A[(i + j) % N]);
        }
        sushi.insert(C);
        cnt = sushi.size();
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