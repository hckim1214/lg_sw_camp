#include <iostream>

using namespace std;

#define MAXN (100)
int L;//정비를 받지 않고 갈수있는 최대거리
int N;//정비소 개수
int dist[MAXN + 10];//정비소사이거리
int times[MAXN + 10];//정비시간
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
    InputData();//입력 받는 부분

    //여기서부터 작성

    return 0;
}