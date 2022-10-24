#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;//문서수, 궁금한 문서 번호
int P[100 + 10];//문서 우선순위
struct Doc {
    int name;
    int selected;
};
Doc D[100+10];
queue<Doc> q_ori;
priority_queue<Doc, cmp> q_sorted;

struct cmp {
    bool operator()(Doc& s1, Doc& s2)
    {
        s1.name > s2.name;
    }
};




void InputData() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        D[i].name = P[i];
        q.push(D[i]);
    }
    D[M].selected = 1;      // 처음 선택한 문서 표시
}

int Solve()
{
    int cnt = 0;
    while (!q.empty())
    {
        for (int i = 0; i = q.size(); i++)
        {

        }
    }
}

int main() {
    int ans = -1;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        InputData();//입력받는 부분

        //count = Solve();

        //count >> ans >> endl;//출력하는 부분
    }
    return 0;
}