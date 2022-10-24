#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;//������׷���
//int H[100000 + 10];//������׷� ����
struct info
{
    int h;
    int idx;
};
info STK;
vector<info> H;
vector<info> stack;
bool InputData() {
    cin >> N;
    long long temp;
    if (N == 0) return false;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        STK.h = temp;
        STK.idx = i;
        H.push_back(STK);
    }
    return true;
}
long long Solve()
{
    int idx = 0;
    int area = 0;
    int temp_area = 0;
    int sp = 0;
    info p;

    stack.push_back(p);          // sp=0 ���� �����ϴµ�, push�� �Ǹ鼭 sp ���� ==> while ������ �����߻�
                                // ���� stack�� [0]�� �� struct �����ϸ� ��������. 
    for (int i = 0; i <= N; i++) // �� ������ �ѹ� �� 0¥�� ���븦 �־��ָ鼭 ������ ���� ����
    {
        idx = i;
        while (!stack.empty() && (stack[sp].h > H[i].h))
        {
            temp_area = (H[i].idx - stack[sp].idx) * stack[sp].h;
            area = max(area, temp_area);
            H[i].idx = stack[sp].idx;
			stack.pop_back();
			sp--;
		}
        stack.push_back(H[i]);
        sp++;
    }
    return area;
}
int main() {
    long long ans = -1;
    while (InputData()) {//�Է¹޴� �κ�

        ans = Solve();

        cout << ans << endl;//����ϴ� �κ�
    }
    return 0;
}