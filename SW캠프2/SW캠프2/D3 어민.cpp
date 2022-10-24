#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>
#include <string.h>

using namespace std;
vector<int> C;

int N;//마을 수
long long A[100000 + 10];//마을 위치
long long B[100000 + 10];//잡힌 물고기 양
long long temp[100000 + 10];
int child;

int s;
int e;
int m;


void InputData() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &A[i], &B[i]);
        C.push_back(B[i]);
    }
}
int Is_Possible()
{
    long long remain = 0;
    long long distance = 0;
    memcpy(temp, B, sizeof(B));
    //int k = sizeof(B);
    //copy(B, B + sizeof(B), temp);
    for (int i = 0; i <N - 1; i++)
    {
        remain = temp[i] - child;
        distance = A[i + 1] - A[i];
		if (remain > 0)
		{
			if (remain < distance) continue;
            temp[i + 1] = temp[i + 1] + remain - (distance);
        }
        if (remain < 0)
        {
            temp[i + 1] = temp[i + 1] + remain - distance;
        }
        temp[i] = child;
    }
    if (temp[N-1] >= child) return 1; // 성공
    else return 0;
}
// binary search에서는 탐색의 최대 최소 잡아주는게 별로 차이가 없어
// 마음편히 최대를 10억 잡는거도 좋아
// 
// bianry 10, 5, 7, 3 ==> 1로 답이 나와야해????
// 질문하기
int Solve()
{
    s = C[0];
    e = C[C.size()-1];
    while (s <= e)
    {
        m = (s + e) / 2;
        child = m;
        int res = Is_Possible();
        if (res == 1)
        {
            s = m+1;
        }
        if (res == 0)
        {
            e = m - 1;
        }
    }
    return e;
}
int main() {
    int ans = -1;
    InputData();//입력받는 부분
    sort(C.begin(), C.end());
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}