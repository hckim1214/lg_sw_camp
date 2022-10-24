#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_SIZE (30)

int L, R, C;
struct info
{
    int h;
    int y;
    int x;
    int cnt;
};
info Pos;
queue <info> q;

//info temp;
char map[MAX_SIZE + 10][MAX_SIZE + 10][MAX_SIZE + 10];
//int visited[MAX_SIZE + 10][MAX_SIZE + 10][MAX_SIZE + 10];
void Map_init()
{
    //fill(&map[0][0][0], &map[MAX_SIZE + 10][MAX_SIZE + 10][MAX_SIZE + 9], '0');

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                map[i][j][k] = '0';
            }
        }
    }
    q = queue<info>();
}
bool InputData() {
    cin >> L >> R >> C;
    if ((L == 0) && (R == 0) && (C == 0)) return false;
    Map_init();
    for (int l = 0; l < L; l++) {
        for (int r = 0; r < R; r++) {
            cin >> map[l][r];
            for (int c = 0; c < C; c++)
            {
                if (map[l][r][c] == 'S')
                {
                    Pos.h = l;
                    Pos.y = r;
                    Pos.x = c;
                    Pos.cnt = 0;
                    q.push(Pos);            // S 큐에 넣기
                }
            }
        }
    }
    return true;
}
int Solve()
{
    int nx, ny, nz, ncnt;
    int k;
    info temp;
    int dx[] = { 1,-1,0,0,0,0 };
    int dy[] = { 0,0,1,-1,0,0 };
    int dz[] = { 0,0,0,0,1,-1 };

    while (!q.empty())
    {
        Pos = q.front();
        //temp = Pos;
        // map[Pos.h][Pos.y][Pos.x] = '*';                                                      // 원래 문제지점
        q.pop();
		for (k = 0; k < 6; k++)
		{
            nz = Pos.h + dz[k], ny = Pos.y + dy[k], nx = Pos.x + dx[k], ncnt = Pos.cnt + 1;
            if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (map[nz][ny][nx] == 'E')
            {
                return ncnt;
                break;
            }
			if (map[nz][ny][nx] != '.') continue;    // 확산 못하는 경우
			temp.h = nz, temp.y = ny, temp.x = nx, temp.cnt = ncnt;
			//q.push({nz,ny,nx,ncnt});
            map[temp.h][temp.y][temp.x] = '*';          //         -------------------     '*' 을 당장 표시하지 않는다면 큐에 의미없는게 들어감 **********
			q.push(temp);

		}
    }
    return -1;
}
int main() {
    int ans = -1;
    while (InputData()) {

        ans= Solve();

        if (ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}