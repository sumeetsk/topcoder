#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    for (int k=0;k<cases;++k) {
        int m,n;
        char **grid;
        cin>>m>>n;
        if (m<=4 || n<=4) {
            cout<<0<<endl;
            return 0;
        }
        grid = (char **)malloc(m*sizeof(char *));
        for (int i=0;i<m;++i)
            grid[i] = (char *)malloc(n*sizeof(char));
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                cin>>grid[i][j];
            }
        }

        int t=0;
        for (int i=2;i<m-2;++i) {
            for (int j=2;j<n-2;++j) {
                if (grid[i][j]=='^' && grid[i-1][j]=='^' && grid[i-2][j]=='^' && grid[i+1][j]=='^' && grid[i+2][j]=='^' && grid[i][j-1]=='^' && grid[i][j-2]=='^' && grid[i][j+1]=='^' && grid[i][j+2]=='^')
                    t++;
            }
        }
        cout<<t<<endl;
        for (int i=0; i<m; ++i)
            free(grid[i]);
        free(grid);
    }
    return 0;
}              
