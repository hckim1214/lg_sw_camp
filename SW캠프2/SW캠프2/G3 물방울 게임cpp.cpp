#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (100)
int A;
int N;
int W[MAXN + 10];
int W_ori[MAXN + 10];
int SKILL_MIN = 123456;
int temp1,temp2,temp3;
int flag;
void InputData() {
    SKILL_MIN = 123456;      // initialize
    fill(W, W + MAXN+1, 0);
    //fill(W_ori, W_ori + MAXN+1, 0);
    cin >> A >> N;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    sort(W, W + N/*sizeof(W[0])*/ );
    for (int i = 0; i < N; i++) { W_ori[i]=W[i];}
}
void DFS(int skill, int size, int trial)
{
	if (W[trial] == 0)  // trial 이 다끝나는 종료조건
	{
		SKILL_MIN = min(SKILL_MIN, skill);
//		if (SKILL_MIN == 0) { flag = 1; }
		return;
	}

    if (skill >= N)     // skill만 계속 쓰는 무한 루프 예방
    {
        SKILL_MIN = min(SKILL_MIN, skill);
//        if (SKILL_MIN == 0) { flag = 1; }
        return;
    }

    // 할 수 있는 것: 다 비교해보기, 스킬1: 자신 크기 -1 생성하고 흡수, 스킬2: 하나 삭제
    if (size > W[trial])
    {
        //cout << "0";
        temp1 = W[trial];
        W[trial] = 0;
        DFS(skill,size+ temp1,trial+1);
//        if (flag == 1) return;
        W[trial] = W_ori[trial];
    }

    //skill 1
   // cout << "1";
    else if (W[trial + 1] != 0)
    {
        temp2 = size;
        DFS(skill + 1, 2 * size - 1, trial);
//        if (flag == 1) return;
        size = temp2;
    }
    //skill 2
    //cout << "2";
    temp3 = W[trial];
    W[trial] = 0;
    DFS(skill+(N-trial), size, N);      // 한번 2번 스킬 선택하면 끝까지 2번 스킬 사용하는게 좋아
//    if (flag == 1) return;
}

int main() {
    int t, T;
    cin >> T;
    for (t = 1; t <= T; t++) {
        InputData();//입력받는 부분

        DFS(0,A,0);

        cout << "Case #" << t << ": " << SKILL_MIN << endl;//출력하는 부분
    }
    return 0;
}