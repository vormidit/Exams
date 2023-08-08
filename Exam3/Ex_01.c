#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>



char* print_bits(char *c){
    
    switch (*c)
        {
        case '0':
            return "0000"; break;
        case '1':
            return "0001"; break;
        case '2':
            return "0010"; break;
        case '3':
            return "0011"; break;
        case '4':
            return "0100"; break;
        case '5':
            return "0101"; break;
        case '6':
            return "0110"; break;
        case '7':
           return "0111"; break;
        case '8':
            return "1000"; break;
        case '9':
            return"1001"; break;
        case 'a':
            return"1010"; break;
        case 'b':
            return"1011"; break;
        case 'c':
            return"1100"; break;
        case 'd':
            return"1101"; break;
        case 'e':
            return "1110"; break;
        case 'f':
            return "1111"; break;
        default:
             return 0;    
    }
}


int main(int argc, char *argv[]){
    char *filename = argv[1];
    char *print_mode = argv[2];
    FILE *f = fopen(filename, "r");
    if(!f){
        perror("Error with opennig file!");
        exit(-1);
    }

    if(!strcmp(print_mode, "-H")){
        uint8_t elem;
       
        while(fread(&elem, sizeof(uint8_t), 1, f) == 1){
            if(feof(f)){
                break;
            }
            fprintf(stdout, "%x ", elem);
        
        }
    }
    else if(strcmp(print_mode, "-B")){
        uint8_t b = 0;
        char elem;
        char *pc = &elem;
        while(fread(&elem, sizeof(uint8_t), 1, f) == 1){
            if(feof(f)){
                break;
            }
            sprintf(pc, "%x", b);
            fprintf(stdout, "%s ", print_bits(&elem));
            
            
        
        }
    }
    printf("\n");



    fclose(f);



    return 0;
}