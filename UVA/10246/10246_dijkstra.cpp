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
            priority_queue<pipii,vector<pipii>,greater<pipii> > Q;
            Q.push(make_pair(party[q1],make_pair(party[q1],q1)));
            /* The first number is the min distance till that node (including the 
             * costliest party so far). The second number is the costliest party
             * so far. The third number is the number of the node.
             */

            int visited[n];
            int distances[n];
            for (int i=0;i<n;++i) {
                visited[i] = 0;
                distances[i] = M;
            }
            while(!Q.empty()) {
                pipii nodepack = Q.top();
                Q.pop();
                int city = (nodepack.second).second;
                int maxparty = (nodepack.second).first;
                int city_distance = nodepack.first;
                if (visited[city])
                    continue;
                visited[city] = 1;
                distances[city] = nodepack.first;

                /* Check if all the nodes we want to reach from this point have
                 * been visited.
                 */
                bool success = true;
                tr(m[q1],j) {
                    if (!visited[j->first]) {
                        success = false;
                        break;
                    }
                }
                if (success)
                    break;


                //Explore its neighbors
                tr(roads[city],j) {
                    int new_city = j->second;
                    int new_city_distance = j->first;
                    if (!visited[new_city]) {
                        int next_best_distance,next_max_party;
                        if (maxparty<party[new_city]) {
                            next_best_distance = city_distance-maxparty+party[new_city]+new_city_distance;
                            next_max_party = party[new_city];
                        }
                        else {
                            next_best_distance = city_distance + new_city_distance;
                            next_max_party = maxparty;
                        }
                        if (distances[new_city]>next_best_distance) {
                            distances[new_city] = next_best_distance;
                            Q.push(make_pair(next_best_distance,make_pair(next_max_party,new_city)));
                        }
                    }
                }
            }
            tr(m[q1],j) {
                int index = j->second;
                int city = j->first;
                if (visited[city]==0)
                    query_solutions[index] = -1;
                else
                    query_solutions[index] = distances[city];
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
