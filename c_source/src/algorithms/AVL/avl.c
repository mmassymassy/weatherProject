#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct AVLNoeu
{
    int data;
    int height;
    struct AVLNoeu *droite;
    struct AVLNoeu *gauche;
};

struct AVLNoeu *avl_insert(struct AVLNoeu *root, int data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct AVLNoeu));
        root->data = data;
        root->droite = NULL;
        root->gauche = NULL;
        root->height = 1;
        return root;
    }

    if (root->data > data)
    {
        root->gauche = avl_insert(root->gauche, data);
        root = avl_update_height(root);
        return avl_apply_rotation(root);
    }
    if (root->data <= data)
    {
        root->droite = avl_insert(root->droite, data);
        root = avl_update_height(root);
        return avl_apply_rotation(root);
    }

    root = avl_update_height(root);

    return avl_apply_rotation(root);
}

int avl_get_balance(struct AVLNoeu *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return avl_get_height(root->gauche) - avl_get_height(root->droite);
}

struct AVLNoeu *avl_rotatte_right(struct AVLNoeu *root)
{
    struct AVLNoeu *gauche = root->gauche;
    struct AVLNoeu *centre = gauche->droite;

    gauche->droite = root;
    root->gauche = centre;

    root = avl_update_height(root);
    gauche = avl_update_height(gauche);

    return gauche;
}

struct AVLNoeu *avl_rotatte_left(struct AVLNoeu *root)
{
    struct AVLNoeu *droite = root->droite;
    struct AVLNoeu *centre = droite->gauche;

    droite->gauche = root;
    root->droite = centre;

    droite = avl_update_height(droite);
    root = avl_update_height(root);

    return droite;
}

struct AVLNoeu *avl_apply_rotation(struct AVLNoeu *root)
{
    int balance = avl_get_balance(root);

    if (balance > 1)
    {
        // left heavy
        if (avl_get_balance(root->gauche) < 0)
        {
            root->gauche = avl_rotatte_left(root->gauche);
        }
        return avl_rotatte_right(root);
    }

    if (balance < -1)
    {
        // right heavy
        if (avl_get_balance(root->droite) > 0)
        {
            root->droite = avl_rotatte_right(root->droite);
        }
        return avl_rotatte_left(root);
    }
    return root;
}

int avl_get_height(struct AVLNoeu *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int height = 0;

    if (root->droite != NULL)
    {
        height = root->droite->height;
    }

    if (root->gauche != NULL)
    {
        if (height < root->gauche->height)
        {
            height = root->gauche->height;
        }
    }


    return height + 1;
}

struct AVLNoeu *avl_update_height(struct AVLNoeu *root)
{
    root->height = avl_get_height(root);

    return root;
}

void avl_imprimer(struct AVLNoeu *root)
{
    if (root == NULL)
    {
        return;
    }

    avl_imprimer(root->droite);
    printf("%d ", root->data);
    avl_imprimer(root->gauche);
}

void avl_print_to_file_order_dec(struct AVLNoeu *root, FILE *f)
{
    if (root == NULL)
    {
        return;
    }

    avl_print_to_file_order_dec(root->droite, f);
    fprintf(f, "%d", root->data);
    fprintf(f, ";");
    avl_print_to_file_order_dec(root->gauche, f);
}

void avl_countElements(struct AVLNoeu *root, int *counter)
{
    if (root == NULL)
    {
        return;
    }

    avl_countElements(root->gauche, counter);
    (*counter)++;
    avl_countElements(root->droite, counter);
}

void avl_getTreeAvg(struct AVLNoeu *root, int *sum, int *count)
{
    if (root == NULL)
    {
        return;
    }

    avl_getTreeAvg(root->gauche, sum, count);
    (*count)++;
    (*sum) = (*sum) + root->data;
    avl_getTreeAvg(root->droite, sum, count);
}

struct AVLNoeu *avl_vider(struct AVLNoeu *root)
{
    if (root != NULL)
    {
        avl_vider(root->droite);
        avl_vider(root->gauche);
        free(root);
    }

    return NULL;
}

void print_avl_2d_util(struct AVLNoeu *root, int space)
{
    int COUNT = 10;
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print_avl_2d_util(root->droite, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d:%d\n", root->data, root->height);
    // Process left child
    print_avl_2d_util(root->gauche, space);
}
// Wrapper over print2DUtil()
void print_avl_2d(struct AVLNoeu *root)
{
    // Pass initial space count as 0
    print_avl_2d_util(root, 0);
}