#include <stdio.h>
#include <stdlib.h>

struct Noeu
{
    int data;
    struct Noeu *droite;
    struct Noeu *gauche;
};

struct Noeu *vider(struct Noeu *root)
{
    if (root != NULL)
    {
        vider(root->droite);
        vider(root->gauche);
        free(root);
    }

    return NULL;
}

struct Noeu *insert(struct Noeu *root, int data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct Noeu));
        root->data = data;
        root->droite = NULL;
        root->gauche = NULL;
        return root;
    }

    if (root->data > data)
    {
        root->gauche = insert(root->gauche, data);
        return root;
    }
    if (root->data <= data)
    {
        root->droite = insert(root->droite, data);
        return root;
    }
    return root;
}

void imprimer(struct Noeu *root)
{
    if (root == NULL)
    {
        return;
    }

    imprimer(root->droite);
    printf("%d ", root->data);
    imprimer(root->gauche);
}

void print_to_file_order_dec(struct Noeu *root, FILE *f)
{
    if (root == NULL)
    {
        return;
    }

    print_to_file_order_dec(root->droite, f);
    fprintf(f, "%d", root->data);
    fprintf(f, ";");
    print_to_file_order_dec(root->gauche, f);
}

void countElements(struct Noeu *root, int *counter)
{
    if (root == NULL)
    {
        return;
    }

    countElements(root->gauche, counter);
    (*counter)++;
    countElements(root->droite, counter);
}

void getTreeAvg(struct Noeu *root, int *sum, int *count)
{
    if (root == NULL)
    {
        return;
    }

    getTreeAvg(root->gauche, sum, count);
    (*count)++;
    (*sum) = (*sum) + root->data; 
    getTreeAvg(root->droite, sum, count);
}