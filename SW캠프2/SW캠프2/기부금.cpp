#include <iostream>
#include <algorithm>
using namespace std;

int N;//���� ��
int M;//��α� �Ѿ�
int A[1000010];//���� �� ������

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);	// ��������
}
int Donate(int L)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] < L) continue;
		sum += (A[i]-L);
	}
	return sum;
}
int Solve()
{
	int sum = 0;
	int s, e, m;
	int sol;
	s = 0;
	e = A[N - 1];
	int D;

	// ŸŶ:M
	// ���� ������ �� �� - 
	while (s <= e)
	{
		m = (s + e) / 2;
		D = Donate(m);
		if (D <= M) { sol = m; e = m - 1; cout << sol << endl; }
		else { cout << "pp" << endl; s = m + 1; }	// Donate(m)>=M
	}
	return sol;
}
int main() {
	int ans = 0;

	InputData();			//	�Է� �Լ�

	ans = Solve();

	cout << ans << endl;	//	���� ���
	return 0;
}
