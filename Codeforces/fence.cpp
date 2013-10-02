#include<iostream>
#include<sstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define M 1000000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

int main() {
    int p;
    cin>>p;
    int paint[9];
    stringstream ss;
    for (int i=0;i<9;++i) {
        cin>>paint[i];
    }
    int minpaint = M;
    int minpaintdigit;
    for (int i=0;i<9;++i) {
        if (paint[i]<=minpaint) {
            minpaint = paint[i];
            minpaintdigit = i;
        }
    }
    if (p<minpaint) {
        cout<<"-1"<<endl;
        return 0;
    }
    int maxnoofdigits = p/minpaint;
    int rem = p%minpaint;
    if (rem==0) {
        for (int i=0;i<maxnoofdigits;++i)
            cout<<(minpaintdigit+1);
    }
    else {
        while (p>0) {
            int x=-1;
            int s;
            for (int i=minpaintdigit;i<9;++i) {
                s = p-paint[i];
                if (s<0)
                    continue;
                if (s/minpaint == maxnoofdigits-1) {
                    x = i;
                }
            }
            if (x<0)
                break;
            else {
                p -= paint[x];
                maxnoofdigits--;
                cout<<x+1;
            }
        }
    }
    cout<<endl;
    return 0;
}
