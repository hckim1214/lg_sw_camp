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
        for (string s : Name)   // Name�̶�� list���� ��ü ����� �� �ݺ�
        {
            cout << s << " ";
            auto i = Map.find(s);
            if ((i->second.size()) == 1) continue;
            for (int i : Map[s])   //  Map[s] ==> map�� value�� (���⼭�� value�� �ִ� list)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    InputData();// �Է¹޴� �κ�

    Solve();
    return 0;
}

