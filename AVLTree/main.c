#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
    int height; // derinlik
};

int max(int a, int b){
    return a>b ? a:b;
}

struct node *newNode(int key){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}

int height(struct node *node){
    if(node==NULL) return 0;
    return node->height;
}

struct node *rightRotate(struct node *y){
    struct node *x=y->left, *T=x->right;
    x->right=y;
    y->left = T;
    
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1; 
    
    return x;
} // sol sol

struct node *leftRotate(struct node *x){
    struct node *y=x->right, *T=y->left; 
    y->left=x;
    x->right = T;
    
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    
    return y;
} // sag sag

int getBalance(struct node *node){
    if(node==NULL) return 0;
    return height(node->left) - height(node->right);
}

struct node *insert_help(struct node *node, int key){
    int balance;
    if(node==NULL) return newNode(key);
    if(key<node->key) node->left = insert_help(node->left,key);
    else node->right = insert_help(node->right,key);
    
    node->height = max(height(node->left),height(node->right)) +1;
    
    balance=getBalance(node);
    
    if(balance>1 && key < node->left->key) // sol sol
        return rightRotate(node);
    if(balance<-1 && key > node->right->key) // sag sag
        return leftRotate(node);
    if(balance>1 && key>node->left->key){  // sol sag
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && key<node->right->key){  // sag sdol
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}
void insert (struct node **node,int key){
    *node=insert_help(*node,key);
}


void preOrder_yardimci(struct node *node) {
    if(node!=NULL){
        printf("%d (%2d) ",node->key,node->height);
        preOrder_yardimci(node->left);
        preOrder_yardimci(node->right);
    }
    
}

void preOrder(struct node *node) {
    preOrder_yardimci(node);
    printf("\n");
}

struct node *minValueNode(struct node *root){
    struct node *current = root;
    if(current == NULL) return NULL;
    while(current->left) current=current->left;
    return current;
}

struct node *deleteNode_help(struct node *root, int key){
    if(root==NULL) return root;
    if(key <root->key) root->left=deleteNode_help(root->left,key);
    else if(key>root->key) root->right=deleteNode_help(root->right,key);
    else {
        if(root->left == NULL || root->right == NULL){
            struct node *temp=root->left ?root->left:root->right;
            if(temp==NULL){
                temp=root;
                root=NULL;
            }
            else *root=*temp; // root->key=temp->key; root->rigt = temp->rigt; root->left= 
            free(temp);
        }
        else {
            struct node *temp=minValueNode(root->right);
            root->key=temp->key;
            root->right=deleteNode_help(root->right,temp->key);
        }
    }
    
    if(root==NULL) return root;
    
    root->height=max(height(root->left),height(root->right))+1;
    int balance=getBalance(root);
    
    if(balance>1 && getBalance(root->left) >=0)
        return rightRotate(root);
    if(balance>1 && getBalance(root->left) < 0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance <-1 && getBalance(root->right) <=0)
        return leftRotate(root);
    if(balance < -1 && getBalance(root->right)>0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
        
    return root;    
}
void deleteNode(struct node **node,int key){
    *node=deleteNode_help(*node,key);
}
int main(int argc, char** argv) {
    struct node *root=NULL;
    
    insert(&root,40);
    insert(&root,35);
    insert(&root,38);
    insert(&root,60);
    insert(&root,80);
    insert(&root,50);
    insert(&root,21);
    insert(&root,18);
    insert(&root,11);
    preOrder(root);
    deleteNode(&root,38);
    return (EXIT_SUCCESS);
}
