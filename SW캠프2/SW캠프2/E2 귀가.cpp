#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define INF (10000000000)
int P;
char N1[10000 + 10];
char N2[10000 + 10];
char Combined1[20000 + 20];
char Combined2[20000 + 20];
int Combined3[20000 + 20];
int L[10000 + 10];
char farm;
int sol;
int visited[126];
struct info
{
    char name;
    char cur_loc;
    int dist;
};
info Cow;
queue<info> q;

void InputData() {
    cin >> P;
    for (int i = 0; i < P; i++) {
        cin >> N1[i] >> N2[i] >> L[i];
        if (65<=N1[i] && N1[i]<=89)
        {
            Cow.name = N1[i];
            Cow.cur_loc = N1[i];
            Cow.dist = 0;
            q.push(Cow);
        }
        if (65 <= N2[i] && N2[i] <= 89)
        {
            Cow.name = N2[i];
            Cow.cur_loc = N2[i];
            Cow.dist = 0;
            q.push(Cow);
        }
    }
}
void initialize()
{
    fill(&visited[0], &visited[126], INF);
    for (int i = 0; i <= P-1; i++)
    {
        Combined1[i] = N1[i];
        Combined2[i] = N2[i];
        Combined3[i] = L[i];
    }
    strcat(Combined1, N2);
    strcat(Combined2, N1);
    for (int j=P; j <= 2*P - 1; j++)
    {
        Combined3[j] = L[j-P];
    }
}
void Solve()
{
    info now;
    info temp;
    int ntime;
    sol=INF;
    
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        
       for (int i = 0; Combined1[i]; i++)
       {
           ntime = 0;
           if (now.cur_loc == Combined1[i])                // 전 이동의 도착목장이 다음 이동의 시작목장
           {
               ntime = now.dist + Combined3[i];              // 그 전 목장에서부터 현재 목장까지 시간
               if (ntime >= visited[Combined2[i]]) continue; // N2[i] 현재 종착 목장
               temp.name = now.name;
               temp.cur_loc = Combined2[i];
               temp.dist = ntime;
               visited[Combined2[i]] = ntime;
               q.push(temp);

               if (Combined2[i] == 'Z')                    // 헛간 들어가는 경우
               {
                   if (sol > ntime)
                   {
                       sol = ntime;
                       farm = now.name;
                   }
               }
           }
        }
    }
    
}
int main() {
    InputData();// 입력받는 부분
    initialize();
    Solve();

    cout << farm << " " << sol << endl;// 출력하는 부분
    return 0;
}