#include <iostream>
using namespace std;
#define MAXN (20)
#define INF (123456)
int N, B;
int H[MAXN + 10];
int N_MIN = INF;
int temp[10];
void InputData() {
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
}
int DFS(int n, int sum)
{
    if (sum > N_MIN) return 0;          // �ߴ�
    if (sum >= B) { N_MIN = min(sum, N_MIN); return 0; }    // ����
    if (n >= N) return 0;    // ����

    if( DFS(n + 1, sum + H[n])==1 ) return 0;       // n��° ��� ���
    if( DFS(n + 1, sum /* + H[n + 1] */ ) == 1) return 0;       // n��° ��� �̻��
}
int Solve()
{
    DFS(0, 0);
    return N_MIN-B;
}

int main() {
    int T, ans = -1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        InputData();//�Է¹޴� �κ�
        
        ans=Solve();
        fill(H, H + 10, 0);     // initailize
        N_MIN = INF;
        cout << ans << endl;
    }
    return 0;
}