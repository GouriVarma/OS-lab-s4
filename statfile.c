//Write a C program to display the status of a given file
#include<stdio.h>

#include<sys/stat.h>

void statfile(struct stat buf);



int main()

{

  char path[100];

  struct stat buf;

  printf("enter path of the file");

  scanf("%s",path);

  stat(path,&buf);

  statfile(buf);

}



void statfile(struct stat buf)

{

  printf("\nuid: %d",buf.st_uid);

  printf("\nsize: %ld",buf.st_size);

}
