#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define M 10000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

int main() {
    int n;
    cin>>n;
    int tc[3];//ticket counts;
    for (int i=0;i<3;++i)
        tc[i] = 0;
    int t;
    for (int i=0;i<n;++i) {
        cin>>t;
        switch(t) {
            case 25:
                tc[0]++;
                break;
            case 50:
                tc[1]++;
                if (tc[0]==0) {
                    cout<<"NO"<<endl;
                    return 0;
                }
                else
                    tc[0]--;
                break;
            case 100:
                tc[2]++;
                if (tc[1]>0 && tc[0]>0) {
                    tc[1]--;tc[0]--;
                }
                else if (tc[0]>2) {
                    tc[0] -= 3;
                }
                else {
                    cout<<"NO"<<endl;
                    return 0;
                }
                break;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
