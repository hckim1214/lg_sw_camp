#include <iostream>
using namespace std;
#define MAXN (100)
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN + 10];//걸린 시간
char Z[MAXN + 10];//정답 여부
void InputData() {
    cin >> K;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> Z[i];
    }
}

int Solve()
{
    int time = 0;
    int limit = 210;
    int remain_quiz = N;
    int person = K;
    int iter = 0;
    while (1)
    {
        if (person > 8) person %= 8;
        time += T[iter];
        if (time >= limit || remain_quiz <= 0)
        {
            break;
        }

        
        if (Z[iter] == 'T')
        {
            person++;
        }
        remain_quiz--;
        iter++;
    }
    return person;
}
int main() {
    int ans = -1;
    InputData();//입력받는 부분
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}