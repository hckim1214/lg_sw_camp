#include <iostream>
#include <vector>
using namespace std;
int N;//������ ����
vector<int> num;

void InputData() {
    cin >> N;
}
void Seperate()
{
    int Dec=N;
    while (Dec > 0)
    {
        int temp;
        temp = Dec % 10;
        num.insert(num.begin(), temp);
        Dec /= 10;
    }
}
void Correlate()
{
    for (int i = 0; i<num.size(); i++)
    {
        if (num[i] > 4) num[i]--;
    }
}
int Fuse()
{
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans = ans * 9 + num[i];
    }
    return ans;
}
int Solve()
{
    Seperate();
    Correlate();
    return Fuse();
}

int main() {
    int ans = -1;
    InputData();//�Է¹޴� �κ�

    ans= Solve();

    cout << ans << endl;//����ϴ� �κ�
    return 0;
}