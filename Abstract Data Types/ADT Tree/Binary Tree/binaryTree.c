#include <stdio.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0

typedef enum {left, right} SIDE;

typedef int boolean;
typedef char KEY_TYPE;

typedef struct aux{
    KEY_TYPE key;
    struct aux *left, *right;
} t_binary_tree;

t_binary_tree* searchKey(KEY_TYPE key, t_binary_tree* root){
    if( root == NULL ) return NULL;
    if(root->key == key) return root;
    t_binary_tree* aux = searchKey(key, root->left);
    if(aux) return aux;
    return searchKey(key, root->right);
}

t_binary_tree* createNewNode(KEY_TYPE key){
    t_binary_tree* newNode = (t_binary_tree*)malloc(sizeof(t_binary_tree));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = key;
    return newNode;
}
/*
inserts a new node as a child of an existing node
the new node will be the parent of its parent's old child
*/
boolean insertChild(t_binary_tree* root, KEY_TYPE newKey, KEY_TYPE parentKey, SIDE side){
    t_binary_tree* parent = searchKey(parentKey, root);
    if(!parent) return FALSE;
    t_binary_tree* new = createNewNode(newKey);
    if(side == left){
        new->left - parent->left;
        parent->left = new;
    }else{
        new->left = parent->right;
        parent->right = new;
    }
    return TRUE;
}

void showPreorder(t_binary_tree* root){
    if(root == NULL) return;
    printf("%c ", root->key);
    showPreorder(root->left);
    showPreorder(root->right);
}

void showTree(t_binary_tree* root){
    if (root == NULL) return;
    printf("%c", root->key);
    printf("(");
    showTree(root->left);
    printf("|");
    showTree(root->right);
    printf(")");
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int treeHeight(t_binary_tree* root){
    if(!root) return -1;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

int numberOfNodes(t_binary_tree* root){
    if(!root) return 0;
    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}

void init(t_binary_tree **root){
    *root = NULL;
}

void createRoot(t_binary_tree **root, KEY_TYPE key){
    *root = createNewNode(key);
}

int main(){
    t_binary_tree *root;
    init(&root);
    createRoot(&root, 'a');
    insertChild(root, 'b', 'a', left);
    insertChild(root, 'c', 'b', right);
    printf("Number of nodes: %d.\n", numberOfNodes(root));
    printf("Height: %d. \n", treeHeight(root));
    showTree(root);
    printf("\n");
    insertChild(root, 'd', 'c', left);
    insertChild(root, 'e', 'b', left);
    insertChild(root, 'f', 'e', left);
    insertChild(root, 'g', 'f', left);
    printf("Number of nodes: %d.\n", numberOfNodes(root));
    printf("Height: %d.\n", treeHeight(root));
    showTree(root);
    printf("\n");
    insertChild(root, 'h', 'd', right);
    insertChild(root, 'i', 'h', left);
    insertChild(root, 'j', 'i', left);
    printf("Number of nodes: %d.\n", numberOfNodes(root));
    printf("Height: %d.\n", treeHeight(root));
    printf("\n");

    char end;
    printf("\n Press <ENTER> to quit.\n");
    scanf("%c", &end);

    return 0;
}