#include <iostream>
using namespace std;

int N;
char A[20000 + 10];
int state = 0;
void InputData() {
    cin >> N >> A;
}
void Solve()
{
    int i = 0;
    state = 0;
    while (A[i]!='\0')
    {
        if (A[i] == '<') state++;
        else if (A[i] == '>') state--; 
        else
        {
            if (state == N)
            {
                cout << A[i];
                if ((A[i + 1] == '<') || (A[i + 1] == '>')) cout << " ";
            }
        }
        i++;
    }

}

int main() {
    InputData();// 입력받는 부분

    Solve();

    return 0;
}