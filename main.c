#include<stdio.h>
#include<string.h>
#define n 1000
int cheakalphabets(char name1[],char name2[])
{
    int len1=strlen(name1);
    int len2=strlen(name2);
    int i,j,totalcount=0,alphabetscount=0;
    for(i=0;i<len1;i++)
    {
        totalcount++;
        if(name1[i]>='a'&&name1[i]<='z'||name1[i]>='A'&&name1[i]<='Z')
        {
            if(name1[i]>='a'&&name1[i]<='z')
            {
                name1[i]=name1[i]-32;
                alphabetscount++;
            }
            else
            {
                alphabetscount++;
            }
        }
    }
    for(i=0;i<len2;i++)
    {
        totalcount++;
        if(name2[i]>='a'&&name2[i]<='z'||name2[i]>='A'&&name2[i]<='Z')
        {
            if(name2[i]>='a'&&name2[i]<='z')
            {
                name2[i]=name2[i]-32;
                alphabetscount++;
            }
            else
            {
                alphabetscount++;
            }
        }
    }
    if(totalcount==alphabetscount)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int flamescount(char name1[],char name2[])
{
    int m=cheakalphabets(name1,name2);
    if(m==1)
    {
        int len1=strlen(name1);
        int len2=strlen(name2);
        int i,j,count=0;
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(name1[i]==name2[j]&&name1[i]!='0'&&name2[j]!='0')
                {
                    name1[i]='0';
                    name2[j]='0';
                    break;
                }
            }
        }
        for(i=0;i<len1;i++)
        {
            if(name1[i]!='0')
            {
                count++;
            }
        }
        for(i=0;i<len2;i++)
        {
            if(name2[i]!='0')
            {
                count++;
            }
        }
        return count;
    }
    else
    {
        return 0;
    }
}
char flamesletter(int count,char letter)
{
    char flames[n]="FLAMES";
    int len3=strlen(flames);
    int i,j,start=0,c;
    for(i=0;i<5;i++)
    {
        c=0;
        for(j=start;j<len3;j++)
        {
            if(flames[j]!='0')
            {
                c++;
            }
            if(c==count&&flames[j]!='0')
            {
                flames[j]='0';
                start=j+1; 
                if(start==len3)
                {
                    start=0;
                }
                break;
            }
            if(j==len3-1)
            {
                j=-1;
            }
        }
    }
    for(i=0;i<len3;i++)
    {
        if(flames[i]!='0')
        {
            letter=flames[i];
        }
    }
    return letter;
}
int main()
{
    char name1[n];
    char name2[n];
    char letter;
    printf("ENTER THE 1st NAME : ");
    scanf("%s",name1);
    printf("ENTER THE 2nd NAME : ");
    scanf("%s",name2);
    int count=flamescount(name1,name2);
    if(count>0)
    {
        letter=flamesletter(count,letter);
        if(letter=='F')
        {
            printf("FRIENDS");
        }
        else if(letter=='L')
        {
            printf("LOVERS");
        }
        else if(letter=='A')
        {
            printf("AFFECTIONATE");
        }
        else if(letter=='M')
        {
            printf("MARRIAGE");
        }
        else if(letter=='E')
        {
            printf("ENEMIES");
        }
        else if(letter=='S')
        {
            printf("SOULMATES");
        }
    }
    else
    {
        printf("NOT A GENDER");
    }
}