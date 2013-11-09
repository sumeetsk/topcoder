#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define M 9999999 
typedef vector<int> vi;
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

int main() {
    int n;
    cin>>n;
    vi hotels;
    int hotels_array[n];
    int b;
    for (int i=0;i<n;++i) {
        cin>>b;
        if (b) {
            hotels.push_back(i);
            hotels_array[i] = 1;
        }
        else
            hotels_array[i] = 0;

    }
    int dest_array[n];
    int dest_counts[n];
    for (int i=0;i<n;++i)
        dest_counts[i] = 0;
    for (int i=0;i<n;++i) {
        cin>>dest_array[i];
        dest_array[i]--;
        dest_counts[dest_array[i]]++;
    }
    int not_allowed[n];
    for (int i=0;i<n;++i) {
        if (dest_counts[i]>1)
            not_allowed[i]=1;
        else
            not_allowed[i] = 0;
    }
    int maxpathlength = 0;
    vi bestpath;
    while (!hotels.empty()) {
        int hotel = hotels.back();
        int path[n];
        hotels.pop_back();
        int source = hotel;
        int dest = dest_array[source];
        int pathlength=1;
        while (dest!=-1 && !hotels_array[dest] && !not_allowed[dest]) {
            pathlength++;
            path[dest] = source;
            source = dest;
            dest = dest_array[source];
        }
        if (pathlength>maxpathlength) {
            bestpath.clear();
            maxpathlength = pathlength;
            while (source!=hotel) {
                bestpath.push_back(source+1);
                source = path[source];
            }
            bestpath.push_back(source+1);
        }
    }
    cout<<maxpathlength<<endl;
    tr(bestpath,i) {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
