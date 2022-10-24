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
    if (sum > N_MIN) return 0;          // 중단
    if (sum >= B) { N_MIN = min(sum, N_MIN); return 0; }    // 성공
    if (n >= N) return 0;    // 실패

    if( DFS(n + 1, sum + H[n])==1 ) return 0;       // n번째 요소 사용
    if( DFS(n + 1, sum /* + H[n + 1] */ ) == 1) return 0;       // n번째 요소 미사용
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
        InputData();//입력받는 부분
        
        ans=Solve();
        fill(H, H + 10, 0);     // initailize
        N_MIN = INF;
        cout << ans << endl;
    }
    return 0;
}