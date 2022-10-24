#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int ID[500 + 10];
int S[500 + 10];
int E[500 + 10];
vector<int> sol;
vector<int> Sm;
vector<vector<int>> Big;

bool cmp(vector<int> a,vector<int> b)
{
    if (a[2] == b[2]) a[1] < b[2];
    return a[2] < b[2];
}
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ID[i] >> S[i] >> E[i];
        Sm.push_back(ID[i]);
        Sm.push_back(S[i]);
        Sm.push_back(E[i]);
        Big.push_back(Sm);
        Sm.clear();
    }
    sort(Big.begin(), Big.end(), cmp);
}
void OutputData() {
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}
void make_ans()
{
    int end = Big[0][2];
    sol.push_back(Big[0][0]);
    for (int i = 0; i < Big.size()-1; i++)
    {
        if (end <= Big[i + 1][1])
        {
            sol.push_back(Big[i + 1][0]);
            end = Big[i + 1][2];
        }
    }
}

void Solve()
{
    make_ans();
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    Solve();

    OutputData();// 출력하는 부분
    return 0;
}