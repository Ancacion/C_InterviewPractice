//
//  main.c
//  C_DS&Algorithm_BinarySearchTree
//
//  Created by Ancacion on 2022/6/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int input) {
    if(*treePtr == NULL) {
        *treePtr = (TreeNode *)malloc(sizeof(TreeNode));
        
        if(*treePtr != NULL) {
            (*treePtr) -> data = input;
            (*treePtr) -> left = NULL;
            (*treePtr) -> right = NULL;
        }
        else {
            printf("No memory available.\n");
        }
    }
    else {
        if(input < (*treePtr) -> data) {
            insertNode(&((*treePtr) -> left), input);
        }
        else if(input > (*treePtr) -> data) {
            insertNode(&((*treePtr) -> right), input);
        }
        else {
            printf("%s", "duplicate");
        }
    }
}

void inOrder(TreeNodePtr treePtr) {
    if(treePtr != NULL) {
        inOrder(treePtr -> left);
        printf("%d ", treePtr -> data);
        inOrder(treePtr -> right);
    }
}

void preOrder(TreeNodePtr treePtr) {
    if(treePtr != NULL) {
        printf("%d ", treePtr -> data);
        preOrder(treePtr -> left);
        preOrder(treePtr -> right);
    }
}

void postOrder(TreeNodePtr treePtr) {
    if(treePtr != NULL) {
        postOrder(treePtr -> left);
        postOrder(treePtr -> right);
        printf("%d ", treePtr -> data);
    }
}

int main(int argc, const char * argv[]) {
    TreeNodePtr root = NULL;
    int num = 0;
    
    srand(time(NULL));
    //int inputData[15] = {15, 6, 8, 26, 9, 10, 1, 3, 99, 12, 17, 56, 2, 9, 87};
    printf("The numbers being placed in the tree are : \n");
    for(int i = 1; i <= 10; i++) {
        num = rand() % 20;
        printf("%d ", num);
        insertNode(&root, num);
    }
    printf("\n");
    
    printf("The inOrder traversal : ");
    inOrder(root);
    printf("\n\nThe preOrder traversal : ");
    preOrder(root);
    printf("\n\nThe postOrder traversal : ");
    postOrder(root);
    printf("\n");
    return 0;
}
