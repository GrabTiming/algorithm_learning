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
//2026.5.13
int n,m,k;
/**
https://ac.nowcoder.com/acm/problem/15553

思路： 
定义l_sum[i] 是[1,i]范围内 连续k个数之和的最大值，r_sum[i]为[i,n]范围内的连续k个数之和最大值

*/
int a[N];
int l_sum[N], r_sum[N];


void solve(){
	cin>>n>>k;
    l_sum[0] = -1e18;
    r_sum[n+1] = -1e18;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        l_sum[i] = -1e18;
        r_sum[i] = -1e18;
    }
    int sl = 0, sr = 0;
    for(int i=1;i<=n;i++){
        sl += a[i];
        if (i==k) l_sum[i] = sl;
        if(i>k) {
            sl-=a[i-k];
            l_sum[i] = max(l_sum[i-1], sl);
        }
    }
    for(int i=n;i>=1;i--){
        sr += a[i];
        if (i==n-k+1) r_sum[i] = sr;
        if( i<= n-k) {
            sr -= a[i+k];
            r_sum[i] = max(r_sum[i+1],sr);
        }
    }
    int ans = -1e18;
    for(int i=k;i<=n-k;i++){
        ans = max(ans,l_sum[i]+r_sum[i+1]);
    }
    cout<<ans<<endl;

}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--) 
	{
		solve();
	}
	return 0;
} 
