#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>
#include <string.h>

using namespace std;
vector<int> C;

int N;//���� ��
long long A[100000 + 10];//���� ��ġ
long long B[100000 + 10];//���� ����� ��
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
    if (temp[N-1] >= child) return 1; // ����
    else return 0;
}
// binary search������ Ž���� �ִ� �ּ� ����ִ°� ���� ���̰� ����
// �������� �ִ븦 10�� ��°ŵ� ����
// 
// bianry 10, 5, 7, 3 ==> 1�� ���� ���;���????
// �����ϱ�
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
    InputData();//�Է¹޴� �κ�
    sort(C.begin(), C.end());
    ans = Solve();

    cout << ans << endl;//����ϴ� �κ�
    return 0;
}