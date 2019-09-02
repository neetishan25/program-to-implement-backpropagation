#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
float d,dw2,err,i,j,D,v0[2],w1[4],w2[2],v2[2],o[2],n,m,fout,finput;
int x;
clrscr();
printf("enter value\n");

for(i=0;i<2;i++)
{
	scanf("\n%f",&v0[i]);
}
printf("\nenter weights");

for(i=0;i<=3;i++)
{
	scanf("\n%f",&w1[i]);
}
printf("\nenter weight for 2nd layer");

for(i=0;i<2;i++)
{
	scanf("\n%f",&w2[i]);
}
printf("\ndesired weight");
scanf("\n%f",&D);

do
{
	v2[1]=v0[1]*w1[1]+v0[2]*w1[2];
	v2[2]=v0[1]*w1[3]+v0[2]*w1[4];
	o[1]=1/(1+exp(-v2[1]));
	o[2]=1/(1+exp(-v2[2]));
	finput=o[1]*w2[1]+o[2]*w2[2];
	fout=1/(1+exp(-finput));
	d=D-fout;
	err=fout*(1-fout)*d;
	dw2=err*fout;
	
	for(i=0;i<2;i++)
	{
		w2[i]=w2[i]+dw2;
	}
	printf("\ndiff is %f",d);
	printf("\nweight of final layer is");
	
	for(i=0;i<2;i++)
	{
		printf("\x%f",w2[i]);
	}
	printf("\ndo u want to continue:\tyes:1 \tno:0");
	scanf("\n\x\x\x%d",&x);
	}
	while(x==1);
	for(i=0;i<2;i++)
	{
		printf("\nfinal weight is %f",w2[i]);
}
getch();
}
