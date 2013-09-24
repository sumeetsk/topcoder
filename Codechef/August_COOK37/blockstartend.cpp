#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc, char* argv[]) {
    long int R = atoi(argv[1]);
    long int C = atoi(argv[2]);
    long int sr = atoi(argv[3])-1;
    long int sc = atoi(argv[4])-1;
    long int tr = atoi(argv[5])-1;
    long int tc = atoi(argv[6])-1;
    long int nr,nc,cr,cc;
    int **grid;
    grid = (int**)malloc(R*sizeof(int*));
    for (int i=0; i<R; ++i) {
        grid[i] = (int*)malloc(C*sizeof(int));
    }
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            grid[i][j] = 0;//unseen
        }
    }
    long int visited_count = 1;
    grid[sr][sc] = 1;
    if (sr==tr && sc==tc) {
        cout<<visited_count<<endl;
        return(1);
    }
    cr = sr;
    cc = sc;
    while(1) {
        if (cc+1<C && grid[cr][cc+1]==0) {
            nr = cr;
            nc = cc+1;
        } else if (cr+1<R && grid[cr+1][cc]==0) {
            nr = cr+1;
            nc = cc;
        } else if (cc-1>=0 && grid[cr][cc-1]==0) {
            nr = cr;
            nc = cc-1;
        } else if (cr-1>=0 && grid[cr-1][cc]==0) {
            nr = cr-1;
            nc = cc;
        } else {
            cout<<"Cannot reach target"<<endl;
            return(1);
        }
        visited_count++;
        cr = nr;
        cc = nc;
        grid[cr][cc] = 1;
        if (cr==tr && cc==tc) {
            cout<<visited_count<<endl;
            return(1);
        }
    }

    for (int i=0; i<R; ++i) {
        free(grid[i]);
    }
    free(grid);
}
