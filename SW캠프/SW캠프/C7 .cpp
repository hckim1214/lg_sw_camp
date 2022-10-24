#include <queue>
#include <iostream>
using namespace std;

int N;//���� ��
int S;//���� ���� ��ȣ
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

	InputData();//	�Է� �Լ�

	Solve();


	return 0;
}