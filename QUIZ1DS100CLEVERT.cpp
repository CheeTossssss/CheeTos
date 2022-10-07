#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const int MAX_TABLE=55;

struct Node{
	char nama[255];
	char ktgr[255];
	char brnd[255];
	int stck;
	int prc;
	int ID;
	int NO;
	Node *next;
}*head[MAX_TABLE],*tail[MAX_TABLE];


Node *createNode(const char* nama,const char* ktgr,const char* brnd,int stck,int prc,int ID,int NO){
	Node *temp=(Node*)malloc(sizeof(Node));
	strcpy(temp->nama,nama);
	strcpy(temp->ktgr,ktgr);
	strcpy(temp->brnd,brnd);
	temp->stck=stck;
	temp->prc=prc;
	temp->ID=ID;
	temp->NO=NO;
	temp->next=NULL;
	return temp;
}

int HASH(int ID){
	return(ID-1)%MAX_TABLE;
}

void InsertChaining(const char* nama,const char* ktgr,const char* brnd,int stck,int prc,int ID,int NO){
	int index=HASH(ID);
	if(head[index]){
		Node *temp=createNode(nama,ktgr,brnd,stck,prc,ID,NO);
		tail[index]->next=temp;
		tail[index]=temp;
	}else{
		Node *temp=createNode(nama,ktgr,brnd,stck,prc,ID,NO);
		head[index]=tail[index]=temp;
	}
}

void popHead(int i){
	if(!head[i]){
		printf("No Data Found !!!");
		printf("Press Enter To Continue...");
		getchar();
		return;
	}else{
		Node *temp=head[i]->next;
		head[i]->next=NULL;
		free(head[i]);
		head[i]=temp;
	}
}

void popTail(int i)
{
  if(!head[i])
  {
    puts("No data found!");
    printf("Press enter to continue...");
    getchar();
    return;
  }
  else
  {
    Node *curr = head[i];

    while(curr->next != tail[i])
    curr = curr->next;

    curr->next = NULL;
    free(tail[i]);
    tail[i] = curr;
  }
}

int DeleteProduct(int ID){
	int n=HASH(ID);
	if(!head[n]){
		puts("No Data Found!");
    	printf("Press enter to continue...");
    	getchar();
    	return 0;
	}else if(head[n]->ID==ID){
		popHead(n);
		return 1;
	}else if(head[n]->ID==ID){
		popTail(n);
		return 1;
	}else{
		Node *curr=head[n];
		while(curr->next&&curr->next->ID!=ID){
			curr=curr->next;
		}
		if(curr!=tail[n]){
			Node *temp=curr->next;
			curr->next=temp->next;
			free(temp);
			return 1;
		}
	}
	puts("No Data Found!");
  	printf("Press enter to continue...");
  	getchar();
  	return 0;
}

void ViewProduct(){
	int flag=1;
	int flag1=0;
	for(int i=0;i<MAX_TABLE;i++){
		if(head[i]){
			flag=0;
			if(!flag1){
       			puts("=======================================================================");
        		printf("NO\tID\tProduct Name\tCategory\tBrand\tStock\tPrice\n");
        		puts("=======================================================================");
        		flag1 = 1;
			}
			Node *curr=head[i];
			while(curr){
        		printf("%d\tNKW%02d\t%s\t\t%s\t\t%s\t%d\t%d\n",curr->NO,curr->ID, curr->nama, curr->ktgr, curr->brnd,curr->stck,curr->prc);
        		curr = curr->next;
      		}
    	}
  	}
  	if(flag){
    puts("There Is No Data!");
}
//    getchar();
//  	}
//
//  	if(optional && !flag){
//    printf("\nPress enter to continue...");
//    getchar();
//    puts("");
//  	}
}

void AddProduct(int id,int no){
	char name[255];
	char kategori[255];
	char brand[255];
	int stock;
	int price;
	
	do{
		printf("Input Product Name [ 5 - 24 Characters ]: ");
		scanf("%[^\n]",name);getchar();
	}while(strlen(name)<6||strlen(name)>25);
	do{
		printf("Choose Category [ Shoes | Bag ] ( case sensitive ): ");
		scanf("%s",kategori);getchar();
	}while(strcmp(kategori,"Shoes")!=0&&strcmp(kategori,"Bag")!=0);
	do{
		printf("Choose Brand [ Nike | Adidas ] ( case sensitive ): ");
		scanf("%s",brand);getchar();
	}while(strcmp(brand,"Nike")!=0&&strcmp(brand,"Adidas")!=0);
	do{
		printf("Input Stock [ 50 - 150 ]: ");
		scanf("%d",&stock);getchar();
	}while(stock<51||stock>151);
	do{
		printf("Input Price [ 200000 - 1000000 ]: ");
		scanf("%d",&price);getchar();
	}while(price<200001||price>1000001);
	InsertChaining(name,kategori,brand,stock,price,id,no);
	ViewProduct();
    puts("");
}



int search(int ID)
{
  int i = HASH(ID);
  Node *curr = head[i];

  int flag = 1;
  while(curr)
  {
    if(curr->ID == ID)
    {
      flag = 0;
      break;
    }
    curr = curr->next;
  }
  return flag;
}

int main()
{
	int flag3,flagDelete,NumbID,flag2,flag1;
	int id=0;
	int no=0;
	char del[255];
	bool menu=true;
	while(true){
		system("cls");
		ViewProduct();
		puts("NAKEWAREHOUSE");
		puts("=================");
		puts("1. Insert New Product");
		puts("2. Delete Product");
		puts("3. Exit");
		printf(">> ");
		
	int input_menu;
	scanf("%d",&input_menu);getchar();
	switch(input_menu){
		case 1:
			++id;
			++no;
			system("cls");
			AddProduct(id,no);
			break;
		case 2:
			system("cls");
			ViewProduct();
			if(!flag3){
				puts("");
				do{
					flagDelete=1;
					 printf("Input ItemID to delete ( case sensitive ): ");
					 scanf("%s",del);getchar();
					 if(del[0]=='N'&&del[1]=='K'&&del[2]=='W'&&(del[3]>='0'&&del[3]<='9')&&(del[4]>='0'&&del[4]<='9')&&del[5]=='\0'){
					 	flagDelete=0;
					 }
				}while(flagDelete);
				NumbID=(((del[3]-'0')*10)+del[4]-'0');
				flag2=search(NumbID);
//				if(!flag2){
//          			View(NumbID);
//        		}
        		flag1 = DeleteProduct(NumbID);
       			if(flag1){
       				puts("Succes!!!");
          			printf("Press enter to continue...");
          			getchar();
        		}
			}
			break;
		case 3:
			menu=false;
	}
	}
	
	
	return 0;
}
