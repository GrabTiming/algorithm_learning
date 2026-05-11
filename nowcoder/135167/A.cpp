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
//2026.05.11 星期一 阴|雨
int n,m,k;
map<string,int> mp;
/*
https://ac.nowcoder.com/acm/contest/135167/A
x/7 小数 的六位循环节 打表
*/
void solve(){
    string s;
    cin>>s;
    cout<<mp[s]<<endl;
}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    mp["142857"]=1;
    mp["285714"]=2;
    mp["428571"]=3;
    mp["571428"]=4;
    mp["714285"]=5;
    mp["857142"]=6;

	cin>>t;
	while(t--) 
	{
		solve();
	}
	return 0;
} 
