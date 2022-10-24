#include <iostream>
#include<algorithm>
using namespace std;


struct Point {
    int direct;
    int length;
    int idx;
};
int K;
int A[6 + 10];
int B[6 + 10];
Point path[12];
int max_index = 0;
void InputData() {
    cin >> K;
    int max_val = 0;
    
    for (int i = 0; i < 6; i++) {
        cin >> A[i] >> B[i];
        path[i].direct = A[i];
        path[i].length = B[i];
        if (max_val < B[i])
        {
            max_val = B[i];
            max_index = i;
        }
    }
}
int Solve()
{
    int large = 1;
    int small = 1;
    int U, P;
    U = max_index - 1;
    P = max_index + 1;
    if (U < 0) U = max_index + 5;
    if (P > 6) P = max_index - 5;
    if (path[U].length < path[P].length)
    {
        large = path[max_index].length * path[P].length;
        small = path[(max_index + 3) % 6].length * path[(max_index + 4) % 6].length;
    }
    if (path[U].length > path[P].length)
    {
        large = path[max_index].length * path[U].length;
        small = path[(max_index + 2) % 6].length * path[(max_index + 3) % 6].length;
    }
    /*if (path[(max_index - 1) % 6].length < path[(max_index + 1) % 6].length)
    {
        large = path[max_index].length * path[(max_index + 1) % 6].length;
        small = path[(max_index + 3) % 6].length * path[(max_index + 4) % 6].length;
    }
    if (path[(max_index - 1) % 6].length > path[(max_index + 1) % 6].length)
    {
        large = path[max_index].length * path[(max_index - 1) % 6].length;
        small = path[(max_index + 2) % 6].length * path[(max_index + 3) % 6].length;
    }*/
    return (large - small)*K;
}

int main() {
    int ans = -1;
    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}