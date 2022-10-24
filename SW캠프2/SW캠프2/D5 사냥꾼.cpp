#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, L;
vector<int> X; // ���
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
        cin >> a >> b;  // x,y��ǥ�� P struct�� ��� Save��� ���Ϳ� ����
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

         if (Save[i].x>X[X.size()-1])      // ���� ū ��κ��� X��ǥ�� ū ����
         {
             if (Save[i].x - Xrange <= X[X.size() - 1])
             {
                 cnt++;
                 continue;
             }
         }
         else if (Save[i].x < X[0])      // ���� ���� ��κ��� X��ǥ�� ���� ����
         {
             if (Save[i].x + Xrange >= X[0])
             {
                 cnt++;
                 continue;
             }
         }

         else if (Save[i].x - Xrange <= X[ans.x_low] &&  X[ans.x_low] <= Save[i].x + Xrange) // ���� �ȿ� ��ΰ� �ִ� ���
         {
             cnt++;
         }
         else if (Save[i].x - Xrange <= X[ans.x_high] && X[ans.x_high] <= Save[i].x + Xrange) // ���� �ȿ� ��ΰ� �ִ� ���
         {
             cnt++;
         }
         // �ƴ� ���� �ľ�
         //if (Save[i].x - Xrange <= X[ans.x_low] || Save[i].x + Xrange >= X[ans.x_high]) // ���� �ȿ� ��ΰ� �ִ� ���
         //{
         //    cnt++;
         //}
    }
    return cnt;
}
int main() {
    int ans = -1;

    InputData();// �Է¹޴� �κ�

    ans = Solve();

    cout << ans << endl;// ����ϴ� �κ�
    return 0;
}

// ��ɰ� ���� L ���� �ȿ� ��밡 �ִ��� �˻�

// ��ɲ� ���信�� index ����?? ==> index�߿��� �ش� ������ ū �� ã�� binary search

// ��ɲ� ��� ����