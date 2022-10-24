#include <iostream>

using namespace std;

#define MAXN ((int)1e5)
#define MAXH ((int)1e9)

typedef long long s64;

//FA stack
struct STK {
    int h, n;//����, �ε���
};

int N;//���簢�� ��
int H[MAXN + 10];//���簢�� ����
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
        int n = i;//i�� ���簢���� �ʱ� �ε���

        //1.���ÿ� ����� ���̰� i�� ���� ���ų� ������ ����
        while (!empty() && (top().h >= H[i])) {
            n = top().n;//�ε��� �������
            area = (s64)top().h * (i - n);
            if (maxarea < area) maxarea = area;
            pop();
        }

        //2.i�� ���簢�� ���ÿ� ����
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
    while (InputData()) {       //�Է¹޴� �κ�
        //s64 ans = SolveN2();
        s64 ans = Solve();
        cout << ans << endl;    //����ϴ� �κ�
    }
    return 0;
}