#include <iostream>
#include<queue>
using namespace std;
int N, M;//문서수, 궁금한 문서 번호
int P[100 + 10];//문서 우선순위
struct Doc {
    int name;
    int selected;
};

Doc D[100 + 10];
int cnt_num[15];
queue<Doc> q;

void cnt_initialize()
{
    for (int i = 0; i < 15; i++)
    {
        cnt_num[i] = 0;
    }
}
void Doc_initialize()
{
    for (int i = 0; i < 105; i++)
    {
        D[i].name = 0;
        D[i].selected = 0;
    }
}
void InputData() {
    cin >> N >> M;
    Doc D[100 + 10] = {};
    cnt_initialize();
    while (!q.empty()) { q.pop(); }
    Doc_initialize();

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        cnt_num[P[i]] = cnt_num[P[i]] + 1;
        D[i].name = P[i];
        if (i == M) D[M].selected = 1;      // 처음 선택한 문서 표시
        q.push(D[i]);
    }
}
int Solve()
{
    int n = 0;
    int count = 0;
    Doc temp;
    int target = P[M];
    for (int i = 9; i > target; i--)        // 9~target+1 까지 우선순위 출력 처리
    {
        n = cnt_num[i];
        while (n > 0)
        {
            if (q.front().name == i) 
            { 
                n--; 
                count++; 
                q.pop();
				if (n == 0)
				{
					break;
				}
                continue;
			}
            temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    while (1)   // target~1 에서 선택문서 출력순서
    {
        if (q.front().name == target)   // target과 같은 우선순위
        {
            count++;
            if (q.front().selected == 1) { return count; }      // 선택 문서 출력
            else {
                q.pop();    // 앞쪽의 선택문서 출력
            }
        }
		else        // target보다 작은 문서들은 뒤쪽 우선순위로 배정
        {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
        
    }
}
int main() {
    int ans = -1;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        InputData();//입력받는 부분

        ans = Solve();

        cout << ans << endl;//출력하는 부분
    }
    return 0;
}