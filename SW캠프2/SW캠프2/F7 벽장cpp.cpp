#include <iostream>
#include<cmath>
using namespace std;

#define MAXN (20)
int N;
int sl, sr;
int M;
int seq[MAXN + 10];
int move_try;
int N_MIN = 123456;
void InputData() {
    cin >> N;
    cin >> sl >> sr;
    cin >> M;
    for (int i = 0; i <M; i++) {
        cin >> seq[i];
    }
}
void DFS(int d_cnt, int d1, int d2, int m_cnt)
{
    if (d_cnt >= M)
    {
        N_MIN = min(N_MIN, m_cnt);
        return;
    }

    // 아래 벽장 이동
    move_try = abs(seq[d_cnt] - d1);
    DFS(d_cnt + 1, seq[d_cnt], d2, m_cnt+move_try);
    // 윗 벽장
    move_try = abs(seq[d_cnt] - d2);
    DFS(d_cnt + 1, d1, seq[d_cnt], m_cnt + move_try);

}

int main() {
    int ans = -1;

    InputData();//입력받는 부분

    DFS(0, sl, sr,0);

    cout << N_MIN << endl;//출력하는 부분
    return 0;
}