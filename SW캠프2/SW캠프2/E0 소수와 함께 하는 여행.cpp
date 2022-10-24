#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include<deque>
#include<algorithm>
using namespace std;
struct ST
{
	int num;
	int trial;
};
ST Bus;
ST temp;
vector<int> SS;
queue <ST> q;
deque<int> dq_ori;

int S, E;//��� ������ ��ȣ, ���� ������ ��ȣ
int state = 0;
int visited[10000+10];
int ans;
void InputData() {
	cin >> S >> E;
}
void find_SS()
{
	for (int i = 1000; i <= 9999; i++)
	{
		state = 0;
		for (int j = 2; j <= (i / 2); j++)
		{
			if (i % j == 0) { state = 1; break; }
		}
		if (state == 0) SS.push_back(i);
	}
}
void slice(ST n)
{
	int k;
	for (int i = 0; i < 4; i++)
	{
		k = n.num % 10;
		n.num /= 10;
		dq_ori.push_front(k);
	}
}
int Fuse(deque<int> D_temp)
{
	int num = 0;
	for (int i = 0; i < 4; i++)
	{
		num = D_temp[i] + num * 10;
	}
	return num;
}
int Next_Stop(deque<int> D)
{
	int Fused_Num;
	int num_sel[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 4; i++)
	{
			for (int k = 0; k <= 9; k++) // õ���ڸ��� 0�� �ƴϴ�
			{
				if (i == 0 && k == 0) continue;

				deque<int> D_temp = D;
				
				if (D[i] == num_sel[k]) continue;
				D_temp[i] = num_sel[k];
				Fused_Num = Fuse(D_temp);
				if (Fused_Num == E)	// ������
				{
					ans= Bus.trial + 1;
					return ans;
				}
				if (visited[Fused_Num] == 1)	// �ϴ� ������ visited�� �̹� �����Ѱ��� �ٽ� �Ǵ� X
				{
					continue;
				}
				if (find(SS.begin(), SS.end(), Fused_Num) != SS.end()) // �Ҽ� �� ���
				{
					temp.num = Fused_Num;
					temp.trial = Bus.trial + 1;
					q.push(temp);
				}
				visited[Fused_Num] = 1;
			}
	}
	return -1;
}
void Solve()
{

	Bus.num = S;
	Bus.trial = 0;
	q.push(Bus);
	visited[S] = 1;
	while (!q.empty())
	{
		Bus = q.front();
		temp = Bus;
		q.pop();
		slice(Bus);// �ڷ�� dq�� ����
		if (Next_Stop(dq_ori) != -1) { break; }
	}
}
int main() {
    ans = -1;
	InputData();// �Է¹޴� �κ�
	find_SS();
	Solve();

	cout << ans << endl;// ����ϴ� �κ�
	return 0;
}