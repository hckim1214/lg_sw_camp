#include <iostream>
#include <vector>
using namespace std;
int N;//히스토그램수
int H[100000 + 10];//히스토그램 높이
struct info
{
    long long height;
    int point;
};
info inner[100000 + 10];
vector<info> stack;
bool InputData() {
    cin >> N;
    if (N == 0) return false;

    for (int i = 0; i < N; i++) {
        cin >> H[i];
        inner[i].height = H[i];
        inner[i].point = i;
    }
    return true;
}
int Solve()
{
    long long max_area = 0;
    long long temp_area = 0;
    for (int i =0 ; i < N; i++)
    {
        if (stack.empty())
        {
            //inner[i].point = temp;
            stack.push_back(inner[i]);
            continue;
        }
        int size_stack= stack.size() - 1;
        //vector<int> PP;
        for (int j = size_stack; j >= 0; j--)
        {
            //PP.push_back(stack[j].point);
            if (stack[j].height > inner[i].height)
            {
                temp_area = stack[j].height * (inner[i].point - stack[j].point);
                max_area = max(max_area, temp_area);
                //inner[i].point = stack[j].point;
                stack.pop_back();
            }
            else if (stack[j].height == inner[i].height)
            {
                inner[i].point = stack[j].point;
                stack.pop_back();
                stack.push_back(inner[i]);
            }
            else
            {
                //inner[i].point = temp;
                stack.push_back(inner[i]);
                break;
            }
        }
    }
    for (int k = stack.size() - 1; k >= 0; k--)
    {
        temp_area= stack[k].height * (N - stack[k].point+1);
        max_area = max(max_area, temp_area);
    }
    return max_area;
}
int main() {
    long long ans = -1;
    while (InputData()) {//입력받는 부분

        ans = Solve();

        cout << ans << endl;//출력하는 부분
    }
    return 0;
}