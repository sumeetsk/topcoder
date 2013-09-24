#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;
class PaperRockScisQuals {
    public:
        int whoPassed(vector<string>);
    private:
        int findDifferenceOfPoints(string a, string b);
};

int PaperRockScisQuals::whoPassed(vector<string> players) {
    double* points = (double*)malloc(players.size()*sizeof(double));
    for (int i=0; i<players.size(); ++i) {
        points[i] = 0;
    }
    string a,b;
    for (int i=0; i<players.size(); ++i) {
        for (int j=i+1; j<players.size(); ++j) {
            a = players[i];
            b = players[j];
            int differencePoints = findDifferenceOfPoints(a,b);
            if (differencePoints>0)
                points[i]++;
            else if (differencePoints<0)
                points[j]++;
            else {
                points[i]+=.5;
                points[j]+=.5;
            }
        }
    }
    int winner = players.size()-1;
    for (int i=players.size()-1; i>=0; --i) {
        if (points[i]>=points[winner])
            winner=i;
    }
    return(winner);
}

int PaperRockScisQuals::findDifferenceOfPoints(string a, string b) {
    int apoints = 0;
    int bpoints = 0;
    for (int k=0; k<5; ++k) {
        char acur = a[k];
        char bcur = b[k];
        switch (acur) {
            case 'R':
                if (bcur=='P') {
                    bpoints++;
                }
                if (bcur=='S') {
                    apoints++;
                }
                break;
            case 'S':
                if (bcur=='P') {
                    apoints++;
                }
                if (bcur=='R') {
                    bpoints++;
                }
                break;
            case 'P':
                if (bcur=='S') {
                    bpoints++;
                }
                if (bcur=='R') {
                    apoints++;
                }
                break;
        }
    }
    return (apoints-bpoints);
}

int main(int argc, char* argv[]) {
    PaperRockScisQuals a;
    vector<string> b;
    /*b.push_back("PPRPS");
    b.push_back("RRRPR");
    b.push_back("SSPRS");
    b.push_back("SSPRR");
    b.push_back("PPRSP");
    b.push_back("SPRPS");
    b.push_back("SPRSP");
    b.push_back("PRSPR");
    b.push_back("PRSPR");*/
    b.push_back("RRRRR");
    b.push_back("PPPPP");
    b.push_back("SSSSS");
    b.push_back("SSSSS");
    b.push_back("RRRRR");
    b.push_back("RRRRR");
    int s = a.whoPassed(b);
    cout<<s<<endl;
    return(1);
}
