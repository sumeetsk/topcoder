#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main() {
    long int no_of_tests;
    scanf("%ld",&no_of_tests);
    for (int test=0; test<no_of_tests; ++test) {
        long int R;
        long int C;
        long int sr;
        long int sc;
        long int tr;
        long int tc;
        scanf("%ld",&R);
        scanf("%ld",&C);
        scanf("%ld",&sr);
        scanf("%ld",&sc);
        scanf("%ld",&tr);
        scanf("%ld",&tc);
        sr = sr-1;
        sc = sc-1;
        tr = tr-1;
        tc = tc-1;
        long int nr,nc,cr,cc;
        bool **grid;
        grid = (bool**)malloc(R*sizeof(bool*));
        for (int i=0; i<R; ++i) {
            grid[i] = (bool*)malloc(C*sizeof(bool));
        }
        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                grid[i][j] = false;//unseen
            }
        }
        long int visited_count = 1;
        grid[sr][sc] = true;
        if (sr==tr && sc==tc) {
            printf("%ld\n",visited_count);
            break;
        }
        cr = sr;
        cc = sc;
        while(1) {
            if (cc+1<C && !grid[cr][cc+1]) {
                nr = cr;
                nc = cc+1;
            } else if (cr+1<R && !grid[cr+1][cc]) {
                nr = cr+1;
                nc = cc;
            } else if (cc-1>=0 && !grid[cr][cc-1]) {
                nr = cr;
                nc = cc-1;
            } else if (cr-1>=0 && !grid[cr-1][cc]) {
                nr = cr-1;
                nc = cc;
            } else {
                printf("Cannot reach target\n");
                break;
            }
            visited_count++;
            cr = nr;
            cc = nc;
            grid[cr][cc] = true;
            if (cr==tr && cc==tc) {
                printf("%ld\n",visited_count);
                break;
            }
        }

        for (int i=0; i<R; ++i) {
            free(grid[i]);
        }
        free(grid);
    }
    return 0;
}
