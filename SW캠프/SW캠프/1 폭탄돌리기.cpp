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
    InputData();//�Է¹޴� �κ�
    ans = Solve();

    cout << ans << endl;//����ϴ� �κ�
    return 0;
}