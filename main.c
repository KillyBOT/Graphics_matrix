#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

#define DIMENSIONS 4

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *identTest;
  struct matrix *multTest;

  edges = new_matrix(DIMENSIONS, 10);
  identTest = new_matrix(DIMENSIONS,DIMENSIONS);
  multTest = new_matrix(DIMENSIONS, DIMENSIONS);

  ident(identTest);
  add_edge(edges, 0,0,0,30,30,0);
  add_edge(edges, 50,70,0,40,90,0);
  add_edge(multTest, 2,0,1,1,2,0);
  add_edge(multTest, 0,3,2,0,0,0);

  print_matrix(identTest);
  print_matrix(edges);
  print_matrix(multTest);

  matrix_mult(multTest,edges);

  draw_lines(edges,s,DEFAULT_COLOR);
  display(s);

  print_matrix(edges);

  free_matrix( edges );
  free_matrix(identTest);
  free_matrix(multTest);
}
