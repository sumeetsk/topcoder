#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class BuildBridge {
    public:
        int howManyCards(int,int);
    private:
        double computeHn(int,double Hnplus1);
};

int BuildBridge::howManyCards(int D, int L) {
    int ncards;
    double n_cont = exp(2*(double)D/(double)L);
    double Hnplus1 = 0;
    for (ncards=ceil(n_cont); ncards>=1; --ncards) {
        double H = computeHn(ncards,Hnplus1);
        Hnplus1 = H;
        if ((double)L*H/2+min(1e-8,1/n_cont)<D)
            break;
    }
    return (ncards+1);
}

double BuildBridge::computeHn(int n,double Hnplus1) {
    if (Hnplus1!=0) 
        return (Hnplus1-1/(double)(n+1));
    double sum=0;
    for (double i=1; i<=n; ++i) {
        sum += 1/i;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    int D = atoi(argv[1]);
    int L = atoi(argv[2]);
    BuildBridge o;
    cout<<o.howManyCards(D,L)<<endl;
    return(1);
}
