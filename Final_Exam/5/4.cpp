#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <windows.h>

using namespace std;

const int N = 1010;

int a[N];
int Min[N];
int n;

int main(){
   
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    int k = 0x3f3f3f3f;
    for(int i = 1; i <= n; i ++)
    {
        k = min(k, a[i]);
        Min[i] = min(Min[i - 1], k);
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        ans = max(ans, a[i] - Min[i]);
    }

    cout << ans << endl;


    system("pause");
    return 0;
}
