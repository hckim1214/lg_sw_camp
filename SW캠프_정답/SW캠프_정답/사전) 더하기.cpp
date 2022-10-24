// ������ ���ϴ� ö���� ���ν�Ű�� ���� �ڿ������� �ְ�, �� �߿� �� ���� ���� ��� �� ���� K�� �� �� �ִ��� �˾ƺ���� ���״�. ö�� ��Ӵϰ� �ڿ������� �������� �����ؼ� ���ε� �������� �ƴ��� �𸣰� �ִ�. ��Ӵϰ� ä���� �� �� �ְ� �־��� ������ ���� ã������.
#include <iostream>
using namespace std;

#define MAXN (20)
int N, K;//�ڿ��� ����, �����
int A[MAXN + 10];//�ڿ��� ��
int psum[MAXN + 10];//�ڿ��� ��
const char* msg[] = { "NO", "YES" };

void InputData() {
    psum[0] = 0;
    fill(&psum[0],&psum[MAXN-1],0);
    fill(&A[0], &A[MAXN - 1], 0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        psum[i] = psum[i-1]+A[i];
    }
}
//int DFS(int s, int sum)
//{
//    if (sum > psum[N] - psum[s-1]) return 0;
//    if (sum == A[s]) return 1;
//    if (sum< A[s]) return 0;
//    for (int i = s; i <= N; i++)
//    {
//        if (DFS(i + 1, K - A[i]) == 1) return 1;
//    }
//    return 0;
//
//}
int DFS2(int n, int sum)
{
    if (sum > psum[N] - psum[n - 1]) return 0;
    else if (sum == 0) return 1;
    else if (sum < 0) return 0;
    if (n > N) return 0;
    if (DFS2(n + 1, sum - A[n]) == 1) return 1;
    if (DFS2(n + 1, sum) == 0) return 1;
    return 0;
}
int Solve()
{
    int ans;

    ans = DFS2(1, K);
    return ans;
}

int main() {
    int T;
    cin >> T;
    int ans;
    for (int t = 1; t <= T; t++) {
        InputData();//�Է�

        ans=Solve();

        cout << msg[ans] << endl;//���
    }
    return 0;
}