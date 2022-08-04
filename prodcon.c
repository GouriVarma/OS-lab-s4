//Write a program to implement producer consumer problem using semaphores


#include<stdio.h>

#include<stdlib.h>



void producer();

void consumer();

int wait(int s);

int signal(int s);

int mutex=1,empty = 5,full =0,x=0,ch;

int main()

{

 printf("1.Producer\n2.Consumer\n3.Exit\n");

 do{

    

     printf("ENTER CHOICE\n");

     printf("1.Producer\n2.Consumer\n3.Exit\n");

     scanf("%d",&ch);

  

     switch(ch)

     {

       case 1:

              if((mutex ==1) && (empty!=0))

                 producer();

              else

                printf("buffer is full");

              break;

              

       case 2:

              if((mutex ==1) && (full!=0))

                 consumer();

              else

                printf("buffer is empty");

              break;

              

       case 3:

            printf("Going to exit");

            break;

            

       default:

            printf("invalid choice");

      }

      

    }while(ch!=3);

}

int wait(int s)

{

  return(--s);

}

int signal(int s)

{

  return(++s);

}

void producer()

{

  mutex = wait(mutex);

  full = signal(full);

  empty = wait(empty);

  x++;

  printf("producer produces item %d",x);

  mutex =  signal(mutex);

}

void consumer()

{

  mutex = wait(mutex);

  full = wait(full);

  empty = signal(empty);

  printf("consumer consumes item %d",x);

  x--;

  mutex = signal(mutex);

}

