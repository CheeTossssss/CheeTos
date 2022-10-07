#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
  int height,bf;
  char title[255];
  char type[255];
  int stok;
  int harga;
  char ID[3];
  Node *left, *right;
};

int find=0;
int prn=0;

int max(int a, int b) {
  return (a > b) ? a : b;
}

int getHeight(Node *root) {
  return (root) ? root->height : 0;
}

int getBalanceFactor(Node *root) {
  return (root) ? getHeight(root->left) - getHeight(root->right) : 0;
}

int computeNewHeight(Node *root) {
  return max(getHeight(root->left), getHeight(root->right)) + 1;
}

Node *rotationType(Node *x, const char *type) {
  Node *y, *z;

  if(strcmp(type, "left") == 0) {
    y = x->right;
    z = y->left;
    y->left = x;
    x->right = z;
  } else {
    y = x->left;
    z = y->right;
    y->right = x;
    x->left = z;
  }

  x->height = computeNewHeight(x);
  y->height = computeNewHeight(y);
  return y;
}

Node *createNode(char* title,char* type,int stok,int harga,char* ID) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->title,title);
  strcpy(newNode->type,type);
  newNode->stok = stok;
  newNode->harga=harga;
  strcpy(newNode->ID,ID);
  newNode->height = 1;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *updateNode(Node *root) {
  root->height = computeNewHeight(root);
  root->bf = getBalanceFactor(root);
  return root;
}

Node *leftRotate(Node *root) {
  Node *pivot = root->right;
  Node *temp = pivot->left;
  pivot->left = root;
  root->right = temp;
  root = updateNode(root);
  pivot = updateNode(pivot);
  return pivot;
}

Node *rightRotate(Node *root) {
  Node *pivot = root->left;
  Node *temp = pivot->right;
  pivot->right = root;
  root->left = temp;
  root = updateNode(root);
  pivot = updateNode(pivot);
  return pivot;
}

Node *rotation(Node *root) {
  if(root->bf > 1 && root->left->bf >= 0) { // bf > 1 = left child unbalanced
    return rightRotate(root);
  } else if(root->bf > 1 && root->left->bf < 0) {
    root->left = leftRotate(root->left); // double rotation
    return rightRotate(root);
  } else if(root->bf < -1 && root->right->bf <= 0) { // bf < -1 = right child unbalanced
    return leftRotate(root);
  } else if(root->bf < - 1 && root->right->bf > 0) {
    root->right = rightRotate(root->right); // double rotation
    return leftRotate(root);
  }

  return root;
}

Node *insertNode(Node *root, char* title,char* type,int stok,int harga,char* ID) {
  if(!root) {
    return createNode(title,type,stok,harga,ID);
  } else if(ID < root->ID) {
    root->left = insertNode(root->left, title,type,stok,harga,ID);
  } else if(ID > root->ID) {
    root->right = insertNode(root->right, title,type,stok,harga,ID);
  }

  return rotation(updateNode(root));
}

Node *predecessor(Node *root) {
  Node *curr = root->left;

  while(curr->right) {
    curr = curr->right;
  }

  return curr;
}

Node *deleteNode(Node *root,char* ID) {
  if(!root) {
    return root;
  } else if(strcmp(ID,root->ID)<0) {
    root->left = deleteNode(root->left, ID);
  } else if(strcmp(ID,root->ID)>0) {
    root->right = deleteNode(root->right,ID);
  } else {
    if(!root->left || !root->right) {
    	root->stok=root->stok-1;
    	if(root->stok==0){
      Node *newRoot = root->left ? root->left : root->right;
      root->left = root->right = NULL;
      free(root);
      root = NULL;
      return newRoot;
 	 }    
    }
      
    Node *inOrderPredecessor = predecessor(root);
    strcpy(root->ID,inOrderPredecessor->ID);
    root->left = deleteNode(root->left, inOrderPredecessor->ID);
  }

  return rotation(updateNode(root));
}

void print(Node *root){
	if(!root){
		prn=1;
		printf("No Game in Storage!\n");
		printf("Press enter to continue...");
		getch();
	}
}

void printInOrder(Node *root) {
  if(root) {
    printInOrder(root->left);
    printf("|GA%s\t\t|%s\t|%s\t\t|%d\t|%d\n",root->ID,root->title,root->type,root->stok,root->harga);
    printInOrder(root->right);
  }
}

void printPreOrder(Node *root) {
  if(root) {
  	printf("|GA%s\t\t|%s\t|%s\t\t|%d\t|%d\n",root->ID,root->title,root->type,root->stok,root->harga);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void printPostOrder(Node *root) {
  if(root) {
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("|GA%s\t\t|%s\t|%s\t\t|%d\t|%d\n",root->ID,root->title,root->type,root->stok,root->harga);
  }
}

//void printAVL(Node *root) {
//  printf("\nCurrent tree: \n");
//  printInOrder(root);
//  printf("\n\n");
//}

char rand_alphabet(){
	int r=rand();
	return 65+r%26;
}

int main() {
  Node *baseRoot = NULL;
  bool inMenu=true;
  while(inMenu){
  	system("cls");
  	puts("1. Insert Game");
  	puts("2. View Games");
  	puts("3. Sell Games");
  	puts("4. Exit");
  	printf("Choose : ");
      int input;
      do{
      	scanf("%d",&input);getchar();
	  }while(input<1||input>4);
	  switch(input){
	  	case 1:
	  		char gametit[255];
	  		do{
	  			printf("Input Game Title [ 3 - 25 ]: ");
	  			scanf("%s",gametit);getchar();
	  		  }while(strlen(gametit)<3||strlen(gametit)>25);
	  		char gametype[255];
	  		do{
	  			printf("Input Game Type [ Action, Strategy, Role-Playing, Simulation, Sports ](case sensitive):");
	  			scanf("%s",gametype);getchar();
			  }while(strcmp(gametype,"Action")!=0&&strcmp(gametype,"Strategy")!=0&&strcmp(gametype,"Role-Playing")!=0&&strcmp(gametype,"Simulation")!=0&&strcmp(gametype,"Sports")!=0);
			int stock;
			do{
				printf("Input Stock [ More than 1 ]:");
				scanf("%d",&stock);
			  }while(stock<1);
			int price;
			do{
				printf("Input Price [ 40.000 - 1.000.000 ]:");
				scanf("%d",&price);
			  }while(price<40000||price>1000000);
			srand(time(NULL));
			char a[3];
			for(int i=0;i<3;i++){
				if(rand()%2==0){
					a[i]=rand_alphabet();
				}else{
				a[i]=(rand()%10)+'0';
				}
			}
	  		baseRoot = insertNode(baseRoot,gametit,gametype,stock,price,a);
    		break;
    	case 2:
    		char inpt[255];
    		print(baseRoot);
    		if(prn==0){
    			do{
    				printf("Input view method [ pre | in | post ](case-sensitive):");
    				scanf("%s",inpt);
				}while(strcmp(inpt,"pre")!=0&&strcmp(inpt,"in")!=0&&strcmp(inpt,"post")!=0);
				printf("|ID\t\t|Title\t|Type\t\t|Stock\t|Price");
				puts("");
				if(strcmp(inpt,"pre")==0){
					printPreOrder(baseRoot);
					printf("Press enter to continue...");
  					getch();
				}else if(strcmp(inpt,"in")==0){
					printInOrder(baseRoot);
					printf("Press enter to continue...");
  					getch();
				}else if(strcmp(inpt,"post")==0){
					printPostOrder(baseRoot);
					printf("Press enter to continue...");
  					getch();
				}
			}
    		break;
    	case 3:
    		char val[255];
    		print(baseRoot);
    		if(prn==0){
    			printInOrder(baseRoot);
    				printf("Choose ID:");
    				scanf("%s",val);
    				baseRoot=deleteNode(baseRoot,val);
				printf("1 Unit of %s is sold!\n",val);
				printf("Press enter to continue...");
  				getch();
			}
    		break;
    	case 4:
    		puts("Thank You");
    		inMenu=false;
	  }
  }


  
  return 0;
}
