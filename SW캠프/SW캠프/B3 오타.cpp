#include <iostream>
#include <algorithm>
using namespace std;

char str[100000 + 10];
void InputData() {
    cin >> str;
}
int Solve()
{
    int balance = 0;
    int pos = 0;
    int cnt = 0;
    int index_pos;
    int index_neg;
    int num_of_open = 0;
    int num_of_close = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
        {
            balance++;
            num_of_open++;
        }
        if (str[i] == ')') { balance--; num_of_close++; }
        if (balance == 1)     // �ں��� 1 ���� �� ���� ����
        {
            index_pos = i;
            num_of_open = 0;
        }
        if (balance == -1)     // �պ��� -1 ���� �� ���� ����
        {
            index_neg = i;
            break;
        }
    }
    if (balance > 0) pos = num_of_open;
    if (balance == 0) pos = 0;
    if(balance<0) pos = num_of_close;

    return pos;
}

int main() {
    int ans = -1;

    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}