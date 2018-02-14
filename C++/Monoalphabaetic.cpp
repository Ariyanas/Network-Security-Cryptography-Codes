// Program to implement Monoalphabetic algorithm
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int i,j;

void firstApproach(char str[100]){
	char pkeyl[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char ckeyl[26] = {'b','y','c','x','d','w','e','v','f','u','g','t','h','s','i','r','j','q','k','p','l','o','m','n','a','z'};
	
	char pkeyu[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char ckeyu[26] = {'B','Y','C','X','D','W','E','V','F','U','G','T','H','S','I','R','J','Q','K','P','L','O','M','N','A','Z'};
	
	for(i=0;str[i]!='\0';i++){
		// for uppercase char
		if(str[i] >= 65 && str[i] <= 90){
			j = (int)(str[i]) - 65;
			str[i] = ckeyu[j];
		}
			
		// for lowercase char	
		if(str[i] >= 97 && str[i] <= 122){
			j = (int)(str[i]) - 97;
			str[i] = ckeyl[j];
		}
	}
	
	cout<<"\n\n\t\tCiphered text   : "<<str;
	
	for(i=0;str[i]!='\0';i++){
		// for uppercase char
		if(str[i] >= 65 && str[i] <= 90){
			for(j=0;j<26;j++){
				if(str[i] == ckeyu[j]){
					str[i] = pkeyu[j];
					break;
				}
			}
		}
			
		// for lowercase char	
		if(str[i] >= 97 && str[i] <= 122){
			for(j=0;j<26;j++){
				if(str[i] == ckeyl[j]){
					str[i] = pkeyl[j];
					break;
				}
			}
		}
	}
	
	cout<<"\n\n\t\tDeciphered text : "<<str;
}

void secondApproach(char str[100]){
	string key = "bycxdwevfugthsirjqkplomnaz";
	
	for(i=0;str[i]!='\0';i++){
		// for uppercase char
		if(str[i] >= 65 && str[i] <= 90){
			j = (int)(str[i]) - 65;
			str[i] = (char)((int)(key[j]) - 32);
		}
			
		// for lowercase char	
		if(str[i] >= 97 && str[i] <= 122){
			j = (int)(str[i]) - 97;
			str[i] = key[j];
		}
	}
	
	cout<<"\n\n\t\tCiphered text : "<<str;
}

int main(){	
	char str[100];
	
	cout<<"\n\tEnter plain text ( max. 100 chars ): ";
	gets(str);
	
	cout<<"\n\n\tCalling firstApproach() :\n\t----------------------------------";
	firstApproach(str);
	
	cout<<"\n\n\n\tCalling secondApproach() :\n\t----------------------------------";
	secondApproach(str);	
	
	return 0;
}
