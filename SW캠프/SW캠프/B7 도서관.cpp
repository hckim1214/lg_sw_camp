#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int S[10000 + 10];
int E[10000 + 10];
int present;
int absent;
vector<int> st;

void InputData(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> E[i];
    }
}
void record()
{
    for (int i = 0; i < N; i++)
    {
        int j = 0;
        if ( (find(st.begin(), st.end(), S[i]) != st.end())  && (find(st.begin(), st.end(), E[i]) != st.end())) continue;
        // �ΰ� �� ��ġ�� ���
        //if (find(st.begin(), st.end(), S[i]) != st.end())   // 
        //{
        //    auto pos = find(st.begin(), st.end(), S[i]);
        //    int index = pos - st.begin();
        //    j = index;
        //}
        for (j; j <= E[i] - S[i]; j++)
        {
            if ((find(st.begin(), st.end(), S[i]+j) != st.end()) && (find(st.begin(), st.end(), E[i]) != st.end()))
            {// �޺κ� ��ġ��, Ư�� �κк��� ��ġ�� �����ߴ�
                break;
            }
            st.push_back(S[i] + j);
        }
    }
}
void Calculate()
{
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    auto iter = st.begin()+1;
    int cnt_pre=0;
    int cnt_abs = 1;
    for (iter; iter < st.end(); iter++)
    {
        if ((*(iter-1)) == ((*iter) - 1) )
        {
            cnt_pre++;
            if (present < cnt_pre) present = cnt_pre;
        }
        else {
            cnt_abs = ( (*iter) - (*(iter-1)));
            cnt_pre = 0;
            if (absent < cnt_abs) absent = cnt_abs;
        }
    }
}

void Solve()
{
    record();
    Calculate();
}

int main(void) {
    InputData();// �Է¹޴� �κ�
    Solve();

    cout << present << " " << absent << endl;// ����ϴ� �κ�
    return 0;
}