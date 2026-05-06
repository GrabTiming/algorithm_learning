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
//2026.05.06

/**
https://www.luogu.com.cn/problem/P16425?contestId=274106

思路：首先考虑只给小Y接n杯水，那至少需要n*d个体力，满足这个情况下，那在接n杯水的途中每次可以通过+1给自己拿一杯水，
那对于这部分答案很明显就是 min(m-n*d, n) ,然后之后就是只给自己接水，用剩下的体力X 除一下d
*/

int n,m,d;

void solve(){
	cin>>n>>m>>d; 
    d+=1;
    if (m<n*d) {
        cout<<-1<<endl;
        return;
    }
    int ans = min(m-n*d, n);
    m = m - n*d - ans;
    if(m>0) ans += m/d;
    cout<<ans<<endl;
}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--) 
	{
		solve();
	}
	return 0;
} 

