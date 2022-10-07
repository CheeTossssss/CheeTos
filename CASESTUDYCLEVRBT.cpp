#include <stdio.h>
#include <stdlib.h>
  
struct node {
    int data;
    int color;
    struct node* parent; 
    struct node* rightchild; 
    struct node* leftchild; 
};
  
struct node* root = NULL;
  

struct node* bst(struct node* travers, struct node* temp)
{
    if (travers == NULL)
        return temp;
    if (temp->data < travers->data) {
        travers->leftchild = bst(travers->leftchild, temp);
        travers->leftchild->parent = travers;
    }else if (temp->data > travers->data) {
        travers->rightchild = bst(travers->rightchild, temp);
        travers->rightchild->parent = travers;
    }
    return travers;
}
  
void rightrotate(struct node* temp)
{
    struct node* left = temp->leftchild;
    temp->leftchild = left->rightchild;
    if (temp->leftchild)
        temp->leftchild->parent = temp;
    left->parent = temp->parent;
    if (!temp->parent)
        root = left;
    else if (temp == temp->parent->leftchild)
        temp->parent->leftchild = left;
    else
        temp->parent->rightchild = left;
    left->rightchild = temp;
    temp->parent = left;
}
  
void leftrotate(struct node* temp)
{
    struct node* right = temp->rightchild;
    temp->rightchild = right->leftchild;
    if (temp->rightchild)
        temp->rightchild->parent = temp;
    right->parent = temp->parent;
    if (!temp->parent)
        root = right;
    else if (temp == temp->parent->leftchild)
        temp->parent->leftchild = right;
    else
        temp->parent->rightchild = right;
    right->leftchild = temp;
    temp->parent = right;
}
  
void fixrbt(struct node* root, struct node* pt)
{
    struct node* parentpt = NULL;
    struct node* grandparentpt = NULL;
  
    while ((pt != root) && (pt->color != 0)
           && (pt->parent->color == 1)) 
    {
        parentpt = pt->parent;
        grandparentpt = pt->parent->parent;
        if (parentpt == grandparentpt->leftchild){
            struct node* unclept=grandparentpt->rightchild;
            if (unclept != NULL && unclept->color == 1) {
                grandparentpt->color = 1;
                parentpt->color = 0;
                unclept->color = 0;
                pt=grandparentpt;
            }else {
                if (pt == parentpt->rightchild) {
                    leftrotate(parentpt);
                    pt = parentpt;
                    parentpt = pt->parent;
                }
                rightrotate(grandparentpt);
                int t = parentpt->color;
                parentpt->color = grandparentpt->color;
                grandparentpt->color = t;
                pt = parentpt;
            }
        }else{
            struct node* unclept = grandparentpt->leftchild;
            if ((unclept != NULL) && (unclept->color == 1)) {
                grandparentpt->color = 1;
                parentpt->color = 0;
                unclept->color = 0;
                pt = grandparentpt;
            }else {
                if (pt == parentpt->leftchild) {
                    rightrotate(parentpt);
                    pt = parentpt;
                    parentpt = pt->parent;
            	}
                leftrotate(grandparentpt);
                int t = parentpt->color;
                parentpt->color = grandparentpt->color;
                grandparentpt->color = t;
                pt = parentpt;
            }
        }
    }
  
    root->color = 0;
}

void inOrder(struct node* travers)
{
    if (travers == NULL)
        return;
    inOrder(travers->leftchild);
    printf("%d ", travers->data);
    inOrder(travers->rightchild);
}
  
int main()
{
    int X =10 ;
    int Y[10] = {3,5,18,21,22,29,41,45,48,51};
  
    for (int i = 0; i < X; i++) {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->rightchild = NULL;
        temp->leftchild = NULL;
        temp->parent = NULL;
        temp->data = Y[i];
        temp->color = 1;
  
        root = bst(root, temp);
  
        fixrbt(root, temp);
    }
  
    printf("Inoder Traversal of Created Tree\n");
    inOrder(root);
  
    return 0;
}
