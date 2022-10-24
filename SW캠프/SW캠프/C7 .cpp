#include <queue>
#include <iostream>
using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;
queue<int> q;
void InputData() {
	cin >> N >> S >> M;
}
void inqueue()
{
	int temp;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	for (int i = 1; i <= S-1; i++)
	{
		temp = q.front();
		q.pop();
		q.push(temp);
	}
}
void dequeue()
{
	int temp = 0;
	for (int i = S; i <= M - 1; i++)
	{
		temp = q.front();
		q.pop();
		q.push(temp);
	}
}
void Solve()
{
	inqueue();
	while (!q.empty())
	{
		dequeue();
		cout << q.front()<<" ";
		q.pop();
	}
}
int main() {

	InputData();//	입력 함수

	Solve();


	return 0;
}