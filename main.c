#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *edgesScaled;
  struct matrix *edgesMatrixMult;
  struct matrix *edgesRotated;
  struct matrix *identTest;
  struct matrix *scalarTest;
  struct matrix *multTest;
  struct matrix *rotTest;
  color white;
  color red;
  color blue;
  color green;

  clear_screen(s);

  white.red = MAX_COLOR;
  white.green = MAX_COLOR;
  white.blue = MAX_COLOR;

  red.red = MAX_COLOR;
  red.green = 0;
  red.blue = 0;

  blue.red = 0;
  blue.green = 0;
  blue.blue = MAX_COLOR;

  green.red = 0;
  green.green = MAX_COLOR;
  green.blue = 0;

  edges = new_matrix(DIMENSIONS, 8);
  edgesScaled = new_matrix(DIMENSIONS, 8);
  edgesMatrixMult = new_matrix(DIMENSIONS, 8);
  edgesRotated = new_matrix(DIMENSIONS, 8);
  identTest = new_matrix(DIMENSIONS,DIMENSIONS);
  scalarTest = new_matrix(DIMENSIONS, DIMENSIONS);
  multTest = new_matrix(DIMENSIONS, DIMENSIONS);
  rotTest = new_matrix(DIMENSIONS, DIMENSIONS);

  //We'll make a square to test transformations
  add_edge(edges, -25,-25,0,25,-25,0);
  add_edge(edges, -25,-25,0,-25,25,0);
  add_edge(edges, -25,25,0,25,25,0);
  add_edge(edges, 25,-25,0,25,25,0);

  copy_matrix(edges, edgesScaled);
  copy_matrix(edges, edgesMatrixMult);
  copy_matrix(edges, edgesRotated);

  ident(identTest);
  ident(scalarTest);

  matrix_scale(scalarTest,3);

  add_edge(multTest, 4, 1, 0, 1, 3, 0);
  add_edge(multTest, 0, 0, 1, 0, 0, 0);

  matrix_rot(edgesRotated,M_PI/4);
  matrix_scale(edgesRotated,1.5);

  print_matrix(identTest);
  print_matrix(edges);
  print_matrix(scalarTest);
  print_matrix(multTest);

  matrix_mult(identTest,edges);

  print_matrix(edges);

  matrix_mult(scalarTest,edgesScaled);
  matrix_mult(multTest,edgesMatrixMult);

  matrix_trans(edges, XRES/2,YRES/2,0);
  matrix_trans(edgesScaled, XRES/2, YRES/2, 0);
  matrix_trans(edgesMatrixMult, XRES/2, YRES/2, 0);
  matrix_trans(edgesRotated, XRES/2, YRES/2, 0);

  print_matrix(edges);
  print_matrix(edgesRotated);

  draw_lines(edges,s,white);
  draw_lines(edgesScaled,s,red);
  draw_lines(edgesMatrixMult,s,green);
  draw_lines(edgesRotated,s,blue);
  display(s);

  free_matrix( edges );
  free_matrix(identTest);
  free_matrix(multTest);
}
