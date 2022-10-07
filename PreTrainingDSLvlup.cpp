#include <stdio.h>
#include <string.h>

int main()
{
	int menu;
	do{
		printf("Travalako\n");
		printf("===============\n");
		printf("1. Book Itinerary\n");
		printf("2. View Bookings\n");
		printf("3. Delete Booking\n");
		printf("4. Exit\n");
		printf("Choose >> ");
		scanf("%d",&menu);
		if(menu==1){
			char name[100];
			char lokasi[100];
			char 
			printf("Input name [3..20 Character, Alphabet Only]: ");
			scanf("%s",name);
			while(strlen(name)<3||strlen(name)>20){
				printf("Input name [3..20 Character, Alphabet Only]: ");
				scanf("%s",name);
			}
			printf("Input Location [ Beach | City | Mountain ]: ");
			scanf("%s",lokasi);
			while(strcmp(lokasi,"Beach")!=0||strcmp(lokasi,"City")!=0||strcmp(lokasi,"Mountain")!=0){
				printf("Input Location [ Beach | City | Mountain ]: ");
				scanf("%s",lokasi);
			}
			
			
		}
	}while(menu>=1&&menu<4);
	
	
	return 0;
}
