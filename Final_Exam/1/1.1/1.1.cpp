#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

const int N = 1010;

int a[N];
int ans; //众数的重数
int idx = 0x3f3f3f3f; // 众数的下标

void solution(int l, int r)
{
    int mid = (l + r) / 2;


    //左右点向中间遍历，直到遇到和a[mid]相等的值停止
    int ll = l;
    int rr = r;
    for(ll; ll < mid && a[ll] != a[mid]; ll ++);
    for(rr; rr > mid && a[rr] != a[mid]; rr --);

    //更新重数和下标，下标规定要小的
    if(rr- ll + 1 >=  ans)
    {
        ans = rr - ll + 1;
        idx = min(idx, mid);
    }

    //左边剩下的数大于等于重数才有遍历的必要
    if(ll - l + 1 >= ans)
        solution(l, ll);
    //右边亦然
    if(r - rr + 1 >= ans)
        solution(rr, r);
    
}

int main(){
   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int len;
    cin >> len;
    for(int i = 0; i < len; i ++)
        cin >> a[i];
    sort(a, a + len);

    solution(0, len - 1);
    printf("%d\n%d", a[idx], ans);
    

    system("pause");
    return 0;
}
