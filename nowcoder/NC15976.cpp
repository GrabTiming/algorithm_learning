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

https://ac.nowcoder.com/acm/problem/15976

思路：对于单个游戏i来说，并查集维护每个子集的节点个数，当加到某条线(u,v) 后，子集节点个数为玩该游戏的人数cnt[i]时即为答案

*/

// 使用随机数，需要在main函数重新设置随机种子，srand(time(0));
unsigned long long rnd() {
    return ( (unsigned long long)rand() << 32 ) ^ rand();
}

int n,m,k,q;

int fd(int x, vector<int>& f){
    return f[x] == x ? x : f[x] = fd(f[x],f);
}

void solve(){
    vector<int> a(n+1);
    vector<int> f(n+1);
    vector<map<int,int>> mp(n+1);
    vector<int> cnt(m+1);
    vector<int> ans(m+1,-1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i] = i;
        mp[i][a[i]]++;
        cnt[a[i]]+=1;
    }

    for(int i=1,u,v;i<=q;i++){
        cin>>u>>v;
        int fu = fd(u,f);
        int fv = fd(v,f);
        if(mp[fu].size() < mp[fv].size()) {
            swap(fu,fv);
        }
        f[fv] = fu;
        for(auto item: mp[fv]) {
            int k = item.first;
            int val = item.second;
            mp[fu][k] += val;
            if (mp[fu][k] == cnt[k] && ans[k] ==-1) {
                ans[k] = i;
            }
        }
        mp[fv].clear();
    }
    for(int i=1;i<=m;i++){
        if(cnt[i]==1) cout<<0<<endl;
        else {
            cout<<ans[i]<<endl;
        } 
    }

}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(cin>>n>>m>>q) 
	{
		solve();
	}
	return 0;
} 
