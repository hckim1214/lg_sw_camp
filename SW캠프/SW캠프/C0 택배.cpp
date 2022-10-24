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

//vector<int> Capacity(2000, C); //(�迭 ũ��,��);
vector<int> Capacity;   //  ���ͷε� �ʱ�ȭ ����
void initialize()
{
    for (int i = 0; i < N; i++)
    {
        Capacity.push_back(C);
    }
}
bool cmp(vector<int>& a, vector<int>& b) // &�� �޾Ҿ��..
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

    // int Capacity[2000] = {C};        //�ٽ� �غ���
    // Nũ�⸸ŭ �迭 ���� �Ұ� ==> initialize ó�� ���� for�� ���� �ִ� ��� ���� �ٸ� ������� �ذ��� X?

    for (int i = 0; i < M; i++)
    {
        int capability=C;
        for (int j = method[i][0]; j < method[i][1]; j++)
        {
            capability = min(Capacity[j], capability);
        }// ������� ����
        
         // ������� �Ѵ� ���
        if (capability < method[i][2])  Load = capability;
        // Load�� ��������ȿ� ������ ���
        else Load = method[i][2];

        for (int j = method[i][0]; j < method[i][1]; j++)
        {
            Capacity[j] -= Load;
        }//Capacity �پ�� �� ����
        cnt += Load;
        Load = 0;
    }
    return cnt;
}
int main() {
    int ans = -1;

    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}