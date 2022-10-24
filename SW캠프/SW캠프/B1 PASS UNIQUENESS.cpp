#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include<set>
using namespace std;

int N;
char S[10000 + 10][20 + 10];
map<string, vector<int> > Used;    // 5000개 크기 최대 20
set<string> already;

void InputData() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
}
void Solve()
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Used.find(S[i]) == Used.end())
        {
            Used.insert(std::pair<string, vector<int>>(S[i], vector<int>()));
            Used[S[i]].push_back(i);
        }
        else Used[S[i]].push_back(i);
    }
}
void OutputData()
{
    for (int i = 1; i <= N/*Used.size()*/; i++)
    {
        if (Used[S[i]].size() >= 2)
        {
            if (already.find(S[i]) == already.end())
            {
                already.insert(S[i]);
                cout << S[i];
            }
            else continue;
            for (int j = 0; j < Used[S[i]].size(); j++)
            {
                cout << " " << Used[S[i]][j];
            }
            cout << endl;
        }
    }
    if (Used.size() == N) cout << "unique";
}
int main() {
    InputData();// 입력받는 부분
    Solve();
    OutputData();
    return 0;
}