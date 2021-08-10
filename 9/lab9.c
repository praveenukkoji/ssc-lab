#include<stdio.h>
#include<stdlib.h>

int main()
{

int choice;
int i, j, n, a[50], frame[10], no, avail, count=0, hit;
int q[20], p[50], c=0, c1, d, f;
int k=0, r, t, b[20], c2[20];
printf("1--> LRU\n");
printf("2--> FIFO\n");
printf("enter a choice");
scanf("%d",&choice);

switch(choice)
{
	case 1 :
		printf("Enter the number of pages :\n");
		scanf("%d",&n);

		printf("Enter the refrence string :\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);

	printf("Enter the number of frames :\n");
	scanf("%d",&f);

	q[k]=p[k];

	printf("\n\t%d\n",q[k]);

	c++;
	k++;

	for(i=1;i<n;i++)
	{
		c1=0;

		for(j=0;j<f;j++)
		{
			if(p[i]!=q[j])
				c1++;
		}

		if(c1==f)
		{
			c++;
			if(k<f)
			{
				q[k]=p[i];
				k++;
				for(j=0;j<k;j++)
				printf("\t%d",q[j]);
				printf("\n");
			}

			else
			{
				for(r=0;r<f;r++)
				{
					c2[r]=0;
					for(j=i-1;j<n;j--)
					{
						if(q[r]!=p[j])
							c2[r]++;
						else
							break;
					}
				}
				for(r=0;r<f;r++)
					b[r]=c2[r];

				for(r=0;r<f;r++)
				{
					for(j=r;j<f;j++)
					{
						if(b[r]<b[j])
						{
							t=b[r];
							b[r]=b[j];
							b[j]=t;
						}
					}
				}

				for(r=0;r<f;r++)
				{
					if(c2[r]==b[0])
						q[r]=p[i];
					printf("\t%d",q[r]);
				}

				printf("\n");
			}
		}
	}

	printf("\nPage Fault = %d",c);

	hit = n-c;
	printf("\nPage Hit = %d\n",hit);
	break;
	case 2 :

	printf("Enter the number of pages : \n");
	scanf("%d",&n);

	printf("Enter the page number : \n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);

	printf("Enter the number of frames :\n");
	scanf("%d",&no);

	for(i=0;i<no;i++)
		frame[i]=-1;
	j=0;

	printf("Reference string \t Page Frames\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t\t\t",a[i]);
		avail=0;

		for(k=0;k<no;k++)

		if(frame[k]==a[i])
			avail=1;

		if(avail==0)
		{
			frame[j]=a[i];
			j=(j+1)%no;
			count++;

			for(k=0;k<no;k++)
			printf("%d\t",frame[k]);
		}

		printf("\n");
	}

	printf("Page Fault = %d\n",count);

	hit=n-count;
	printf("Page Hit = %d\n",hit);
	break;

	default:printf("enter valid choice\n");
}
}
