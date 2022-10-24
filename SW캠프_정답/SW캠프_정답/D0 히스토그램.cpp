#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;//히스토그램수
//int H[100000 + 10];//히스토그램 높이
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

    stack.push_back(p);          // sp=0 부터 시작하는데, push가 되면서 sp 증가 ==> while 문에서 오류발생
                                // 따라서 stack의 [0]에 빈 struct 대입하면 맞춰진다. 
    for (int i = 0; i <= N; i++) // 맨 마지막 한번 더 0짜리 막대를 넣어주면서 마지막 과정 수행
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
    while (InputData()) {//입력받는 부분

        ans = Solve();

        cout << ans << endl;//출력하는 부분
    }
    return 0;
}