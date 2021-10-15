#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>

size_t stringlen(char *str)
{
    size_t i;
    for(i=0;str[i]!='\0';i++) ;
    i--;

    return i;
}

bool stringcmp(char *str1,char *str2)
{
    size_t i;
    for(i=0;str1[i]||str2[i];i++) if(str1[i]!=str2[i]) return 0;
    if(str1[i]==str2[i]) return 1;
    return 0;
}

void stringcat(char *str1,char *str2)
{
    char *tmp=str1;
    while(*tmp) tmp++;
    while(*str2) *tmp++=*str2++;
}

void stringrev(char *str)
{
    size_t i=stringlen(str);

    for(size_t j=0;j<i-j;j++)
    {
	char tmp=str[i-j];
	str[i-j]=str[j];
	str[j]=tmp;
    }
}

void itos(char *str,uint32_t num)
{
    size_t i;
    for(i=0;num>0;num/=10,i++) str[i]='0'+num%10;
    str[i]='\0';
    stringrev(str);
}

uint32_t stoi(char *str)
{
    uint32_t num=0;
    for(size_t i=0;str[i]!='\0';i++)
    {
	num*=10;
	num+=str[i]-'0';
    }
    return num;
}
