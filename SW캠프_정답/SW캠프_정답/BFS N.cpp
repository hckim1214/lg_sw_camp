#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN (20)
int N, K;//�ڿ��� ����, �����
int A[MAXN + 10];//�ڿ��� ��
int presum[MAXN + 10];

const char* msg[] = { "NO", "YES" };

void InputData() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}
int DFS(int s, int sum)
{
    int pp = presum[N] - presum[s - 1];
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    if (sum > presum[N] - presum[s - 1]) return 0;

    for (int j = s; j <= N; j++)
    {
        if (DFS(j + 1, sum - A[j]) == 1) return 1;
    }
    return 0;
}

int Solve()
{
    int i, ans;
    for (i = 1; i <= N; i++)
    {
        presum[i] = presum[i - 1] + A[i];
    }
    ans = DFS(1, K);
    return ans;
}

int main() {
    int T;
    cin >> T; // �׽�Ʈ Ƚ��
    for (int t = 1; t <= T; t++) {
        InputData();//�Է�
        int ans = 2;
        ans = Solve();
        cout << msg[ans] << endl;//���
    }
    return 0;
}