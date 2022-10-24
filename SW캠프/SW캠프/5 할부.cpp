#include <iostream>
#include <vector>
using namespace std;

int N, B;
int solmin, solmax;
vector<int> pay;

void InputData() {
    cin >> N >> B;
}
void split()
{
    int basic;
    int remain = 0;
    basic = B / (N - 1);
    remain = B - (N - 1) * basic;

    for (int i = 0; i < N - 1; i++)
    {
        pay.push_back(basic);
    }
    if (remain == 0)
    {
        solmin = N * pay[0] - 1;
        solmax = solmin + 1;
    }
    if (remain > 0)
    {
        for (int j = N - 2; j > 0; j--)
        {
            pay[j] = pay[j] + 1;
            --remain;
            if (remain == 0) break;
        }
        solmin = solmax = B + pay[0];
    }


}

int main() {
    InputData();// 입력받는 부분

    split();

    cout << solmin << " " << solmax;// 출력하는 부분
    return 0;
}