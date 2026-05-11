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
//2026.05.11
int n,m,k;
string s;

/**
https://ac.nowcoder.com/acm/contest/135167/B
题意：一个回文串s，问删除一个位置后还为回文串的方案数

思路：对于位置i(0<=i<n/2)，删除了它，因为原本为回文串，那s[0..i] 和s[n-i..n] 一定是对应的，就看s[i+1..n-1-i] 是不是回文串
那原本s[i...n-1-i]都满足回文串了，那等价于 s[i+1]=s[i]，由此可以得出，删除的的位置i一定与中心点相等
*/

void solve(){
	cin>>n;
    cin>>s;
    int  l = (n-1)/2, r = n/2; 
    while(l>=0 && s[l]==s[(n-1)/2]) l--;
    while(r<n && s[r]==s[n/2]) r++;
    cout<<r-l+1<<endl;
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
