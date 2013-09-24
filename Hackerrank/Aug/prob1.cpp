#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef vector<int>::iterator vit;
int main() {
    int T,N,K,a,count;
    cin >> T;
    for (int test=0; test<T; ++test) {
        vector<int> A,B; 
        cin>>N;
        cin>>K;
        for (int i=0; i<N; ++i) {
            cin>>a;
            A.push_back(a);
        }
        for (int i=0; i<N; ++i) {
            cin>>a;
            B.push_back(a);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int count=0;
        for (vit i=A.begin(); i!=A.end(); ++i) {
            vit it=lower_bound(B.begin(),B.end(),K-*i);
            if (it==B.end())
                break;
            B.erase(it);
            count++;
        }
        if (count==N)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
