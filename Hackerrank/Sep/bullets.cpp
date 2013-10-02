#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
#define M 10000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

int main() {
    int T;
    cin>>T;
    for (int i=0;i<T;++i) {
        int m,n,k;
        cin>>m>>n>>k;
        int row = ceil(m/sqrt(2));
        int col = ceil(n/sqrt(2));
        int maxballs = row*col;
        if (k>maxballs)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
