#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N;
char S[10000 + 10][20 + 10];
map<char[20 + 10], vector<int> > Used;    // 5000개 크기 최대 20

void InputData() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
}
void Solve()
{
    int cnt=0;
    for (int i = 1; i <= N; i++)
    {
        if (Used.find(S[i]) == Used.end())
        {
            Used[S[i]].push_back(i);
        }
        else ++Used.find(S[i]);
    }
}
void OutputData()
{
    for (int i = 1; i <= Used.size(); i++)
    {
        if ((Used.find(S[i])).size() >= 2)
        {
            cout << Used[S[i]];
            auto pos = Used.find(S[i]);
            for (int j = 0; j < Used[S[i]]; j++)
            {
                cout << pos;
            }
        }
        if()
    }
}
int main() {
    InputData();// 입력받는 부분
    Solve();
    OutputData();
    return 0;
}