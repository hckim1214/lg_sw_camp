#include <iostream>

using namespace std;

#define MAXN (100)
int L;//���� ���� �ʰ� �����ִ� �ִ�Ÿ�
int N;//����� ����
int dist[MAXN + 10];//����һ��̰Ÿ�
int times[MAXN + 10];//����ð�
void InputData() {
    cin >> L;
    cin >> N;
    for (int i = 1; i <= N + 1; i++) {
        cin >> dist[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> times[i];
    }
}

int main() {
    InputData();//�Է� �޴� �κ�

    //���⼭���� �ۼ�

    return 0;
}