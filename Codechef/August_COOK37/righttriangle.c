#include<stdio.h>
#include<math.h>
int main() {
    long int no_of_tests;
    scanf("%ld",&no_of_tests);
    long int success_count=0;
    for (long int test=0; test<no_of_tests; ++test) {
        int x1,y1,x2,y2,x3,y3;
        scanf("%d",&x1);
        scanf("%d",&y1);
        scanf("%d",&x2);
        scanf("%d",&y2);
        scanf("%d",&x3);
        scanf("%d",&y3);
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
    printf("%ld\n",success_count);
    return 0;
}
