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
    sort(V.begin(), V.end(), cmp);      // 끝나는 날 기준으로 소트
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
        if (iter >= V.size()) { return 0; }     //  11/30 까지 피는 꽃이 없는 경우
        else if (V[iter].end < 301) { iter++; continue; }       // 3월 1일 이전 꽃 무시
        else if ((V[iter].start < E) && (E<V[iter].end))        // 다음 꽃 기간이 전 꽃의 end 지점을 포함하는 경우
        {
            temp_S = V[iter].start;
            temp_E = max(V[iter].end,temp_E);
            iter++;
        }
        else	// 포함하지 못할 시 가장 최근에 포함한 범위
        {
            S = temp_S;
            E = temp_E;
            cnt++;
            if (E <= V[iter].start)      // 정원의 꽃이 없는 경우라면
            {
                return 0;       // 실패하는 경우
            }
        }

    }
    return cnt+1;
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}