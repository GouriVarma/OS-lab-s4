#include<stdio.h>



int main()

{

  int i,j,t,pos,total=0,n,avg_wt,avg_tat;

  printf("enter no of processes: ");

  scanf("%d",&n);

  int p[n],wt[n],bt[n],pr[n],tat[n];

  printf("enter priority and burst time");

  for(i=0;i<n;i++)

  {

    printf("\nP[%d]\n",i+1);

    printf("Priority: ");

    scanf("%d",&pr[i]);

    printf("Burst time: ");

    scanf("%d",&bt[i]);

    p[i] = i+1;

  }

  

  for(i =0;i<n-1;i++)

  {

    pos = i;

    for(j=i+1;j<n;j++)

    {

      if(pr[j]<pr[pos])

        pos = j;

    }

    

    

    t = pr[i];

    pr[i] = pr[pos];

    pr[pos]=t;

    

    t = bt[i];

    bt[i] = bt[pos];

    bt[pos] = t;

    

    t = p[i];

    p[i] = p[pos];

    p[pos] = t;

    

  }

  

  wt[0] = 0;

  for(i=1;i<n;i++)

  {

    wt[i]=0;

    for(j=0;j<i;j++)

    {

      wt[i] += bt[j];

    }

    total += wt[i];

  }

  avg_wt = total/n;

  total = 0;

  

  for(i=0;i<n;i++)

  {

    tat[i] = bt[i]+wt[i];

    total += tat[i]; 

  }

 avg_tat =total/n;

 

 printf("\nprocesses\tburst time\twaiting time\tturn around time");

 for(i=0;i<n;i++)

 {

   printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);

 }

 printf("\naverage waiting time: %d",avg_wt);

 printf("\naverage turn around time: %d",avg_tat);

 }
