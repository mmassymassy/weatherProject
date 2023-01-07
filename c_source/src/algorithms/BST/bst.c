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

void appliquer_fonction_en_ordre(struct Noeu *root, void (*f)(int))
{
    if (root == NULL)
    {
        return;
    }

    appliquer_fonction_en_ordre(root->droite, f);
    (*f)(root->data);
    appliquer_fonction_en_ordre(root->gauche, f);
}