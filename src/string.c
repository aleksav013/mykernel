#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>

bool stringcmp(char *str1,char *str2)
{
    size_t i;
    for(i=0;str1[i]||str2[i];i++) if(str1[i]!=str2[i]) return 0;
    if(str1[i]==str2[i]) return 1;
    return 0;
}

size_t pieces(char pieces[15][15],char *buffer)
{
    for(size_t x=0;x<15;x++) for(size_t y=0;y<15;y++) pieces[x][y]='\0';

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
