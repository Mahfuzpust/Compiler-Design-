

#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*void printchar(char buffer[])
{
    for(int i=0; i<strlen(buffer); i++)
    {
        printf("%c",buffer[i]);
    }
    printf("\n");
}*/
using namespace std;
int isHeader(char buffer[])
{
    char headers[26][9] =
    {
        "stdio.h","stdlib.h","conio.h","string.h",
        "math.h","time.h","assert.h","locale.h",
        "ctype.h","signal.h",
        "setjmp.h","stdarg.h","errno.h",
        "STDIO.H","STDLIB.H","CONIO.H",
        "STRING.H","MATH.H","TIME.H",
        "ASSERT.H","LOCALE.H","CTYPE.H","SIGNAL.H",
        "SETJMP.H","STDARG.H","ERRNO.H"
    };
    int i, flag = 0;

    for(i = 0; i < 26; ++i)
    {
        if(strcmp(headers[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    char ch, buffer[30];
    ifstream fin("sample.cpp");// Input file *
    int mark[1000]= {0},inc=0,stdi=0;
    string str[100];
    char ch01[2][9] =
    {
        "include","INCLUDE"
    };
    int j=0;
    if(!fin.is_open())
    {
        cout<<"error while opening the file\n";
        exit(0);
    }

    while(!fin.eof())
    {
        ch = fin.get();
        if(ch == '#')
        {
            while(!fin.eof())
            {

                while(ch!='<')
                {
                    ch=fin.get();
                    if(ch!='<')
                    {
                        buffer[j++]=ch;
                        inc++;
                        if(inc>=8)
                        {
                            cout<<"Syntax Error"<<endl;
                            return 0;
                        }
                    }
                    else
                    {
                        buffer[j]='\0';
                    }
                }
                if(strcmp(buffer,ch01[0])==0 || strcmp(buffer,ch01[1])==0)
                {
                    j=0;
                    while(ch!='>')
                    {
                        ch=fin.get();
                        if(ch!='>')
                        {
                            buffer[j++]=ch;
                            stdi++;
                        }
                        else
                        {
                            buffer[j]='\0';
                        }
                    }
                    if(isHeader(buffer)==1)
                    {
                        cout<<"Syntax is Ok"<<endl;
                        return 0;
                    }
                    else
                    {
                        cout<<"Syntax Error"<<endl;
                        return 0;
                    }
                }
                else
                {
                    cout<<"Syntax Error"<<endl;
                    return 0;
                }
            }

        }

        else
        {
            cout<<"Syntax Error"<<endl;
            return 0;
        }
        fin.close();
    }

    return 0;
}



