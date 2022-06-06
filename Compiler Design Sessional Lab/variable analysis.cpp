

#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void printchar(char buffer[])
{
    for(int i=0; i<strlen(buffer); i++)
    {
        printf("%c",buffer[i]);
    }
    printf("\n");
}
using namespace std;
int isDataType(char buffer[])
{
    char dtype[14][40] =
    {
        "short int","unsigned short int","unsigned int","int",
        "long int","unsigned long int","long long int","unsigned long long int",
        "signed char","unsigned char",
        "float","double","long double",
        "char"
    };
    int i, flag = 0;

    for(i = 0; i < 14; ++i)
    {
        if(strcmp(dtype[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    char ch, buffer[100],b[100], c[30],d[100],logical_op[] = "><";
    ifstream fin("vdec_input.txt");// Input file *
    int mark[1000]= {0},i=1,l=0,stdi=0;
    string str[100];
    int check=0;
    char ch01[2][9] =
    {
        "include","INCLUDE"
    };
    int j=1;
    if(!fin.is_open())
    {
        cout<<"error while opening the file\n";
        exit(0);
    }

    while(!fin.eof())
    {
        ch = fin.get();
        if(ch==' ')
        {
            continue;
        }
        else{
                buffer[0]=ch;
            while(!fin.eof())
            {
                    ch=fin.get();
                    if(ch!=';')
                    {
                        buffer[j++]=ch;
                        buffer[j]='\0';

                         if(isDataType(buffer)==1)
                    {

                        check=1;
                        strcpy(d,buffer);
                         while(!fin.eof())
                         {
                          ch = fin.get();
                          if(ch ==' ')
                           {
                           continue;
                           }
                           else{
                               b[0]=ch;
                             cout<<b[0]<<endl;

                                if(b[0]=='0' || b[0]=='1' || b[0]=='2' || b[0]=='3' || b[0]=='4' || b[0]=='5' || b[0]=='6' ||b[0]=='7' ||b[0]=='8' ||b[0]=='9' ||
                                  b[0]=='<' ||b[0]=='>' ||b[0]=='?' ||b[0]=='}' ||b[0]=='{' ||b[0]=='[' || b[0]==']' || b[0]=='+' ||b[0]=='-' ||b[0]=='=' ||
                                   b[0]=='(' ||b[0]==')' ||b[0]=='*' ||b[0]=='&' ||b[0]=='^' ||b[0]=='%' ||b[0]=='$' ||b[0]=='#' || b[0]=='@' || b[0]=='!' ||
                                   b[0]=='.'  || b[0]=='|')
                                   {
                                       cout<<"Variable declaration is not correct"<<endl;
                                       return 0;
                                   }
                                 else if(ch==';'){
                                   break;
                                 }
                                 else{
                                        b[0]=ch;

                                    b[i++]=ch;
                                   // continue;
                                 }
                                 b[i]='\0';



                           }

                         }
                         break;

                    }
                    else{
                     continue;
                    }
                    break;
                    }
                    else
                    {
                        buffer[j]='\0';
                       break;


                    }
                }


        }
        b[i]='\0';
          if(check==0)
          {
            cout<<"datatype is not correct"<<endl;
            return 0;
          }
          else{
                for(int k=0;k<strlen(b);k++)
                {
                    if(b[k]==' ')
                    {
                       cout<<"Variable declaration is not correct"<<endl;
                        return 0;
                    }
                }
           cout<<"datatype:"<<buffer<<endl<<"Variable:"<<b<<endl;
          }

        fin.close();
         return 0;
    }


    return 0;
}



