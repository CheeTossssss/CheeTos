#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//variabel global in structs
typedef struct{
	int day;
	int month;
	int year;
}
date;

typedef struct{
	int event_day;
	int event_month;
	int event_year;
}
event_date;

typedef struct{
	char name[30];
	char nationality[30];
	int period; // jumlah hari penginapan
}
guest_detail;

typedef struct{
	char event_name[30];
	char event_nationality[30];
	int event_period; // jumlah hari event
}
guest_event_detail;

typedef struct{
	int booked; // 1 = belum, 0 = sudah
	guest_detail guest; // guest details
	date start; // tanggal mulai
}
room_detail;

typedef struct{
	char type[15]; // nama room type
	int price; // records room type price, in dollars
	int available; // jumlah room yang available
	room_detail rooms[10]; // catat 0 (kamar kosong) / 1 (kamar terisi)
}
KAMAR; 

typedef struct{
	int event_booked; // 1 = belum, 0 = sudah
	guest_event_detail event_guest; // guest details
	event_date event_start; // tanggal mulai
}
event_detail;

typedef struct{
	char eventRoomType[15];//room buat event
	int eventPrice;//harga room
	int eventAvailable;// catat 0 (ruangan kosong) / 1 (ruangan terisi)
	event_detail event_rooms[2];
}
EVENT;

KAMAR room_type[5];
EVENT event_type[2];

//prototype
void main_menu();
void design();
void intro();
void availability();
void print_table();
void print_event_table();
void hotelFeatures();
void eventFeatures();
void roomFeatures();
void bookRoom();
void bookEvent();
void bookingDetails();
void eventDetails();
void roomDetails();
void Bookingcancellation();
void Roomcancel();
void Eventcancel();
void setup_room();
void setup_event();

//pause (optional kalo mau)
void sleep(){
	for(int x=0;x<500000000;x++){
		
	}
}

int main()
{
	char ans; 
    int choose;
	
	setup_room();
	setup_event();
    design();
    intro();
    do{
		main_menu();
		do
		{
			scanf("%d",&choose);
        	system("cls");
        	switch(choose){
            	case 1:
                	availability();
                	break;
            	case 2:
                	hotelFeatures();
                	break;
            	case 3:
                	bookRoom();
                	break;
                case 4:
                	bookEvent();
                	break;
            	case 5:
                	bookingDetails();
                	break;
            	case 6:
                	Bookingcancellation();
                	break;
            	case 7: return(0);
            }
		} while(choose > 7 || choose < 1);
    	printf("\n\tPress (y) to go back to options and (n) to terminate. Do you wish to continue? ");
    	fflush(stdin);
    	scanf("%c",&ans);
    	system("cls");
    }
    while(ans=='y'||ans=='Y');
    return 0;
}

//________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

void design()
{	
	puts ("");
    printf ("                     |>                                        |>         \n");
    sleep();
    printf ("                   nnnnn                                     nnnnn        \n");
    sleep();
    printf ("                  nnnnnnn              HOTEL 247            nnnnnnn       \n");
    sleep();
	printf ("                 nnnnnnnnn   ^  _._._._ _._._._._._._      nnnnnnnnn ^    \n");
    sleep();
	printf ("                  | ___ |_._._._| ___ || ___ || ___ |_._._._| ___ |       \n");
    sleep();
	printf ("                  | |_| |  ___  | |_| || |_| || |_| |  ___  | |_| |       \n");
    sleep();
	printf ("                  |_III_|  |_|  |_III_||_III_||_III_|  |_|  |_III_| ^!^   \n");
    sleep();
	printf ("         ^        | ___ |__III__| ___ || ___ || ___ |__III__| ___ |       \n");
    sleep();
	printf ("              ^   | |_| |  ___  | |_| || |_| || |_| |  ___  | |_| |   ^!^ \n");
    sleep();
	printf ("                  |_III_|  |_|  |_III_||_III_||_III_|  |_|  |_III_|       \n");
    sleep();
	printf ("    ^             | ___ |__III__| ___ || ___ || ___ |__III__| ___ |       \n");
    sleep();
	printf ("                  |_III_|  |_|  |    ooooooooooo    |  |_|  |_III_|       \n");
    sleep();
	printf ("                  | ___ |__III__|   oo    |    oo   |__III__| ___ |       \n");
    sleep();
	printf ("           ^      | |_| |  ___  |  oo-----|-----oo  |  ___  | |_| |       \n");
    sleep();
	printf ("                  |_III_|  |_|  | oo______|______oo |  |_|  |_III_|       \n");
    sleep();
	printf ("                  | ___ |__III__|_____||_____||_____|__III__| ___ |       \n");
    sleep();
	printf ("                  | | | |***********|     |     |***********| | | |       \n");
    sleep();
	printf ("                  | |_| |***********|    o|o    |***********| |_| |       \n");
    sleep();
	printf ("                  |_III_|@@@@@@@@@@@|_____|_____|@@@@@@@@@@@|_III_|       \n");
    sleep();
	printf ("             @@@@@@@@@@@@@@@@@@@@@  @[=========]@   @@@@@@@@@@@@@@@@@@@@@ \n\n");
    sleep();
	printf ("         88     88  8888888  88        8888888   8888888   88     88  8888888 \n");
    sleep();
	printf ("         88     88  88       88       88        88     88  88 8 8 88  88      \n");
    sleep();
	printf ("         88  8  88  88888    88       88        88     88  88  8  88  88888   \n");
    sleep();
	printf ("         88 8 8 88  88       88       88        88     88  88     88  88      \n");
    sleep();
	printf ("         88     88  8888888  8888888   8888888   8888888   88     88  8888888 \n");
	sleep();
}

void main_menu()
{
	printf("\n   88  88   8888  888888 88888  88        8888      888  888888");
	printf("\n   88  88  88  88   88   88     88       88  88   88 88     88 ");
	printf("\n   888888  88  88   88   88888  88         88    88  88    88  ");
	printf("\n   88  88  88  88   88   88     88        88    8888888   88   ");
	printf("\n   88  88   8888    88   88888  88888    888888      88  88    ");
	
	printf("\n\n\n             Options:\n");
    printf("             1. Check Availibity\n");
    printf("             2. Room and booked event Features\n");
	printf("             3. Book a room\n");
	printf("             4. Book for an event\n");
    printf("             5. Guest details\n");
    printf("             6. Cancellation\n");
	printf("             7. Exit\n");
	printf("\n\tSelect option: ");
}

void intro()
{
    printf("\n                         224 W 50th St, Midtown, Manhattan");
    sleep();
    printf("\n\n                              Ph. No.: +1-212-608-3333    ");
    sleep();
	printf("\n\n\n\tHotel 247 is one of the newest hotel in the heart of Midtown. The hotel is \n\t  equipped with all sorts of amenities that makes for a memorable stay.");
    sleep();
    printf("\n\n                                LIST OF AMENITIES\n");
    sleep();
	printf("\t\t\t      1. Free Wi-Fi\n");
    sleep();
	printf("\t\t\t      2. Automatic lift\n");
    sleep();
	printf("\t\t\t      3. Round the clock security\n");
    sleep();
	printf("\t\t\t      4. Running hot and cold water\n");
    sleep();
	printf("\t\t\t      5. 24 hours room service\n");
    sleep();
	printf("\t\t\t      6. Laundry service\n");
    sleep();
    
	printf("\n\tPress any character to continue: ");
    getchar();
    system("cls");
}
void availability(){
	int NUMBER;
	printf("\n\t What kind of booking you want to check its availability?");
	printf("\n\t 1. Room booking avaliability");
    printf("\n\t 2. Event booking availability");
    puts("");
	printf("\t Enter: ");
    scanf("%d",&NUMBER);
    system("cls");
    if(NUMBER>2){
        printf("\tPlease press a number between 1-2\n");
        availability();
    }
    switch(NUMBER){
    	case 1:
    		print_table();
    		break;
    	case 2:
    		print_event_table();
    		break;
	}
}
void print_table()
{
    printf("\n\t                   ROOM AVAILABILITY                     ");
    printf("\n\t_________________________________________________________");
    printf("\n\t| No |     Type      |    Price / Day    | Availability |");
    printf("\n\t|____|_______________|___________________|______________|");
    for(int i = 0; i < 5; i++)
	{
        printf("\n\t| %d  | %s", i+1, room_type[i].type);
        for(int j = 0, space = 14 - strlen(room_type[i].type); j < space; j++) printf(" ");
        printf("|       $%d        |", room_type[i].price);
        if(room_type[i].available >= 10) printf("      %d      |", room_type[i].available);
        else printf("       %d      |", room_type[i].available);
    }
    printf("\n\t|____|_______________|___________________|______________|\n");
}

void print_event_table(){
	printf("\n\t                   EVENT ROOM AVAILABILITY                     ");
    printf("\n\t_________________________________________________________");
    printf("\n\t| No |     Type      |    Price / Day    | Availability |");
    printf("\n\t|____|_______________|___________________|______________|");
    for(int i = 0; i < 2; i++)
	{
        printf("\n\t| %d  | %s", i+1, event_type[i].eventRoomType);
        for(int j = 0, space = 14 - strlen(event_type[i].eventRoomType); j < space; j++) printf(" ");
        printf("|       $%d        |", event_type[i].eventPrice);
        if(event_type[i].eventAvailable >= 2) printf("      %d       |", event_type[i].eventAvailable);
        else printf("      %d       |", event_type[i].eventAvailable);
    }
    printf("\n\t|____|_______________|___________________|______________|\n");
}
void hotelFeatures(){
	int input_number;
	printf("\n\tPress enter the number of the hotel features you would like to view");
	printf("\n\t\t\t      1. Room Features");
    printf("\n\t\t\t      2. Booked Event Features\n");
	puts("");
	printf("\t Enter: ");
    scanf("%d",&input_number);
    system("cls");
    if(input_number>2){
        printf("\tSadly, we don't have that many features. Please press a number between 1-2\n");
        hotelFeatures();
    }
    switch(input_number){
    	case 1:
    		roomFeatures();
    		break;
    	case 2:
    		eventFeatures();
    		break;
	}
}
void eventFeatures(){
	printf("\n\t FEATURES      \n");
            printf("\t----------------------------");
            printf("\n\t 1.2 Connected ballrooms available to use");
            printf("\n\t 2.2 Meeting rooms available to use");
            printf("\n\t 3.Full AC on all ballrooms and meeting rooms");
            printf("\n\t 4.Free snacks for meetings and seminars\n\n");
}
void roomFeatures()//room features
{
    int input_type;
    printf("\n\tPress enter the number of the room type listed to view room features");
	for(int i = 0; i < 5; i++) printf("\n\t\t %d. %s", i + 1, room_type[i]);
	puts("");
//    printf("\n\t\t 1. Standard");
//    printf("\n\t\t 2. Twin");
//    printf("\n\t\t 3. Deluxe");
//    printf("\n\t\t 4. Suite");
//    printf("\n\t\t 5. Presidential\n");
    printf("\t Enter: ");
    scanf("%d",&input_type);
    system("cls");
    if(input_type>5){
        printf("\tSadly, we don't have that many variations of rooms. Please press a number between 1-5\n");
        roomFeatures();
    }
    switch(input_type){
        case 1:
            printf("\n\t FEATURES      \n");
            printf("\t----------------------------");
            printf("\n\t 1.Bed type: Full (1)");
            printf("\n\t 2.Capacity: 2 pax");
            printf("\n\t 3.Air conditioner");
            printf("\n\t 4.TV");
            printf("\n\t 5.Writing desk");
            printf("\n\t 6.Reading light");
            printf("\n\t 7.Telephone\n");
            break;
        case 2:
            printf("\n\t FEATURES      \n");
            printf("\t----------------------------");
            printf("\n\t 1.Bed type: Twin (2)");
            printf("\n\t 2.Capacity: 2 pax");
            printf("\n\t 3.Air conditioner");
            printf("\n\t 4.TV");
            printf("\n\t 5.Writing desk");
            printf("\n\t 6.Reading light");
            printf("\n\t 7.Telephone\n");
            break;
        case 3:
            printf("\n\t FEATURES      \n");
            printf("\t----------------------------");
            printf("\n\t 1.Bed type: Queen (1)");
            printf("\n\t 2.Capacity: 2 pax");
            printf("\n\t 3.Air conditioner");
            printf("\n\t 4.TV");
            printf("\n\t 5.Writing desk");
            printf("\n\t 6.Reading light");
            printf("\n\t 7.Telephone");
            printf("\n\t 8.Refrigerator");
            printf("\n\t 9.Safety box");
            printf("\n\t 10.Toiletries");
            printf("\n\t 11.Hair dryer\n");
            break;
        case 4:
            printf("\n\t FEATURES      \n");
            printf("\t------------------------------------");
            printf("\n\t 1.Bed type: King (1)");
            printf("\n\t 2.Capacity: 3 pax");
            printf("\n\t 3.Air conditioner");
            printf("\n\t 4.TV with satellite channels");
            printf("\n\t 5.Writing desk");
            printf("\n\t 6.Reading light");
            printf("\n\t 7.Telephone");
            printf("\n\t 8.Refrigerator");
            printf("\n\t 9.Safety box");
            printf("\n\t 10.Toiletries");
            printf("\n\t 11.Hair dryer");
            printf("\n\t 12.Balcony");
            printf("\n\t 13.Coffee maker");
            printf("\n\t 14.Individual climate control");
            printf("\n\t 15.Complimentary fruit basket");
            printf("\n\t 16.Complimentary local newpaper\n");
            break;
        case 5:
            printf("\n\t FEATURES      \n");
            printf("\t------------------------------------");
            printf("\n\t 1.Bed type: California King (2)");
            printf("\n\t 2.Capacity: Up to 5 pax");
            printf("\n\t 3.Air conditioner");
            printf("\n\t 4.TV with satellite channels");
            printf("\n\t 5.Writing desk");
            printf("\n\t 6.Reading light");
            printf("\n\t 7.Telephone");
            printf("\n\t 8.Refrigerator");
            printf("\n\t 9.Safety box");
            printf("\n\t 10.Toiletries");
            printf("\n\t 11.Hair dryer");
            printf("\n\t 12.Balcony");
            printf("\n\t 13.Coffee maker");
            printf("\n\t 14.Individual climate control");
            printf("\n\t 15.Complimentary fruit basket");
            printf("\n\t 16.Complimentary local newpaper");
            printf("\n\t 17.Complimentary pastry basket");
            printf("\n\t 18.Champagne");
            printf("\n\t 19.Breakfast in bed");
            printf("\n\t 20.Minibar");
            printf("\n\t 21.Fully equipped kitchen\n");
            break;
        printf("\n\tPress any character to continue: "); 
		getchar ();
		system("cls");
    }
}

void bookRoom()//room booking
{
    int type, qty, period, year, month, day;
    char name[30], nation[30];
	print_table();
	printf("\n\t Please enter the room type you want to stay in (1-5): "); 
	scanf("%d",&type);
	while(type < 1 || type > 5)
	{
		printf("\n\t Please re-enter the room type you want to stay in (1-5): "); 
		scanf("%d",&type);
	}
	printf("\n\t Please enter how many rooms you want to book (1-%d): ", room_type[type-1].available); 
	scanf("%d",&qty);
	while(qty < 1 || qty > room_type[type-1].available)
	{
		if (qty == 0) printf("\n\t You do know, you have to book at least 1 right?");
		else printf("\n\t Unfortunately, we don't have that amount of rooms available.");
		printf("\n\t Please re-enter the number quantity room you want to book (1-%d): ", room_type[type-1].available); 
		scanf("%d",&qty);
	}
    if(qty <= room_type[type-1].available) // if room available
    {
    	fflush(stdin);
    	// input data
    	// scan guest data
    	printf("\n\t Enter your name: "); scanf("%[^\n]",name);
    	printf("\n\t Enter your nationality: "); scanf("%s",nation);
	    printf("\n\t How long will your be staying with us (in days)? "); scanf("%d",&period);
	    
	    //scan date
	    printf("\n\t When will you be arriving?");
	    printf("\n\t Year: "); scanf("%d",&year);
    	printf("\t Month: "); scanf("%d",&month);
        printf("\t Day: "); scanf("%d",&day);
        getchar();
        
        int booked = 1;
        // check condition of valid date
        while((year < 2020 || year > 9999 || month > 12 || month < 1 || day < 1) // kondisi : tanggal tidak mengandung 0 (hari/bulan) ataupun kurang dari tahun 2020
		|| ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) // kondisi 1 : bulan dengan jumlah hari 31
		|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) // kondisi 2 : bulan dengan jumlah hari 30
		|| (month == 2 && ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && day > 29) // kondisi 3.1 : febuari kabisat
		|| ((year % 4 != 0 || year % 100 == 0) && day > 28))) // kondisi 3.2 : febuari non kabisat
		{
			char choice;
			booked = 0; // failed booking
			printf("\n\tThe date you put is invalid, would you like to try again (y/n)? ");
			scanf("%c", &choice);
			if(choice == 'n') break;
			else
			{
				system("cls");
      			// reprint the screen but only check the date again
      			print_table();
      			// reprint previously inputed data
      			printf("\n\t Please enter the room type you want to stay in (1-5): %d", type); 
      			printf("\n\t Please enter how many rooms you want to book (1-%d): %d", room_type[type-1].available, qty);
      			
      			// re-scan guest data
      			printf("\n\t Enter your name: %s\n", name);
    			printf("\n\t Enter your nationality: %s\n", nation);
	    		printf("\n\t How long will your be staying with us (in days)? %d\n", period);
	    		
	    		// re-scan date
	    		printf("\n\t When will you be arriving?");
	    		printf("\n\t Year: "); scanf("%d",&year);
    			printf("\t Month: "); scanf("%d",&month);
        		printf("\t Day: "); scanf("%d",&day);
        		getchar();
        		booked = 1; //successful booking
			}
        }
        if(booked)
        {	
        	// post valid input
        	system("cls");
        	printf("\n You've successfully booked %d room(s) for %d days.\n\n", qty, period);
        	  printf("\t You will have to pay 50%% of the total payment for down payment ($%.2f)\n", (float) ((qty *period)* room_type[type-1].price) / 2);
        	  printf("\t due this week to the following bank account: 1560009861578 (Citygroup)\n\n");
        	  printf("\t Check the guest details to see more information about this booking.\n");
			
        	// set all booked rooms to booked
        	int start = 10 - room_type[type-1].available, end = start + qty - 1;
			for(int i = start; i <= end; i++)
        	{
        		room_type[type-1].rooms[i].booked = 1;
        		
        	// after valid registration, record input data
        		// guest data
        		strcpy(room_type[type-1].rooms[i].guest.name, name);
        		strcpy(room_type[type-1].rooms[i].guest.nationality, nation);
        		room_type[type-1].rooms[i].guest.period = period;
        	
        		// starting date
        		room_type[type-1].rooms[i].start.year = year;
        		room_type[type-1].rooms[i].start.month = month;
        		room_type[type-1].rooms[i].start.day = day;
        	}
        	room_type[type-1].available -= qty;
        	// available = 10, qty = 4 -> 10 - 4 = 6
		}
	}
	
	//reset screen
    printf("\n\tPress any character to continue: ");
	getchar();
    system("cls");
}
void bookEvent(){
	int type, qty, period, year, month, day;
    char name[30], nation[30];
	print_event_table();
	printf("\n\t Please enter the room you want to book for an event: "); 
	scanf("%d",&type);
	while(type < 1 || type > 2)
	{
		printf("\n\t Please re-enter the room type you want to book for your event (1-2): "); 
		scanf("%d",&type);
	}
	printf("\n\t Please enter how many rooms you want to book (1-%d): ", event_type[type-1].eventAvailable); 
	scanf("%d",&qty);
	while(qty < 1 || qty > event_type[type-1].eventAvailable)
	{
		if (qty == 0) printf("\n\t You do know, you have to book at least 1 right?");
		else printf("\n\t Unfortunately, we don't have that amount of rooms available.");
		printf("\n\t Please re-enter the number quantity room you want to book for your event (1-%d): ", event_type[type-1].eventAvailable); 
		scanf("%d",&qty);
	}
    if(qty <= event_type[type-1].eventAvailable) // if room available
    {
    	fflush(stdin);
    	// input data
    	// scan guest data
    	printf("\n\t Enter your name: "); scanf("%[^\n]",name);
    	printf("\n\t Enter your nationality: "); scanf("%s",nation);
	    printf("\n\t How long will you use the ballroom(s)/meeting room(s) (in days)? "); scanf("%d",&period);
	    
	    //scan date
	    printf("\n\t When will you be arriving?");
	    printf("\n\t Year: "); scanf("%d",&year);
    	printf("\t Month: "); scanf("%d",&month);
        printf("\t Day: "); scanf("%d",&day);
        getchar();
        
        int booked = 1;
        // check condition of valid date
        while((year < 2020 || year > 9999 || month > 12 || month < 1 || day < 1) // kondisi : tanggal tidak mengandung 0 (hari/bulan) ataupun kurang dari tahun 2020
		|| ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) // kondisi 1 : bulan dengan jumlah hari 31
		|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) // kondisi 2 : bulan dengan jumlah hari 30
		|| (month == 2 && ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && day > 29) // kondisi 3.1 : febuari kabisat
		|| ((year % 4 != 0 || year % 100 == 0) && day > 28))) // kondisi 3.2 : febuari non kabisat
		{
			char choice;
			booked = 0; // failed booking
			printf("\n\tThe date you put is invalid, would you like to try again (y/n)? ");
			scanf("%c", &choice);
			if(choice == 'n') break;
			else
			{
				system("cls");
      			// reprint the screen but only check the date again
      			print_event_table();
      			// reprint previously inputed data
      			printf("\n\t Please enter the room type you want to book for your event (1-2): %d", type); 
      			printf("\n\t Please enter how many rooms you want to book (1-%d): %d", event_type[type-1].eventAvailable, qty);
      			
      			// re-scan guest data
      			printf("\n\t Enter your name: %s\n", name);
    			printf("\n\t Enter your nationality: %s\n", nation);
	    		printf("\n\t How long will your be staying with us (in days)? %d\n", period);
	    		
	    		// re-scan date
	    		printf("\n\t When will you be arriving?");
	    		printf("\n\t Year: "); scanf("%d",&year);
    			printf("\t Month: "); scanf("%d",&month);
        		printf("\t Day: "); scanf("%d",&day);
        		getchar();
        		booked = 1; //successful booking
			}
        }
        if(booked)
        {	
        	// post valid input
        	system("cls");
        	printf("\n\t You've successfully booked %d event room(s) for %d days.\n\n", qty, period);
        	  printf("\t You will have to pay 50%% of the total payment for down payment ($%.2f)\n", (float) ((qty *period)* event_type[type-1].eventPrice) / 2);
        	  printf("\t due this week to the following bank account: 1560009861578 (Citygroup)\n\n");
        	  printf("\t Check the guest details to see more information about this booking.\n");
			
        	// set all booked rooms to booked
        	int start = 2 - event_type[type-1].eventAvailable, end = start + qty - 1;
			for(int i = start; i <= end; i++)
        	{
        		event_type[type-1].event_rooms[i].event_booked = 1;
        		
        	// after valid registration, record input data
        		// guest data
        		strcpy(event_type[type-1].event_rooms[i].event_guest.event_name, name);
        		strcpy(event_type[type-1].event_rooms[i].event_guest.event_nationality, nation);
        		event_type[type-1].event_rooms[i].event_guest.event_period = period;
        	
        		// starting date
        		event_type[type-1].event_rooms[i].event_start.event_year = year;
        		event_type[type-1].event_rooms[i].event_start.event_month = month;
        		event_type[type-1].event_rooms[i].event_start.event_day = day;
        	}
        	event_type[type-1].eventAvailable -= qty;
        	// available = 10, qty = 4 -> 10 - 4 = 6
		}
	}
	
	//reset screen
    printf("\n\tPress any character to continue: ");
	getchar();
    system("cls");
}

void bookingDetails(){
	int input_a_number;
	printf("\n\tPress enter the number of booking information you would like to view");
	printf("\n\t\t\t      1. Room Booking");
    printf("\n\t\t\t      2. Event Booking\n");
	puts("");
	printf("\t Enter: ");
    scanf("%d",&input_a_number);
    system("cls");
    if(input_a_number>2){
        printf("\tPlease press a number between 1-2\n");
        bookingDetails();
    }
    switch(input_a_number){
    	case 1:
    		roomDetails();
    		break;
    	case 2:
    		eventDetails();
    		break;
	}
}

void roomDetails()
{
    int type, room;
    print_table();
    printf("\n\t Enter room type   : ");
    scanf("%d",&type);
    printf("\n\t Enter room number : ");
    scanf("%d",&room);
    if(room_type[type-1].rooms[room-1].booked == 0)
	{
        printf("\n\t Data isn't available.\n");
        printf("\n\tPress any character to continue: ");
        getchar();
    }
	else
	{
        printf("\n\t Room Type        : %s\n", room_type[type-1].type);
          printf("\t Room No          : %d\n", room);
          printf("\t Customer Name    : %s\n", room_type[type-1].rooms[room-1].guest.name);
          printf("\t Period           : %d day(s)\n", room_type[type-1].rooms[room-1].guest.period);
          printf("\t Nationality      : %s\n", room_type[type-1].rooms[room-1].guest.nationality);
          printf("\t Arrival Date     : %d/%d/%d\n", room_type[type-1].rooms[room-1].start.day, room_type[type-1].rooms[room-1].start.month, room_type[type-1].rooms[room-1].start.year);
        
        printf("\n\tPress any character to continue: "); 
		getchar();
    }
}
void eventDetails(){
	int type, room;
    print_event_table();
    printf("\n\t Enter event room type   : ");
    scanf("%d",&type);
    printf("\n\t Enter event room number : ");
    scanf("%d",&room);
    if(event_type[type-1].event_rooms[room-1].event_booked == 0)
	{
        printf("\n\t Data isn't available.\n");
        printf("\n\tPress any character to continue: ");
        getchar();
    }
	else
	{
        printf("\n\t Room Type        : %s\n", event_type[type-1].eventRoomType);
          printf("\t Room No          : %d\n", room);
          printf("\t Customer Name    : %s\n", event_type[type-1].event_rooms[room-1].event_guest.event_name);
          printf("\t Period           : %d day(s)\n", event_type[type-1].event_rooms[room-1].event_guest.event_period);
          printf("\t Nationality      : %s\n", event_type[type-1].event_rooms[room-1].event_guest.event_nationality);
          printf("\t Arrival Date     : %d/%d/%d\n", event_type[type-1].event_rooms[room-1].event_start.event_day, event_type[type-1].event_rooms[room-1].event_start.event_month, event_type[type-1].event_rooms[room-1].event_start.event_year);
        
        printf("\n\tPress any character to continue: "); 
		getchar();
    }
}

void Bookingcancellation(){
	int input_cancellation_number;
	printf("\n\t What kind of booking you want to cancel?");
	printf("\n\t 1. Room booking");
    printf("\n\t 2. Event booking");
    puts("");
	printf("\t Enter: ");
    scanf("%d",&input_cancellation_number);
    system("cls");
    if(input_cancellation_number>2){
        printf("\tPlease press a number between 1-2\n");
        Bookingcancellation();
    }
    switch(input_cancellation_number){
    	case 1:
    		Roomcancel();
    		break;
    	case 2:
    		Eventcancel();
    		break;
	}
}

void Roomcancel()
{
	char name[30]; // intput name
	printf("\n\t We will unbook all previously booked rooms by your name.");
	printf("\n\t Enter your name: ");
	scanf("%s", name);
	int count = 0;
    for(int i = 0; i < 5; i++)
    {
    	for(int j = 0; j < 10; j++)
    	{
    		// set all booked rooms under the given name to unbooked
    		if(strcmp(room_type[i].rooms[j].guest.name, name) == 0) 
			{
				room_type[i].rooms[j].booked = 0;
    			room_type[i].available++;
    			count++;
			}
		}
	}
    if (count) printf("\n\t All reservation(s) made by the name %s has been successfully cancelled.\n", name);
    else printf("\n\t There were no reservations made by the name %s\n", name);
}

void Eventcancel(){
	char name[30]; // intput name
	printf("\n\t We will unbook all previously booked rooms by your name.");
	printf("\n\t Enter your name: ");
	scanf("%[^\n]", name);
	int count = 0;
    for(int i = 0; i < 2; i++)
    {
    	for(int j = 0; j < 2; j++)
    	{
    		// set all booked rooms under the given name to unbooked
    		if(strcmp(event_type[i].event_rooms[j].event_guest.event_name, name) == 0) 
			{
				event_type[i].event_rooms[j].event_booked = 0;
    			event_type[i].eventAvailable++;
    			count++;
			}
		}
	}
    if (count) printf("\n\t All reservation(s) made by the name %s has been successfully cancelled.\n", name);
    else printf("\n\t There were no reservations made by the name %s\n", name);
}

void setup_room()
{
	strcpy(room_type[0].type, "Standard");
	strcpy(room_type[1].type, "Twin");
	strcpy(room_type[2].type, "Deluxe");
	strcpy(room_type[3].type, "Suite");
	strcpy(room_type[4].type, "President");
	
	// price in dollars
	room_type[0].price = 125;
	room_type[1].price = 150;
	room_type[2].price = 200;
	room_type[3].price = 300;
	room_type[4].price = 500;
	
	room_type[0].available = 10;
	room_type[1].available = 10;
	room_type[2].available = 10;
	room_type[3].available = 10;
	room_type[4].available = 10;
	
	// set semua kamar ke available
	for(int i = 0; i < 5; i++)
	{
		// set all rooms to unbooked
		for(int j = 0; j < 10; j++) 
		{
			room_type[i].rooms[j].booked = 0;
		}
	}
}
void setup_event(){
	strcpy(event_type[0].eventRoomType, "Ballroom");
	strcpy(event_type[1].eventRoomType, "Meeting room");
	
	// price in dollars
	event_type[0].eventPrice = 900;
	event_type[1].eventPrice = 500;
	
	event_type[0].eventAvailable = 2;
	event_type[1].eventAvailable = 2;
	
	// set semua event ke available
	for(int i = 0; i < 2; i++){
		// set all rooms to unbooked
		for(int j = 0; j < 2; j++) {
			event_type[i].event_rooms[j].event_booked = 0;
		}
	}
}
