#include<stdio.h>
#include<stdlib.h>

void RR()
{
	int i, count, n, tq, temp1, sq=0, swt=0, stat=0;
	int st[10], tat[10], bt[10], wt[10];
	float awt=0.0, atat=0.0;

	printf("Enter the total number of processes : \n");
	scanf("%d",&n);

	printf("Enter the Time Quantum : \n");
	scanf("%d",&tq);

	printf("Enter Burst Time :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	{
	st[i]=bt[i];
	}

while(1)
{ // Write the variables
	for(i=0,count=0;i<n;i++)
	{
		temp1=tq;
		if(st[i]==0)
		{
			count++;
			continue;
		}

		if(st[i]>tq)
			st[i]=st[i]-tq;
		else
			if(st[i]>=0)
			{
				temp1=st[i];
				st[i]=0;
			}

		sq=sq+temp1;
		tat[i]=sq;
	}

	if(n==count)
		break;
}

for(i=0;i<n;i++)
{
	wt[i]=tat[i]-bt[i];
	swt=swt+wt[i];
	stat=stat+tat[i];
}

awt=(float)swt/n;
atat=(float)stat/n;
printf("Process No.	Burst Time	Wait Time	Turn Around Time\n");
for(i=0;i<n;i++)
{
	printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	printf("Average Waiting time is = %f \n Average Turn Around Time = %f\n",awt,atat);
}
}



int SJN()
{
int a[10],bt[10],x[10],i,j,smallest,count=0,time,n;
float avg=0,tt=0,end;

printf("enter the no of process\n");
scanf("%d",&n);

printf("enter arrival time\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);

}
printf("enter burst time\n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
x[i]=bt[i];
}

bt[9]=9999;

for(time=0;count!=n;time++)
{
smallest = 0;
	for(i=0;i<n;i++)
	{
		if(a[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
		{
			smallest=i;
		}
	}
		bt[smallest]--;
		if(bt[smallest]==0)
		{
			count++;
			end=time+1;
			avg=avg+end-a[smallest]-x[smallest];
			tt=tt+end-a[smallest];
		}
}
printf("\n average waiting time = %lf\n",avg/n);
printf("\n average turnarround time = %lf\n",tt/n);
return 0;
}

int main()
{	int choice;
	printf("enter your choice\n");
	printf("1--> shortest job Next\n");
	printf("2 --> round robin scheduling\n");
	printf("3 --> exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1: SJN();
		   break;
	case 2: RR();
		  break;
	case 3: exit(0);
	default: printf("invalid");
	}

}
