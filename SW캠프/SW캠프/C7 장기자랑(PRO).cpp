#include <iostream>
#include <vector>
using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;
vector<int> q;

void InputData() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)
	{
		q.push_back(i);
	}
}
//struct Cir_Que
//{
//	int num[10000+100];
//	int front, rear;
//	Cir_Que() {
//		front = N - 1;
//		rear = N - 1;
//	}
//	bool isEmpty()
//	{
//		return rear == front;
//	}
//	bool isFull()
//	{
//		return ((rear)+1) % N == front;
//	}
//	void enqueue(int data)
//	{
//		if (isFull) cout << "Q is Ful;"; return;
//		rear = (rear + 1) % N;
//		num[rear] = data;
//	}
//	int dequeue()
//	{
//		return num[front = (front + 1) % N; ]
//	}
//};

void Solve()
{
	auto iter = q.begin();
	int start = S;
	while (!q.empty())
	{
		start = start + 3;
		if (start > 7) start = start - 7;
		if (iter > q.begin() + 7) iter = iter - 7;
		cout << q[start % q.size()];
		iter = iter + start;
		q.erase((iter+start));
	}
}
int main() {

	InputData();//	입력 함수

	Solve();//	코드를 작성하세요


	return 0;
}