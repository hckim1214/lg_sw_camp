#include <iostream>
using namespace std;
#define MAXN (9)
int sudoku[MAXN][MAXN];//스도쿠판
struct POS {
    int r, c;//세로, 가로
};
POS A[MAXN * MAXN];//빈칸 좌표
int N;//빈칸 개수
#if 0
bool isPossible(int r, int c, int num) {
    //1.가로줄 & 세로줄 체크
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == num) return false;//불가
        if (sudoku[i][c] == num) return false;//불가
    }
    //2.(r,c)포함된 작은 사각형 체크
    int sr = r / 3 * 3, sc = c / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[sr + i][sc + j] == num) return false;//불가
        }
    }
    return true;//가능
}
int DFS(int n) {
    if (n >= N) return 1;//모든 빈칸 채웠음, 성공
    int r = A[n].r, c = A[n].c;//n번째 빈칸의 좌표
    for (int i = 1; i <= 9; i++) {
        if (!isPossible(r, c, i)) continue;//[r][c]=i 사용 불가
        sudoku[r][c] = i;//표시
        if (DFS(n + 1) == 1) return 1;//성공 리턴
        sudoku[r][c] = 0;//표시제거
    }
    return 0;//실패
}
void Solve() {
    //1.빈칸 좌표를 A배열 저장하기
    N = 0;
    for (int r = 0; r < MAXN; r++) {
        for (int c = 0; c < MAXN; c++) {
            if (sudoku[r][c] == 0) {
                A[N].r = r; A[N].c = c; N++;
            }
        }
    }
    //2.모든 경우 해보기
    DFS(0);
}
#else
int col[9][10];//[c][숫자]=사용여부
int row[9][10];//[r][숫자]=사용여부
int rect[9][10];//[r/3*3+c/3][숫자]=사용여부
int DFS(int n) {
    if (n >= N) return 1;//모든 빈칸 채웠음, 성공
    int r = A[n].r, c = A[n].c;//n번째 빈칸의 좌표
    for (int i = 1; i <= 9; i++) {
        if (col[c][i] == 1) continue;
        if (row[r][i] == 1) continue;
        if (rect[r / 3 * 3 + c / 3][i] == 1) continue;
        col[c][i] = row[r][i] = rect[r / 3 * 3 + c / 3][i] = 1;//표시
        sudoku[r][c] = i;//표시
        if (DFS(n + 1) == 1) return 1;//성공 리턴
        sudoku[r][c] = 0;//표시제거
        col[c][i] = row[r][i] = rect[r / 3 * 3 + c / 3][i] = 0;//표시제거
    }
    return 0;//실패
}
void Solve() {
    //1.빈칸 좌표를 A배열 저장하기
    N = 0;
    for (int r = 0; r < MAXN; r++) {
        for (int c = 0; c < MAXN; c++) {
            if (sudoku[r][c] == 0) {
                A[N].r = r; A[N].c = c; N++;
            }
            else {
                int k = sudoku[r][c];//숫자
                col[c][k] = 1;
                row[r][k] = 1;
                rect[r / 3 * 3 + c / 3][k] = 1;
            }
        }
    }
    //2.모든 경우 해보기
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
