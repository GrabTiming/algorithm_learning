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
//2025.3.15
int n,m,k,x;
/**
https://www.luogu.com.cn/problem/P16427?contestId=274106

思路：先将n弄成一个x进制的字符串，那所有位置的值加起来为S，问题就转为 是否存在 k 使的 2^k >= S ，将这S个x幂次的数 通过反向操作的形式分散为2^k个数。
这里的反向操作指将高幂次的数转为低幂次，比如x^2 可以拆分出x个x病毒群，这里原来对比多出了 x-1 个病毒群，
那么最后的结果可以通过 2^k - S 是否能整除 x-1 
*/

void solve(){
    cin>>n>>x;
    int s = 0;
    int tmp = n;
    if (x==1){
        for(int k = 1 ; k<=n ;k=k*2){
            if(k==n){
                cout<<"Yes"<<endl;
                return;
            }
        }
        cout<<"No"<<endl;
        return;
    }
    while(tmp){
        s += tmp%x;
        tmp /= x;
    }
    for(int k = 1 ; k<=n ;k=k*2){
        if(k<s) continue;
        if((k-s)%(x-1)==0){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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
