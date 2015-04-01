//FCFS scheduling implementation
#include<stdio.h>
//Assuming that all the process arrive at time 0.

void main()
{
  //Burst Time: Time taken by process to finish itself
  //Wait Time: Time for a process to get scheduled i.e. time for a process till the previous process gets completed.
  //TurnAroundTime: serviceTime+Wait Time 
  int noOfProc,i,k;
  k=0;
  printf("\nEnter the no of processes:");
  scanf("%d",&noOfProc);
  int brstTim[noOfProc],WaitTim[noOfProc],TurnTim[noOfProc];
  //Input the burst time for each process
  for(i=0;i<noOfProc;i++)
  	{
  		printf("\nEnter burst time for process %d:",i+1);
  		scanf("%d",&brstTim[i]);
  	}
  //Compute wait time and turn around time for each process.
  for(i=0;i<noOfProc;i++)
  	{
  		WaitTim[i]=k;
  		TurnTim[i]=WaitTim[i]+brstTim[i];
  		k=k+brstTim[i];
  	}
  printf("\nProcess\tWaitTime TurnAroundTime\n"); 
  for(i=0;i<noOfProc;i++)
  printf("%d	  %d	  %d\n",i+1,WaitTim[i],TurnTim[i]);
  
}
