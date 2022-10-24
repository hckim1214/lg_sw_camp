#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

#define MAXN (25)
int N;
char map[MAXN + 10][MAXN + 10];
int cnt;
vector<int> v;
void InputData() {
    fill(&map[0][0], &map[MAXN + 9][MAXN], '0');
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> &map[i][1];
    }
}
int Flood_fill(int x, int y)
{
    int dx[] = { 1,-1,0,0 };
    int dy[] = { 0,0,-1,1 };
    cnt++;
    map[y][x] = '0';
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx<0 || nx>N) continue;
        if (ny<0 || ny>N) continue;
        if (map[ny][nx] == '0') continue;
        
        Flood_fill(x + dx[k], y + dy[k]);
    }
    return cnt;
}
void Solve()
{
	for (int j = 0; j <= N; j++)
	{
		for (int i = 0; i <= N; i++)
		{
            if (map[j][i] == '1')
            {
                cnt = 0;
                Flood_fill(i,j);
                v.push_back(cnt);
            }
		}
	}
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int value : v)
    {
        cout << value <<endl;
    }
}

int main() {
    InputData();//ют╥б

    Solve();

    return 0;
}