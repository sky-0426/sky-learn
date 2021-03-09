# minishell的实现

## 实现逻辑

1. 从标准输入当中读取数据(要执行的可执行程序)
2. 拆分可执行程序名称和命令行参数，我们认为从标准输入当中读取到的内容第一个空格之前的数据是可执行程序的名称，第一个空格之后的内容都认为是命令行参数
3. 创建子进程，子进程程序替换可执行程序
4. 在子进程程序替换时间内，让父进程进行等待进程等待
5. isspace()函数，判断一个字符是否有空白字符(空格、换页符、换行符、回车、水平指标符、垂直制表符)
   - 返回值，返回0为没有读到了空白字符，返回非0读到了空白字符

## 代码实现

```cpp
#include <stdio.h>
#include <unistd.h>
#include <string.h>
//保存字符的ASCII码值
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>

char g_command[1024];

//从标准输入当中获取命令
int GetCommand()
{
    //清空字数组
    memset(g_command,'\0',sizeof(g_command));
    //gets()存在bug,并不会控制读多少数据
    //按行读取
    printf("[sky@localhost minshell]$ ");                                                                        
    //刷新缓冲区
    fflush(stdout);
    //-1是为\0预留位置
    if(fgets(g_command,sizeof(g_command)-1,stdin)==NULL)
    {   
        printf("fgets error\n");
        return -1; 
    }   
    return 0;
}

int ExecCommand(char* argv[])
{
    if(argv[0]==NULL)
    {
        printf("ExecCommand error\n");
        return -1;
    }
    pid_t pid=fork();
    if(pid<0)
    {
        printf("create subprocess fail\n");
        return -1;
    }
    else if(pid==0)
    {
        execvp(argv[0],argv);
        //万一替换失败，一定要杀掉
        exit(0);
    }
    else
    {
        waitpid(pid,NULL,0);
    }
    return 0;
}  

int DealCommand(char* command)
{
    //差错控制，排除无效参数
    if(!command && *command=='\0')
    {
        printf("command error\n");
        return -1;
    }

    //拆分命令
    int argc=0;
    char* argv[1024]={0};
    while(*command)
    {
        while(!isspace(*command) && *command!='\0')
        {
            //argv[0]=ls\0-al
            argv[argc]=command;
            argc++;
            while(!isspace(*command) && *command != '\0')
            {
                command++;
            }
            *command='\0';
        }
        command++;
    }  
        argv[argc]=NULL;
    for(int i=0;i<argc;i++)
    {
        printf("argv[%d]=%s\n",i,argv[i]);
    }
    //创建子进程，子进程进程程序替换
    ExecCommand(argv);
    return 0;
}

int main()
{
    //循环保证minishell程序不会退出
    while(1)
    {
        if(GetCommand()==-1)
        {
            continue;
        }
        //拆分字符串，创建子进程进行进程程序替换
       DealCommand(g_command); 
    }
    return 0;
}
```

