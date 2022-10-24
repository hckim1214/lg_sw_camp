#include <iostream>
#include<list>
#include<vector>
using namespace std;

int K;
int A[6 + 10];
int B[6 + 10];
struct Point {
    int direct;
    int length;
};
Point path[12];
list<int> rot;  //���� ��ٵδ� ��
int DoubleCheck[2];
//vector<vector<int>> All;  // ����, index����

void InputData() {
    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> A[i] >> B[i];
        path[i].direct = A[i];
        path[i].length = B[i];
        if (find(rot.begin(), rot.end(), path[i].direct) == rot.end())
        {
            rot.push_back(path[i].direct);
        }
        else {
            for (int j = 0; j < 2; j++)
            {
                DoubleCheck[j] = i;
            }
        }
    }
}
int Solve()
{
    int large = 1;
    int small = 1;
	for (int i = 0; i < 6; i++)
	{
    //DoubleCheck�� ��ȯ���� index 
		if ((path[DoubleCheck[0]].direct != path[i].direct) && (path[DoubleCheck[1]].direct != path[i].direct) )
		{
            large *= path[i].length;
            if ((i - 1) < 0) i = i + 6;
            if ((i + 1) > 6) i = i - 6;
            small *=(max(path[i - 1].length, path[i + 1].length) - min(path[i - 1].length, path[i + 1].length));
		}
	}
    return large - small;
}

int main() {
    int ans = -1;
    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}