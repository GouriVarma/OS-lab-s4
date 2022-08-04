//Given memory partitions of 100kb,500kb,200kb,300kb and 600kb(in order).Write a program to allocate processes of 212 kb,417kb,112kb,and 426kb using first fit algorithm.

#include<stdio.h>



void firstfit(int blocksize[],int processsize[],int n,int m)

{

  int i,j;

  int allocation[n];

  

  for(i=0;i<n;i++)

    allocation[i]=-1;

    

  for(i=0;i<n;i++)

  {

    for(j=0;j<m;j++)

    {

      if(processsize[i]<=blocksize[j])

      {

         allocation[i]=j;

         blocksize[j] -= processsize[i];

         break;

      }

    }

  }

  printf("FIRST FIT\n");

  printf("Process no\tProcess size\tBlock size\n");

  for(int i=0;i<n;i++)

  {

    printf("%i\t\t",i+1);

    printf("%i\t\t",processsize[i]);

    if(allocation[i]!=-1)

      printf("%i",allocation[i] +1);

    else

      printf("Not allocated");

    printf("\n");

   }

}

 

int main()

{ 

 int m,n;

 int blocksize[] = {100,500,200,300,600};

 int processsize[] = {212,417,112,426};

 m = sizeof(blocksize)/sizeof(blocksize[0]);

 n = sizeof(processsize)/sizeof(processsize[0]);

 

 firstfit(blocksize,processsize,n,m);

 

 return 0;

}
