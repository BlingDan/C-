#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

void LCS()
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(a[i] == b[j]) 
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
}
int main(){
    cin >> n >> m >> a + 1>> b + 1;

    LCS();
    cout << f[n][m] << endl;
    
    system("pause");
    return 0;
}
