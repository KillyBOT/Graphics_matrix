#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *identTest;

  edges = new_matrix(4, 4);
  identTest = new_matrix(4,4);

  ident(identTest);

  print_matrix(identTest);

  free_matrix( edges );
  free_matrix(identTest);
}
