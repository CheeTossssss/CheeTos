#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
  int value, height,bf;
  Node *left, *right;
};

int find=0;

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

Node *createNode(int value) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
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

Node *insertNode(Node *root, int value) {
  if(!root) {
    return createNode(value);
  } else if(value < root->value) {
    root->left = insertNode(root->left, value);
  } else if(value > root->value) {
    root->right = insertNode(root->right, value);
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

Node *deleteNode(Node *root, int value) {
  if(!root) {
  	printf("Data not found");
  	find=1;
    return root;
  } else if(value < root->value) {
    root->left = deleteNode(root->left, value);
  } else if(value > root->value) {
    root->right = deleteNode(root->right, value);
  } else {
    if(!root->left || !root->right) {
      Node *newRoot = root->left ? root->left : root->right;
      root->left = root->right = NULL;
      free(root);
      root = NULL;
      return newRoot;
    }
      
    Node *inOrderPredecessor = predecessor(root);
    root->value = inOrderPredecessor->value;
    root->left = deleteNode(root->left, inOrderPredecessor->value);
  }

  return rotation(updateNode(root));
}

void printInOrder(Node *root) {
  if(root) {
    printInOrder(root->left);
    printf("%d ",root->value);
    printInOrder(root->right);
  }
}

void printPreOrder(Node *root) {
  if(root) {
  	printf("%d ",root->value);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void printPostOrder(Node *root) {
  if(root) {
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ",root->value);
  }
}

//void printAVL(Node *root) {
//  printf("\nCurrent tree: \n");
//  printInOrder(root);
//  printf("\n\n");
//}

int main() {
  Node *baseRoot = NULL;
  bool inMenu=true;
  while(inMenu){
  	system("cls");
  	puts("1. Insertion");
  	puts("2. Deletion");
  	puts("3. Traversal");
  	puts("4. Exit");
  	printf("Choose : ");
      int input;
      do{
      	scanf("%d",&input);getchar();
	  }while(input<1||input>4);
	  switch(input){
	  	case 1:
	  		int val;
	  		printf("Insert : ");
	  		scanf("%d",&val);getchar();
	  		baseRoot = insertNode(baseRoot,val );
    		printf("Added %d to the tree.\n",val);
//    		printAVL(baseRoot);
			getch();
    		break;
    	case 2:
    		int del;
    		printf("Delete : ");
    		scanf("%d",&del);getchar();
    		baseRoot=deleteNode(baseRoot,del);
    		if(find==0){
    			puts("Data found");
    			printf("Value %d was deleted",del);
			}
//			printAVL(baseRoot);
			getch();
    		break;
    	case 3:
    		printf("Preorder : ");
    		printPreOrder(baseRoot);
    		puts("");
    		printf("Inorder : ");
    		printInOrder(baseRoot);
    		puts("");
    		printf("Postorder : ");
    		printPostOrder(baseRoot);
    		puts("");
    		getch();
    		break;
    	case 4:
    		puts("Thank You");
    		inMenu=false;
	  }
  }


  
  return 0;
}
