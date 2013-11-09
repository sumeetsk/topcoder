#include<iostream>
#include<sstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define M 200

class Trie {
    public:
        int words;
        int prefixes;
        int firstrow, firstcol;
        Trie* edges[26];
        Trie();
        void addWord(string word,int row, int col);
        int countWords(string word);
        int countPrefixes(string prefix);
        string findWord(string word);
};

class WordFind {
    public:
        string findVerticalWord(vector<string> grid,int i,int j,int rows,int cols);
        string findDiagonalWord(vector<string> grid,int i,int j,int rows,int cols);
        vector<string> findWords(vector<string> grid, vector<string> wordList);
};

Trie::Trie() {
    words = 0;
    prefixes = 0;
    firstrow = M;
    firstcol = M;
    for(int i=0;i<26;++i)
        edges[i] = NULL;
}

void Trie::addWord(string word,int row,int col) {
    if (row<firstrow) {
        firstrow = row;
        firstcol = col;
    }
    if (row==firstrow && col<firstcol) {
        firstcol = col;
    }
    if (word.size()==0) 
        words = words+1;
    else {
        prefixes = prefixes+1;
        char k = word[0];
        if (edges[k-'A']==NULL) {
            edges[k-'A'] = new Trie;
        }
        edges[k-'A']->addWord(word.substr(1),row,col);
    }
}

int Trie::countWords(string word) {
    if (word.size()==0)
        return words;
    else {
        char k = word[0];
        if (edges[k-'A']==NULL)
            return 0;
        else {
            return edges[k-'A']->countWords(word.substr(1));
        }
    }
}

int Trie::countPrefixes(string prefix) {
    if (prefix.size()==0)
        return prefixes;
    else {
        char k = prefix[0];
        if (edges[k-'A']==NULL)
            return 0;
        else {
            return edges[k-'A']->countPrefixes(prefix.substr(1));
        }
    }
}

string Trie::findWord(string word) {
    Trie* vertex = this;
    for (int i=0;i<word.size();++i) {
        char k=word[i];
        if (vertex->edges[k-'A']==NULL)
            return "";
        else {
            vertex = vertex->edges[k-'A'];
        }
    }
    stringstream ss;
    ss<<vertex->firstrow<<" "<<vertex->firstcol;
    return ss.str();
}

vector<string> WordFind::findWords(vector<string> grid, vector<string> wordList) {
    Trie* root;
    root = new Trie;
    int rows  = grid.size();
    int cols = grid[0].size();
    for (int i=0;i<rows;++i) {
        for (int j=0;j<cols;++j) {
            string horiword = grid[i].substr(j);
            root->addWord(horiword,i,j);
            if (!(i==rows-1 && j==cols-1)) {
                string vertword = findVerticalWord(grid,i,j,rows,cols);
                root->addWord(vertword,i,j);
            }
            if (j!=cols-1 && i!=rows-1) {
                string diagword = findDiagonalWord(grid,i,j,rows,cols);
                root->addWord(diagword,i,j);
            }
        }
    }
    vector<string> v;
    for (int i=0;i<wordList.size();++i) {
        v.push_back(root->findWord(wordList[i]));
    }
    return v;
}

string WordFind::findVerticalWord(vector<string> grid,int i,int j,int rows,int cols) {
    string s = "";
    for (int count=i;count<rows;++count) {
        s += grid[count][j];
    }
    return s;
}

string WordFind::findDiagonalWord(vector<string> grid,int i,int j,int rows,int cols) {
    string s = "";
    for (int count1=i,count2=j;count1<rows && count2<cols;++count1,++count2) {
        s += grid[count1][count2];
    }
    return s;
}

int main() {
    vector<string> grid;
    grid.push_back("EASYTOFINDEAGSRVHOTCJYG");
    grid.push_back("FLVENKDHCESOXXXXFAGJKEO");
    grid.push_back("YHEDYNAIRQGIZECGXQLKDBI");
    grid.push_back("DEIJFKABAQSIHSNDLOMYJIN");
    grid.push_back("CKXINIMMNGRNSNRGIWQLWOG");
    grid.push_back("VOFQDROQGCWDKOUYRAFUCDO");
    grid.push_back("PFLXWTYKOITSURQJGEGSPGG");

    vector<string> v,retv;
    v.push_back("EASYTOFIND");
    v.push_back("DIAG");
    v.push_back("GOING");
    v.push_back("THISISTOOLONGTOFITINTHISPUZZLE");
    WordFind w;
    retv = w.findWords(grid,v);
    for(int i=0;i<retv.size();++i) {
        cout<<retv[i]<<endl;
    }
    return 0;
}
