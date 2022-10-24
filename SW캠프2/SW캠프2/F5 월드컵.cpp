#include <iostream>
using namespace std;
#define MAXN (6)
int win[MAXN + 10], lose[MAXN + 10], draw[MAXN + 10];
int sol[4 + 10];
int team1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int team2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
int result[6][3];
int ary[4][6][3];

void InputData() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cin >> ary[i][j][k];
            }
        }
    }
}
void OutputData() {
    for (int i = 0; i < 4; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}
void DFS(int n)
{
    if (n >= 15)    // 게임을 다 한 경우
    {
        for (int i = 0; i < 4; i++)
        {
            // 해당 케이스가 존재하는 경우
            if (sol[i] == 1) continue;

            bool flag = true;                           // ary 결과와 result 결과가 같지 않다면 다른 경우의 수 시행           
            for (int j = 0; j < 6; j++) {               // break문으로 빠른 result 경우의 수 실행
                for (int k = 0; k < 3; k++) {
                    if (ary[i][j][k] != result[j][k]) {
                        flag = false;
                        break;              // return 과 break 과의 차이??
                    }
                }
                if (!flag) break;           // 2개 for 문 나가기 위해 설정한 break
            }

            // 결과가 일치
            if (flag) {
               sol[i] = 1;
                return;
            }
        }
        return;                             // 모든 경우의 수를 다 시행한 후에 종료를 알리기 위해
    }

    int t1 = team1[n];
    int t2 = team2[n];

    // t1 승
    result[t1][0]++; result[t2][2]++;
    DFS(n + 1);
    result[t1][0]--; result[t2][2]--;

    // 무승부
    result[t1][1]++; result[t2][1]++;
    DFS(n + 1);
    result[t1][1]--; result[t2][1]--;

    //t1 패
    result[t1][2]++; result[t2][0]++;
    DFS(n + 1);
    result[t1][2]--; result[t2][0]--;
}
int main() {
    int i, ans = -1;
    for (i = 0; i < 4; i++) {
        InputData();// 입력받는 부분

        DFS(0);
    }

    OutputData();// 출력하는 부분
    return 0;
}