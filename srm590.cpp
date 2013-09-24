#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
using namespace std;
class FoxAndGomoku {
    public:
        string win(vector<string> board);
        void printall(int **top, int **upright, int **upleft, int **left, int n);
};

void FoxAndGomoku::printall(int **top, int **upright, int **upleft, int **left, int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout<<top[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout<<upright[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout<<upleft[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout<<left[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

string FoxAndGomoku::win(vector<string> board) {
    int n=board.size();
    int **top,**upright,**upleft,**left;
    top = (int **)malloc(n*sizeof(int *));
    upright = (int **)malloc(n*sizeof(int *));
    upleft = (int **)malloc(n*sizeof(int *));
    left = (int **)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++) {
        top[i] = (int *)malloc(n*sizeof(int));
        upright[i] = (int *)malloc(n*sizeof(int));
        upleft[i] = (int *)malloc(n*sizeof(int));
        left[i] = (int *)malloc(n*sizeof(int));
    }
    for (int i=0;i<n;++i) {
        if (board[0][i]=='o') {
            top[0][i]=1;
            upright[0][i] = 1;
            upleft[0][i] = 1;
        }
        else {
            top[0][i]=0;
            upright[0][i] = 0;
            upleft[0][i] = 0;
        }

        if (board[i][0]=='o') {
            left[i][0] = 1;
            upleft[i][0] = 1;
        }
        else {
            left[i][0] = 0;
            upright[i][0] = 0;
        }

        if (board[i][n-1] == 'o') {
            upright[i][n-1] = 1;
        }
        else {
            upright[i][n-1] = 0;
        }
    }
    int inew,jnew;
    for (int i=1;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (board[i][j]=='.') {
                top[i][j]=0;
                upright[i][j]=0;
                upleft[i][j]=0;
            }
            else {
                top[i][j] = top[i-1][j]+1;
                if (top[i][j]>=5)
                    return("found");
                if (j>0) {
                    upleft[i][j] = upleft[i-1][j-1]+1;
                    if (upleft[i][j]>=5)
                        return("found");
                }
                if (j<n-1) {
                    upright[i][j] = upright[i-1][j+1]+1;
                    if (upright[i][j]>=5)
                        return("found");
                }
            }

            inew = j;
            jnew = i;
            if (board[inew][jnew]=='.') {
                left[inew][jnew]=0;
            }
            else {
                left[inew][jnew] = left[inew][jnew-1]+1;
                if (left[inew][jnew]>=5)
                    return("found");
            }
        }
    }
    return("not found");
}

int main(int argc, char* argv[]) {
    string str;
    vector<string> board;
    cin>>str;
    while(str!="#") {
        board.push_back(str);
        cin>>str;
    }
    FoxAndGomoku o;
    cout<<o.win(board)<<endl;
    return 0;
}
