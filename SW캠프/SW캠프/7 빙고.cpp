#include <iostream>
using namespace std;

int A[5 + 10][5 + 10];
int B[25 + 10];
int map[5 + 10][5 + 10];
void InputData() {
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            cin >> A[j][i];     // i 세로 j 가로
        }
    }
    for (int i = 0; i < 25; i++) {
        cin >> B[i];
    }
}
void Search(int k)
{
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            if (A[j][i] == B[k]) map[j][i] = 1;
        }
    }
}
int Bingo()
{
    int cnt = 0;
    int sum1 = 0;
    int sum2 = 0;
    // 대각선 검사

    //int sum4 = 0;
   /* for (int j = 0; j < 5; j++) {
        int sum3 = 0;
        for (int i = 0; i < 5; i++) {
            if (i + j == 4) sum1+=map[j][i];
            if (i == j) sum2+= map[j][i];
            sum3 += map[j][i];
            if (sum3 == 5) cnt++;
        }
    }
    if (sum1 == 5) cnt++;
    if (sum2 == 5)cnt++;

    for (int i = 0; i < 5; i++) {
        int sum4 = 0;
        for (int j = 0; j < 5; j++) {
            sum4 += map[j][i];
            if (sum4 == 5) cnt++;
        }
    }*/

    if ((map[0][0] + map[1][1] + map[2][2] + map[3][3] + map[4][4]) == 5) cnt++;
    if ((map[0][4] + map[1][3] + map[2][2] + map[3][1] + map[4][0]) == 5) cnt++;
    for (int i = 0; i < 5; i++)
    {
        int sum1 = 0;
        for (int j = 0; j < 5; j++)
        {
            sum1 += map[i][j];
            if (sum1 == 5) cnt++;
        }
    }
    for (int j = 0; j < 5; j++)
    {
        int sum2 = 0;
        for (int i = 0; i < 5; i++)
        {
            sum2 += map[i][j];
            if (sum2 == 5) cnt++;
        }
    }
    return cnt;
}
int Solve()
{
    int ans;
    for (int k = 0; k < 25; k++)
    {
        Search(k);
        ans = Bingo();
        if (ans >= 3)
        {
            ans = k+1;
            break;
        }
    }
    return ans;
}
int main() {
    int ans = -1;
    InputData();// 입력받는 부분
    ans=Solve();
    cout << ans << endl;// 출력하는 부분
    return 0;
}