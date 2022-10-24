#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, M;
int S[10000 + 10];
int E[10000 + 10];
int NUM[10000 + 10];
vector<int> st_en;
vector < vector<int> > method;

//vector<int> Capacity(2000, C); //(배열 크기,수);
vector<int> Capacity;   //  벡터로도 초기화 가능
void initialize()
{
    for (int i = 0; i < N; i++)
    {
        Capacity.push_back(C);
    }
}
bool cmp(vector<int>& a, vector<int>& b) // &로 받았어야..
{
    if (a[1] == b[1]) return a[0] > b[0];
    return a[1] < b[1];
}
void InputData() {
    cin >> N >> C;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> E[i] >> NUM[i];
        st_en.push_back(S[i]);
        st_en.push_back(E[i]);
        st_en.push_back(NUM[i]);
        method.push_back(st_en);
        st_en.clear();
    }
    sort(method.begin(), method.end(), cmp);
}

int Solve()
{
    int cnt = 0;
    int Load = 0;
    initialize();

    // int Capacity[2000] = {C};        //다시 해볼것
    // N크기만큼 배열 설정 불가 ==> initialize 처럼 벡터 for문 통해 넣는 경우 말고 다른 방법으로 해결방법 X?

    for (int i = 0; i < M; i++)
    {
        int capability=C;
        for (int j = method[i][0]; j < method[i][1]; j++)
        {
            capability = min(Capacity[j], capability);
        }// 가용공간 조사
        
         // 가용공간 넘는 경우
        if (capability < method[i][2])  Load = capability;
        // Load가 가용공간안에 들어오는 경우
        else Load = method[i][2];

        for (int j = method[i][0]; j < method[i][1]; j++)
        {
            Capacity[j] -= Load;
        }//Capacity 줄어든 것 적용
        cnt += Load;
        Load = 0;
    }
    return cnt;
}
int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}