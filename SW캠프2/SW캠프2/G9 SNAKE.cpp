#include <iostream>
#include <queue>
using namespace std;
#define MAXN (100)
int N;
int K;
int R[MAXN + 10];
int C[MAXN + 10];
int L;
int X[MAXN + 10];
char CMD[MAXN + 10];

int map[MAXN + 10][MAXN + 10];

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int nx, ny;
int k;

struct info
{
    int y;
    int x;
    int dir;
};
info P;
queue <info> q;

void Print_Map()
{
    cout << endl;
    for (int jj = 0; jj <= N+1; jj++)
    {
        for (int ii = 0; ii <= N+1; ii++)
        {
            if (ii == 0 || ii == N + 1 || jj == 0 || jj == N + 1) map[jj][ii] = 9;
            cout << map[jj][ii];
        }
        cout << endl;
    }
}
void InputData() {
    cin >> N;       // 격자크기
    cin >> K;       // 과일갯수
    for (int i = 0; i < K; i++) {
        cin >> R[i] >> C[i];        // 과일 좌표 r:세로 c:가로
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> X[i] >> CMD[i];      // X: 초 CMD: 방향
    }
}
void Put_fruit()
{
    for (int oo = 0; oo < K; oo++)
    {
        map[R[oo]][C[oo]] = 5;// 과일
    }
}
int Solve()
{
    int time = 0;
    int iter = 0;
    info temp;
    info del_temp;
    Put_fruit();
    P.x = 1, P.y = 1, P.dir = 1;
    map[P.y][P.x] = 1;
    q.push(P);
    while (!q.empty())
    {
        //Print_Map();
        
        if (time == X[iter])
        {
            switch (CMD[iter])
            {
            case 'L':
                if (P.dir - 1 < 0) P.dir = P.dir + 4;
                P.dir--;
                break;
            case 'D':
                if (P.dir + 1 > 3) P.dir = P.dir - 4;
                P.dir++;
                break;
            }
            iter++;
        }
        temp.x = P.x + dx[P.dir];       // 다음 지렁이 이동위치 미리 계산
        temp.y = P.y + dy[P.dir];
        temp.dir = P.dir;

        if (temp.x<1 || temp.x>N || temp.y<1 || temp.y>N || map[temp.y][temp.x] == 1)     // map 넘는 경우 or 자신 몸
        {
            return time + 1;
        }

        if (map[temp.y][temp.x] != 5)    // 과일 없는 경우
        {
            del_temp = q.front();
            map[del_temp.y][del_temp.x] = 0;
            q.pop();
        }

        map[temp.y][temp.x] = 1;
        P = temp;
        q.push(P);
        time++;
        
    }
}
int main() {
    int ans = -1;

    InputData();//입력받는 부분


    ans = Solve();

    cout << ans << endl;//출력하는 부분 
    return 0;
}