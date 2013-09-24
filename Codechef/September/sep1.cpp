#include<iostream>
#include<cstdlib>
using namespace std;

int calculateTop(char **grid,int i,int j) {
    int t=0;
    for (int c=i-1;c>=0;--c) {
        if (grid[c][j]=='#')
            return t;
        else
            t++;
    }
    return t;
}

int calculateBottom(char **grid, int i, int j, int m) {
    int t=0;
    for (int c=i+1;c<m;++c) {
        if (grid[c][j]=='#')
            return t;
        else
            t++;
    }
    return t;
}

int calculateRight(char **grid, int i, int j, int n) {
    int t=0;
    for (int c=j+1;c<n;++c) {
        if (grid[i][c]=='#')
            return t;
        else
            t++;
    }
    return t;
}

int calculateLeft(char **grid,int i,int j) {
    int t=0;
    for (int c=j-1;c>=0;--c) {
        if (grid[i][c]=='#')
            return t;
        else
            t++;
    }
    return t;
}

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
        int **top,**left,**bottom,**right;
        top = (int **)malloc((m-4)*sizeof(char *));
        bottom = (int **)malloc((m-4)*sizeof(char *));
        left = (int **)malloc((m-4)*sizeof(char *));
        right = (int **)malloc((m-4)*sizeof(char *));
        for (int i=0;i<m-4;++i) {
            top[i] = (int *)malloc((n-4)*sizeof(char));
            bottom[i] = (int *)malloc((n-4)*sizeof(char));
            left[i] = (int *)malloc((n-4)*sizeof(char));
            right[i] = (int *)malloc((n-4)*sizeof(char));
        }
        for (int i=2;i<m-2;++i) {
            for (int j=2;j<n-2;++j) {
                if (i==2 && j==2) {
                    top[i-2][j-2] = calculateTop(grid,i,j);
                    left[i-2][j-2] = calculateLeft(grid,i,j);
                    right[i-2][j-2] = calculateRight(grid,i,j,n);
                    bottom[i-2][j-2] = calculateBottom(grid,i,j,m);
                }
                else if (i==2) {
                    left[i-2][j-2] = (grid[i][j-1]=='#')?0:left[i-2][j-3]+1;
                    right[i-2][j-2] = (grid[i][j]=='#')?calculateRight(grid,i,j,n):right[i-2][j-3]-1;
                    top[i-2][j-2] = calculateTop(grid,i,j);
                    bottom[i-2][j-2] = calculateBottom(grid,i,j,m);
                }
                else if (j==2) {
                    top[i-2][j-2] = (grid[i-1][j]=='#')?0:top[i-3][j-2]+1;
                    bottom[i-2][j-2] = (grid[i][j]=='#')?calculateBottom(grid,i,j,m):bottom[i-3][j-2]-1;
                    left[i-2][j-2] = calculateLeft(grid,i,j);
                    right[i-2][j-2] = calculateRight(grid,i,j,n);
                }
                else {
                    top[i-2][j-2] = (grid[i-1][j]=='#')?0:top[i-3][j-2]+1;
                    left[i-2][j-2] = (grid[i][j-1]=='#')?0:left[i-2][j-3]+1;
                    right[i-2][j-2] = (grid[i][j]=='#')?calculateRight(grid,i,j,n):right[i-2][j-3]-1;
                    bottom[i-2][j-2] = (grid[i][j]=='#')?calculateBottom(grid,i,j,m):bottom[i-3][j-2]-1;
                }

            }
        }

        int result=0;
        for (int i=2;i<m-2;++i) {
            for (int j=2;j<n-2;++j) {
                if (grid[i][j]=='^' && top[i-2][j-2]>=2 && bottom[i-2][j-2]>=2 && right[i-2][j-2]>=2 && left[i-2][j-2]>=2)
                    result++;
            }
        }
        cout<<result<<endl;
        for (int i=0;i<m-4;i++) {
            for (int j=0;j<n-4;j++) {
                cout<<top[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i=0;i<m-4;i++) {
            for (int j=0;j<n-4;j++) {
                cout<<bottom[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i=0;i<m-4;i++) {
            for (int j=0;j<n-4;j++) {
                cout<<left[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i=0;i<m-4;i++) {
            for (int j=0;j<n-4;j++) {
                cout<<right[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        for (int i=0; i<m; ++i) {
            free(grid[i]);
        }
        for (int i=0;i<m-4;++i) {
            free(top[i]);
            free(bottom[i]);
            free(left[i]);
            free(right[i]);
        }
        free(grid);
        free(top);
        free(left);
        free(right);
        free(bottom);
    }
    return 0;
}              
