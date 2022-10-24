#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
struct ST {
    int y;
    int x;
    int t;
};
queue<ST> q;
ST F;
ST A;

#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN + 10][MAXN + 10];
void InputData() {
    cin >> R >> C;
    for (int j = 0; j < R; j++) {
        cin >> map[j];
        for (int i = 0; i < C; i++)
        {
            if (map[j][i] == '*')
            {
                F.y = j;
                F.x = i;
                F.t = -10;
                q.push(F);
            }
            if (map[j][i] == 'S')
            {
                A.y = j;
                A.x = i;
            }
        }
    }
    q.push(A);
}
void initialize()
{
    fill(&map[0][0], &map[MAXN + 10 - 1][MAXN + 10], '0');
    q = queue <ST>();
}
int Solve()
{
    int ans=-1;
    int k = 0;
    int dx[] = { -1,1,0,0 };
    int dy[] = { 0,0,1,-1 };
    while (!q.empty())
    {
        ST ori,temp;      // 원래 값: ori
        ori = q.front();
        temp = ori;
        q.pop();
        k = 0;
        for (k; k < 4; k++)
        {
            int nx = ori.x + dx[k];
            int ny = ori.y + dy[k];
            if (nx<0 || nx>=C) continue;
            if (ny<0 || ny>=R) continue;
            if (map[ny][nx] == 'D' && temp.t >= 0)  // 화가가 D에 간 경우
            {
                ans = ori.t+1;
                return ans;
            }
            if (map[ny][nx] != '.') continue;
            temp.x = nx;
            temp.y = ny;
            if (temp.t == -10) //홍수 경우
            {
                map[ny][nx] = '*';
            }
            else if (temp.t >= 0) //화가 경우
            {
                map[ny][nx] = '1';
                temp.t = ori.t + 1;
            }
            q.push(temp);
        }
        
    }
    return ans;
}
int main() {
    int T;
    int ans = -5;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        initialize();
        InputData();//입력 받는 부분
        ans=Solve();
        if (ans == -1) cout << "KAKTUS" << endl;//출력 하는 부분
        else cout << ans << endl;
    }
    return 0;
}