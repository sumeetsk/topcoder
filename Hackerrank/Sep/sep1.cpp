#include<iostream>
using namespace std;
int main() {
    int cases;
    cin>>cases;
    for (int case_=0;case_<cases;case_++) {
        int k;
        int success = true;
        cin>>k;
        int threes_upon_five=0, fives;
        while (true) {
            fives = k-5*threes_upon_five;
            if (fives%3==0) {
                for (int j=0;j<fives;j++) {
                    cout<<5;
                }
                for (int j=0;j<threes_upon_five*5;++j) {
                    cout<<3;
                }
                cout<<endl;
                break;
            }
            else {
                threes_upon_five++;
            }
            if (threes_upon_five*5>k) {
                success = false;
                break;
            }
        }
        if (success==false)
            cout<<-1<<endl;
    }
    return 0;
}
