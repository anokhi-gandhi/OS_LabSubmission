//Lab 12
//LeastSlackTime Scheduling Algorithm
#include<stdio.h>
void main()
{

 int noOfProc,i,wait_prev,k,temp,m,l;
 
 printf("\nInput No of Processes:");
 scanf("%d",&noOfProc);
 
 int exec[noOfProc],start[noOfProc],deadline[noOfProc], flag[noOfProc];
 for(i=0;i<noOfProc;i++)
	flag[noOfProc] = 0;
 
 wait_prev = 0;
  
 
 
 for(i=0;i<noOfProc;i++)
 {
 	printf("\nInput start time, exec time and deadline for process %d:",i+1);
 	scanf("%d %d %d", &start[i], &exec[i], &deadline[i]);
 }
	
 int time_quatum      = 0;
 int end_false        = 1;
 int smallest_slack = 100;
 int index            = -1;
 int count            = 0;
 while(end_false)
 {
	for(i = 0; i< noOfProc;i++)
	{
	
		if(start[i] == time_quatum || exec[index] == 0)
		{
			if(exec[index] == 0)
			{
				smallest_slack = 100;
				index=-1;
			}
			
			if(flag[i] != 1)
			{
				if(((deadline[i] - time_quatum) - exec[i]) < smallest_slack)
				{
					smallest_slack = (deadline[i] - time_quatum);
					index            = i;
				}
			}
		}
		
		
	}
	printf("\n From time quantum %d to %d, proc %d", time_quatum,time_quatum+1, index+1);
	exec[index]--;
	if(exec[index] == 0)
	{
		flag[index]=1;
		count++;
	}
	
	if(count == noOfProc)
		end_false = 0;
	
 time_quatum++;
 }
 
}
