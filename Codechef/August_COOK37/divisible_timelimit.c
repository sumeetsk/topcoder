#include<stdio.h>
#include<stdlib.h>
int main() {
    long int N,Q;
    scanf("%ld",&N);
    scanf("%ld",&Q);
    long int* A = (long int*)malloc(N*sizeof(long int));
    for (long int i=0; i<N; ++i) {
        scanf("%ld",&A[i]);
    }
    long int L,R,K;
    long int count;
    long int index;
    for (long int i=0; i<Q; ++i) {
        count = 0;
        scanf("%ld",&L);
        scanf("%ld",&R);
        scanf("%ld",&K);
        L=L-1;
        R=R-1;
        for (index=L; index<=R; ++index) {
            if (!(A[index]%K))
                count++;
        }
        printf("%ld\n",count);
    }
    free(A);
    return 0;
}
