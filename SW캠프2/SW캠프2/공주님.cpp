#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int sm[100000 + 10];
int sd[100000 + 10];
int em[100000 + 10];
int ed[100000 + 10];
struct info
{
    int start;
    int end;
};
info F;
vector<info> V;
int S;
int E;
bool cmp(info a, info b)
{
    if (a.end == b.end) return a.start < b.start;
    return a.end > b.end;
}
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sm[i] >> sd[i] >> em[i] >> ed[i];
        F.start = sm[i] * 100 + sd[i];
        F.end = em[i] * 100 + ed[i];
        V.push_back(F);
    }
    sort(V.begin(), V.end(), cmp);      // ������ �� �������� ��Ʈ
}
int Solve()
{
    int iter = 0;
    E = 301;
    int cnt = 0;
    int limit_temp = 123456;
    while (1)
    {
        if (V[0].end < 1131) return 0;
        if (V[iter].start < E)          // start�� E ���� ������ ã��
        {
            S = V[iter].start;
            E = V[iter].end;
            if (limit_temp < iter) return 0;
            limit_temp = iter;
            iter = -1;      // �ٽ� iter 0 ���� ������ �ַ���
            cnt++;
            if (E > 1130) return cnt;
        }

        if (iter == V.size() - 1)       // �� ���� ������ ���� ���� ���� 3/1 ���Ŀ� �� ���
        {
            return 0;
        }
        iter++;
    }
}
int main() {
    int ans = -1;

    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}
