#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[14 + 10];
vector <int> All;
vector <int> group_1;
vector <int> group_2;

void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

void Vectorize()
{
    for (int i = 0; i < N; i++)
    {
        All.push_back(A[i]);
    }
}
bool is_zero(int n) { return n != 0; }
vector<int> zero_arrange(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    auto order = find_if(vec.begin(), vec.end(), is_zero);
    //order = find(vec.end(), vec.begin(), 0);
    if (order != vec.begin())
    {
        //vec.insert(vec.begin(), find_if(vec.begin(), vec.end(), is_zero));
        //vec.erase(find_if(vec.begin(), vec.end(), is_zero));

        int temp;
        temp = vec[0];
        vec[0] = *order;
        *order = temp;
    }
    return vec;
}
bool is_zero1(int n) { return n == 0; }
void Split_arrange()
{
    sort(All.begin(), All.end());
    //auto order = find(All.begin(), All.end(), is_zero1);
    while (All[0] * All[1] == 0)
    {
        if (All[0] == 0)
        {
            All.push_back(All[0]);
            All.erase(All.begin());
        }
        if (All[1] == 0)
        {
            All.push_back(All[1]);
            All.erase(All.begin()+1);
        }
    }
    /*
    for (int i=0;i<All.size();i++)
    {
       if(All[0]==0)
       {
           All.push_back(All[0]);
           All.erase(All.begin()+i);
       }
    }*/
    sort(All.begin() + 2, All.end());

    for (int i = 0; i < All.size(); i++)
    {
        if (i % 2 == 0) group_1.insert(group_1.begin(), All[i]);
        else group_2.insert(group_2.begin(), All[i]);
    }
    group_1 = zero_arrange(group_1);
    group_2 = zero_arrange(group_2);
}
int make_num(vector<int> vec)
{
    int num1 = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        num1 = (num1 * 10) + vec[i];
    }
    return num1;
}

int Solve()
{
    int answer;
    int group1_num, group2_num;
    Vectorize();
    sort(All.begin(), All.end());
    Split_arrange();
    group1_num = make_num(group_1);
    group2_num = make_num(group_2);
    answer = group1_num + group2_num;
    return answer;
}

int main() {
    int ans = -1;

    InputData();// 입력받는 부분

    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}