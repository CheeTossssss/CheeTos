#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void menu(){
		printf("1. Login\n");
		printf("2. Register\n");
		printf("3. Exit\n");
		printf("Choose [1-3] >> ");
}
void Addsong(){
	char lagu[100];
	printf("What is your song name >> ");
	scanf("%s",lagu);
	
}
void Adminpage(){
	int admin;
	printf("Welcome admin\n");
	printf("===============\n");
	printf("1. View All Song\n");
	printf("2. Add Song\n");
	printf("3. Delete Song\n");
	printf("4. Exit\n");
	printf("================\n");
	printf("Choose >> ");
	scanf("%d",&admin);
	if(admin==1){
		Viewallsong();
	}
	if(admin==2){
		Addsong();
	}
	if(admin==3){
		Delete();
	}
	if(admin==4){
		menu();
	}
}
int main()
{
	int choose;
	do{
		menu();
		scanf("%d",&choose);
		if(choose==1){
			char email[100];
			char password[100];
			printf("input 'exit' to cancel\n");
			printf("input email: ");
			scanf("%s",email);
			printf("input password: ");
			scanf("%s",password)
			if(strcmp(email,"exit")==0){
				menu();
			}else if(strcmp(email,"admin")==0&&strcmp(password,"admin")==0){
				Adminpage();
			}
			system("cls");
		}
	}while(choose>=1&&choose<3);
	
	
	return 0;
}
