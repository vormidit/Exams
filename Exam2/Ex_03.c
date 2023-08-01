#include <inttypes.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

    if(argc <= 1){
        printf("Няма въведени аргументи!\n");
        return 0;
    }
    double sum = 0, c=0;
    int  d=0, di=0;
    for(size_t i = 1; i < argc; i++){
        
        if(strchr(argv[i], '.')){
            c += strtof(argv[i], NULL);
        }
        else if(strchr(argv[i], 'x')){
            d += (int)strtof(argv[i], NULL);
        }else{
            di += strtoimax(argv[i], NULL, 10);
        }
        
        
    }
    sum = c + d + di;
    printf("Сумата на аргументите е: %lf\n", sum);


    return 0;
}
