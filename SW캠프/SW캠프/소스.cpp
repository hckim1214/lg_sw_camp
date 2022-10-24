#include <iostream>

using namespace std;

int main()
{
    char c[200];
    cin >> c;
    int balance = 0;
    for (int i = 0; c[i]; i++)
    {
        if (c[i] == '(') balance++;
        else balance--;
    }
    cout << balance;

    return 0;
}
