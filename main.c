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
  color testColor;

  clear_screen(s);

  testColor.red = MAX_COLOR;
  testColor.green = MAX_COLOR;
  testColor.blue = MAX_COLOR;

  edges = new_matrix(DIMENSIONS, 32);
  identTest = new_matrix(DIMENSIONS,DIMENSIONS);
  multTest = new_matrix(DIMENSIONS, DIMENSIONS);

  ident(identTest);
  //We'll make a square to test transformations
  add_edge(edges, 50,50,0,100,50,0);
  add_edge(edges, 50,50,0,50,100,0);
  add_edge(edges, 50,100,0,100,100,0);
  add_edge(edges, 100,50,0,100,100,0);
  //add_edge(multTest, 2,0,0,0,2,0);
  //add_edge(multTest, 0,0,0,0,0,0);
  ident(multTest);
  scalar_mult(multTest,2);

  print_matrix(identTest);
  print_matrix(edges);
  print_matrix(multTest);

  matrix_mult(identTest,edges);

  print_matrix(edges);

  matrix_mult(multTest,edges);

  print_matrix(edges);

  draw_lines(edges,s,testColor);
  display(s);

  free_matrix( edges );
  free_matrix(identTest);
  free_matrix(multTest);
}
