#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

const int N = 210;
const int INF = 0x3f3f3f3f;

int n, m, Q;
int d[N][N];

void floyd()
{
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
    cin >> n >> m >> Q;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }

    for(int i = 0; i < m; i ++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    floyd();

    while(Q--)
    {
        int x, y;
        cin >> x >> y;

        if(d[x][y] > INF / 2) puts("imposible");
        else cout << d[x][y] << endl;
    }

    system("pause");
    return 0;
}
