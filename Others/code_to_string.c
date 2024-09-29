
#include<stdio.h>


int main()
{
    FILE *file1  = fopen("code.cpp","r");
    FILE *file2 = fopen("string.txt","w");

    char x ;
    while((x = fgetc(file1))!= EOF){
        if(x == '\n'){
            fprintf(file2,"\\n");
        }
        else if(x == '\"')fprintf(file2,"\\\"");
        else fprintf(file2,"%c",x);
    }

    fclose(file2);


    return 0;
}
