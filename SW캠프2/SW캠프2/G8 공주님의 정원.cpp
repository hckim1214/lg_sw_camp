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
    return a.start < b.start;
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
    E = 301;
    int iter = 0;
    int temp_S = 0;
    int temp_E = 0;
    int cnt = 0;

    while (temp_E<= 1130)
    {
        if (iter >= V.size()) { return 0; }     //  11/30 ���� �Ǵ� ���� ���� ���
        else if (V[iter].end < 301) { iter++; continue; }       // 3�� 1�� ���� �� ����
        else if ((V[iter].start < E) && (E<V[iter].end))        // ���� �� �Ⱓ�� �� ���� end ������ �����ϴ� ���
        {
            temp_S = V[iter].start;
            temp_E = max(V[iter].end,temp_E);
            iter++;
        }
        else	// �������� ���� �� ���� �ֱٿ� ������ ����
        {
            S = temp_S;
            E = temp_E;
            cnt++;
            if (E <= V[iter].start)      // ������ ���� ���� �����
            {
                return 0;       // �����ϴ� ���
            }
        }

    }
    return cnt+1;
}

int main() {
    int ans = -1;

    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}