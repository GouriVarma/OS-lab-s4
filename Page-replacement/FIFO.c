#include<stdio.h>
void FIFO(int prs[], int n, int frame);
void print(int [],int);

void main()
{
	int n,i,frame;
	printf("Enter the Length of sequence : ");
	scanf("%d",&n);
	int prs[n];
	printf("Enter the Sequence : ");
	for(i=0;i<n;i++)
		scanf("%d",&prs[i]);
	printf("Enter the number of frame : ");
	scanf("%d",&frame);
	FIFO(prs,n,frame); 
}
	
void FIFO(int prs[], int n, int frame)
	{
		int pagefault = 0, hit=0,i,j,s;
		int temp[frame];
		printf("\nValues\t");
		for(i=1;i<=f;i++)
			printf("Frame%d\t",i);
		printf("\n");
		for(i= 0; i< frame; i++)
		{
			temp[i] = -1;
		}
		for(i= 0; i< n; i++)
		{
			s = 0;
			for(j = 0; j < frame; j++)
			{
				
				if(prs[i] == temp[j])
				{
					s++;
					pagefault--;
				}
			}     
			pagefault++;
			if((pagefault <= frame) && (s == 0))
			{
				temp[i] = prs[i];
			}   
			else if(s == 0)
			{
				temp[(pagefault - 1) % frame] = prs[i];
			}
			printf("\n");
			printf("%d\t",prs[i]);
			for(j = 0; j < frame; j++)
			{ 
				if(temp[j]!=-1)
					{
						printf("%d\t", temp[j]);
					}
				else
					{
						printf("\t");
					}
			}
		} 
		printf("\nTotal Page Faults: %d\n", pagefault);
	}
