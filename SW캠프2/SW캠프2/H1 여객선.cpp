#include <iostream>
using namespace std;
#define MAXB (9)
#define MAXN ((int)1e5)
int B, N;
int S[MAXB + 10];
int P[MAXN + 10];
int visited[12];
int presum[MAXN];
int R_MAX = 0;
int state_P = 0;
struct info
{
    int ship;
    int person;
};
void Make_presum()
{
    int sum = 0;
    for (int iii = 0; iii < N; iii++)
    {
        sum += P[iii];
        presum[iii] = sum;
    }
}
void InputData() {
    cin >> B >> N;
    for (int i = 0; i < B; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
}
int Binary(int jj, int ss)
{
    // P[i]: ���� ��   n: ��°
    // ã������ �� presum[ss-1]+S[jj]
    // if (ss = 0)
    int target = 0;
    if (ss == 0) { target = S[jj]; }
    else { target = presum[ss] + S[jj]; }       // ������ presum[ss-1]+S[jj] �� �� �˾Ҵµ�, ���� ó�� ���ľ� ��
    int s = 0;
    int e = N - 1;
    int m = 0;
    m = (s + e) / 2;
    int sol=0;
    while (s <= e)
    {
        if (presum[m] <= target) { sol = m; s = m + 1; }
        else { e = m - 1; }
        m = (s + e) / 2;
    }
    return sol;
}
int DFS(int n, int remain)
{
    if (n >= N-1)
    {
        R_MAX = max(remain, R_MAX);
        state_P = 1;
        return R_MAX;
    }
    else if (remain == 0 && n < N - 1)
    {
        return 0;
    }
    // �� 1~9 ���� �� �������
    int person = 0;// ���� ����: i, ����� ����:person
    for (int i = 0; i < B; i++)     // j ��° (������ ���� ���� ����)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            person = Binary(i, n);
            DFS(person, remain-S[i]);     // n��° ���, 
            visited[i] = 0;
        }
    }
    return state_P;
}
int Sum_remain()
{
    int ii = 0;
    for (int i = 0; i < B; i++)
    {
        ii += S[i];
    }
    return ii;
}
int main(void) {
    int ans = -1;
    
    InputData();//�Է¹޴� �κ�
    Make_presum();  // presum �����
    int R = Sum_remain();
    
    ans=DFS(0,R);
    if (state_P == 0) { R_MAX = -1; }
    cout << R_MAX << endl;//����ϴ� �κ�
    return 0;
}