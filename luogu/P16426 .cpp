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
int n,m,k,t;
int b[N];
int f[N][2];
/**
思路：问题可以转为以下描述：
对于一个长度为n的数组A， 令新数组B为 B[i] = t - A[i], 
对于i<n, 相邻的两个位置（一公一母）B[i]和B[i+1]产生的贡献是取两者的较小值，
对于一个位置i而言，用0和1表示性别， 位置i产生的贡献只与前面的位置i-1有关。
设置状态 f[i][0/1] 表示位置i的性别为0/1时，能获得的最大贡献，状态转移方程为：
f[i][0] = f[i][1] = 0 , i == 1 
f[i][0] = max(f[i-1][0],f[i-1][1]+min(B[i],B[i-1])) , i > 1
f[i][1] = max(f[i-1][1],f[i-1][0]+min(B[i],B[i-1])) , i > 1
*/

void solve(){
	cin>>n>>t;
    for(int i=1,a; i<=n; i++){
        cin>>a;
        b[i] = t - a;
    }
    f[1][0] = f[1][1] = 0;
    for(int i=2; i<=n ;i++){
        f[i][0] = max(f[i-1][0],f[i-1][1]+min(b[i],b[i-1]));
        f[i][1] = max(f[i-1][1],f[i-1][0]+min(b[i],b[i-1]));
    }
    cout<<max(f[n][0],f[n][1])<<endl;
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
