struct Noeu
{
    int data;
    struct Noeu *droite;
    struct Noeu *gauche;
};

struct Noeu* vider(struct Noeu*);
struct Noeu* insert(struct Noeu*, int data);
void appliquer_fonction_en_ordre(struct Noeu* , void (*f)(int));
void imprimer(struct Noeu*);
