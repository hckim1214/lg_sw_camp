#include <iostream>
using namespace std;

int N, D, K, C;
int A[3000000 + 10];
struct check_overlap
{
    int num;
    int check;
};
struct check_overlap O[3000 + 10];

void InputData() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}
void initialize()
{
    for (int i = 0; i < 3000 + 10; i++)  // O initialize
    {
        O[i].num = i;
        O[i].check = 0;
    }
}
int Solve()
{
    int max = 0;
    int cnt = 0;
    initialize();
    for (int j = 0; j < K; j++) // 0~500 ��° �ʹ�
    {
        if (O[A[(j)]].check >= 1)     
        {
            O[A[(j)]].check++;
            continue;
        }
        O[A[(j)]].check++;
        cnt++;
    }
    O[C].check++;
    if (O[C].check == 1) cnt++;
    max = cnt;
    for (int i = 0; i <= N; i++) //
    {
        if (O[A[(i + K) % N]].check == 0) cnt++;//�߰��� �ʹ��� ���ο� �ʹ�
        O[A[(i + K) % N]].check++;
        if (O[A[i%N]].check == 1) cnt--;// �� �տ� �ʹ��� �����ߴٸ� -1 ó��
        O[A[i%N]].check--;
        if (max < cnt) max = cnt;
    }
    return max;
}

int main() {
    int ans = -1;

    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}