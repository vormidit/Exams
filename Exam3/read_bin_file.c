#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Product
{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[11];
}Product;

int main(int agrc, char *argv[]){
    if(agrc != 2){
        perror("No CL Args!");
        exit(-1);
    }
    char *s = argv[1];
    FILE *f = fopen(s, "r");
    if(!f){
        perror("Error!");
        exit(-1);
    }
    Product p;
    while(fread(&p, sizeof(Product), 1, f) == 1){
        if(feof(f)){
            break;
        }
        printf("Product id: %u\n", p.id);
        printf("Old price: %lf\n", p.old_price);
        printf("New price: %lf\n", p.new_price);
        printf("Product type: %c\n", p.product_type);
        printf("Product name: ");
        for(size_t j =0 ; j < strlen(p.product_name); j++){
            printf("%c" , p.product_name[j]);
        }

        printf("\n");
    }
    

    fclose(f);
    return 0;
}