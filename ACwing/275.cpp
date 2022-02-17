#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <windows.h>

using namespace std;

const int N = 55;

int f[N + N][N][N];
int w[N][N];
int m, n;

int main(){
   cout << 111 << endl;
    cin >> m >> n;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; i ++)
            cin >> w[i][j];
    
    for(int k = 2; k <= m + n; k ++)
        for(int i1 = 1; i1 <= m; i1 ++)
            for(int i2 = 1; i2 <= n; i2 ++)
            {
                int j1 = k - i1, j2 = k - i2;
                if(j1 <= n && j1 >= 1 && j2 <= n && j2 >= 1)
                {
                    int t = w[i1][j1];
                    if(i1 != i2) t += w[i2][j2];

                    int &x = f[k][i1][j1];
                    x = max(x, f[k - 1][i1 - 1][j1] + t);
                    x = max(x, f[k - 1][i1 - 1][j1 - 1] + t);
                    x = max(x, f[k - 1][i1][j1] + t);
                    x = max(x, f[k - 1][i1][j1 - 1] + t);
                }
            }

    cout << f[m + n][m][n] << endl;
    system("pause");
    return 0;
}
