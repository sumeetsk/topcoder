#include<iostream>
#include<string>
using namespace std;
int main() {
    int k,n,zcount,ocount;
    string str;
    cin>>k>>str;
    n = str.length();
    int start[n],end[n];
    zcount=0;ocount=0;
    for (int i=0;i<n;++i) {
        if (str[i]=='0')
            zcount++;
        else
            ocount++;
        start[i] = 3*ocount-2*zcount;
        cout<<ocount<<" "<<zcount<<" "<<start[i]<<endl;
    }
    cout<<endl;
    zcount=0;ocount=0;
    for (int i=n-1;i>=0;--i) {
        if (str[i]=='0')
            zcount++;
        else
            ocount++;
        end[i] = 3*ocount-2*zcount;
        cout<<ocount<<" "<<zcount<<" "<<end[i]<<endl;
    }
    cout<<endl;
    return 0;
}
