#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, L;
vector<int> X; // 사대
int s, m, e;
struct Range
{
    int x_low;
    int x_high;
};
Range ans;

struct Point {
    int x;
    int y;
};
Point P;
vector<Point> Save;

bool cmp(Point& a,Point& b)
{
    return a.x < b.x;
}
void InputData() {
    int x;
    int a, b;
    cin >> M >> N >> L;
    for (int i = 0; i < M; i++) {
        cin >> x;
        X.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        cin >> a >> b;  // x,y좌표는 P struct로 묶어서 Save라는 벡터에 보관
        P.x = a;
        P.y = b;
        Save.push_back(P);
    }
    sort(X.begin(),X.end());
    sort(Save.begin() , Save.end(),cmp);
}
Range BinarySearch(int target)   //target= A[0],A[1]....
{
    // Initialize
    s = 0;
    e = X.size() - 1;
    ans.x_high = 0;
    ans.x_low = 0;
    int value_X;

    while (s + 1 < e)
    {
        m = (s + e) / 2;
        value_X = X[m];
        if (target < X[m])
        {
            e = m;
        }
        else if (target > X[m])
        {
            s = m;
        }
        else { s = e = m; break; }
        // target==X[m] 
    }

    ans.x_low = s;
    ans.x_high = e;
    return ans;
}

int Solve()
{
    int cnt = 0;
    int Xrange = 0;
    for (int i = 0; i < Save.size(); i++)
    {
        Xrange = L - Save[i].y;
        if (Xrange < 0) continue;

         ans= BinarySearch(Save[i].x);

         if (Save[i].x>X[X.size()-1])      // 가장 큰 사로보다 X좌표가 큰 동물
         {
             if (Save[i].x - Xrange <= X[X.size() - 1])
             {
                 cnt++;
                 continue;
             }
         }
         else if (Save[i].x < X[0])      // 가장 작은 사로보다 X좌표가 작은 동물
         {
             if (Save[i].x + Xrange >= X[0])
             {
                 cnt++;
                 continue;
             }
         }

         else if (Save[i].x - Xrange <= X[ans.x_low] &&  X[ans.x_low] <= Save[i].x + Xrange) // 범위 안에 사로가 있는 경우
         {
             cnt++;
         }
         else if (Save[i].x - Xrange <= X[ans.x_high] && X[ans.x_high] <= Save[i].x + Xrange) // 범위 안에 사로가 있는 경우
         {
             cnt++;
         }
         // 아닌 원인 파악
         //if (Save[i].x - Xrange <= X[ans.x_low] || Save[i].x + Xrange >= X[ans.x_high]) // 범위 안에 사로가 있는 경우
         //{
         //    cnt++;
         //}
    }
    return cnt;
}
int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}

// 사냥감 기준 L 범위 안에 사대가 있는지 검사

// 사냥꾼 정답에서 index 접근?? ==> index중에서 해당 값보다 큰 값 찾는 binary search

// 사냥꾼 어민 질문