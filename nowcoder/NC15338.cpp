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
const int N=1e6+10, M = 1e6, mod = 1e9+7, inf=1e18;
const double eps = 1e-15;
//2026.5.17 阴|雨

/**
https://ac.nowcoder.com/acm/problem/15338
题意：
给出n个点和m条边，要求找出一条路径使得 可以经过每个点一次且经过每条边一次

思路：
1. 先用并查经看看有多少个连通子集，大于1 就不行
2. 要满足经过每个点一次且经过每条边一次，说明只有一个起点和一个终点，且每个点只有一条入边和一条出边
*/

// 使用随机数，需要在main函数重新设置随机种子，srand(time(0));
unsigned long long rnd() {
    return ( (unsigned long long)rand() << 32 ) ^ rand();
}

int n,m,k;
int in[N],out[N], nxt[N];
int f[N];

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}


void solve(){
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        in[i] = out[i] = 0 ;
        f[i] = i;
        nxt[i] = 0;
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        nxt[u] = v;
        in[v]++;
        out[u]++;
        u = find(u);
        v = find(v);
        if(u != v) f[v] = u;
    }
    int cnt = 0;
    int in_zero = 0;
    int out_zero = 0;
    int st,ed;
    for(int i=1;i<=n;i++){
        if(in[i]==0) {
            in_zero++;
            st = i;
        }
        if(out[i]==0) {
            out_zero++;
            ed = i;
        }
        if(f[i]==i) cnt++;
        if(in[i]>1 || out[i]>1){
            cout<<"NO\n";
            return;
        }
    }
    if(cnt!=1) {
        cout<<"NO\n";
        return;
    }
    if(in_zero!=1 || out_zero!=1){
        cout<<"NO\n";
        return;
    }
    int tmp = st;
    while(tmp){
        cout<<tmp;
        if(tmp == ed) {
            cout<<endl;
            break;
        }
        else{
            cout<<" ";
        }
        tmp = nxt[tmp];
    }

}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
        cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
} 
