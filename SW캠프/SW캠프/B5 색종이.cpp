#include <iostream>
#include <algorithm>
using namespace std;
#define Cor 1 // 좌표 보정
int N;
int A[100 + 10];
int B[100 + 10];
int map[110][110] = { 0, };      // -1,-1 면 을 좌표 처음으로 잡는다 (0,0이면 x나 y값이 0인 둘레는 포함되지 않아

void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                map[B[i] +j + Cor][A[i] + k + Cor] = 1;
            }
        }
    }
}
int Solve()
{
    int cnt = 0;
    int dx[] = { -1,1,0,0 };
    int dy[] = { 0,0,1,-1 };
    for (int i = Cor; i < Cor+100; i++)
    {
        for (int j = Cor; j < Cor+100; j++)
        {
            if (map[j + Cor][i + Cor] == 1) {
                for (int k = 0; k < 4; k++)
                {
                    if (map[j + Cor + dy[k]][i + Cor + dx[k]] == 0) cnt++;
                }
            }
        }
    }
    return cnt;
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분
    ans=Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}