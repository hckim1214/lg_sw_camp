#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int S[10000 + 10];
int E[10000 + 10];
int present;
int absent;
vector<int> st;
vector<vector<int> > stL;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0]) a[1] < b[1];
    return a[0] < b[0];
}
void InputData(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> E[i];
        st.push_back(S[i]);
        st.push_back(E[i]);
        stL.push_back(st);
        st.clear();
    }
    sort(stL.begin(), stL.end(), cmp);
}
//void Sort()
//{
//    auto iter = stL.begin();
//    int i = 0;
//    int j = 0;
//    int k = stL.end() - stL.begin()-1;
//    for (iter; iter != stL.end(); iter++)
//    {
//        i = iter - stL.begin();
//        for (j = 0; j < k-i; j++)
//        {
//            if (stL[i][0] > stL[i + j][0])
//            {
//                vector<int> temp;
//                temp = stL[i];
//                stL[i] = stL[i + j];
//                stL[i + j] = temp;
//            }
//        }
//    }
//}
void Expand()
{
    int i = 0;
    int cnt_pre = 0, cnt_abs = 0;
    int start_pre= stL[0][0];
    int end_pre= stL[0][1];
    for (i; i < N-1; i++)
    {
        if (stL[i + 1][0] <= end_pre)
        {
            end_pre = max(stL[i+1][1], end_pre);
            // cnt_pre 정의
            cnt_pre = end_pre - start_pre;
        }
        else
        {
            cnt_pre = end_pre - start_pre;
            present = max(present,cnt_pre);

            cnt_abs = stL[i + 1][0] - end_pre;
            absent = max(absent, cnt_abs);

            start_pre = stL[i + 1][0];// 초기화
            end_pre = stL[i+1][1];
        }
        cnt_pre = end_pre - start_pre;
        present = max(present, cnt_pre);
    }
}

void Solve()
{
    Expand();
}
int main(void) {
    InputData();// 입력받는 부분

    Solve();

    cout << present << " " << absent << endl;// 출력하는 부분
    return 0;
}