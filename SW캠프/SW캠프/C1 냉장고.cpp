#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int N;
int X[100 + 10];
int Y[100 + 10];
struct Property
{
    int x, y;
};
Property Prop[100+10];

bool cmp(Property a,Property b)
{
    return a.x < b.x;
}
void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        Prop[i].x = X[i];
        Prop[i].y = Y[i];
    }
    sort(Prop, Prop+N, cmp);
}
int Solve()
{
    int start = Prop[0].x;
    int end = Prop[0].y;
    int cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        if (Prop[i].x <= end) {
            start = max(start, Prop[i].x);
            end = min(end, Prop[i].y);
        }
        else {
            cnt++;
            start = Prop[i].x;
            end = Prop[i].y;
        }
    }
    return cnt;
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}