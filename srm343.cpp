#include<iostream>
#include<cstdlib>
using namespace std;
class PersistentNumber {
    public:
        int getPersistence(int);
    private:
        int getProductOfDigits(int);
};

int PersistentNumber::getPersistence(int n) {
    int count = 0;
    if (n<10) {
        return count;
    }
    else {
        while (n>=10) {
            n = getProductOfDigits(n);
            count++;
        }
        return count;
    }
}

int PersistentNumber::getProductOfDigits(int n) {
    if (n<10)
        return n;
    else {
        int quot = n/10;
        int rem = n%10;
        return rem*getProductOfDigits(quot);
    }
}

int main(int argc, char* argv[]) {
    PersistentNumber o;
    int n = atoi(argv[1]);
    cout<<o.getPersistence(n)<<endl;
    return(1);
}
