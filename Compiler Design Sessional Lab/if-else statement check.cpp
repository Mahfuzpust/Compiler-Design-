#include<bits/stdc++.h>
using namespace std;

char ch, buffer[10],b[30], logical_op[] = "><";
ifstream fin("sample.cpp");// Input file *
string str[100];


int isDatatype(char buffer[])
{
    char keywords[9][15] =
    {
        "int","void","char","float","double","long int",
        "long long int","long double","unsigned int"
    };
    int i, flag = 0;

    for(i = 0; i < 8; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int checkIf(char buffer[])
{
    int i, flag = 0;
    char ch;
    if(strcmp(buffer,"if")==0)
    {
        flag=1;
        while(ch!=')')
        {
            ch=fin.get();
        }
        ch=fin.get();
        while(ch=='\n')
        {
            ch=fin.get();
            continue;
        }

        if(ch=='{')
        {
            while(ch!='}')
            {
                ch=fin.get();
            }
        }
    }
    else
        flag=0;
    return flag;
}



int checkElseIf(char buffer[])
{
    int i, flag = 0;
    char ch;
    if(strcmp(buffer,"else if")==0)
    {
        flag=1;
        while(ch!=')')
        {
            ch=fin.get();
        }
        ch=fin.get();
        while(ch=='\n')
        {
            ch=fin.get();
            continue;
        }
        if(ch=='{')
        {
            while(ch!='}')
            {
                ch=fin.get();
            }
            //cout<<buffer<<endl;
        }
    }
    else if(strncmp(buffer,"else",4))
    {
        flag=2;
    }
    else
        flag=0;
    return flag;
}


int checkIdentifier(char buffer[])
{
    int i=0,j=0,flag=0;
    int length=strlen(buffer);
    while(i<length)
    {
        if(buffer[i]>='a' && buffer[i]<='z' || buffer[i]=='_')
        {
            flag=1;
        }
        else if (buffer[i]>='A' && buffer[i]<='Z' || buffer[i]=='_')
        {
            flag=1;
        }
        else if (buffer[i]>='0' && buffer[i]<='9' || buffer[i]=='_' || buffer[i]==' ')
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
        i++;
    }
    return flag;
}

int main()
{
    int inc=0,stdi=0,flag=1;
    int i=0,j=0;
    while(!fin.eof())
    {
        ch = fin.get();
        if(ch==' ')
        {
            continue;
        }
        else if((ch>=97 && ch<=122))
        {
            int _if=0;
            j=0;
            while(!fin.eof())
            {

                if(_if!=1)
                {
                    while(ch!='(')
                    {
                        buffer[j++]=ch;
                        ch=fin.get();
                    }
                    buffer[j]='\0';
                }
                else
                {
                    ch=fin.get();
                    while(ch=='\n')
                    {
                        ch=fin.get();
                        continue;
                    }
                    buffer[0]=ch;
                    j=1;
                    for(int i=0; i<6; i++)
                    {
                        ch=fin.get();
                        buffer[j++]=ch;
                    }
                    buffer[j]='\0';
                }
                if(checkIf(buffer)==1)
                {
                    _if=1;
                    flag=1;
                    continue;
                }
                else if(checkElseIf(buffer)==1)
                {
                    flag=0;
                    continue;
                }
                else if(checkElseIf(buffer)==2)
                {
                    flag=1;
                    break;
                }
                else
                {
                    flag=0;
                }
            }

        }
    }
    if(flag==0)
    {
        cout<<"Syntax Error"<<endl;
        return 0;
    }
    else
    {
        cout<<"Syntax OK"<<endl;
    }
    fin.close();
    return 0;
}
