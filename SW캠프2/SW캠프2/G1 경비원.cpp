#include <iostream>
#include <cmath>
using namespace std;

int w, h, n;
int dir[100 + 10];
int len[100 + 10];
int loc[100 + 10];
void InputData() {
    cin >> w >> h;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> dir[i] >> len[i];
    }   // ������: dir[n] len[n]
}

// �� �ٷ� ����� ��� 1 4 2 3
// dir[i] == 1 �� ��� line��ġ: len[n]
// dir[i] == 2 �� ��� line��ġ: 2*w+h-len[n]
// dir[i] == 3 �� ��� line��ġ: 2*w+2*h-len[n]
// dir[i] == 4 �� ��� line��ġ: w+len[n]
int Transform(int D, int L)
{
    int line = 0;
    switch (D)
    {
    case 1:
        line = L;
        break;
    case 2:
        line = 2 * w + h - L;
        break;
    case 3:
        line = 2 * w + 2 * h - L;
		break;
	case 4:
		line = w + L;
		break;

    }
    return line;
}
int Solve()
{
    int iter = 0;
    int dis = 0;
    int loc = 0;
    int ab_loc = 0;

    int tot = 0;
    int Dong = Transform(dir[n], len[n]);

    //cout << "Dong is " << Dong << endl;
    for (iter = 0; iter < n; iter++)
    {
        loc = Transform(dir[iter], len[iter]);
        //cout << "---------" << loc << endl;
        ab_loc = abs(Dong - loc);
        dis = min(ab_loc, 2 * w + 2 * h - ab_loc);
       // cout << dis << endl;
        tot += dis;
    }
    return tot;
}
int main() {
    int ans = -1;

    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}