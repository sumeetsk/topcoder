#include<iostream>
using namespace std;
int main() {
    int cases;
    cin>>cases;
    for (int case_=0;case_<cases;case_++) {
        long int n,k,g1,g2,g3;
        cin>>n>>k;
        long int kmultiple = k,total=0;
        while (kmultiple<=2*n-1) {
            g1 = (kmultiple-1)/2;
            g2 = (2*n-kmultiple+1)/2;
            g3 = (g1<g2)?g1:g2;
            total += g3;
            kmultiple += k;
        }
        cout<<total<<endl;
    }
    return 0;
}
