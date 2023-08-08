#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>


typedef struct Node{
    int data;
    struct Node *next;

}Node;
size_t read_index=0, write_index=0;
int N;

void push_back(int new_data, Node *head){
    if(write_index - read_index == N){
        printf("LL is full!");
        return;
    }

    Node *new = malloc(sizeof(Node));

    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    if(head == NULL){
        new->data = new_data;
        new->next = NULL;
    }
    new->data = new_data;
    new->next = head;
    (head+write_index)->next = new;
    
    write_index = (write_index+1)%N;

}

void pop_front(int *result, Node *head){
    Node *temp = (head+read_index);
    if(write_index == read_index){
        printf("LL is empty!");
        return;
    }
    if(head == NULL){
        perror("Could not pop in empty list!");
        exit(-1);
        return;
    }
    *result = (head+read_index)->data;
    read_index = (read_index+1)%N;
    (head+write_index)->next = (head+read_index);
    
    free(temp);

}

void print(Node *cll){
    Node *temp = cll;
    while(temp->next != cll){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");

}


int main(int argc, char *argv[]){
    Node *head = NULL;
    N = atoi(argv[1]);

    for(size_t i = 2; i<N; i++){
        push_back(atoi(argv[i]), head);
    }
    Node *cll = (head+read_index+2);
    print(cll);


    






    free(head);
    return 0;
}