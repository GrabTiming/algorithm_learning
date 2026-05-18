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
//2026.05.17 阴|多云

/**
https://atcoder.jp/contests/abc458/tasks/abc458_d
题意：一开始有一个数X，每次加入两个新的数，问这些数的中位数是哪个

思路：用一个大顶堆和一个小顶堆解决

*/

// 使用随机数，需要在main函数重新设置随机种子，srand(time(0));
unsigned long long rnd() {
    return ( (unsigned long long)rand() << 32 ) ^ rand();
}

int n,m,k;
priority_queue<int> p;
priority_queue<int,vector<int>, greater<int>> q;

void add(int x){
    p.push(x);
    if(p.size()>q.size()+1){
        int y = p.top();
        p.pop();
        q.push(y);
    }
    if(!p.empty() && !q.empty()){
        int y = p.top();
        int z = q.top();
        if(y > z) {
            p.pop();
            q.pop();
            p.push(z);
            q.push(y);
        }
    }
}

void solve(){
    int x; 
    cin>>x;
    cin>>n;
    while(p.size()>0) p.pop();
    while(q.size()>0) q.pop();

    p.push(x);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        add(a);
        add(b);
        cout<<p.top()<<endl;
    }


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
