#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;//연잎수
int A[1000 + 10];//연잎좌표
vector<int> P;
bool cmp(int a, int b)
{
    return a < b;
}
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        P.push_back(A[i]);
    }
    sort(P.begin(), P.end(), cmp);
}
int Solve()
{
    int S = P.size();
    int cnt = 0;
    int first_jump = 0;
    for (int i = 0; i < S-2; i++)
    {   
        for (int j = i+1; j < S-1; j++)
        {
            first_jump = P[j] - P[i];
            for (int k = j + 1; k < S; k++)
            {
                if (k > S) break;
                if ((P[j] + first_jump <= P[k]) && (P[k] <= P[j] + 2*first_jump))
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

// 이진 탐색으로 특정 범위찾는 법 해보기
int main() {
    int ans = -1;
    InputData();//입력받는 부분

    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}