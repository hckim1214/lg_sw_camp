#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, P;
void InputData() {
    cin >> N >> P;
}
int Solve()
{
    vector<int> num(1000);
    num[0] = (N * N) % P;
    int iter = 0;
    int i = 1;
    while (iter<999)
    {
        num[iter + 1] = (num[iter] * N) % P;
        iter++;
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
   
    return num.size(); 
}

int main() {
    int ans = -1;
    InputData();// 입력받는 부분

    ans = Solve();
    cout << ans << endl;// 출력하는 부분
    return 0;
}