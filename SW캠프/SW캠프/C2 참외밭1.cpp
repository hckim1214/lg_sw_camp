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
    int idx;
};
Point path[12];
list<int> rot;  //���� ��ٵδ� ��
vector<int, vector<int>> All;  // ����, index����
vector<int> inner;

void InputData() {
    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> A[i] >> B[i];
        
        inner.push_back(i); //index i ���
        All.push_back(A[i]);
        All.push_back(inner);

        if (find(rot.begin(), rot.end(), path[i].direct) == rot.end())
        {
            rot.push_back(path[i].direct);
        }
        else {
            for (int i = 0; i < 2; i++)
            {
                DoubleCheck[i]
            }
        }
    }
}

int main() {
    int ans = -1;
    InputData();// �Է¹޴� �κ�

    // ���⼭���� �ۼ�

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}