#include <iostream>
#include <list>
#include <map>
#include<algorithm>
using namespace std;

int N;
char S[10000 + 10][20 + 10];
map<string, list<int>> Map;
list<string> Name;

void InputData() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
}
void Record()
{
    for (int i = 1; i <= N; i++)
    {
        auto iter= Map.find(S[i]);
        if (iter == Map.end())
        {
            Map.insert({ S[i],list<int>() });
            Name.push_back(S[i]);
            iter = Map.find(S[i]);
        }
        iter->second.push_back(i);
    }
}
void Solve()
{
    Record();
    if (Name.size() == N) cout << "unique";
    else
    {
        for (string s : Name)   // Name이라는 list내의 전체 경우의 수 반복
        {
            cout << s << " ";
            auto i = Map.find(s);
            if ((i->second.size()) == 1) continue;
            for (int i : Map[s])   //  Map[s] ==> map의 value값 (여기서는 value에 있는 list)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    InputData();// 입력받는 부분

    Solve();
    return 0;
}

