#include<utility>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#define M 100000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
using namespace std;
typedef map<char, vector<pair<char,int> > > Graph;
typedef pair<int,char> ic;
typedef pair<char,int> ci;

void buildGraph(int n, Graph &my_graph, Graph &prof_graph, char &mycity, 
        char &profcity) {
    for (int i=0; i<n; ++i) {
        char age, direction, start, end;
        int distance;
        cin>>age>>direction>>start>>end>>distance;
        if (age=='Y') {
            my_graph[start].push_back(make_pair(end,distance));
            if (direction=='B') {
                my_graph[end].push_back(make_pair(start,distance));
            }
            else {
                my_graph[end];
            }
        }
        if (age=='M') {
            prof_graph[start].push_back(make_pair(end,distance));
            if (direction=='B') {
                prof_graph[end].push_back(make_pair(start,distance));
            }
            else {
                prof_graph[end];
            }
        }
    }
    cin>>mycity>>profcity;
}

void exploreGraph(Graph &graph, map<char,int> &F, set<pair<int,char> > &Q, 
        map<char,int> &D) {
    pair<int,char> top = *Q.begin();
    Q.erase(Q.begin());
    char cur_city = top.second;
    int cur_distance = top.first;
    F[cur_city] = cur_distance;

    tr(graph[cur_city],i) {
        char to_city = i->first;
        int cost = i->second;
        if (D[to_city]>D[cur_city]+cost) {
            if (D[to_city]!=M) {
                Q.erase(Q.find(ic(D[to_city],to_city)));
            }
            D[to_city] = D[cur_city]+cost;
            Q.insert(ic(D[to_city],to_city));
        }
    }
}

int main() {
    int n;
    cin>>n;
    while (n) {
        Graph my_graph,prof_graph;
        char mycity, profcity, my_new_node, prof_new_node;
        map<char,int> my_D, prof_D; //temporary distances
        map<char,int> my_F, prof_F; //final distances
        set<pair<int,char> > my_Q, prof_Q; //acts as priority queue
        buildGraph(n, my_graph, prof_graph, mycity, profcity);
        tr(my_graph,i) {
            my_D[i->first] = M;
        }
        tr(prof_graph,i) {
            prof_D[i->first] = M;
        }
        my_D[mycity] = 0;
        prof_D[profcity] = 0;
        my_Q.insert(pair<int,char>(0,mycity));
        prof_Q.insert(pair<int,char>(0,profcity));
        while (!my_Q.empty()) {
            exploreGraph(my_graph,my_F,my_Q,my_D);
        }
        while (!prof_Q.empty()) {
            exploreGraph(prof_graph,prof_F,prof_Q,prof_D);
        }

        set<ic> common_cities;
        map<char,int>::iterator i=my_F.begin(), j=prof_F.begin();
        while (i!=my_F.end() && j!=prof_F.end()) {
            if (i->first==j->first)  {
                common_cities.insert(ic(i->second+j->second, i->first));
                i++;
                j++;
            }
            else if (i->first<j->first)
                i++;
            else
                j++;
        }

        if (common_cities.empty()) 
            cout<<"You will never meet.";
        else {
            set<ic>::iterator i=common_cities.begin();
            cout<<i->first;
            while (i->first==common_cities.begin()->first && 
                    i!=common_cities.end()) {
                cout<<" "<<i->second;
                i++;
            }
        }
        cout<<endl;
        cin>>n;
    }
    return 0;
}
