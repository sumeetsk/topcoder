#include<iostream>
#include<cmath>
using namespace std;
int main() {
    long int no_of_tests;
    cin>>no_of_tests;
    long int success_count=0;
    for (long int test=0; test<no_of_tests; ++test) {
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        int l_sqr[3];
        l_sqr[0] = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        l_sqr[1] = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
        l_sqr[2] = (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
        int max_length,max_index;
        max_length = 0;
        max_index = 0;
        for (int i=0; i<3; ++i) {
            if (l_sqr[i]>max_length){
                max_index = i;
                max_length = l_sqr[i];
            }
        }
        int index1 = (max_index+1)%3;
        int index2 = (max_index+2)%3;
        if (l_sqr[max_index]==(l_sqr[index1]+l_sqr[index2])) {
            success_count++;
        }
    }
    cout<<success_count<<endl;
    return(1);
}
