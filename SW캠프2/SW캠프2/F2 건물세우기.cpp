#include <iostream>
using namespace std;

#define MAXN (10)
int N;
int cost[MAXN + 10][MAXN + 10];
int solpath[MAXN + 10];//답 경로
int Building[MAXN + 10];//답 경로
int visited[MAXN + 10];
int ANS=123456;

void InputData() 
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
}
void OutputData(int sol) 
{
    cout << sol << endl;
    for (int i = 0; i < N; i++) {
        cout << solpath[i] << " ";
    }
    cout << endl;
}
void DFS(int n, int sum)
{
    if (n >= N)
    {
        if (ANS > sum)
        {
            ANS = sum;
            for (int i = 0; visited[i]; i++)
            {
                solpath[i] = Building[i];
            }
        }
        return;                                 ///////////// 종료할 때 return
    }
    //
    for (int j = 0; j < N; j++)
    {
        if (visited[j] == 0)
        {
            visited[j] = 1;
            Building[n] = j+1;          // 0번 필지 존재 X
            DFS(n + 1, sum + cost[n][j]);          ////////// return이 나오면 바로 전의 함수가 시작했던 곳으로 오게 된다
            visited[j] = 0;     /////////////////////
        }
    }
}
int main() 
{
    InputData();//입력받는 부분

    DFS(0, 0);

    OutputData(ANS);//출력하는 부분
    return 0;
}