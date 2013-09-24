#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
typedef set<string> ss;
typedef vector<string> vs;
typedef map<char,int> mci;
ss permutations(string s) {
    if (s.length()==1){
        ss v;
        v.insert(s);
        return v;
    }
    else {
        ss ret;
        tr(s,i) {
            string rem = string(s.begin(),i)+string(i+1,s.end());
            ss temp = permutations(rem);
            tr(temp,j) {
                ret.insert(*i+*j);
            }
        }
        return ret;
    }
}

int main() {
    string s,t="";
    cin>>s;
    mci H;
    tr(s,i) {
        if (H.find(*i)!=H.end())
            H[*i]++;
        else
            H[*i]=1;
    }
    tr(H,i) {
        i->second /= 2;
        t += string(i->second,i->first);
    }
    ss v = permutations(t);
    vs v1;
    v1.assign(v.rbegin(),v.rend());

    bool success;
    tr(v1,i) {
        string t1 = *i;
        string t2(t1);
        string::iterator it1=t1.begin();
        tr(s,j) {
            if (*it1==*j) {
                it1++;
                if (it1==t1.end()) {
                    success = true;
                    break;
                }
                continue;
            }
            unsigned int it2=t2.find(*j);
            if (it2!=string::npos) {
                t2.erase(it2);
            }
            else {
                success = false;
                break;
            }
        }
        if (success==true) {
            string t3 = t1.assign(t1.rbegin(),t1.rend());
            cout<<t3<<endl;
            break;
        }
    }
    return 0;
}
