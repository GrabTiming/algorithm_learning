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
//2026.5.16
int n,m,k;
/**
https://ac.nowcoder.com/acm/problem/17375
思路： 推了半天公式，最后看题解 https://ac.nowcoder.com/acm/problem/blogs/17375
大部分前缀和的题都是 解出递推的公式就能解决问题了
*/
int a[N];
int ss[N];
int q[N][2];


void solve(){
    cin>>n>>m;
    int sum = 0 ;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum = (sum+a[i])%mod;
    }
    int mx_q = 0 ;
    for(int i=1;i<=m;i++) {
        cin>>q[i][0]>>q[i][1];
        mx_q = max(mx_q, q[i][1]);
    }
    ss[0] = sum ;
    int tmp_sum = sum; 
    for(int i=1;i<=mx_q;i++){
        tmp_sum = tmp_sum * (n-1) % mod;
        if (i&1){
            ss[i] = (ss[i-1] - tmp_sum + mod) % mod;
        }
        else {
            ss[i] = (ss[i-1] + tmp_sum) % mod;
        }
    }
    for(int i=1;i<=m;i++) {
        int x = q[i][0], t = q[i][1];
        if (t == 0) {
            cout<<a[x]<<endl;
        } 
        else {
            int ans = ss[t-1]; 
            if (t&1){
                ans = (ans - a[x] + mod) % mod;
            }else {
                ans = (ans * -1 + a[x] + mod) % mod;
            }
            cout<<ans<<endl;
        }
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
