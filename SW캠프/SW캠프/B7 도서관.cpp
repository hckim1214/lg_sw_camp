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
        // 두개 다 겹치는 경우
        //if (find(st.begin(), st.end(), S[i]) != st.end())   // 
        //{
        //    auto pos = find(st.begin(), st.end(), S[i]);
        //    int index = pos - st.begin();
        //    j = index;
        //}
        for (j; j <= E[i] - S[i]; j++)
        {
            if ((find(st.begin(), st.end(), S[i]+j) != st.end()) && (find(st.begin(), st.end(), E[i]) != st.end()))
            {// 뒷부분 겹치고, 특정 부분부터 겹치기 시작했다
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
    InputData();// 입력받는 부분
    Solve();

    cout << present << " " << absent << endl;// 출력하는 부분
    return 0;
}