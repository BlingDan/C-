#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

int f(int n, int m)
{
    if(m == n || m == 1)
        return 1;
    
    return f(n - 1, m - 1) + m * f(n - 1, m);
}

int main(){
   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    cout << f(n, m) << endl;
    
    system("pause");
    return 0;
}
