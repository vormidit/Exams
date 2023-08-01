#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

typedef struct Car{
    char model[20];
    uint8_t maxspeed;
    double price;

}Car;

int cmp_model_inc(const void *p1, const void *p2){

   return strcmp((char*)p1 ,(char*)p2);

}
int cmp_model_dec(const void *p1, const void *p2){

   return - strcmp((char*)p1 ,(char*)p2);

}
int cmp_maxspeed_inc(const void *p1, const void *p2){

   return *(uint8_t*)p1 - *(uint8_t*)p2;

}
int cmp_maxspeed_dec(const void *p1, const void *p2){

   return *(uint8_t*)p2 - *(uint8_t*)p1;

}
int cmp_price_inc(const void *p1, const void *p2){

   return *(double*)p1 - *(double*)p2;

}
int cmp_price_dec(const void *p1, const void *p2){

   return *(double*)p2 - *(double*)p1;

}

int (*getComparator(int n))(const void*, const void*){
    switch(n){
        case 1:
            return &cmp_model_inc;
            break;
        case 2:
            return &cmp_model_dec;
            break;
        case 3:
            return &cmp_maxspeed_inc;
            break;
        case 4:
            return &cmp_maxspeed_dec;
            break;
        case 5:
            return &cmp_price_inc;
            break;
        case 6:
            return &cmp_price_dec;
            break;
        default:
            return NULL;
            break;

    }
}

int main(){
    Car arr[10];
    for(size_t i =0; i < 10; i++){
        size_t size_num = (rand()%7+4);
        for(size_t j = 0; j < size_num; j++){
            arr[i].model[j] = 'A' + (rand()%26);
        }
        arr[i].maxspeed = rand()%201 + 100;
        arr[i].price = (rand()%99001 + 1000)/1000.;
        
    }
    int choise;
    printf("Въведете избор за сорт. [1-6]:\n");
    scanf("%d", &choise);
    
    qsort(arr, 10, sizeof(Car), getComparator(choise));
    
    printf("Сортирания масив е:\n");
    for(size_t i =0; i < 10; i++){
        printf("Model: ");
        for(size_t j = 0; j < strlen(arr[i].model); j++){
            printf("%c ", arr[i].model[j]);
        }
        printf("\n");
        printf("Max sp: %u\n", arr[i].maxspeed);
        printf("Price: %lf\n", arr[i].price);
        arr[i].maxspeed = rand()%201 + 100;
        arr[i].price = rand()%99001 + 1000;
        
    }


    return 0;
}