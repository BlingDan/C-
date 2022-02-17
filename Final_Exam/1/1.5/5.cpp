#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

int solution(int k)
{
    int ans = 1;
    int i;

    for(i = 2; i * i < k; i ++)
    {
        if(k % i == 0)
            ans += solution(i) + solution(k / i);
    }

    if(i * i == k)
        ans += solution(i);
    
    return ans;
}

int main(){
   
    int n;
    cin >> n;
    cout << solution(n) << endl;

    system("pause");
    return 0;
}
