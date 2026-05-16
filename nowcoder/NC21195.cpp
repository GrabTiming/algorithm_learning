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

https://ac.nowcoder.com/acm/problem/21195
题意： 给出一个数组为多个汉堡的重量，每次只吃从第a重到第b重的汉堡，求这m次吃的汉堡的总重量的最大值

*/

// 使用随机数，需要在main函数重新设置随机种子，srand(time(0));
unsigned long long rnd() {
    return ( (unsigned long long)rand() << 32 ) ^ rand();
}

int n,m,k;
int x[N], sum[N];

void solve(){
	cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    reverse(x+1,x+n+1);
    for(int i=1;i<=n;i++){
        sum[i] = (sum[i-1]+x[i]);
    }
    int ans = 0 ;
    for(int i=1,a,b;i<=m;i++){
        cin>>a>>b;
        ans = max(ans, sum[b]-sum[a-1]);
    }
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
