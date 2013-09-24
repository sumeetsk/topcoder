#include<iostream>
using namespace std;
int main() {
    int cases;
    cin>>cases;
    for (int case_=0;case_<cases;case_++) {
        int n,k,g1,g2,g3;
        cin>>n>>k;
        int kmultiple = k,total=0;
        while (kmultiple<=2*n-1) {
            for (int i=1;i<=n;++i) {
                if ((kmultiple-i<=n) && (i!=kmultiple-i) && (kmultiple-i>=1)) {
                    total++;
                }
            }
            kmultiple += k;
        }
        cout<<total/2<<endl;
    }
    return 0;
}
