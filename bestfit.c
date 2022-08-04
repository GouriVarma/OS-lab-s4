//Given memory partitions of 100kb,500kb,200kb,300kb and 600kb(in order).Write a program to allocate processes of 212 kb,417kb,112kb,and 426kb using best fit algorithm.

#include<stdio.h>
void bestFit(int blockSize[], int blocks, int processSize[], int processes)
{

    int allocation[processes];
    


    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
 


    for (int i=0; i < processes; i++)
    {
        
        int indexPlaced = -1;
        for (int j=0; j < blocks; j++) 
        { 
            if (blockSize[j] >= processSize[i])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                    



                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
 

        if (indexPlaced != -1)
        {

            allocation[i] = indexPlaced;
 

            blockSize[indexPlaced] -= processSize[i];
        }
    }
 			printf("\t\tBest Fit");
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t %d \t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
	int m; 
	int n; 
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	m = sizeof(blockSize) / sizeof(blockSize1[0]);
	n = sizeof(processSize) / sizeof(processSize1[0]);
  return 0;
}
