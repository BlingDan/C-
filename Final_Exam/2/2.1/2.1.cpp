#include <iostream>
#include <windows.h>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 10010;

struct Range{
    int l, r;
}range[N];

bool compare(Range x, Range y)
{
    return x.l < y.l;
}


int main(){
   
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> range[i].l >> range[i].r;
    
    sort(range, range + n, compare);

    // for(int i = 0; i < n; i ++)
    //     cout << range[i].l << " ";

    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i ++)
    {
        if(q.empty() || q.top() > range[i].l)
            q.push(range[i].r);
        else
        {
            q.pop();
            q.push(range[i].r);
        }
    }

    cout << q.size() << endl;
    system("pause");
    return 0;
}

// 5                            
// 1 23
// 12 28
// 25 35
// 27 80
// 36 50