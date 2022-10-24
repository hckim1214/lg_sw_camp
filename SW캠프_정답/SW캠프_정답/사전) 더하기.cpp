// 덧셈을 못하는 철수를 공부시키기 위해 자연수들을 주고, 그 중에 몇 개의 수를 골라서 그 합이 K가 될 수 있는지 알아보라고 시켰다. 철수 어머니가 자연수들을 무작위로 선택해서 본인도 가능한지 아닌지 모르고 있다. 어머니가 채점을 할 수 있게 주어진 문제의 답을 찾아주자.
#include <iostream>
using namespace std;

#define MAXN (20)
int N, K;//자연수 개수, 만들수
int A[MAXN + 10];//자연수 값
int psum[MAXN + 10];//자연수 값
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
        InputData();//입력

        ans=Solve();

        cout << msg[ans] << endl;//출력
    }
    return 0;
}