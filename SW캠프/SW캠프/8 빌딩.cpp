#include <iostream>
#include <vector>
using namespace std;
int N;//빌딩의 층수
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
    InputData();//입력받는 부분

    ans= Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}