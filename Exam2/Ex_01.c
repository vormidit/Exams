#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char even_coder(char c){
    char new_c;
    switch(c){

        case '0':
            new_c = 'A';
            break;
        case '1':
            new_c = 'B';
            break;
        case '2':
            new_c = 'C';
            break;
        case '3':
            new_c = 'D';
            break;
        case '4':
            new_c = 'E';
            break;
        case '5':
            new_c = 'F';
            break;
        case '6':
            new_c = 'G';
            break;
        case '7':
            new_c = 'H';
            break;
        case '8':
            new_c = 'I';
            break;
        case '9':
            new_c = 'J';
            break;
        default:
            new_c = ' ';
            break;
    }
    return new_c;
}


char odd_coder(char c){
    char new_c;
    switch(c){

        case '0':
            new_c = '!';
            break;
        case '1':
            new_c = '#';
            break;
        case '2':
            new_c = '/';
            break;
        case '3':
            new_c = '~';
            break;
        case '4':
            new_c = '=';
            break;
        case '5':
            new_c = '\'';
            break;
        case '6':
            new_c = '\\';
            break;
        case '7':
            new_c = '>';
            break;
        case '8':
            new_c = '.';
            break;
        case '9':
            new_c = ',';
            break;
        default:
            new_c = ' ';
            break;
    }
    return new_c;
}


char* mapF(char arr[], int size, char (*f_even)(char), char (*f_odd)(char)){

    char *new_arr = malloc(sizeof(char)*size);

     for(size_t i =0; i < size; i++){
        if(i%2 == 0){
            new_arr[i] = f_even(arr[i]);
        }else{
            new_arr[i] = f_odd(arr[i]);
        }
    } 

    return new_arr; 
        
}


int main(){

    char buff[500];
    printf("Въведете цяло пол. число до 500 цифри:\n");
    scanf("%s", buff);
    printf("Вашият символен низ:\n");
    for(size_t i = 0; i < strlen(buff); i++){
        printf("%c ", buff[i]);
    }
    printf("\n");

    char *new = mapF(buff, strlen(buff), even_coder, odd_coder);
    
    printf("Символния низ след обработката:\n");
    for(size_t i = 0; i < strlen(new); i++){
        printf("%c ", new[i]);
    }
    printf("\n");


    free(new);
    return 0;
}