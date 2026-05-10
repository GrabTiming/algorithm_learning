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

//2026.05.10 星期日 阴|雨
/**
https://ac.nowcoder.com/acm/problem/19798

思路：
​
 
前缀和sa，和sw
f(l,r) = (sa[r]-sa[l-1])*(sw[r]-sw[l-1])
要求所有 1<=l<=r<=n f(l,r) 

根据和式变换转化公式

*/

int n,m,k;
int a[N],w[N], sa[N], sw[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa[i] = (sa[i-1]+a[i])%mod;
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sw[i] = (sw[i-1]+w[i])%mod;
    }
    
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = (ans + sa[i]*sw[i]%mod) % mod;
    }
    for(int i=1;i<=n;i++){
        ans = (ans - sa[i-1]*sw[n-i+1]%mod + mod) %mod;
    }
    cout<<ans<<endl;

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
