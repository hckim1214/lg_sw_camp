#include <iostream>
#include<queue>
using namespace std;
int N, M;//������, �ñ��� ���� ��ȣ
int P[100 + 10];//���� �켱����
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
        if (i == M) D[M].selected = 1;      // ó�� ������ ���� ǥ��
        q.push(D[i]);
    }
}
int Solve()
{
    int n = 0;
    int count = 0;
    Doc temp;
    int target = P[M];
    for (int i = 9; i > target; i--)        // 9~target+1 ���� �켱���� ��� ó��
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
    while (1)   // target~1 ���� ���ù��� ��¼���
    {
        if (q.front().name == target)   // target�� ���� �켱����
        {
            count++;
            if (q.front().selected == 1) { return count; }      // ���� ���� ���
            else {
                q.pop();    // ������ ���ù��� ���
            }
        }
		else        // target���� ���� �������� ���� �켱������ ����
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
        InputData();//�Է¹޴� �κ�

        ans = Solve();

        cout << ans << endl;//����ϴ� �κ�
    }
    return 0;
}