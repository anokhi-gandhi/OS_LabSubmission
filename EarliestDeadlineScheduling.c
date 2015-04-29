//LAB11
//Earliest Deadline First Scheduling Algorithm
//Assumption: The algorithm is implemented as non-preemptive algorithm.
//	      Here if the process starts before its deadline(completion time) but would end after its deadline goes that is it has a greater execution time than that processes are allowed to execute.
//	      if currentTime<deadline
//			if currentTime+executionTime>deadline
//				The process will get executed
#include<stdio.h>

void main()
{
 printf("\n--------------------------------\n");
 printf("Assumption:Here if the process starts before its deadline(completion time) but would end after its deadline goes that is it has a greater execution time than that processes are allowed to execute.");
 printf("\n--------------------------------\n");
 int noOfProc,i,wait_prev,k,temp,m,l;
 
 printf("\nEnter the no of processes:");
 scanf("%d",&noOfProc);
 
 int exec[noOfProc],start[noOfProc],deadline[noOfProc], flag[noOfProc],proc[noOfProc],deadline2[noOfProc];
 for(i=0;i<noOfProc;i++)
	flag[noOfProc] = 0;
 
 wait_prev = 0;
  
 
 
 for(i=0;i<noOfProc;i++)
 {
 	printf("\nEnter start time,execution time and Deadline of process %d:",i+1);
 	scanf("%d %d %d", &start[i],&exec[i],&deadline[i]);

 	deadline2[i]=deadline[i];
 }


 int time_quantum      = 0;
 int endtime;
 int smallest_slack = 10000;
 int index            = 0;
 int count            = 0;
 int startTime;
 
 //Sort Processes according to the Deadline
 for(l=0;l<noOfProc;l++)
  {
  	proc[i]=0;
 	 for(i=l+1;i<noOfProc;i++)
 	 {
  		if(deadline[l]>deadline[i])
  		{
  			temp=deadline[i];
  			deadline[i]=deadline[l];
  			deadline[l]=temp;
  			temp=exec[i];
  			exec[i]=exec[l];
  			exec[l]=temp;
  			temp=start[i];
  			start[i]=start[l];
  			start[l]=temp;
  		}
  	}
  }
 for(i=0;i<noOfProc;i++)
 {
 	for(l=0;l<noOfProc;l++)
 	{
 		if(deadline2[i]==deadline[l])
 		proc[l]=i+1;
 	}
 }
 //Schedule process according to the earliest Deadline
 i=0;
 int j,p;
 printf("\n ProcessNo	StartTime	EndTime		Deadline	Executed/Missed\n");
while(i<noOfProc)
 {
 	if(time_quantum<start[i])
 	{
 	        j=i;
 	        for(i=j+1;i<noOfProc;i++)
 	        {
 	        	if(time_quantum==start[i])
 	        	{
 	        		p=i;
 	        		count=time_quantum;
 				if(count>deadline[i])
 				{
 					printf("\n%d\t\t%d\t\t-\t\t%d\t\tMissed Deadline",proc[i],start[i],deadline[i]);
 				}
 				else
 				{
 					index=1;
 					startTime=time_quantum;
 					endtime=startTime+exec[i];
 					
 					printf("\n%d\t\t%d\t\t%d\t\t%d\t\tExecuted",proc[i],time_quantum,endtime,deadline[i]);
 					time_quantum=endtime+1;
 				}	
 				if(p==noOfProc-1)
 				noOfProc=noOfProc-1;
 				else
 				{
 					for(k=p;k<noOfProc-1;k++)
 					{
 					proc[k]=proc[k+1];
 					exec[k]=exec[k+1];
 					start[k]=start[k+1];
 					deadline[k]=deadline[k+1];
 					}
 					noOfProc=noOfProc-1;
 				}
 	        	}
 	        		
 	        }
 	        i=j;
 		time_quantum++;
 		continue;
 	}
 	else
 	{
 		count=time_quantum;
 		if(count>deadline[i])
 		{
 			printf("\n%d\t\t%d\t\t-\t\t%d\t\tMissed Deadline",proc[i],start[i],deadline[i]);
 		}
 		else
		{
 			startTime=time_quantum;
 			endtime=startTime+exec[i];
 			
 			printf("\n%d\t\t%d\t\t%d\t\t%d\t\tExecuted",proc[i],time_quantum,endtime,deadline[i]);
 			time_quantum=endtime+1;
 		}
 		i++;
 		
 	}
 }
printf("\n");
 
}
