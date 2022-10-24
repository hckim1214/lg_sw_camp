#include <iostream>
using namespace std;

int N;
int W[20];
int sol;
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
}
bool check(int a, int b)
{
    while (a && b)        // a�� b ���� �ϳ��� ���� ������ ���� ����
    {
        if ((a % 10 + b % 10) >= 10) return 0;
        a /= 10;
        b /= 10;
    }
    return 1;
}
void DFS(int n, int sum, int cnt)
{
    if (n >= N)
    {
        sol = max(sol, cnt);
        return;
    }

    if (sol > cnt + N - n) return;

    // �Ҹ� �¿�� ���
    if (check(sum,W[n]))
    {
        DFS(n + 1, sum + W[n], cnt + 1);
    }
    // �Ҹ� �¿��� �ʴ� ���
    // �¿��� ���� ���� ���ٸ� ������ �ʿ� ����
    DFS(n + 1, sum, cnt);
}
int main() {

    InputData();// �Է¹޴� �κ�

    DFS(0,0,0);

    cout << sol << endl;//����ϴ� �κ�
    return 0;
}