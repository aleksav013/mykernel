#include"../include/types.h"

size_t stringlen(char *str)
{
    size_t i;

    for(i=0;str[i]!='\0';i++) ;

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
    *tmp=*str2;
}

void stringcpy(char *str1,char *str2)
{
    for(size_t i=0;str2[i]!='\0';i++) str1[i]=str2[i];
}

void stringrev(char *str)
{
    size_t i=stringlen(str)-1;

    for(size_t j=0;j<i-j;j++)
    {
	char tmp=str[i-j];
	str[i-j]=str[j];
	str[j]=tmp;
    }
}

uint32_t stoi(const char *str)
{
    uint32_t num=0;

    for(size_t i=0;str[i]!='\0';i++)
    {
	if(str[i]<'0'||str[i]>'9') return num;
	num*=10;
	num+=str[i]-'0';
    }

    return num;
}

void itos(uint32_t num,char *str)
{
    if(num==0) stringcpy(str,"0");
    else
    {
	size_t i=0;
	for(;num>0;num/=10,i++) str[i]='0'+num%10;
	str[i]='\0';

	stringrev(str);
    }
}

double stof(const char *str)
{
    double num=0;

    bool point=0;
    uint32_t pow=1;
    size_t i=0;

    for(;str[i]!='\0';i++)
    {
	if(str[i]=='.')
	{
	    if(point) return num/pow;
	    point=1;
	    continue;
	}
	if(str[i]<'0'||str[i]>'9') return num/pow;
	num*=10;
	num+=str[i]-'0';
	if(point) pow*=10;
    }

    return num/pow;
}

const int decimals=7;
void ftos(double num, char *str)
{
    itos((uint32_t)num,str);

    stringcat(str,".");
    char c[2];
    c[1]='\0';

    for(size_t i=0;i<decimals;i++)
    {
	num-=(uint32_t)num;
	num*=10;
	c[0]=(uint32_t)num+'0';
	stringcat(str,c);
    }
}
