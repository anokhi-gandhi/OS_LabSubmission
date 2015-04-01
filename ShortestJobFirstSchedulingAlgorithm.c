//Shortest Job First Scheduling Algorithm
//Assuming all jobs arrive at time 0

#include<stdio.h>

void main()
{
  //Burst Time: Time taken by process to finish itself
  //Wait Time: Time for a process to get scheduled i.e. time for a process till the previous process gets completed.
  //TurnAroundTime: BurstTime+Wait Time 
  int noOfProc,i,k,temp,m,l;
  k=0;
  printf("\nEnter the no of processes:");
  scanf("%d",&noOfProc);
  int brstTim[noOfProc],WaitTim[noOfProc],TurnTim[noOfProc],proc[noOfProc],brstTim2[noOfProc];
  for(i=0;i<noOfProc;i++)
  	{
  		printf("\nEnter burst time for process %d:",i+1);
  		scanf("%d",&brstTim[i]);
  		brstTim2[i]=brstTim[i];
  		proc[i]=i+1;
  	}
  //sorting processes according to their burst time
  for(l=0;l<noOfProc;l++)
  {
 	 for(i=l+1;i<noOfProc;i++)
 	 {
  		if(brstTim[l]>brstTim[i])
  		{
  			temp=brstTim[i];
  			brstTim[i]=brstTim[l];
  			brstTim[l]=temp;
  		}
  	}
  }
 for(i=0;i<noOfProc;i++)
 {
 	for(l=0;l<noOfProc;l++)
 	{
 		if(brstTim2[i]==brstTim[l])
 		proc[l]=i+1;
 	}
 }
 
    	
 for(i=0;i<noOfProc;i++)
  	{
  		WaitTim[i]=k;
  		TurnTim[i]=WaitTim[i]+brstTim[i];
  		k=k+brstTim[i];
  	}
  printf("\nProcessNo burstTime WaitTime TurnAroundTime\n"); 
  for(i=0;i<noOfProc;i++)
  printf("%d	   %d	    %d        %d\n",proc[i],brstTim[i],WaitTim[i],TurnTim[i]);
  
}
