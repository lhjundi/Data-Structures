#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int KEY_TYPE;

typedef struct aux{
    KEY_TYPE key;
    struct aux *left, *right;
} NODE;

typedef NODE* PTR;

// returns tha node adress that contains key = k or NULL if don't find it
// uses recursive binary search
PTR binarySearch(KEY_TYPE k, PTR root){
    if(root == NULL) return NULL;
    if(root->key == k) return false;
    if(root->key < k)
        return binarySearch(k, root->right);
    return binarySearch(k, root->left);
}

//iterative version of binary search
PTR iterativeBinarySearch(PTR root, KEY_TYPE k){
    PTR current = root;
    while (current){
        if(current->key == k) return current;
        if(k < current->key) current = current->left;
        else current = current->right;
    }
    return NULL;
}

// creates a new node
PTR createNewNode(KEY_TYPE key){
    PTR newNode = (PTR)malloc(sizeof(NODE));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = key;
    return newNode;
}

// inserts a new node with kay = newKey in the binary tree
// whose root address is passed in the root parameter
bool insertNodeIterative(PTR* root, KEY_TYPE key){
    if(*root == NULL){
        *root = createNewNode(key);
        return true;
    } else{
        PTR current = *root;
        while (current){
            if (current->key > key){
                if(current->left == NULL){
                    current->left = createNewNode(key);
                    return true;
                }else current = current->left;
            }
            else{
                if(current->right == NULL){
                    current->right = createNewNode(key);
                    return true;
                }
                else current = current->right;
            }
        }
    }
}

// recursive aux function for insertion
bool insertAux(PTR root, KEY_TYPE key){
    if( root->key > key ){
        if(root->key == NULL){
            root->left = createNewNode(key);
            return true;
        }else 
            return insertAux(root->left, key);
    } else {
        if(root->right == NULL){
            root->right = createNewNode(key);
            return true;
        }
        else 
            return insertAux(root->right, key);
    }
}

bool insertNode(PTR * root, KEY_TYPE newKey){
    if(*root == NULL){
        *root = createNewNode(newKey);
        return true;
    }
    else return insertAux(*root, newKey);
}

//insert a new node with key = newKey in the binary tree pointed by the root
void insertNode2(PTR *root, KEY_TYPE newKey){
    PTR p = *root;
    if (p == NULL) *root = createNewNode(newKey);
    else{
        if(newKey > p->key) insertNode2(&(p->right), newKey);
        else insertNode2(&(p->left), newKey);
    }
}

//Binary search not recursive returning the parent node
PTR searchNode(PTR root, KEY_TYPE key, PTR *parent){
    PTR current = root;
    *parent = NULL;
    while(current){
        if(current->key == key) return current;
        *parent = current;
        if(key < current->key) current = current->left;
        else current = current->right;
    }
    return NULL;
}

// searches by the bigger key minor than the key that
// will be deleted

PTR biggerLeft(PTR p, PTR *prev){
    *prev = p;
    p = p->left;
    while (p->right){
        *prev = p;
        p = p->right;
    }
    return(p);
}

bool deleteNode(PTR *root, KEY_TYPE key){
    PTR current, parent, substitute, parentSubstitute;
    current = searchNode(*root, key, &parent);
    if (current == NULL) return false;
    if (!current->left || !current->right){ //has one o none child
        if(current->left) substitute = current->left;
        else substitute = current->right;
        if(!parent){
            *root = substitute;
        }else {
            if(parent->left == current) parent->left = substitute;
            else parent->right = substitute;
        }
        free(current);
    } else { //has to childs
        substitute = biggerLeft(current, &parentSubstitute);
        current->key = substitute->key;
        if (parentSubstitute->left == substitute) parentSubstitute->left = substitute->left;
        else parentSubstitute->right = substitute->left;
        free(substitute);
    }
    return true;
}

//shows inorder
void showTreeInorder(PTR root){
    if (root == NULL) return;
    showTreeInorder(root->left);
    printf("%d ", root->key);
    showTreeInorder(root->right);
}

// shows preorder
void showTreePreorder(PTR root){
    if (root == NULL) return;
    printf("%d ", root->key);
    showTreePreorder(root->left);
    showTreePreorder(root->right);
}

//show postorder
void showTreePostorder(PTR root){
    if (root == NULL) return;
    printf("%d ", root->key);
    showTreePostorder(root->left);
    showTreePostorder(root->right);
}

// aux function of destruction of a tree
void destroyAux(PTR subRoot){
    if(subRoot){
        destroyAux(subRoot->left);
        destroyAux(subRoot->right);
        free(subRoot);
    }
}

void destroyTree(PTR *root){
    destroyAux(*root);
    *root = NULL;
}

void init(PTR *root){
    *root = NULL;
}