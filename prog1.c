/*Note a program to create 2 processes.
One parent process must add odd number upto limit n,at the sametime child process must add even numbers upto n,also print the process id*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  int n,a1,a2,i;
  a1=a2=0;
  printf("Enter Limit: ");
  scanf("%d",&n);

  if(fork()==0)
  {
    printf("\nThis is the child process\n");
    for(i=0;i<=n;i=i+2)
    {
      a1 = a1+i;
    }
    printf("Sum of even numbers upto %d:%d ",n,a1);
    printf("\nThe Child process id is: %d",getpid());
  }
  else
  {
    printf("\nThis is the parent process\n");
    for(i=1;i<=n;i=i+2)
    {
      a2 = a2+i;
    }
    printf("Sum of odd numbers upto %d:%d ",n,a2);
    printf("\nThe Parent process id is: %d\n",getppid());
  }
}
