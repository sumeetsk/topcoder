#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define vii vector<pair<int,int> >
#define pipii pair<int,pair<int,int> >
#define M 10000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

int main() {
    int caseno = 0;
    while(true) {
        caseno++;
        int n,r,q;
        cin>>n>>r>>q;
        if (!n && !r && !q)
            break;
        int party[n],query_solutions[q];
        vii roads[n];
        for (int i=0;i<n;++i)
            cin>>party[i];
        for (int i=0;i<r;++i) {
            int c1,c2,d;
            cin>>c1>>c2>>d;
            c1--;c2--;
            roads[c1].push_back(make_pair(d,c2));
            roads[c2].push_back(make_pair(d,c1));
        }

        map<int,vector<pair<int,int> > > m;
        for (int i=0;i<q;++i) {
            int q1,q2;
            cin>>q1>>q2;q1--;q2--;
            m[q1].push_back(make_pair(q2,i));
        }
        
        tr(m,i) {
            int q1=i->first;
            pair<int,int> distances[n]; 
            /* Store the min distance and the max party for each node */

            for (int k=0;k<n;++k)
                distances[k] = make_pair(M,M);
            distances[q1] = make_pair(party[q1],party[q1]);

            for (int count=0;count<n-1;++count) {
                for (int j=0;j<n;++j) {
                    tr(roads[j],k) {
                        int edgestart = j;
                        int edgeend = k->second;
                        int edgeweight = k->first;
                        int maxparty = max(distances[edgestart].second,party[edgeend]);
                        int potential_distance = distances[edgestart].first-distances[edgestart].second+maxparty+edgeweight;
                        if (potential_distance < distances[edgeend].first) {
                            distances[edgeend].first = potential_distance;
                            distances[edgeend].second = maxparty;
                        }
                    }
                }
            }

            tr(m[q1],j) {
                int index = j->second;
                int city = j->first;
                if (distances[city].first==M)
                    query_solutions[index] = -1;
                else
                    query_solutions[index] = distances[city].first;
            }
        }
        if (caseno!=1)
            cout<<endl;
        cout<<"Case #"<<caseno<<endl;
        for (int i=0;i<q;++i) {
            cout<<query_solutions[i]<<endl;
        }
    }
    return 0;
}
