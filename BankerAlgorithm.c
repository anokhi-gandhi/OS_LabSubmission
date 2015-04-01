#include<stdio.h>
void main()
{
int np,i,j,k,p,k_prev=0;
int totalResource[]={10,10,10};
int availableResource[]={0,0,0};
int blockResource=0;
int availableR[]={0,0,0};
printf("Enter the number of processes you want to initiate:");
scanf("%d",&np);
int maxNeed[np][3];
int currAlloc[np][3];
int needMatrix[np][3],h[np];
for(i=0;i<np;i++)
{
printf("Enter the resources needed by process %d",i+1);
	for(j=0;j<3;j++)
	{
	printf("\nEnter maximum claim for resource %d:",j+1);
	scanf("%d",&maxNeed[i][j]);
	}
	for(j=0;j<3;j++)
	{
	printf("\nEnter current allocation for resource %d:",j+1);
	scanf("%d",&currAlloc[i][j]);
	}
	h[i]=0;
}
for(i=0;i<np;i++)
{
	for(j=0;j<3;j++)
	{
	needMatrix[i][j]=maxNeed[i][j]-currAlloc[i][j];
	
	}
	
	
}
for(j=0;j<3;j++)
{
	for(i=0;i<np;i++)
	{
	availableR[j]+=currAlloc[i][j];
	}
}
for(i=0;i<3;i++)
	availableResource[i]=totalResource[i]-availableR[i];
k=0;
p=0;
reiterate:
k=0;
for(i=0;i<np;i++)
{
	int allocat=0;
	blockResource=0;

	for(j=0;j<3;j++)
	{
		if(needMatrix[i][j]>availableResource[j])
		blockResource++;
		else 
		allocat++;
	}

	if(allocat==3)
	{
		for(j=0;j<3;j++)
		{
			availableResource[j]=availableResource[j]+currAlloc[i][j];
			currAlloc[i][j]=0;
			needMatrix[i][j]=0;
		}
	}	

	if(blockResource>0)
	{
		h[i]=i+1;
		k++;
	}
}
if(k!=k_prev)
{
	k_prev=k;
	goto reiterate;
}
for(i=0;i<np;i++)
{
	for(j=0;j<3;j++)
		p=p+needMatrix[i][j];
}
if(p==0)
	printf("\nSafe State\n");
else
{
	printf("\nUnsafe State Detected\nLast Safe state need matrix");
	for(i=0;i<np;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
			printf("%d\t",needMatrix[i][j]);
	}
	for(i=0;i<np;i++)
	{
		if(h[i]!=0)
		printf("\nProcess which blocks resources:%d",h[i]);
	}
}
}
