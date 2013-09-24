#include <stdio.h>
int main()
{
	int t,a,b;
	long long int pairs,x,y;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		x=a/b;
		y=a%b;
		pairs=((x*x*b-x*b)/2)+x*y+x*((b-1)/2);
		if(y > b/2)
			pairs+=(y-(b/2));
		printf("%lld\n", pairs);
	}
	return 0;
} 
