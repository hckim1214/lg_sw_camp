#include <iostream>
#include <vector>
using namespace std;
char map[5][10];
struct info
{
	int y;
	int x;
};
info P;
vector<info> M;
vector<info> Blank;

int num;
int visited[20];
int temp;
bool ans;
int Atoint(char c)
{
	if (c == 'x') return 0;
	return c - '@';
}
void InputData() {
	P.x = 0;
	P.y = 0;
	M.push_back(P);	//	M[0]에 공백 push
	for (int h = 0; h < 5; h++) {
		cin >> map[h];
		for (int i = 0; i < 10; i++)
		{
			if (map[h][i] != '.' && map[h][i] != '\0')
			{
				temp = Atoint(map[h][i]);
				if(temp!=0) visited[temp] = 1;
				P.y = h;
				P.x = i;
				M.push_back(P);

				if (map[h][i] == 'x') Blank.push_back(P);
			}
		}
	}
}
void OutputData() {
	for (int h = 0; h < 5; h++) {
		cout << map[h] << endl;
	}
}
bool Check()
{
	int state = 0;
	int star1 = Atoint(map[M[1].y][M[1].x]), star2 = Atoint(map[M[2].y][M[2].x]), star3 = Atoint(map[M[3].y][M[3].x]), star4 = Atoint(map[M[4].y][M[4].x]);
	int star5 = Atoint(map[M[5].y][M[5].x]), star6 = Atoint(map[M[6].y][M[6].x]), star7 = Atoint(map[M[7].y][M[7].x]), star8 = Atoint(map[M[8].y][M[8].x]);
	int star9 = Atoint(map[M[9].y][M[9].x]), star10 = Atoint(map[M[10].y][M[10].x]), star11 = Atoint(map[M[11].y][M[11].x]), star12 = Atoint(map[M[12].y][M[12].x]);

	if (star1+star3+star6+star8 != 26) return state;
	if (star1 + star4 + star7 + star11 != 26) return state;
	if (Atoint(map[M[2].y][M[2].x]) + Atoint(map[M[3].y][M[3].x]) + Atoint(map[M[4].y][M[4].x]) + Atoint(map[M[5].y][M[5].x]) != 26) return state;
	if (Atoint(map[M[2].y][M[2].x]) + Atoint(map[M[6].y][M[6].x]) + Atoint(map[M[9].y][M[9].x]) + Atoint(map[M[12].y][M[12].x]) != 26) return state;
	if (Atoint(map[M[5].y][M[5].x]) + Atoint(map[M[7].y][M[7].x]) + Atoint(map[M[10].y][M[10].x]) + Atoint(map[M[12].y][M[12].x]) != 26) return state;
	if (Atoint(map[M[8].y][M[8].x]) + Atoint(map[M[9].y][M[9].x]) + Atoint(map[M[10].y][M[10].x]) + Atoint(map[M[11].y][M[11].x]) != 26) return state;
	state = 1;
	return state;
}
void DFS(int n)
{

	if (n >= Blank.size())
	{
		ans=Check();
		if(ans==1) //OutputData();
		return;
	}

	// 알파벳 체우기
	for (int i =1; i <= 12; i++)
	{
		if (visited[i] == 0)		// 넣는 숫자 1부터 시작하니까
		{
			visited[i] = 1;
			map[Blank[n].y][Blank[n].x] = (char)(i+'@');
			DFS(n + 1);
			visited[i] = 0;
			if (ans == 1) return;
		}
		if (ans == 1) break;
	}
}
int main() {
	InputData();//입력받는 부분

	DFS(0);

	OutputData();//출력하는 부분
	return 0;
}