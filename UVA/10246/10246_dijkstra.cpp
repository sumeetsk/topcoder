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
        cout<<"Case #"<<caseno<<endl;
        int party[n];
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

        vector<pair<int,int> > m;
        for (int i=0;i<q;++i) {
            int q1,q2;
            cin>>q1>>q2;q1--;q2--;
            m.push_back(make_pair(q1,q2));
        }
        
        tr(m,i) {
            int q1=i->first, q2=i->second;
            vii roads_copy[n];
            //create a copy of roads
            for (int k=0; k<n; ++k) {
                tr(roads[k],l) {
                    roads_copy[k].push_back(make_pair(l->first,l->second));
                }
            }
            vector<int> distanceset;
            while (true) {
                priority_queue<pipii,vector<pipii>,greater<pipii> > Q;
                Q.push(make_pair(0,make_pair(q1,q1)));
                /* The first number is the minimum distance, the second is the
                 * node number, the third is the previous city.
                 */
                int visited[n];
                pair<int,int> distances[n];
                for (int i=0;i<n;++i) {
                    visited[i] = 0;
                    distances[i] = make_pair(M,-1);
                }
                while(!Q.empty()) {
                    pipii nodepack = Q.top();
                    Q.pop();
                    int city = (nodepack.second).first;
                    int city_distance = nodepack.first;
                    int referring_city = (nodepack.second).second;
                    if (visited[city])
                        continue;
                    visited[city] = 1;
                    distances[city] = make_pair(city_distance,referring_city);

                    if (city==q2)
                        break;

                    //Explore its neighbors
                    tr(roads_copy[city],j) {
                        int new_city = j->second;
                        int new_city_distance = city_distance + j->first;
                        if (!visited[new_city]) {
                            if (distances[new_city].first > new_city_distance) {
                                distances[new_city] = make_pair(new_city_distance, city);
                                Q.push(make_pair(new_city_distance,make_pair(new_city,city)));
                            }
                        }
                    }
                }
                if (visited[q2]==1) {
                    //calculate distance
                    int maxparty = party[q2];
                    vector<int> costliest_nodes;
                    costliest_nodes.push_back(q2);
                    int node = q2;
                    while (node!=q1) {
                        node = distances[node].second;
                        if (party[node]>=maxparty) {
                            maxparty = party[node];
                            if (party[node]>maxparty)
                                costliest_nodes.clear();
                            costliest_nodes.push_back(node);
                        }
                    }
                    distanceset.push_back(distances[q2].first+maxparty);
                    int costliest_node = -1;
                    if (costliest_nodes.size()==1)
                        costliest_node = *costliest_nodes.begin();
                    else {
                        //check if any node other than q1 and q2
                        tr(costliest_nodes,l) {
                            if (*l!=q1 && *l!=q2)
                                costliest_node = *l;
                        }
                        if (costliest_node==-1)
                            costliest_node = *costliest_nodes.begin();
                    }
                    if (costliest_node == q1 || costliest_node==q2)
                        break;
                    tr(roads_copy[costliest_node],l) {
                        int city = l->second;
                        tr(roads_copy[city],l1) {
                            if (l1->second==costliest_node) {
                                l1 = roads_copy[city].erase(l1);
                                break;
                            }
                        }
                    }
                    roads_copy[costliest_node].clear();
                }
                else { 
                    break;
                }
            }

            if (distanceset.empty()) {
                cout<<"-1"<<endl;
            }
            else {
                int mindistance = M;
                tr(distanceset,l) {
                    if (*l<mindistance)
                        mindistance = *l;
                }
                cout<<mindistance<<endl;
            }
        }
    }
    return 0;
}
