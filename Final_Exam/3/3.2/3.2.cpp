#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

const int N = 1010;

//f[i][j] 完成i个任务，A机器花费时间为j情况下 B机器花费时间
int f[N][N];
int a[N];
int b[N];


int main(){
   
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        sum += a[i];
    }
        
    for(int i = 1; i <= n; i ++)
        cin >> b[i];
    
    for(int i = 1; i < n; i ++)
        for(int j = 0; j <= sum ; j ++)
        {
            if(j < a[i]) 
                f[i][j] = f[i - 1][j] + b[i];
            else
                f[i][j] = min(f[i - 1][j - a[i]], f[i - 1][j] + b[i]);

        }
    
    int ans = -1;
    for(int i = 0; i <= sum; i ++)
        ans = min(ans, max(f[n][i], i));
    cout << ans << endl;

    system("pause");
    return 0;
}
