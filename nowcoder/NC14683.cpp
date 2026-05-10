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
https://ac.nowcoder.com/acm/problem/14683

思路：有n个位置i，a[i]表示i到i+1的距离，这里可以简单前缀处理一下，变成每个点位置为a[i]，每个位置有b[i]个物品

那么[l,r] 挪到 位置x 代价： Σ b[i] * abs(a[x]-a[i]) , i∈[l,r]
根据 x 与 l，r的关系分三种情况

1. x <= l : 代价 = Σ b[i] * (a[i] - a[x]) = Σ b[i] * a[i] - a[x] * Σ b[i]
2. x >= r : 代价 = Σ b[i] * (a[x] - a[i]) = a[x] * Σ b[i] - Σ b[i] * a[i]
3. l<=x<=r : 拆开两部分[l,x], [x+1,r] 带入上面

可以看到 维护 a[i]*b[i] 前缀和 + b[i]前缀和
*/

int n,m,k;
int a[N],b[N], sum_ab[N], sum_b[N];

void solve(){
    cin>>n>>m;
    for(int i=1,x;i<n;i++){
        cin>>x;
        a[i+1] = (a[i] + x) % mod;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        sum_b[i] = (sum_b[i-1] + b[i]) % mod;
        sum_ab[i] = (sum_ab[i-1]+ a[i]*b[i]%mod) % mod;
    }
    int x, l, r;
    while(m--){
        int ans = 0 ;
        cin>>x>>l>>r;
        if(x <=l){
            ans = (sum_ab[r] - sum_ab[l-1] - a[x]*((sum_b[r]-sum_b[l-1]+mod)%mod)%mod + mod) % mod;
        }
        else if(x>=r){
            ans = (a[x]*((sum_b[r]-sum_b[l-1]+mod)%mod) %mod - (sum_ab[r] - sum_ab[l-1]) + mod) % mod;
        }
        else{
            ans = (a[x]*((sum_b[x]-sum_b[l-1]+mod)%mod) %mod - (sum_ab[x] - sum_ab[l-1]) + mod) % mod;
            ans = (ans + (sum_ab[r] - sum_ab[x] - a[x]* ((sum_b[r]-sum_b[x]+mod)%mod)  % mod)) % mod;
        }
        cout<<(ans+mod)%mod<<endl;
    }
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
