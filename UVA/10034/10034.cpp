#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<set>
#define M 100000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
using namespace std;
typedef vector<pair<double, double> > vdd;
typedef vector<int> vi;
typedef pair<double, double> pdd;
typedef map<int, double> mid;
typedef set<pair<double,int> > sdi;
int howManyRemaining(int *a,int n) {
    int sum=0;
    for (int i=0; i<n; ++i)
        sum += a[i];
    return sum;
}
int main() {
    cout<<setprecision(2)<<fixed;
    int n_cases,temp,n_points;
    cin>>n_cases;
    for(int caseno=0; caseno<n_cases; ++caseno) {
        double x,y,distance;
        int *remaining;
        pdd nextxy,currxy;
        mid D;
        sdi Q;
        if (caseno!=0) {
            cout<<endl;
        }
        cin>>n_points;
        if (n_points==1) {
            cin>>x>>y;
            cout<<0.00<<endl;
            continue;
        }
        pdd *coords = (pdd *)malloc(n_points*sizeof(pdd));
        remaining = (int *)malloc(n_points*sizeof(int));
        for (int i=0; i<n_points; ++i) {
            cin>>x>>y;
            coords[i] = make_pair(x,y);
            remaining[i] = 1;
            D[i] = M;
        }
        double sum = 0;
        int node = 0;
        Q.insert(make_pair(0,node));
        while(howManyRemaining(remaining,n_points)>0) {
            node = Q.begin()->second;
            sum += Q.begin()->first;
            currxy = coords[node];
            D[node] = 0;
            remaining[node] = 0;
            Q.erase(Q.begin());
            for (int i=0; i<n_points; ++i) {
                if (!remaining[i])
                    continue;
                nextxy = coords[i]; 
                distance = sqrt((currxy.first-nextxy.first)*(currxy.first-nextxy.first) + (currxy.second-nextxy.second)*(currxy.second-nextxy.second));
                if (D[i]>distance) {
                    if (D[i]!=M) {
                        Q.erase(Q.find(make_pair(D[i],i)));
                    }
                    D[i] = distance;
                    Q.insert(pair<double,int>(distance,i));
                }
            }
        }
        cout<<sum<<endl;
        free(remaining);
        free(coords);
    }
    return 0;
}
