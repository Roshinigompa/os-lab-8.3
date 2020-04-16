#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
        int fd1[2],fd2[2],n;
        char buff[100];
        pid_t p;
        pipe(fd1);
        pipe(fd2);
        p=fork();
        if(p>0){
                close(fd1[0]);
                close(fd2[1]);
                printf("passing mesaage to child\n");
                write(fd1[1],"end term practical \n",19);
                wait(NULL);
                n=read(fd2[0],buff,100);
                write(1,buff,n);
                printf("Acknowledgement Recieved\n");
        }
  else
        {
                close(fd1[1]);
                close(fd2[0]);
                n=read(fd1[0],buff,100);
                write(1,buff,n);
                printf("sending acknowledgement\n");
                write(fd2[1],"Message recieved\n",17);
        }
}
