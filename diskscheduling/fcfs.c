#include<stdio.h>

#include<stdlib.h>

void fcfs(int[],int,int);

void main()

{

 int n,i,ihead;

 printf("-----fccfs disk scheduling algorithm-------\n");

 printf("enter the no of requests: ");

 scanf("%d",&n);

 int req[n];

 printf("enter the sequence: ");

 for(i=0;i<n;i++)

    scanf("%d",&req[i]);

 printf("enter initial head: ");

 scanf("%d",&ihead);

 fcfs(req,ihead,n);

 }

 void fcfs(int p[],int ihead,int n)

 {

   int i,total = 0;

   for(i=0;i<n;i++)

   {

     total = total+abs(p[i]-ihead);

     ihead = p[i];

   }

   printf("\ntotal head movement = %d\n",total);

 }
