#include <iostream>
#include <algorithm>
using namespace std;

int N;//직원 수
int M;//기부금 총액
int A[1000010];//직원 별 성과급

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);	// 내림차순
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

	// 타킷:M
	// 직원 성과급 총 합 - 
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

	InputData();			//	입력 함수

	ans = Solve();

	cout << ans << endl;	//	정답 출력
	return 0;
}
