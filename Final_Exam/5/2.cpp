//分数背包
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int N = 1010;

typedef pair<float, int> PFI;

//Find the most v in pre w
int v[N];
int w[N];
int n;
int C;
PFI p[N];

//ascending sort
bool compare(PFI p1, PFI p2)
{
    return p1.first > p2.first;
}

int main(){
    cin >> n >> C;
    for(int i = 0; i < n; i ++)
        cin >> w[i];
    for(int i = 0; i < n; i ++)
        cin >> v[i];
    
    for(int i = 0; i < n; i ++)
    {
        p[i].first = (float)v[i] / (float)w[i];
        p[i].second = i;
    }

    sort(p, p + n, compare);

    // for(int i = 0; i < n; i ++)
    //     cout << p[i].first << ' ' << p[i].second << endl;

    int sum_w = 0;
    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        int idx = p[i].second;

        if(sum_w + w[idx] <= C)
        {
            ans += v[idx];
            sum_w += w[idx];
        }
            
        else{
            ans += (C - sum_w) * p[i].first;
            break;
        }
    }

    cout << ans << endl;

    system("pause");
    return 0;
}
