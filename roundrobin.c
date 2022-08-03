#include<stdio.h>

int main()

{

 int i,time,flag,tq,remain,n,bt[10],rt[10],tat[10],wt[10],at[10];

 int sum_wait,sum_tat;

 printf("enter the number of processes: ");

 scanf("%d",&n);

 remain = n;

 for(i=0;i<n;i++)

 {

   printf("\nenter arrival time of process %d : ",i+1);

   scanf("%d",&at[i]);

   printf("enter burst time of process %d : ",i+1);

   scanf("%d",&bt[i]);

   rt[i] = bt[i];

 }

 printf("\nenter the time quantum: ");

 scanf("%d",&tq);

 printf("\n\nProcess\t|\tTurnaround time\t|\twaiting time\n\n");

 for(time=0,i=0;remain!=0;)

 {

   if(rt[i]>0 && rt[i]<=tq)

   {

     time +=rt[i];

     rt[i] = 0;

     flag = 1;

   }

   else if(rt[i]>0)

   {

     rt[i] -=tq;

     time +=tq;

   }

  if(rt[i]==0 && flag == 1)

  {

    remain--;

    printf("p[%d]\t|\t%d|\t%d\n",i+1,time-at[i],time-bt[i]);

    sum_wait +=time - at[i] - bt[i];

    sum_tat +=time -at[i];

    flag =0 ;

  }

   if(i==n-1)

    i=0;

   else if(at[i+1]<=time)

    i++;

   else

    i=0;

 } 

 printf("\nTotal waiting time = %d\n",sum_wait);

 printf("\nTotal turn around time = %d\n",sum_tat);

 printf("\nAverage waiting time = %f\n",sum_wait*1.0/n);

 printf("\nAverage turn around time = %f",sum_tat*1.0/n);

return 0;

}



