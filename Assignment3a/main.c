// Assignment N3 Template

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define FLUSH stdin=freopen(NULL,"r",stdin)
#define FLUSH while(getchar() != '\n')
#define RMN(str) str[strcspn(str,"\n")]=0
#define MAX_LEN 50
#define MAX_GPA 100
#define MAX_ID 1010

typedef struct node {
    char *name;
    float gpa;
    size_t id;
    struct node *next;
} student_t;

// You must use the prototypes below. Do NOT declare any other functions!
// You must fix the prototypes below: Make sure you use the correct parameter(s)
struct node *p, *q, *previous, *head;
student_t* createNode(); // function to create the node
student_t* createList(); // function to create the list
void displayList(student_t*);         // function to display the list
void insertNode(student_t**);  // function to insert node into the sorted list.
void removeList(student_t*);  // function to delete the linked list


int main() {
    printf("\nCreating List of students:\n\n");

    student_t* head = createList();

    displayList(head);

    //removeList(&head);

    return 0;
}

// Your code goes below!!
// Declare the functions according to prototypes.
student_t* createNode() {
    student_t* node = NULL;

    char tmp[MAX_LEN];
    size_t tmp_len;
    char str[MAX_GPA];
    int i, n, item, id;

    //previous = NULL;

    printf("Insert student's name (id= 1000): ");
    fgets(tmp,MAX_LEN,stdin);
    RMN(tmp); //FLUSH;
    tmp[strcspn(tmp, "\n")] = 0;

    tmp_len=strlen(tmp);

    if ( tmp_len >0) {
        node = (student_t*) malloc( sizeof(student_t) );
        if (node == NULL) {
            printf("Cannot allocate memory for a person!\n");
            exit(1);
        }

        node->name = (char*) calloc( tmp_len+1, sizeof(char));
        if (node->name == NULL) {
            printf("Cannot allocate memory for name!\n");
            exit(1);
        }

        strcpy(node->name, tmp);

    do {
        printf("Insert student's GPA (0-100): ");
        fgets(str, MAX_GPA, stdin);
        //FLUSH;
        RMN(tmp);

        node->gpa = (float) strtol(tmp, NULL, 10);

        printf("Insert student ID: ");
        fgets(str, MAX_ID, stdin);
        //FLUSH;
        RMN(tmp);
        node->id = (size_t) strtol(tmp, NULL, 10);


        q = (struct node *)malloc(sizeof(struct node)); //sizeof calculates the size of the node
        q->name= (char *)malloc(sizeof(char)*MAX_LEN);
        strcpy(q->name, tmp);
        q->gpa = node->gpa;
        q->id = node->id;
        q->next = NULL;

        head = q;
        p = head;
    } while (node->gpa < 1 || node->gpa > 100);

        node->next=NULL;
    }


    return p;

}

student_t* createList(){

    student_t *next_node=NULL, *current=NULL, *head=NULL;

    // We get next_node. It can be NULL in case we provide empty input
    while ((next_node=createNode()) != NULL) {

        if(current==NULL) {
            head=next_node;
            //current=next_node;
        }
        else {
            current->next=next_node;
            //current=next_node;
        }
        current=next_node;

    };

    return head;
}

void displayList(student_t* head){

    if(head == NULL) {
        printf("Linked List is empty.\n");
    }
    else  {
        while(head != NULL)  {
            printf("=============== List of Students: ===============\n");
            printf("No\tGPA\tID\tName\n");

            printf ("1.\t%zu\t%f\t%s \n", head->id, head->gpa, head->name);
            head = head->next;
        }
        printf("\n");
    }
}

void insertNode(student_t** head) {

    if (*head==NULL) {
        *head=createNode();
    }
    else {
        student_t* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode();
    }
}

void removeList(student_t* head){
    while (head != NULL)
    {
        free(head);
        free(head->name);
        head = head->next;

    }
}
