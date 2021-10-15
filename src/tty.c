#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>

#include"string.h"
#include"stdio.h"

#define CMD_LENGTH 20

void clear();

size_t pieces(char pieces[][CMD_LENGTH],char *buffer)
{
    for(size_t x=0;x<CMD_LENGTH;x++) for(size_t y=0;y<CMD_LENGTH;y++) pieces[x][y]='\0';

    size_t i=0,j=0,r=0;
    while(buffer[i]==' '&&buffer[i]!='\0') i++;
    for(;buffer[i]!='\0';i++)
    {
	if(buffer[i]==' ')
	{
	    while(buffer[i]==' '&&buffer[i]!='\0') i++;
	    j=0;
	    r++;
	    i--;
	}
	else
	{
	    pieces[r][j++]=buffer[i];
	}
    }
    return r+1;
}

void echo(size_t numberof,char parts[][CMD_LENGTH])
{
    for(size_t i=1;i<numberof;i++)
    {
	printf("%s ",parts[i]);
    }
    printf("\n");
}

void merge(char parts[][CMD_LENGTH])
{
    char *str1=parts[1];
    char *str2=parts[2];
    stringcat(str1,str2);
    printf("%s\n",str1);
}

void ls(size_t numberof,char parts[][CMD_LENGTH])
{
    size_t i=numberof;
    char *part=parts[0];
    printf("filesystem not implemented yet\n");
}

void tty(char *buffer)
{
    char parts[CMD_LENGTH][CMD_LENGTH];
    size_t numberof=pieces(parts,buffer);
    if(stringcmp(parts[0],"clear")) clear();
    else if(stringcmp(parts[0],"echo")) echo(numberof,parts);
    else if(stringcmp(parts[0],"merge")) merge(parts);
    else if(stringcmp(parts[0],"ls")) ls(numberof,parts);
    else if(stringcmp(parts[0],"number")) printf("number times two is %d\n",stoi(parts[1])*2);
    else printf("command not found: %s\n",parts[0]);
}
