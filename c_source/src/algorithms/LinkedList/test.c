#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void main(int argc, char **argv)
{
    // source file
    FILE *fd;
    printf("got here");

    char *line_d = NULL;

    size_t len_d = 0;
    ssize_t read_d;

    size_t len_r = 0;
    ssize_t read_r;

    struct ListNode *root = NULL;

    // fd = fopen(argv[1], "r");
    fd = fopen(argv[1], "r");

    if (fd == NULL)
    {
        printf("error opening data file");
        exit(EXIT_FAILURE);
    }

    while ((read_d = getline(&line_d, &len_d, fd)) != -1)
    {
        int number = atoi(line_d);
        root = add_sorted_asc(root, number);
    }

    fclose(fd);
    if (line_d)
        free(line_d);

    printList(root);
}
