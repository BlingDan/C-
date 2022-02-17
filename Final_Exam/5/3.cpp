#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <windows.h>

using namespace std;

const int N = 1010;

int f[N];  
int coin[N];
int n;
int k;  


//f[0][j] 前0个找金额为j所需要的最少硬币数INF
//f[i][0] 0
//状态转移方程式 分f[i][j] = min(f[i - 1][j - coin[i]] + 1, f[i - 1][j])

int main(){
   
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
        cin >> coin[i];

    memset(f, 1000 , sizeof f);

    f[0] = 0;

    for(int i = 1; i <= n; i ++)
        for(int j = coin[i]; j <= k; j ++)
            f[j] = min(f[j - coin[i]] + 1, f[j]);
    
    cout << f[k] << endl;
    system("pause");
    return 0;
}
