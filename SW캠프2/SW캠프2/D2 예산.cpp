// Parametric Search 문제

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int A[10000 + 10];
int budget = 0;
int max_portion = 0;
int portion = 0;

int s = 0;
int e;// P.size() - 1;
int m;// (e - s) / 2;

int m_left_bud = 0;
int m_right_bud = 0;
int estimated = 0;
vector<int> P;
bool cmp(int a, int b)
{
    return a < b;
}
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        budget += A[i];
        portion = A[i];
        max_portion = max(portion, max_portion);
        P.push_back(A[i]);
    }
    cin >> M;
    sort(P.begin(), P.end(), cmp);
    e = P.size() - 1;
    m = (s + e) / 2;
}
void initialize()
{
    m_left_bud = 0;
    m_right_bud = 0;
    estimated = 0;
    m = (s + e) / 2;
}
int Left_cal()
{
    int n=0;
    for (int i = 0; i <= m; i++)
    {
        n += P[i];
    }
    return n;
}
int Solve()
{
    int size = P.size();

    if (budget <= M) return max_portion;
    else
    {
        while (s<=e)
        {
            initialize();
            m_left_bud = Left_cal();
            m_right_bud = P[m] * (size-1 - m );

            estimated = m_left_bud + m_right_bud;
            if (estimated == M) return P[m];
            if (s + 1 == e)
            {
                for (int k = 0; k <= m; k++)
                {
                    M -= P[k];
                }
                return M / (size-1 - m);
            }
            if (estimated > M)
            {
                e = m;  //e=m-1
                continue;
            }
            if (estimated < M)
            {
                s = m;  //s=m+1
                continue;
            }
            
        }
    }
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}