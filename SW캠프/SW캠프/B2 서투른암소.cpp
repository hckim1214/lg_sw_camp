#include <iostream>
using namespace std;

char str[100000 + 10];
void InputData() {
    cin >> str;
}
int Solve()
{
    int balance = 0;
    int cnt = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i]=='(') balance++;
        if (str[i]==')') balance--;
        if (balance < 0)
        {
            balance = 1;
            cnt++;
        }
    }
    cnt += (balance / 2);
    return cnt;
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}