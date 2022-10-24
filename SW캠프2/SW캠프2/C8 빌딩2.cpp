#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N;//빌딩수
int H[100000 + 10];//빌딩높이
int sol[100000 + 10];//각 빌딩에서 보이는 빌딩 번호
vector<struct info> cmp_list;
struct info
{
    int height;
    int idx;
};
info inner[100000 + 10];
void InputData()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
        //scanf("%d", &H[i]);
        inner[i].height = H[i];
        inner[i].idx = i;
    }
}

void OutputData() {
    for (int i = 1; i <= N; i++) {
        cout << sol[i] << '\n';
    }
}
void Solve()
{
    //cmp_list.push_back(inner[1]);
    for (int i = 1; i <= N-1; i++)
    {
        cmp_list.push_back(inner[i]);
        int size_vec = cmp_list.size();
        for (int j = size_vec; j > 0; j--)
        {
            if (cmp_list[j-1].height >= H[i+1])
            {
                cmp_list.push_back(inner[i+1]);
                break;
            }
            else
            {
                sol[cmp_list[j-1].idx] = i+1;
                cmp_list.pop_back();
            }
            //cmp_list.push_back(inner[i]);
        }
    }
}

int main() {
    InputData();//입력받는 부분

    Solve();

    OutputData();//출력하는 부분
    return 0;
}
