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
https://ac.nowcoder.com/acm/problem/14650
题意：一个长度为n的数组a（循环，首尾相接），0为不开心，1为开心，需要找出有多少个位置i，满足以位置i为开头的接下来n个数a[i...i+n-1]，
对于每个位置j，a[1..j]的不开心天数小于 a[j,i+n-1] 

思路：将序列视为循环，并复制一份接在后面。计算前缀和 Q 后，规则等价于找这样的起点 d：Q_{d-1} 是它后面连续 n 个位置中的严格最小值。当总收益 S > 0 时，这些最小值点恰好有 S 个，每个对应一个可行的 d。
*/

int n,m,k;

void solve(){
	cin>>n;
    int c0 = 0 ,c1 = 0;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(x==1) c1++;
        else c0++;
    }
    cout<<max(0ll,c1-c0)<<endl;
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
