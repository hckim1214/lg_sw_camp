#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include<string.h>
using namespace std;

#define INF (10000000000)
int N, M;
int A[20000 + 20];
int B[20000 + 20];
int L[20000 + 20];
int visited[10000 + 10];
int path[10000 + 10];
int L_ori[20000 + 20];

struct info
{
    int time;
    int cur_loc;
};

struct compare
{
    bool operator()(const info& m1, const info& m2)
    {
        return m1.time < m2.time;
    }
};
priority_queue<info, vector<info>, compare> pq;
info cur;
info temp;
deque<int> cumulated_path;
void InputData() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> L[i];
        A[M + i] = B[i];
        B[M + i] = A[i];
        L[M + i] = L[i];
    }

    memcpy(L_ori, L, sizeof(L));
}
void Initialize()
{
    /*      ****************주의****************
     
    //for (int i : L_ori)     // i는 인덱스가 아니라 해당 인덱스의 원소
    //{
    //    L[i] = L_ori[i];
    //}
                                                                */
    for (int i = 0; L_ori[i]; i++)
    {
        L[i] = L_ori[i];
    }
    fill(&visited[0], &visited[10000 + 10], INF);
    fill(&path[0], &path[10000 + 10], 0);
    pq = priority_queue<info, vector<info>, compare>();
}
void Find_Double_Path()
{
    int k = N;
    cumulated_path.push_front(k);
    while (k != 1)
    {
        k = path[k];
        cumulated_path.push_front(k);
    }
}
int RunPQ()
{
    int sol = INF;
    cur.cur_loc = 1;
    cur.time = 0;
    pq.push(cur);

    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        for (int i = 0; A[i]; i++)
        {
            if (A[i] == cur.cur_loc)
            {
                int ntime = cur.time + L[i];
                if (visited[B[i]] <= ntime) continue;

                temp.cur_loc = B[i];
                temp.time = ntime;
                visited[B[i]] = ntime;
                path[B[i]] = A[i];
                pq.push(temp);

                if (B[i] == N)
                {
                    sol = min(ntime, sol);
                }

            }
        }
    }
    return sol;
}
void Make_Double(int i)
{
    int variety = INF;

    for (int j = 0; A[j]; j++)
    {
        if ((cumulated_path[i] == A[j]) && (cumulated_path[i + 1] == B[j]))
        {
            L[j] *= 2;
            L[j + M] *= 2;
            break;
        }
    }
}
int Solve()
{
    int s1 = 0;
    int s2 = 0;
    Initialize();
    s1 = RunPQ();
    Find_Double_Path();
    for (int i = 0; i <= cumulated_path.size() - 2; i++)
    {
        Initialize();
        Make_Double(i);
        int temp = RunPQ();
        s2 = max(s2, temp);
    }

    return s2 - s1;
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}