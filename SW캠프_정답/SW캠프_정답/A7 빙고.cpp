#include <iostream>
using namespace std;

int A[5 + 10][5 + 10];
int B[25 + 10];
struct check
{
    int r, c;
};
check map[30];
void InputData() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < 25; i++) {
        cin >> B[i];
    }
}
int Check(int k) {
    int vr = map[k].r, vc = map[k].c;
    int cnt = 0, i;//완성된 줄 개수

    //0.(vr, vc) 0으로 표시
    A[vr][vc] = 0;

    //1.가로 완성 확인
    for (i = 0; i < 5; i++) {
        if (A[vr][i] != 0) break;
    }
    if (i == 5) cnt++;

    //2.세로 완성 확인
    for (i = 0; i < 5; i++) {
        if (A[i][vc] != 0) break;
    }
    if (i == 5) cnt++;

    //3.좌상단 대각선 확인
    if (vr == vc) {
        for (i = 0; i < 5; i++) {
            if (A[i][i] != 0) break;
        }
        if (i == 5) cnt++;
    }

    //4.우상단 대각선 확인
    if (vr + vc == 4) {
        for (i = 0; i < 5; i++) {
            if (A[i][4 - i] != 0) break;
        }
        if (i == 5) cnt++;
    }
    return cnt;
}
int Solve()
{
    int k=0;
    int bingo = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            k = A[i][j];
            map[k].r = i; map[k].c = j;
        }
    }
    for (k = 0; k < 25; k++)
    {
        bingo += Check(B[k]);
        if (bingo >= 3) break;
    }
    return k + 1;
}
int main() {
    int ans = -1;
    InputData();// 입력받는 부분
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}