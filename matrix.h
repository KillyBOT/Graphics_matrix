#ifndef MATRIX_H
#define MATRIX_H

#define DIMENSIONS 4

struct matrix {
  double **m;
  int rows, cols;
  int lastcol;
};

//Basic matrix manipulation routines
struct matrix *new_matrix(int rows, int cols);
void free_matrix(struct matrix *m);
void grow_matrix(struct matrix *m, int newcols);
void copy_matrix(struct matrix *a, struct matrix *b);

//functions students need to complete
void print_matrix(struct matrix *m);
void ident(struct matrix *m);
void matrix_mult(struct matrix *a, struct matrix *b);
void matrix_scale(struct matrix* m, double s);
void matrix_trans(struct matrix* m, double x, double y, double z);// Translate the matrix's points
void matrix_rot(struct matrix* a, double rads);

#endif
