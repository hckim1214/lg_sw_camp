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
    if (n >= 15)    // ������ �� �� ���
    {
        for (int i = 0; i < 4; i++)
        {
            // �ش� ���̽��� �����ϴ� ���
            if (sol[i] == 1) continue;

            bool flag = true;                           // ary ����� result ����� ���� �ʴٸ� �ٸ� ����� �� ����           
            for (int j = 0; j < 6; j++) {               // break������ ���� result ����� �� ����
                for (int k = 0; k < 3; k++) {
                    if (ary[i][j][k] != result[j][k]) {
                        flag = false;
                        break;              // return �� break ���� ����??
                    }
                }
                if (!flag) break;           // 2�� for �� ������ ���� ������ break
            }

            // ����� ��ġ
            if (flag) {
               sol[i] = 1;
                return;
            }
        }
        return;                             // ��� ����� ���� �� ������ �Ŀ� ���Ḧ �˸��� ����
    }

    int t1 = team1[n];
    int t2 = team2[n];

    // t1 ��
    result[t1][0]++; result[t2][2]++;
    DFS(n + 1);
    result[t1][0]--; result[t2][2]--;

    // ���º�
    result[t1][1]++; result[t2][1]++;
    DFS(n + 1);
    result[t1][1]--; result[t2][1]--;

    //t1 ��
    result[t1][2]++; result[t2][0]++;
    DFS(n + 1);
    result[t1][2]--; result[t2][0]--;
}
int main() {
    int i, ans = -1;
    for (i = 0; i < 4; i++) {
        InputData();// �Է¹޴� �κ�

        DFS(0);
    }

    OutputData();// ����ϴ� �κ�
    return 0;
}