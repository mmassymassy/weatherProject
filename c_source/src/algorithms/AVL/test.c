#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

void print_number(int a)
{
    printf("%d", a);
}

void avl_write_to_file(struct AVLNoeu *root)
{
    FILE *fptr;

    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("./res.txt", "a");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    avl_print_to_file_order_dec(root, fptr);
    fclose(fptr);
}

float avl_getAvg(struct AVLNoeu *root)
{
    int sum = 0;
    int count = 0;

    avl_getTreeAvg(root, &sum, &count);
    float avg = sum / count;
    return avg;
}

int main(int argc, char **argv)
{
    // source file
    FILE *fd;

    char *line_d = NULL;

    size_t len_d = 0;
    ssize_t read_d;

    size_t len_r = 0;
    ssize_t read_r;

    struct AVLNoeu *root = NULL;

    // fd = fopen(argv[1], "r");
    fd = fopen("/home/abdou/repos/weatherProject/c_source/bin/test.txt", "r");

    if (fd == NULL)
    {
        printf("error opening data file");
        exit(EXIT_FAILURE);
    }

    while ((read_d = getline(&line_d, &len_d, fd)) != -1)
    {
        int number = atoi(line_d);
        printf("insering %d it was like this before \n", number);
        print_avl_2d(root);
        root = avl_insert(root, number);
    }

    fclose(fd);
    if (line_d)
        free(line_d);

    remove("./res.txt");
    // write_to_file(root);

    int count = 0;
    avl_countElements(root, &count);
    printf("count: %d \n", count);

    float avg = avl_getAvg(root);

    printf("avg: %f \n",avg); 

    avl_write_to_file(root);

    print_avl_2d(root);


    
    avl_vider(root);
    exit(EXIT_SUCCESS);
}