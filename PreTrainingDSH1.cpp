#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int menuindex=0;

typedef struct add{
	char name[100];
	int price;
	int jumlah;
}add;
add newaice[100];


void Add(){
	int jml;
	char aice[100];
	int aise;
	system("cls");
	while(strlen(aice)>=20||strlen(aice)<8){
		printf("Enter Aice Cream Name [CANT CONTAIN NUMBER,LOWER THAT 8 CHARACTERS AND BE GREATER THAN 20 CHARACTERS]\n");
		getchar();
		scanf("%[^\n]",aice);
		getchar();
		strcpy(newaice[menuindex].name,aice);
	}

	
	while(aise<1000||aise>10000){
		printf("Enter Aice Cream Price [MUST BE GREATER THAN 1000 AND LESS THAN 10000]\n");
		scanf("%d",&aise);
		getchar();
		newaice[menuindex].price=aise;
		
	}	
	while(jml<=0){
		printf("Enter Aice Cream Quantity [MUST BE GREATER THAN 0]\n");
		scanf("%d",&jml);
		getchar();
		newaice[menuindex].jumlah=jml;
		
	}
	printf("Aice Cream Succesfully Added\n");
	printf("Press enter to continue...");
	getchar();
	menuindex++;
}
void Sell(){
	char x[100];
	int y;
	int flag=0;
		system("cls");
		printf("No.\tName\t\t\tPrice\tQuantity\n");
		printf("================================================\n");
		for(int i=0;i<menuindex;i++){
			printf("%d\t%s\t\t%d\t%d\n",i+1,newaice[i].name,newaice[i].price,newaice[i].jumlah);
		}
		getchar();
		printf("Input Aice Krim name[CASE SENSITIVE]: ");
		scanf("%[^\n]",x);
		getchar();
		for(int j=0;j<menuindex;j++){
			if(strcmp(x,newaice[j].name)==0){
				flag=1;
			}		
		}
		if(flag){
			printf("Input quantity: ");
			scanf("%d",&y);
			for(int j=0;j<menuindex;j++){
				if(strcmp(x,newaice[j].name)==0){
					if(y<=newaice[j].jumlah){
						newaice[j].jumlah=newaice[j].jumlah-y;
						printf("Thank you for purchasing %s\n",newaice[j].name);
						printf("Press any key to continue...");
						getch();
						break;
					}else{
						printf("Not Enough STOCK !\n");
						printf("Press any key to continue...");
						getch();
					}
				}
			}
			
		}else{
			puts("Couldn't Find Aice Krim");
			printf("Press any key to continue...");
			getch();
		}
		
		
}
void View(){
	int view;
	int limit;
	int count=0;
	system("cls");
	do{
		printf("1. View all Aice Krim\n");
		printf("2. View with limit\n");
		printf(">> ");
		scanf("%d",&view);
		getchar();
		switch(view){
			case 1:
			system("cls");
		printf("No.\tName\t\t\tPrice\tQuantity\n");
		printf("================================================\n");
		for(int i=0;i<menuindex;i++){
			printf("%d\t%s\t\t%d\t%d\n",i+1,newaice[i].name,newaice[i].price,newaice[i].jumlah);
		}
		printf("Press any key to continue...\n");
		getch();
		break;
			case 2:
				system("cls");
				printf("Enter the price limit\n");
			scanf("%d",&limit);
			system("cls");
			printf("No.\tName\t\t\tPrice\tQuantity\n");
			for(int k=0;k<menuindex;k++){
				if(newaice[k].price<=limit){
					printf("%d\t%s\t\t%d\t%d\n",k+1,newaice[k].name,newaice[k].price,newaice[k].jumlah);
					count++;
				}
			}
			if(count==0){
					printf(">>>>>>>>>> SORRY U NEED MORE MONEY SIR <<<<<<<<<\n");
				
			}
			printf("Press any key to continue...\n");
			getch();
			break;	
		}
	}while(view!=1&&view!=2);
}


void header()
{
	int menu;
	do{
		system("cls");
		printf("1. Add New Aice Cream\n");
		printf("2. Sell Aice Cream\n");
		printf("3. View Aice Cream\n");
		printf("4. Find Similar Aice Cream\n");
		printf("5. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
			switch(menu){
				case 1:
					Add();
					break;
				case 2:
					Sell();
					break;
				case 3:
					View();
					break;
				


			}
	}while(menu!=5);
}

int main()
{
	strcpy(newaice[menuindex].name,"Yellow Krim");
	newaice[menuindex].price=500;
	newaice[menuindex].jumlah=20;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Silver Krim");
	newaice[menuindex].price=750;
	newaice[menuindex].jumlah=1;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Good Krim");
	newaice[menuindex].price=1000;
	newaice[menuindex].jumlah=10;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Red Krim");
	newaice[menuindex].price=1000;
	newaice[menuindex].jumlah=12;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Orange Krim");
	newaice[menuindex].price=1250;
	newaice[menuindex].jumlah=5;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Magenta Krim");
	newaice[menuindex].price=1501;
	newaice[menuindex].jumlah=5;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Blue Krim");
	newaice[menuindex].price=2000;
	newaice[menuindex].jumlah=13;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Purple Krim");
	newaice[menuindex].price=6000;
	newaice[menuindex].jumlah=5;
	menuindex++;
	
	strcpy(newaice[menuindex].name,"Super Krim");
	newaice[menuindex].price=10000;
	newaice[menuindex].jumlah=100;
	menuindex++;
	header();
	
}
