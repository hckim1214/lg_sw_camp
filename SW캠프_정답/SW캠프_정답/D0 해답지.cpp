#include <iostream>

using namespace std;

#define MAXN ((int)1e5)
#define MAXH ((int)1e9)

typedef long long s64;

//FA stack
struct STK {
    int h, n;//높이, 인덱스
};

int N;//직사각형 수
int H[MAXN + 10];//직사각형 높이
STK stack[MAXN + 10];

int sp;

void push(int h, int n) {
    stack[++sp].h = h; stack[sp].n = n;
}

STK top() { return stack[sp]; }

void pop() { sp--; }

int size() { return sp; }

bool empty() { return sp == 0; }

s64 Solve() {
    s64 maxarea = 0, area;
    sp = 0;//stack init
    for (int i = 0; i < N; i++) {
        int n = i;//i번 직사각형의 초기 인덱스

        //1.스택에 저장된 높이가 i번 보다 높거나 같으면 제거
        while (!empty() && (top().h >= H[i])) {
            n = top().n;//인덱스 뺏어오기
            area = (s64)top().h * (i - n);
            if (maxarea < area) maxarea = area;
            pop();
        }

        //2.i번 직사각형 스택에 저장
        push(H[i], n);
    }

    while (!empty()) {
        area = (s64)top().h * (N - top().n);
        if (maxarea < area) maxarea = area;
        pop();
    }

    return maxarea;
}

bool InputData() {
    cin >> N;
    if (N == 0) return false;

    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    return true;
}

s64 SolveN2() {
    s64 maxarea = 0, area;
    for (int s = 0; s < N; s++) {
        int h = MAXH;
        for (int k = s; k < N; k++) {
            if (h > H[k]) h = H[k];
            if (h == 0) break;
            area = (s64)h * (k - s + 1);
            if (maxarea < area) maxarea = area;
        }
    }
    return maxarea;
}

int main() {
    while (InputData()) {       //입력받는 부분
        //s64 ans = SolveN2();
        s64 ans = Solve();
        cout << ans << endl;    //출력하는 부분
    }
    return 0;
}