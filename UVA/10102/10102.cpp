#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

void appendNeighbors(queue<pair<int,int> > &q, int r1, int c1,int n) {
    if (r1>=1)
        q.push(make_pair(r1-1,c1));
    if (r1<n-1)
        q.push(make_pair(r1+1,c1));
    if (c1>=1)
        q.push(make_pair(r1,c1-1));
    if (c1<n-1)
        q.push(make_pair(r1,c1+1));
}

int findClosest3(char** arr,int r,int c,int n) {
    int visited[n][n];
    queue<pair<int, int> > q;
    int r1,c1;
    pair<int,int> next;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            visited[i][j] = 0;
        }
    }
    q.push(make_pair(r,c));
    while(true) {
        next = q.front();
        q.pop();
        r1 = next.first;
        c1 = next.second;
        if (arr[r1][c1]=='3')
            return (abs(r1-r)+abs(c1-c));
        else if (!visited[r1][c1]) {
            appendNeighbors(q,r1,c1,n);
            visited[r1][c1] = 1;
        }
    }

}

int main() {
    int n;
    while(cin>>n) {
        char **arr;
        arr = (char **)malloc(n*sizeof(char *));
        for (int i=0;i<n;++i) {
            arr[i] = (char *)malloc(n*sizeof(char));
        }
        for(int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                cin>>arr[i][j];
            }
        }
        int M = 0;
        for(int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (arr[i][j]=='1') {
                    int m = findClosest3(arr,i,j,n);
                    if (m>M) {
                        M = m;
                    }
                }
            }
        }
        for (int i=0;i<n;++i) {
            free(arr[i]);
        }
        free(arr);
        cout<<M<<endl;
    }
    return 0;
}
