//
//  main.c
//  xml
//
//  Created by Hsieh Yu Hua on 2013/12/14.
//  Copyright (c) 2013年 Hsieh Yu Hua_NTHU_s102062210. All rights reserved.
//

#include"Stack.h"
#include<stdio.h>
#include <string.h>
int main()
{
    Stack *ps = InitStack();//棧初始化
    
    FILE *fp;
    fp=fopen("/Users/Andy/Downloads/testcase/testcase5.txt","rt");
    
    char s[30]={0};//保存<?xml version="1.0" ?>用 無視
    fgets(s, 30, fp);
    
    char buffer[1000]={0};
    int j=0;
    while ((buffer[j]=fgetc(fp))!=EOF)//把檔案全部保存到buffer去
    {
        j++;
    }
    
    char temp[20],temp2[20];
    int k=0,count=0,m=0;
    //k用來記錄:當找到關鍵字<>時，把關鍵字放入temp用,
    //count 用來記錄現在在字串哪裡
    
    int size=(int)strlen(buffer);//判斷所有字串總長度
    while (count<size)//當現在字串小於總長度
    {
        if((buffer[count]=='<')&&(buffer[count+1]!='/'))
            //讀到<xxx>形式（入棧）
        {
            k=count;
            m=0;
            do//把<xxx>複製到temp裡去,等再把temp丟入stack
            {
                temp[m]=buffer[k+1];
                k++;
                m++;
                count++;
            } while (buffer[k+1]!='>');
            temp[m]='\0';
            printf("我要入閘%s\n",temp);
            Push(ps, temp);//入棧
            
        }
        if((buffer[count]=='<')&&(buffer[count+1]=='/'))
            //讀到</xxxx>形式（出棧）
        {
            k=count;
            m=0;
            do//把<xxx>複製到temp裡去,Temp入棧
            {
                temp[m]=buffer[k+2];
                k++;
                m++;
                count++;
            } while (buffer[k+2]!='>');
            temp[m]='\0';
            
            GetTop(ps, &temp2);//取得棧的top_element
            if(strcmp(temp2, temp)!=0)//如果不相等,error結束
            {
                printf("[ERROR] tag mismatch\n");
                return 0;
            }
            else//確認相等，出棧
            {
                printf("%s出棧\n",temp2);
                Pop(ps, &temp2);
            }
        }
        
        
        count++;
    }

    ClearStack(ps);
    if(IsEmpty(ps))
        printf("\n将栈置空成功\n");
    DestroyStack(ps);
    printf("栈已被销毁\n");
    printf("[OK]");
    
    return 0;
    
}
