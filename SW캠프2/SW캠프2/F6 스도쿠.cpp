#include <iostream>
using namespace std;
#define MAXN (9)
int sudoku[MAXN][MAXN];//��������
struct POS {
    int r, c;//����, ����
};
POS A[MAXN * MAXN];//��ĭ ��ǥ
int N;//��ĭ ����
#if 0
bool isPossible(int r, int c, int num) {
    //1.������ & ������ üũ
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == num) return false;//�Ұ�
        if (sudoku[i][c] == num) return false;//�Ұ�
    }
    //2.(r,c)���Ե� ���� �簢�� üũ
    int sr = r / 3 * 3, sc = c / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[sr + i][sc + j] == num) return false;//�Ұ�
        }
    }
    return true;//����
}
int DFS(int n) {
    if (n >= N) return 1;//��� ��ĭ ä����, ����
    int r = A[n].r, c = A[n].c;//n��° ��ĭ�� ��ǥ
    for (int i = 1; i <= 9; i++) {
        if (!isPossible(r, c, i)) continue;//[r][c]=i ��� �Ұ�
        sudoku[r][c] = i;//ǥ��
        if (DFS(n + 1) == 1) return 1;//���� ����
        sudoku[r][c] = 0;//ǥ������
    }
    return 0;//����
}
void Solve() {
    //1.��ĭ ��ǥ�� A�迭 �����ϱ�
    N = 0;
    for (int r = 0; r < MAXN; r++) {
        for (int c = 0; c < MAXN; c++) {
            if (sudoku[r][c] == 0) {
                A[N].r = r; A[N].c = c; N++;
            }
        }
    }
    //2.��� ��� �غ���
    DFS(0);
}
#else
int col[9][10];//[c][����]=��뿩��
int row[9][10];//[r][����]=��뿩��
int rect[9][10];//[r/3*3+c/3][����]=��뿩��
int DFS(int n) {
    if (n >= N) return 1;//��� ��ĭ ä����, ����
    int r = A[n].r, c = A[n].c;//n��° ��ĭ�� ��ǥ
    for (int i = 1; i <= 9; i++) {
        if (col[c][i] == 1) continue;
        if (row[r][i] == 1) continue;
        if (rect[r / 3 * 3 + c / 3][i] == 1) continue;
        col[c][i] = row[r][i] = rect[r / 3 * 3 + c / 3][i] = 1;//ǥ��
        sudoku[r][c] = i;//ǥ��
        if (DFS(n + 1) == 1) return 1;//���� ����
        sudoku[r][c] = 0;//ǥ������
        col[c][i] = row[r][i] = rect[r / 3 * 3 + c / 3][i] = 0;//ǥ������
    }
    return 0;//����
}
void Solve() {
    //1.��ĭ ��ǥ�� A�迭 �����ϱ�
    N = 0;
    for (int r = 0; r < MAXN; r++) {
        for (int c = 0; c < MAXN; c++) {
            if (sudoku[r][c] == 0) {
                A[N].r = r; A[N].c = c; N++;
            }
            else {
                int k = sudoku[r][c];//����
                col[c][k] = 1;
                row[r][k] = 1;
                rect[r / 3 * 3 + c / 3][k] = 1;
            }
        }
    }
    //2.��� ��� �غ���
    DFS(0);
}
#endif
void InputData() {
    for (int r = 0; r < MAXN; r++) {
        for (int c = 0; c < MAXN; c++) {
            cin >> sudoku[r][c];
        }
    }
}
void OutputData() {
    for (int r = 0; r < MAXN; r++) {
        for (int c = 0; c < MAXN; c++) {
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}
int main() {
    InputData();
    Solve();
    OutputData();
    return 0;
}
