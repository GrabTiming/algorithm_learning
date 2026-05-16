#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long 
#define int ll
#define pb push_back
#define eb emplace_back 
#define pii pair<int,int>
#define fi first
#define se second 
using namespace std;
typedef unsigned long long ull;
const int N=1e6, M = 1e6, mod = 1e9+7, inf=1e18;
const double eps = 1e-15;

//2026.05.16 星期六 阴|多云
/**
https://ac.nowcoder.com/acm/problem/245314

题意：求全排列下 逆序对数总和

思路：
对于 两个不相同的数a,b，假设 a大于b，那么他们的贡献是全排列中 b排在a前面的次数，为 P =  n*(n-1)/2 * (n-2)! 
那么统计一下数组中每个数的个数, 转为cnt数组， 对于i而言，它的贡献为 cnt[i] * (n - cnt[i]) * P
上面的统计方式会多算一遍，要除以2
*/

int n,m,k;
int a[N], cnt[N];

int ksm(int a,int b){
    int ans = 1;
    while(b){
        if (b&1) ans = ans * a % mod;
        a = a * a % mod;
        b>>=1;
    }
    return ans;
}

int faci(int x){
    int ans = 1;
    for(int i=1;i<=x;i++){
        ans = ans * i % mod;
    }
    return ans;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[i]=0;
    }
    a[0] = 0;
    sort(a+1, a+n+1);
    m = 0 ;
    for(int i=1;i<=n;i++){
        if (a[i] != a[i-1]) {
            m++;
        }
        cnt[m]++;
    }
    int P = n*(n-1)/2 % mod * faci(n-2) % mod;
    int ans = 0 ;
    for(int i=1;i<=m;i++){
        ans = (ans + cnt[i] * (n-cnt[i]) % mod * P) % mod;
    }
    cout<< (ans * ksm(2, mod-2)) % mod <<endl;

}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	while(t--) 
	{
		solve();
	}
	return 0;
} 