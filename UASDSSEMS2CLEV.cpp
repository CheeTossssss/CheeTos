#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
	char word[255];
	char language[255];
  int height,bf;
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

Node *createNode(char language[],char word[]) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->word,word);
  strcpy(newNode->language,language);
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

Node *insertNode(Node *root,char language[],char word[]) {
  if(!root) {
    return createNode(language,word);
  } else if(strcmp(word,root->word)<0) {
    root->left = insertNode(root->left, language,word);
  } else if(strcmp(word,root->word)>0) {
    root->right = insertNode(root->right, language,word);
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

Node *deleteNode(Node *root, char delang[]) {
  if(!root) {
  	printf("Data not found");
    return root;
  } else if(strcmp(delang,root->language)<0) {
    root->left = deleteNode(root->left, delang);
  } else if(strcmp(delang,root->language)>0) {
    root->right = deleteNode(root->right, delang);
  } else {
    if(!root->left || !root->right) {
      Node *newRoot = root->left ? root->left : root->right;
      root->left = root->right = NULL;
      free(root);
      root = NULL;
      return newRoot;
    }
      
    Node *inOrderPredecessor = predecessor(root);
    strcpy(root->language,inOrderPredecessor->language);
    root->left = deleteNode(root->left, inOrderPredecessor->language);
  }

  return rotation(updateNode(root));
}

Node *deleteNode2(Node *root, char delwrd1[],char delwrd2[]) {
  if(!root) {
  	printf("Data not found");
    return root;
  } else if(strcmp(delwrd1,root->language)<0) {
    root->left = deleteNode2(root->left, delwrd1,delwrd2);
  } else if(strcmp(delwrd1,root->language)>0) {
    root->right = deleteNode2(root->right, delwrd1,delwrd2);
  } else {
    if(!root->left || !root->right) {
      Node *newRoot = root->left ? root->left : root->right;
      root->left = root->right = NULL;
      free(root);
      root = NULL;
      return newRoot;
    }
      
    Node *inOrderPredecessor = predecessor(root);
    strcpy(root->language,inOrderPredecessor->language);
    root->left = deleteNode2(root->left, inOrderPredecessor->language,inOrderPredecessor->word);
  }

  return rotation(updateNode(root));
}

void printInOrder(Node *root) {
	char dumb[255];
	char dumb2[255];
  if(root) {
    printInOrder(root->left);
    printf("%s\n",root->language);
    printf("-%s\n",root->word);
    printInOrder(root->right);
  }
}

void printInOrder2(Node *root,char lang[]) {
	char dumb[255];
	char dumb2[255];
  if(root) {
    printInOrder2(root->left,lang);
    if(strcmp(root->language,lang)==0){
    printf("-%s\n",root->word);
	}
    printInOrder2(root->right,lang);
  }
}

//void search(Node *root, char lang[]){
//    if (!root){
//    	printf("Nothing\n");
//        return NULL;
//    }else if(strcmp(lang,root->language)==0){
//    	
//	}
//
//    else if (strcmp(lang, root->language) < 0){
//        search(root->left, language);
//    }
//    else if (strcmp(lang, root->language) > 0){
//        search(root->right, language);
//    }
//}

int main() {
  Node *baseRoot = NULL;
  char conf[255];
  char kata[255];
  char bahasa[255];
  int T;
  scanf("%d",&T);
  for(int i=0;i<T;i++){
  	scanf("%s",conf);
  	if(strcmp(conf,"ADD")==0){
  		scanf("%s",bahasa);
  		scanf("%s",kata);
  		baseRoot=insertNode(baseRoot,bahasa,kata);
  		printf("Case %d:\n",i+1);
  		printf("Successfully Added...");
	  }
	if(strcmp(conf,"SHOW-ALL")==0){
		printf("Case %d:\n",i+1);
		printInOrder(baseRoot);
	}
	if(strcmp(conf,"SHOW-LANG")==0){
		char lang[255];
		scanf("%s",lang);
		printf("Case %d:\n",i+1);
		printInOrder2(baseRoot,lang);
	}
	if(strcmp(conf,"DEL-LANG")==0){
		char delang[255];
		scanf("%s",delang);
		printf("Case %d:\n",i+1);
		printf("Successfully Deleted...");
		baseRoot=deleteNode(baseRoot,delang);
	}
	if(strcmp(conf,"DEL-WORD")==0){
		char delwrd1[255];
		char delwrd2[255];
		scanf("%s",delwrd1);
		scanf("%s",delwrd2);
		printf("Case %d:\n",i+1);
		printf("Successfully Deleted...");
		baseRoot=deleteNode2(baseRoot,delwrd1,delwrd2);
	}
  }


  
  return 0;
}
