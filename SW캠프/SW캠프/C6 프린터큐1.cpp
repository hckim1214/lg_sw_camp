#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int N, M;//문서수, 궁금한 문서 번호
int P[100 + 10];//문서 우선순위
struct Doc {
    int name;
    int selected;
};
Doc D[100 + 10];
deque<Doc> q;

bool cmp(Doc& s1, Doc& s2)
{
    return s1.name > s2.name;
}

void InputData() {
    cin >> N >> M;
    q.clear();
    Doc D[100 + 10] = {};
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        D[i].name = P[i];
        if(i==M) D[M].selected = 1;      // 처음 선택한 문서 표시
        q.push_back(D[i]);
    }
    
}
int max_sort()
{
    int max_num = 0;
    int cnt = 0;
    Doc temp;
    for (int i = 0; i < q.size(); i++)
    {
        max_num = max(q[i].name, max_num);
    }
    while (q[0].name != max_num)
    {
        temp = q.front();
        q.pop_front();
        q.push_back(temp);
        cnt++;
    }
    return cnt;
}
int Solve()
{
    int cnt = 1;
    Doc temp;
    deque<Doc> right(q);
    while (!q.empty())
    {
        sort(right.begin(), right.end(), cmp);
        if (right[0].selected == 1)
        {
            return 1;   // 가장 처음 출력되는 경우
        }
        else {
            //temp = q.front();
            //q.pop_front();
            cnt=max_sort();
            q.pop_front();
            //q.push_back(temp);
            if (q[0].selected == 1) return ++cnt;
            cnt++;
        }
    }
    return 0;
}

int main() {
    int ans = -1;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        InputData();//입력받는 부분

        ans = Solve();

        cout << ans << endl;//출력하는 부분
    }
    return 0;
}