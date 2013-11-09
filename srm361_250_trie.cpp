#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
#define M 10000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

class Trie {
    public:
        vector<int> wordPosition;
        vector<int> prefixPosition;
        map<char,Trie*> edges;
        void addWord(string word,int pos,int isWord);
};

class SearchBox {
    Trie* root;
    public:
        void createWordsFromText(string text, vector<string> &s, vector<int> &index);
        int find(string text, string search, string wholeWord, int start);
};

void SearchBox::createWordsFromText(string text, vector<string> &s, vector<int> &index) {
    int start = 0;
    int end = 0;
    while (end<text.size()) {
        while (text[end]!=' ' && end<text.size()) {
            end++;
        }
        s.push_back(text.substr(start,end-start));
        index.push_back(start);
        end++;
        start = end;
    }
}

int SearchBox::find(string text, string search, string wholeWord, int start) {
    root = new Trie;
    vector<string> v;
    vector<int> index;
    createWordsFromText(text,v,index);
    for (int i=0;i<v.size();++i) {
        root->addWord(v[i],index[i],1);
        for (int j=1;j<v[i].size();++j) {
            root->addWord(v[i].substr(j),index[i]+j,0);
        }
    }

    Trie* vertex = root;
    for (int i=0;i<search.size();++i) {
        char k = search[i];
        if ((vertex->edges).find(k)==(vertex->edges).end()) {
            return -1;
        }
        else
            vertex = vertex->edges[k];
    }
    vector<int> wordPositions = vertex->wordPosition;
    vector<int> prefixPositions = vertex->prefixPosition;
    if (wholeWord=="Y") {
        for (int i=0;i<wordPositions.size();++i) {
            if (wordPositions[i]>=start)
                return wordPositions[i];
        }
        return -1;
    }
    else {
        for (int i=0;i<prefixPositions.size();++i) {
            if (prefixPositions[i]>=start)
                return prefixPositions[i];
        }
        return -1;
    }
}

void Trie::addWord(string word, int pos, int isWord) {
    prefixPosition.push_back(pos);
    if (word.size()==0) {
        if (isWord)
            wordPosition.push_back(pos);
    }
    else {
        char k = word[0];
        if (edges.find(k)==edges.end()) {
            edges[k] = new Trie;
        }
        edges[k]->addWord(word.substr(1),pos,isWord);
    }
}

int main() {
    SearchBox t;
    cout<<t.find("All in all youre just another brick in the wall","just","Y",17)<<endl;
    return 0;
}
