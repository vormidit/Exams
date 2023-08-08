#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<time.h>



typedef struct Product
{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[11];
}Product;

int write_to_bin_file(Product *p){
    FILE *f = fopen("bin_file.bin", "w");
    if(!f){
        perror("Error!");
        exit(-1);
    }
    if(fwrite(p, sizeof(Product), 40, f) == 40){
        return 1;
    }else{
        return 0;
    }


    fclose(f);

}

int main(){
   Product arr[40];
   char *strings[] = {"adf", "wefv", "qqwjdy", "djdeie", "cckki"};
   srand(time(NULL));
   for(size_t i = 0; i < 40; i++){
        arr[i].id = rand()%10000000000;
        arr[i].old_price = (rand()%9546 + 499)/100.00;
        arr[i].new_price = (rand()%9546 + 499)/100.00;
        arr[i].product_type = rand()%('D'-'A') + 'A';
        size_t str = rand()%5;
        char *new = strings[str];
        size_t j =0;
        for(; j < strlen(new); j++){
           arr[i].product_name[j] = new[j];
        }
        arr[i].product_name[j] = '\0';
        

   }

   for(size_t i = 0; i < 40; i++){
        printf("Product id: %u\n", arr[i].id);
        printf("Old price: %lf\n", arr[i].old_price);
        printf("New price: %lf\n", arr[i].new_price);
        printf("Product type: %c\n", arr[i].product_type);
        printf("Product name: ");
        for(size_t j =0 ; j < strlen(arr[i].product_name); j++){
            printf("%c" , arr[i].product_name[j]);
        }

        
      printf("\n");
      printf("\n");
   }

   if(write_to_bin_file(arr) == 1){
    printf("Success with writing to file!\n");
   }
   



    return 0;
}
