#include <iostream>
using namespace std;
#define MAXN (100)
int K;//ó�� ��ź�� ���� ��� ��ȣ
int N;//���� ����
int T[MAXN + 10];//�ɸ� �ð�
char Z[MAXN + 10];//���� ����
void InputData() {
    cin >> K;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> Z[i];
    }
}
int Solve()
{
    int i, t = 0;
    for (i = 0; i < N; i++)
    {
        t += T[i];
        if (t > 210) break;
        if (Z[i] == 'T')
        {
            if (++K > 8) K = 1;
        }
    }
    return K;
}

int main() {
    int ans = -1;
    InputData();//�Է¹޴� �κ�
    ans = Solve();

    cout << ans << endl;//����ϴ� �κ�
    return 0;
}