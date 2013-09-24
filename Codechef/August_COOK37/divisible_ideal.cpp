#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
const int maxn=100100;
 
int n;
int a[maxn];
int m;
int s[maxn],t[maxn],q[maxn];
int prev[maxn];
vector<int> g[maxn];
bool visited[maxn];
int c;
int p[maxn],e[maxn];
int pos;
 
void generate(int d,int x)
{
	if (d==c) 
	{
		if (visited[x]) g[x].push_back(pos);
		return;
	}
	for (int i=0;i<=e[d];i++)
	{
		generate(d+1,x);
		x*=p[d];
	}
}
int solve(vector<int>& a,int key)
{
	if (key<=0) return 0;
	int h=-1,t=SIZE(a);
	for (;h+1<t;)
	{
		int m=h+(t-h)/2;
		if (a[m]>key) t=m;
		else h=m;
	}
	return t;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d%d%d",&s[i],&t[i],&q[i]);
	memset(visited,false,sizeof(visited));
	for (int i=0;i<m;i++) visited[q[i]]=true;
	memset(prev,255,sizeof(prev));
	for (int i=2;i<maxn;i++) if (prev[i]<0)
		for (int j=i;j<maxn;j+=i)
			prev[j]=i;
	for (int i=0;i<n;i++)
	{
		int key=a[i];
		c=0;
		for (;key>1;c++)
		{
			p[c]=prev[key];
			e[c]=0;
			for (;key%p[c]==0;key/=p[c]) e[c]++;
		}
		pos=i+1;
		generate(0,1);
	}
	for (int i=0;i<m;i++)
		printf("%d\n",solve(g[q[i]],t[i])-solve(g[q[i]],s[i]-1));
	return 0;
}
