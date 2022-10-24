#include <iostream>
#include <queue>
#include <deque>
using namespace std;

#define MAXN (100)

int N, M;//지하철역수, 목적역
int S[MAXN + 2][MAXN + 2];//[s][e]=시간
int visited[MAXN];
int path[MAXN];
queue<int> q;

void InputData() {
	cin >> N >> M;
	for (int s = 1; s <= N; s++) {
		for (int e = 1; e <= N; e++) {
			cin >> S[s][e];
		}
	}
}
void Solve()
{
	int cur;
	for (int i = 1; i <= N; i++)
	{
		visited[i] = S[1][i];
	}
	q.push(1);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		//for (int j = 1; j <= N; j++)		M이 아니라 e
		//{
		//	if (S[cur][j] == 0 || S[j][M]==0) continue;
		//	if (S[cur][M] > S[cur][j] + S[j][M] )		// visited[j] ==> S[cur][j]
		//	{
		//		visited[M] = S[cur][j] + S[j][M];
		//		q.push(j);
		//		path[j] = cur;
		//	}
		//	
		//}
	}
	cout << visited[M]<<endl;
	int k=M;
	deque<int> dq;
	dq.push_front(M);
	while (k!=1)
	{
		k = path[k];
		dq.push_front(k);
	}
}
int main() {
	InputData();//입력

	Solve();
	return 0;
}