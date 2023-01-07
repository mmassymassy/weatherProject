#ifndef AVL_H_ /* Include guard */
#define AVL_H_
#include <stdio.h>
#include <stdlib.h>
struct AVLNoeu *avl_vider(struct AVLNoeu *);
struct AVLNoeu *avl_insert(struct AVLNoeu *, int);
int avl_get_balance(struct AVLNoeu *);
struct AVLNoeu *avl_rotatte_right(struct AVLNoeu *);
struct AVLNoeu *avl_rotatte_left(struct AVLNoeu *);
struct AVLNoeu *avl_apply_rotation(struct AVLNoeu *);
int avl_get_height(struct AVLNoeu *);
struct AVLNoeu *avl_update_height(struct AVLNoeu *);
void avl_imprimer(struct AVLNoeu *);
void avl_print_to_file_order_dec(struct AVLNoeu *, FILE *);
void avl_countElements(struct AVLNoeu *, int *);
void avl_getTreeAvg(struct AVLNoeu *, int *, int *);
void print_avl_2d_util(struct AVLNoeu *, int);
void print_avl_2d(struct AVLNoeu *);

#endif // FOO_H_
