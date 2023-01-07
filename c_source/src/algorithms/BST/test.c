#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void print_number(int a){
    printf("%d",a);
}

void write_to_file(int a){
   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("./res.txt","a");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }



   fprintf(fptr,"%d",a);
   fprintf(fptr,";");
   fclose(fptr);
}

void main(int argc, char **argv)
{
    // source file
    FILE *fd;

    char *line_d = NULL;
    
    size_t len_d = 0;
    ssize_t read_d;

    size_t len_r = 0;
    ssize_t read_r;

    struct Noeu *root = NULL;

    fd = fopen(argv[1], "r");

    if (fd == NULL){
        printf("error opening data file");
        exit(EXIT_FAILURE);
    }

    while ((read_d = getline(&line_d, &len_d, fd)) != -1)
    {
        int number = atoi(line_d);
        root = insert(root,number);
    }

    fclose(fd);
    if (line_d)
        free(line_d);


    remove("./res.txt");
    appliquer_fonction_en_ordre(root,write_to_file);
    vider(root);
    exit(EXIT_SUCCESS);
}

