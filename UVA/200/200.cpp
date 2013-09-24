#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<map>
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
using namespace std;
typedef set<char> sc;
typedef map<char,sc> mcsc;
typedef map<char,int> mci;
void read_graph(mcsc &graph) {
    string a,b;
    cin>>a;
    cin>>b;
    while (b!="#") {
        string::iterator it1,it2;
        for (it1=a.begin(),it2=b.begin();*it1==*it2 && it1!=a.end() && it2!=b.end();it1++,it2++);
        if (it1!=a.end() && it2!=b.end()) 
            graph[*it1].insert(*it2);
        a=b;
        cin>>b;
    }
}

void create_indegrees(mcsc &graph, mci &indegrees) {
    tr(graph,i) {
        indegrees[i->first];
        tr(i->second,j) {
            indegrees[*j]++;
        }
    }
}

char findStartNode(mci &indegrees) {
    tr(indegrees,i) {
        if (i->second==0) {
            char top = i->first;
            indegrees.erase(i);
            return top;
        }
    }
}

int main() {
    mcsc graph;
    mci indegrees;
    read_graph(graph);
    create_indegrees(graph,indegrees);
    while(!indegrees.empty()) {
        char top = findStartNode(indegrees);
        cout<<top;
        tr(graph[top],i) {
            indegrees[*i]--;
        }
        graph.erase(top);
    }
    cout<<endl;
    return 0;
}
