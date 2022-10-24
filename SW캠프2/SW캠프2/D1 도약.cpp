#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;//���ټ�
int A[1000 + 10];//������ǥ
vector<int> P;
bool cmp(int a, int b)
{
    return a < b;
}
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        P.push_back(A[i]);
    }
    sort(P.begin(), P.end(), cmp);
}
int Solve()
{
    int S = P.size();
    int cnt = 0;
    int first_jump = 0;
    for (int i = 0; i < S-2; i++)
    {   
        for (int j = i+1; j < S-1; j++)
        {
            first_jump = P[j] - P[i];
            for (int k = j + 1; k < S; k++)
            {
                if (k > S) break;
                if ((P[j] + first_jump <= P[k]) && (P[k] <= P[j] + 2*first_jump))
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

// ���� Ž������ Ư�� ����ã�� �� �غ���
int main() {
    int ans = -1;
    InputData();//�Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;//����ϴ� �κ�
    return 0;
}