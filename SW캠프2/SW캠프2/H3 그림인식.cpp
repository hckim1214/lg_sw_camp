#include <iostream>
#include <algorithm>
using namespace std;

int N;//도화지 크기
char A[10 + 2][10 + 2];//도화지 색정보
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int nx, ny;
struct info
{
	int min_x = 99;
	int max_x;
	int min_y = 99;
	int max_y;
};
struct info C[12];
char num;
int Changed_num = 0;
int state[12];
void InputData() {
	cin >> N;
	for (int j = 0; j < N; j++)
	{
		cin >> A[j];
		for (int i = 0; i < N; i++)
		{
			num = A[j][i];
			Changed_num = (int)(num - '0');
			C[Changed_num].min_x = min(C[Changed_num].min_x, i);
			C[Changed_num].max_x = max(C[Changed_num].max_x, i);
			C[Changed_num].min_y = min(C[Changed_num].min_y, j);
			C[Changed_num].max_y = max(C[Changed_num].max_y, j);
		}
	}
	for (int oo = 0; oo < 10; oo++)
	{
		state[oo] = 1;
	}
}
void print_st()
{
	for (int j = 0; j < 10; j++)
	{
		cout << j << " min_x is " << C[j].min_x << " max_x is " << C[j].max_x << " min_y is " << C[j].min_y << " max_y is " << C[j].max_y << endl;
	}
}
int Find_left()
{
	int cnt = 0;
	for (int ii = 1; ii < 10; ii++)
	{
		//cout << ii<<" "<<state[ii]<<endl;
		if (state[ii] == 1)
		{
			cnt++;
		}
	}
	return cnt;
}
int Solve()
{
	int ans = 0;
	//print_st();
	//ans=Find_left();
	for (int k = 1; k < 10; k++)
	{
		if (C[k].min_x == 99) { state[k] = 0; continue; } //도화지에 나오지 않은 색
		//cout<<endl<<k<<" 일 떄";
		for (int y_p = C[k].min_y; y_p <= C[k].max_y; y_p++)
		{
			for (int x_p = C[k].min_x; x_p <= C[k].max_x; x_p++)
			{
				if (A[y_p][x_p] != (char)(k + '0'))		// k일 때 A[y_p][x_p] 검사하는 칸
				{
					state[(int)(A[y_p][x_p] - '0')] = 0;
				}
			}
		}
		//cout<<state[k]<<endl;
	}
	ans = Find_left();
	return ans;
}

int main() {
	int ans = -1;
	InputData();//	입력 함수

	ans = Solve();

	cout << ans << endl;//출력
	return 0;
}
