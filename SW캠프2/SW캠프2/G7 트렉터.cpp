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
    while(pq.top() != D) pq.pop();  // D �� ������ �� �� �ִ� Field �� pop

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

    InputData();// �Է¹޴� �κ�

    ans=Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}