#ifndef BST_H_ /* Include guard */
#define BST_H_

#include <stdio.h>
#include <stdlib.h>
struct ABRNoeu
{
    int data;
    struct ABRNoeu *droite;
    struct ABRNoeu *gauche;
};

struct ABRNoeu *abr_vider(struct ABRNoeu *);
struct ABRNoeu *abr_insert(struct ABRNoeu *, int data);
void abr_imprimer(struct ABRNoeu *);
void abr_print_to_file_order_dec(struct ABRNoeu *, FILE *);
void abr_countElements(struct ABRNoeu *, int *);
void abr_getTreeAvg(struct ABRNoeu *, int *, int *);
void print_abr_2d_util(struct ABRNoeu *, int);
void print_abr_2d(struct ABRNoeu *);
#endif // FOO_H_
