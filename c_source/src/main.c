#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algorithms/BST/bst.c"

struct Options
{
    bool grouped;
    int num_groups;
    bool dec;
};

struct Option *read_options(FILE *);

struct Option *read_options(FILE *fd)
{
    char *line_d = NULL;

    size_t len_d = 0;
    ssize_t read_d;

    size_t len_r = 0;
    ssize_t read_r;

    struct Options *options = malloc(sizeof(struct Options));

    if ((read_d = getline(&line_d, &len_d, fd)) != -1)
    {
        int number = atoi(line_d);
        options->grouped = number == 1 ? true : false;
    }

    if ((read_d = getline(&line_d, &len_d, fd)) != -1)
    {
        int number = atoi(line_d);
        options->num_groups = number;
    }

    if ((read_d = getline(&line_d, &len_d, fd)) != -1)
    {
        int number = atoi(line_d);
        options->dec = number == 1 ? true : false;
    }

    return options;
}

int main(int argc, char **argv)
{
    FILE *input_file_ptr;
    size_t len_d = 0;
    ssize_t read_d;

    size_t len_r = 0;
    ssize_t read_r;
    char *line_d = NULL;

    input_file_ptr = fopen(argv[1], "r");

    if (input_file_ptr == NULL)
    {
        printf("error opening data file");
        exit(EXIT_FAILURE);
    }

    struct Options *options = read_options(input_file_ptr);

    int stations[options->num_groups];
    struct ABRNoeu *trees[options->num_groups];

    int counter = 0;

    while ((read_d = getline(&line_d, &len_d, input_file_ptr)) != -1)
    {
        int stationId = atoi(line_d);
        stations[counter] = stationId;
        struct ABRNoeu *tree = NULL;

        while ((read_d = getline(&line_d, &len_d, input_file_ptr)) != -1)
        {
            if (strcmp(line_d, "\n") == 0)
            {
                break;
            }
            else
            {
                int number = atoi(line_d);
                tree = abr_insert(tree, number);
            }
        }
        trees[counter] = tree;
        counter++;
    }
    fclose(input_file_ptr);

    input_file_ptr = fopen(argv[1], "w");


    for(int i =0;i<options->num_groups;i++){
        int max = 0;
        abr_get_tree_min(trees[i],&max);
        fprintf(input_file_ptr,"%d,%d\n",stations[i],max);
    }

    fclose(input_file_ptr);
    return 0;
}