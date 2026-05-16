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


unsigned long long rnd() {
    return ( (unsigned long long)rand() << 32 ) ^ rand();
}

int hash_val[N];


//2026.05.16 星期六 阴|多云
/**
https://ac.nowcoder.com/acm/problem/16637

题意：一个农田表示为二维数组a, (i,j)这个位置只能下a[i][j] 这种药物，下其他就会死亡，
有m次撒药的机会，每次选择一个矩形区域(左上角为(x1,y1)，右下角为(x2,y2))撒药物k，求最多能种活多少个农作物

思路：对于位置(i,j), 要知道它是否存活，那就要确保对这个位置每次下的药物都是a[i][j], 
考虑维护一个二维前缀和数组sum作为每块区域下药的和，再维护一个二维前缀数组cnt，记录每块区域下药的次数，
那么对于位置(i,j)而言，该位置的下药次数*a[i][j]的和等于该位置下药的总和，那就存活，否则死亡

存在一个误判的可能，比如a[i][j] = 3, 分别下药两次，2和4；通过hash随机数降低误判可能

*/

int n,m,k;

void add(int x1,int y1,int x2,int y2, int k, vector<vector<int>>& sum){
    sum[x1][y1] += k;
    sum[x1][y2+1] -= k;
    sum[x2+1][y1] -= k;
    sum[x2+1][y2+1] += k;
}

void solve(){
    int t;
    cin>>n>>m>>t;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    vector<vector<int>> sum(n+2, vector<int>(m+2));
    vector<vector<int>> cnt(n+2, vector<int>(m+2));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1,x1,y1,x2,y2,k;i<=t;i++){
        cin>>x1>>y1>>x2>>y2>>k;
        add(x1,y1,x2,y2, hash_val[k], sum);
        add(x1,y1,x2,y2, 1, cnt);
    }

    int ans = 0 ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            cnt[i][j] = cnt[i][j] + cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            if (sum[i][j] == hash_val[a[i][j]] *cnt[i][j]) ans++;
        }
    }
    cout<<n*m-ans<<endl;
}


signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    srand(time(0));
    for(int i=0;i<=N;i++){
        hash_val[i] = rnd();
    }
	int t=1;
	// cin>>t;
	while(t--) 
	{
		solve();
	}
	return 0;
} 