#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define M 10000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

int main() {
    int n,m; //n correct m wrong
    cin>>n>>m;
    int cmin=M,cmax=0;
    int a;
    for (int i=0;i<n;++i) {
        cin>>a;
        if (a<=cmin)
            cmin = a;
        if (a>=cmax)
            cmax = a;
    }
    int wmin=M;
    for (int i=0;i<m;++i) {
        cin>>a;
        if (a<=wmin)
            wmin = a;
    }
    cmax = max(2*cmin,cmax);
    if (wmin<=cmax)
        cout<<"-1"<<endl;
    else
        cout<<cmax<<endl;
    return 0;
}
