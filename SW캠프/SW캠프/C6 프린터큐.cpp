#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;//������, �ñ��� ���� ��ȣ
int P[100 + 10];//���� �켱����
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
    D[M].selected = 1;      // ó�� ������ ���� ǥ��
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
        InputData();//�Է¹޴� �κ�

        //count = Solve();

        //count >> ans >> endl;//����ϴ� �κ�
    }
    return 0;
}