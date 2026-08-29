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
//2026.8.29
/*
题目：RainbowDash 在无限长数轴上的移动与坏掉的 GPS 指示

题意摘要：
有无限长数轴，糖果店位于 0 点。初始位置为整数 X，且 X∈[-10,10]。
RainbowDash 会进行 2 步移动（字符串 s，长度为 2，'L' 表示向左移 1，'R' 表示向右移 1）。
坏掉的 GPS 给出每次移动后的相对信息（字符串 t，长度为 2），若第 i 次移动后位置距离糖果店比移动前更近，ti='C'，否则 ti='F'。
给定 s 和 t，判断所有可能的初始位置 X（整数）有哪些，使得按照 s 的移动顺序并根据 X 计算每步后与糖果店的距离变化，得到的GPS指示与给定的 t 完全一致。
输出：若存在合法的初始位置，输出它们的集合或对应结果（题目原文有具体输出格式）；若不存在则输出 "T_T"。

输入格式：
第一行：长度为 2 的字符串 s（由 'L' 和 'R' 组成）。
第二行：长度为 2 的字符串 t（由 'C' 和 'F' 组成）。

注：该注释基于题目链接（牛客网），用于提醒题意与输入约束；实际实现需按题目要求输出具体格式。
*/

/**
题目链接：
https://ac.nowcoder.com/acm/contest/139209/A

*/


// 使用随机数，需要在main函数重新设置随机种子，srand(time(0));
unsigned long long rnd() {
    return ( (unsigned long long)rand() << 32 ) ^ rand();
}

int n,m,k;

void solve(){
	string s,t;
    cin>>s>>t;
    // 如果移动同向
    if(s[0]==s[1]){
        // gps判断相同
        if (t[0]==t[1]){
            // 向左走两步
            if(s[0]=='L'){
                if(t[0]=='C'){
                    cout<<10<<endl;
                    return;   
                }else{
                    cout<<-10<<endl;
                    return;
                }
            }else{
                if(t[0]=='C'){
                    cout<<-10<<endl;
                    return;   
                }else{
                    cout<<10<<endl;
                    return;
                }
            }
            cout<<0<<endl;
        }else{
            if (t[0]=='F'){
                cout<<"T_T"<<endl;
                return;
            }
            int f1 = ((s[0]=='L') ? 1 : -1);
            int f2 = ((t[0]=='C') ? 1 : -1);
            cout<<f1 * f2<<endl;
            return;
        }
    }else{
        if (t[0]==t[1]){
            cout<<"T_T"<<endl;
            return;
        }else{
            int f1 = ((s[0]=='L') ? 1 : -1);
            int f2 = ((t[0]=='C') ? 1 : -1);
            cout<<f1 * f2<<endl;
            return;
        }
    }
    cout<<"T_T"<<endl;

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
