#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cctype>

using namespace std;

int Keyword(char buffer[]){
	char keywords[60][10] = {"auto","break","case",
	"char","const","continue","default",
							"do","double","else","enum",
							"extern","float","for","goto",
							"if","int","long","register",
							"return","short","signed",
							"sizeof","static","struct",
							"switch","typedef","union",
							"unsigned","void","volatile",
							"while","include","iostream",
							"cstdio","cmath","cctype","cstring",
							"string.h","math.h","ctype.h",
							"stdlib.h","stdio.h","vector",
							"list","map","stack","queue",
							"main","class","define","typedef",
							"scanf","printf","cin","cout","endl"
							};
	int i, flag = 0;

	for(i = 0; i < 57; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}

int main(){
	char ch, buffer[15], operators[] = "+-*/%=";
	char separators[15]={'#','<','>','(',')','{','}','[',']',',',';','?','&'};
    string s;
	cout<<"Enter Your File Name: ";
	cin>>s;
    ifstream fin(s.c_str());
	int i,j=0;
	if(!fin.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}

	while(!fin.eof()){
   		ch = fin.get();

		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				cout<<ch<<" is operator\n";
   		}
		for(i = 0; i < 15; ++i){
   			if(ch == separators[i])
   				cout<<ch<<" is separator\n";
   		}

   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;

   				if(Keyword(buffer) == 1)
   					cout<<buffer<<" is keyword\n";
   				else
   					cout<<buffer<<" is identifier\n";
   		}

	}

	fin.close();

	return 0;
}
