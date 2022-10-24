#include <queue>
#include <iostream>
using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;

int q[10001];
int rp = 0;
int wp = 0;

void InputData() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)
	{
		q[i] = i;
	}
}
void push()
{
	for (int i = 1; i <= M - 1; i++)
	{
		q[wp] = q[rp];
		wp = (wp + 1) % 10001;
		rp = (rp + 1) % 10001;
	}
}
void pop()
{
	cout << q[rp]<<" ";
	rp = (rp + 1) % 10001;
}
void Solve()
{
	int cnt = M;
	rp = 1;
	wp = (N+1)%10001;
	for (int k = 1; k < S; k++)
	{
		q[wp] = q[k];
		wp=(wp+1)%10001;
		rp=(rp+1)%10001;
	}
	while (rp != wp)
	{
		push();
		pop();
	}
}
int main() {

	InputData();//	입력 함수

	Solve();


	return 0;
}