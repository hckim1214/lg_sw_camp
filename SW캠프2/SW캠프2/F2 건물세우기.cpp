#include <iostream>
using namespace std;

#define MAXN (10)
int N;
int cost[MAXN + 10][MAXN + 10];
int solpath[MAXN + 10];//�� ���
int Building[MAXN + 10];//�� ���
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
        return;                                 ///////////// ������ �� return
    }
    //
    for (int j = 0; j < N; j++)
    {
        if (visited[j] == 0)
        {
            visited[j] = 1;
            Building[n] = j+1;          // 0�� ���� ���� X
            DFS(n + 1, sum + cost[n][j]);          ////////// return�� ������ �ٷ� ���� �Լ��� �����ߴ� ������ ���� �ȴ�
            visited[j] = 0;     /////////////////////
        }
    }
}
int main() 
{
    InputData();//�Է¹޴� �κ�

    DFS(0, 0);

    OutputData(ANS);//����ϴ� �κ�
    return 0;
}