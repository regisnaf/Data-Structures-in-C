// Assignment N4: Template file!
/*
 * Name: Regis Negreiros de Andrade Filho
 * Student Number: 991617976
 * Assignment 4 - PROG20799
 * Date: December 11, 2021
 * References: https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/?ref=lbp
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLUSH stdin=freopen(NULL,"r",stdin)
#define RMN(str) str[strcspn(str,"\n")]=0

#define MAX_LEN 50

typedef struct node BST_node;

struct node {
    short id;
    float gpa;
    BST_node *leftChild;
    BST_node *rightChild;
};

// You must implement all the functions below
BST_node* createBST_node(BST_node* root);   // function to create the BST node
BST_node* createBST();                      // function to create the BST
void displayBST(BST_node* root);            // function to display the BST
void insert_node(BST_node** root, BST_node* node );  // function to insert node into the BST.
void removeBST(BST_node** root);            // function to remove BST
void tree_traversal(BST_node*);             // function used in displayBST() to traverse
BST_node* searchBST(BST_node*, short);      // function to return a node with specific ID
void changeBST (BST_node**);                // function called to change ID in a node in BST
void move_node(BST_node**, short, short);   // function used inside changeBST() to delete node with specific ID and then re-insert it into BST.

// You can declare and implement your own function(s) if needed below:
short get_id(BST_node*, int);
float get_gpa(void);
void detach_node(BST_node**, BST_node**, BST_node*);

// Do NOT modify main() function!
int main() {
    printf("\nCreating List of students:\n\n");

    BST_node* root = createBST();

    displayBST(root);

    if (root!=NULL) {
        putchar('\n');
        changeBST(&root);
        displayBST(root);
    }

    removeBST(&root);

    return 0;
}


// function to display the BST. No need to change it!
void displayBST(BST_node* root){

    printf("\n------------------\n");
    printf(" ID\t  GPA\n");
    printf("------------------\n");

    if(root == NULL) {
        printf("List of students is empty.\n");
    }
    else  {
        tree_traversal(root);
    }
}



// Functions below are declared so template can compile!
// Check all the function prototypes above main() function!


// function to create the BST
BST_node* createBST() {

    BST_node* root = NULL;

    while(1){

        BST_node* new_node = createBST_node(root);

        do {

            printf("Input student's ID (4 digits): ");
            new_node->id = get_id(root, 1);

        } while (new_node->id == -1);

        if(new_node->id == -2){
            //BST creation finished
            free(new_node);
            return root;
        }

        //Capture GPA, initialize with invalid value

        do{

            new_node->gpa = get_gpa();

        } while (new_node->gpa == -1);

        //Insert node in the BST
        insert_node(&root, new_node);

    }


    return root;
}


// function called to change ID in a node in BST
void changeBST (BST_node** root) {

    short old_id, new_id;

    do{
        printf("Input ID you want to change (4 digits): ");
        old_id = get_id(*root, 0);
        if(old_id >= 1000 && old_id <= 9999 ){
            if(searchBST(*root, old_id) == NULL){
                printf("Student with id=%d not found!\n", old_id);
                old_id = -1;
            }
        }
    } while (old_id == -1);

    if(old_id >= 1000 && old_id <= 9999){
        do{
            printf("Input new ID (4 digits): ");
            new_id = get_id(*root, 1);
        }while(new_id == -1);

        if(new_id >= 1000 && new_id <= 9999){
            move_node(root, old_id, new_id);
        }
    }

}


// function used in displayBST() to traverse through nodes!
void tree_traversal(BST_node* root) {

    if (root->leftChild != NULL){
        tree_traversal(root->leftChild);
    }

    printf("%d\t %.2f\n", root->id, root->gpa);

    if(root->rightChild != NULL){
        tree_traversal(root->rightChild);
    }

}


// function to remove BST
void removeBST(BST_node** root) {

    if(*root != NULL){

        BST_node *current = *root;

        if(current->leftChild != NULL){
            removeBST(&current->leftChild);
        }

        if(current->rightChild != NULL){
            removeBST(&current->rightChild);
        }

        free(current);

        *root = NULL;
    }

}

// Function to capture ID
// Return -1 if ID is incorrect, -2 if input is empty, or the actual ID value
short get_id(BST_node* node, int flag){

    char* id_string = (char*) malloc(MAX_LEN*sizeof(char));
    short id_short;

    if(fgets(id_string, MAX_LEN, stdin) == NULL){
        printf("Incorrect value! Please try again!\n");
        id_short = -1;
    } else if(id_string[0] == '\n'){
        //Input is empty
        id_short = -2;
    } else {
        //Convert ID from string to int
        id_short = (int) strtol(id_string, NULL, 10);

        if (id_short < 1000 || id_short > 9999){
            printf("Incorrect value! Please try again!\n");
            id_short =  -1;
        } else {
            //Check for duplicate
            if(flag == 1){
                if(searchBST(node, id_short) != NULL){
                    printf("Incorrect value! Record with id=%d already exists!\n", id_short);
                    id_short = -1;
                }
            }
        }
    }


    free(id_string);
    return id_short;

}

// Function to capture GPA
// Returns -1 if value is incorrect, return GPA otherwise
float get_gpa(){

    char* gpa_string = (char*) malloc(MAX_LEN*sizeof(char));
    float gpa_flt;

    printf("Input student's GPA (0-100): ");

    if(fgets(gpa_string, MAX_LEN, stdin) == NULL){
        printf("Incorrect value! Please try again!\n");
        free(gpa_string);
        return -1;
    }

    if(gpa_string[0] == '\n'){
        printf("Incorrect value! Please try again!\n");
        free(gpa_string);
        return -1;
    }

    //Convert GPA to float
    gpa_flt = strtof(gpa_string, NULL);

    if (gpa_flt < 0.0 || gpa_flt > 100.0){
        printf("Incorrect value! Please try again!\n");
        free(gpa_string);
        return -1;
    }

    free(gpa_string);
    return gpa_flt;
}

// Insert node to BST
void insert_node(BST_node** root, BST_node* node ){

    BST_node *parent, *current;

    //What if tree is empty?
    if(*root == NULL) {
        *root = node;
    } else {
        current = *root;
        parent = NULL;

        do {
            parent = current;

            //go to left of the tree
            if(node->id < parent->id) {
                current = current->leftChild;

                //insert to the left
                if(current == NULL) {
                    parent->leftChild = node;
                }
            }  //go to right of the tree
            else {
                current = current->rightChild;

                //insert to the right
                if(current == NULL) {
                    parent->rightChild = node;
                }
            }

        } while (current != NULL);

    }
}

BST_node* searchBST(BST_node* root, short id) {

    BST_node *current = root;

    while(current !=NULL && current->id != id) {

        //go to left tree or right!
        current = (current->id > id) ?  current->leftChild : current->rightChild;
    }
    // If not found -> returns NULL!
    return current;

}

BST_node* createBST_node(BST_node* root) {
    BST_node* bst = (BST_node*) malloc(sizeof(BST_node));
    if(bst == NULL) {
        printf("Cannot allocate memory for a node!\n");
        exit(-1);
    }
    bst->id = -1;
    bst->leftChild = NULL;
    bst->rightChild = NULL;

    return bst;
}


void move_node(BST_node** node, short existing_id, short new_id){
    BST_node *parent, *current;

    if(*node != NULL){
        current = *node;
        parent = NULL;

        if(current->id == existing_id){

            // existing_id is the root node
            if(current->leftChild != NULL){

                //Left child becomes the new root
                *node = current->leftChild;

                if(current->rightChild != NULL){
                    // re insert old root right child to the tree, where old root left child is the new root
                    insert_node(node, current->rightChild);
                }
            } else {
                //Right child becomes the new root
                *node = current->rightChild;
            }
        } else {
            // existing_id is not the root node

            do {
                parent = current;
                if(existing_id < current->id){
                    current = parent->leftChild;
                    if (current->id == existing_id){
                        detach_node(node, &parent->leftChild, current);
                    }
                } else {
                    current = parent->rightChild;
                    if(current->id == existing_id){
                        detach_node(node, &parent->rightChild, current);
                    }
                }
            } while (current->id != existing_id);
        }

        // re insert node with new ID to the tree
        current->leftChild = NULL;
        current->rightChild = NULL;
        current->id = new_id;
        insert_node(node, current);
    }
}

void detach_node(BST_node **node, BST_node **parentChild, BST_node *current){
    if(current->leftChild != NULL){
        *parentChild = current->leftChild;
        if(current->rightChild != NULL){
            //reinsert current->rightChild to the tree
            insert_node(node, current->rightChild);
        }
    } else {
        *parentChild = current->rightChild;
    }
}
