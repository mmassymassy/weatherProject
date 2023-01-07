#include <stdio.h>
#include <stdlib.h>

struct ABRNoeu
{
    int data;
    struct ABRNoeu *droite;
    struct ABRNoeu *gauche;
};

struct ABRNoeu *abr_vider(struct ABRNoeu *root)
{
    if (root != NULL)
    {
        abr_vider(root->droite);
        abr_vider(root->gauche);
        free(root);
    }

    return NULL;
}

struct ABRNoeu *abr_insert(struct ABRNoeu *root, int data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct ABRNoeu));
        root->data = data;
        root->droite = NULL;
        root->gauche = NULL;
        return root;
    }

    if (root->data > data)
    {
        root->gauche = abr_insert(root->gauche, data);
        return root;
    }
    if (root->data <= data)
    {
        root->droite = abr_insert(root->droite, data);
        return root;
    }
    return root;
}

void abr_imprimer(struct ABRNoeu *root)
{
    if (root == NULL)
    {
        return;
    }

    abr_imprimer(root->droite);
    printf("%d ", root->data);
    abr_imprimer(root->gauche);
}

void abr_print_to_file_order_dec(struct ABRNoeu *root, FILE *f)
{
    if (root == NULL)
    {
        return;
    }

    abr_print_to_file_order_dec(root->droite, f);
    fprintf(f, "%d", root->data);
    fprintf(f, ";");
    abr_print_to_file_order_dec(root->gauche, f);
}

void abr_countElements(struct ABRNoeu *root, int *counter)
{
    if (root == NULL)
    {
        return;
    }

    abr_countElements(root->gauche, counter);
    (*counter)++;
    abr_countElements(root->droite, counter);
}

void abr_getTreeAvg(struct ABRNoeu *root, int *sum, int *count)
{
    if (root == NULL)
    {
        return;
    }

    abr_getTreeAvg(root->gauche, sum, count);
    (*count)++;
    (*sum) = (*sum) + root->data; 
    abr_getTreeAvg(root->droite, sum, count);
}

void abr_get_tree_max(struct ABRNoeu *root, int *max){
    if(root == NULL){
        return;
    }

    if(root->droite != NULL){
        return abr_get_tree_max(root->droite, max);
    }else{
        (*max) = root->data;
        return;
    }
    
}

void abr_get_tree_min(struct ABRNoeu *root, int *min){
    if(root == NULL){
        return;
    }

    if(root->gauche != NULL){
        return abr_get_tree_min(root->gauche, min);
    }else{
        (*min) = root->data;
        return;
    }
    
}

void print_abr_2d_util(struct ABRNoeu *root, int space)
{
    int COUNT = 10;
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print_abr_2d_util(root->droite, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    // Process left child
    print_abr_2d_util(root->gauche, space);
}
// Wrapper over print2DUtil()
void print_abr_2d(struct ABRNoeu *root)
{
    // Pass initial space count as 0
    print_abr_2d_util(root, 0);
}