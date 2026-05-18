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
const int N=3*1e6+10, M = 1e6, mod = 998244353, inf=1e18;
const double eps = 1e-15;
//2026.05.17 阴|多云

/**
https://atcoder.jp/contests/abc458/tasks/abc458_e

题意：有x1个1，x2个2，x3个3， 问有多少种排列方式，使得相邻的数绝对值不会大于1，结果mod 998244353

*/

// 使用随机数，需要在main函数重新设置随机种子，srand(time(0));
unsigned long long rnd() {
    return ( (unsigned long long)rand() << 32 ) ^ rand();
}

int n,m,k;
int x1,x2,x3;
int fac[N],inv[N];

int ksm(int a,int b,int c) {
    int res = 1;
    a = a % c;
    while(b){
        if(b&1) res= res * a %c;
        a = a*a %c;
        b>>=1;
    }
    return res;
}

void init(){
    fac[0]=fac[1] = 1;
    for(int i=1; i<N;i++){
        fac[i] = fac[i-1]*i %mod;
    }
    inv[N-1] = ksm(fac[N-1],mod-2,mod);
    for(int i=N-1; i>=1; i--){
        inv[i-1] = inv[i] * i %mod; 
    }
}

int C(int x,int y) {
    if (y<0 || y>x) return 0;
    return fac[x] * inv[x-y] %mod *inv[y] %mod;
}


int get(int x,int y){
    if(x<y || y <= 0 ) return 0;
    return C(x-1,y-1);
}

void solve(){
    cin>>x1>>x2>>x3;
    int ans = 0;
    // 枚举 两边不同的位置数 
    for(int k=1; k<=min(x1+x3-1,x2);k++){
        int tmp_ans = 0;
        if (k%2 ==1){
            int x = (k+1)/2;
            tmp_ans = 2* get(x1,x) % mod *get(x3,x) %mod;
        }
        else{
            int x = k/2;
            // 开头和结尾都是1
            int tmp_1 = get(x1,x+1) * get(x3,x) %mod;
            int tmp_2 = get(x1,x) * get(x3,x+1) %mod;
            tmp_ans = (tmp_1 + tmp_2) %mod;

        }
        ans = (ans + (tmp_ans * C(x1+x3+x2-k, x1+x3)%mod)) %mod;
    }
    cout<<ans<<endl;

}


signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    init();
//	cin>>t;
	while(t--) 
	{
		solve();
	}
	return 0;
} 