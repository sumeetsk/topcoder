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
        int words;
        int prefixes;
        Trie* edges[26];
        Trie();
        void addWord(string word);
        int countWords(string word);
        int countPrefixes(string prefix);
};

Trie::Trie() {
    words = 0;
    prefixes = 0;
    for(int i=0;i<26;++i)
        edges[i] = NULL;
}

void Trie::addWord(string word) {
    if (word.size()==0) 
        words = words+1;
    else {
        prefixes = prefixes+1;
        char k = word[0];
        if (edges[k-'A']==NULL) {
            edges[k-'A'] = new Trie;
        }
        edges[k-'A']->addWord(word.substr(1));
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

int main() {
    Trie root;
    return 0;
}
