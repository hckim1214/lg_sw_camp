#include <iostream>
#include <queue>
using namespace std;

int N;
int grids[500 + 10][500 + 10];
struct info
{
    int y;
    int x;
    int h;
};
int limit;
int nx, ny;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
info P;
queue<info> que;
priority_queue<int,vector<int>, greater<>> pq;
int D;
void InputData() {
    cin >> N;
    if (N % 2 == 0) limit = N / 2;
    else limit = N / 2 + 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grids[i][j];
            //P.y = i;
            //P.x = j;
            //P.h = grids[i][j];
            pq.push(grids[i][j]);
        }
    }
}
int Solve()
{
    int p, q;

    D = pq.top();
    while(pq.top() != D) pq.pop();  // D 가 같을때 갈 수 있는 Field 는 pop

    if (p == 1 || p == N || q == 1 || q == N)
    {
        if (grids[q][p] <= D)
        {
            P.y = q;
            P.x = p;
            P.h = grids[q][p];
            que.push(P);
        }
    }
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans=Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}