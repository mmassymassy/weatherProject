#include <stdio.h>

struct Noeu
{
    int data;
    struct Noeu *droite;
    struct Noeu *gauche;
};

struct Noeu *vider(struct Noeu *);
struct Noeu *insert(struct Noeu *, int data);
void imprimer(struct Noeu *);
void print_to_file_order_dec(struct Noeu *, FILE *);
void countElements(struct Noeu *, int *);
void getTreeAvg(struct Noeu *, int *, int *);
