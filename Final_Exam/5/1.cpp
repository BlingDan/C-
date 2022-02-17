#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

const int N = 20;

int x[N];//解向量
int a[N];//集合
int n;
int sum;
int aim;


void backtrack(int k)
{
    if(k <= n + 1 && sum == aim){

        for(int i = 1; i <= n; i ++)
            if(x[i]) cout << a[i] << ' ';
        cout << endl;
        return;
    }

    else if(k > n || sum > aim)
        return;
    
    else
    {
        x[k] = 1;
        sum += a[k];
        backtrack(k + 1);

        x[k] = 0;
        sum -= a[k];
        backtrack(k + 1);
    }
}

int main(){
   
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> aim;

    backtrack(1);

    system("pause");
    return 0;
}



