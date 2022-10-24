#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include<set>
using namespace std;

int N;
char S[10000 + 10][20 + 10];
map<string, vector<int> > Used;    // 5000개 크기 최대 20
//set<string> s;

void InputData() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
//        s.insert(S[i]);
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
    int cnt = 0;
    auto iter = Used.begin();
    if (Used.size() < N)
    {
        for (int i = 1; i <= Used.size(); i++)
        {
            if (Used[S[i]].size() >= 2)
            {
                if (++cnt != 1) { cout << endl; }
                cout << iter->first;
                
                int temp = Used[S[i]].size();
                for (int j = 0; j < temp; j++)
                {
                    cout << " " << (iter->second)[j];
                }
                //if( s[s.size()] == Used[S[i]] )
                iter++;
            }
            else continue;
        }
    }
    else cout << "unique";
}
int main() {
    InputData();// 입력받는 부분
    Solve();
    OutputData();
    return 0;
}