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
list<int> rot;  //방향 모다두는 곳
vector<int, vector<int>> All;  // 방향, index정보
vector<int> inner;

void InputData() {
    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> A[i] >> B[i];
        
        inner.push_back(i); //index i 담기
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
    InputData();// 입력받는 부분

    // 여기서부터 작성

    cout << ans << endl;// 출력하는 부분
    return 0;
}