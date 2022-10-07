#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 50

int doHash(char name[]){
	int len=strlen(name);
	int count=0;
	for(int i=0;i<len;i++){
		count+=name[i];
	}
	return count%SIZE;
}
void insert(char table[SIZE][50],char name[]){
	int hash=doHash(name);
////	if(strcmp(table[hash],"")==0){
////		strcpy(table[hash],name);
//	}
	int temp=hash;
	do{
		if(strcmp(table[temp],"")==0){
			strcpy(table[temp],name);
			return;
		}
		if(temp==hash-1){
			return;
		}
		temp++;
		if(temp==SIZE){
			temp=0;
		}
	}while(strcmp(table[temp-1],"")!=0);
}

void View(char table[SIZE][50]){
	for(int i=0;i<SIZE;i++){
		printf("[ %d ] ==> %s\n",i,table[i]);
	}
	
}
void init(char table[SIZE][50]){
	for(int i=0;i<SIZE;i++){
		strcpy(table[i],"");
	}
}
int search(char table[SIZE][50],char name[]){
	int hash=doHash(name);
	int temp=hash;
	do{
		if(strcmp(table[temp],name)==0){
			return temp;
		}
		if(temp==hash-1){
			return -1;
		}
		temp++;
		if(temp==SIZE){
			temp=0;
		}
	}while(strcmp(table[temp-1],"")!=0);
	return -1;
}
void Delete(){
	
}
int main()
{
	int choose;
	char table[SIZE][50];
	init(table);
	do{
		printf("Catalog Finder -1.0\n");
		printf("1. Add catalog\n");
		printf("2. View catalog\n");
		printf("3. Delete catalog\n");
		printf("4. Search catalog\n");
		printf("5. Exit\n");
		printf("Choose >> ");
		scanf("%d",&choose);
		if(choose==1){
				char name[100];
				char nohp[100];
					printf("Insert name [3- 50] : ");
					scanf("%s",name);
				while(strlen(name)<3||strlen(name)>50){
					printf("Insert name [3- 50] : ");
					scanf("%s",name);
						}
					printf("Insert phone number [10 - 13] : ");
					scanf("%s",nohp);
				while(strlen(nohp)<10||strlen(nohp)>13){
					printf("Insert phone number [10 - 13] : ");
					scanf("%s",nohp);
						}
					printf("Press anykey to continue...");
					getch();
					insert(table,name);
			}
			if(choose==2){
				View(table);
			}
			if(choose==3){
				Delete();
			}
			if(choose==4){
				char name[100];
				char nohp[100];
					printf("Insert name [3- 50] : ");
					scanf("%s",name);
					printf("Insert phone number [10 - 13] : ");
					scanf("%s",nohp);
				int check=search(table,name);
				if(check!=-1){
					printf("Found on index %d!\n",check);
				}else{
					printf("Not Found!\n");
				}
				
				
		}
	}while(choose>=1&&choose<5);
	
	
	
	return 0;
}
