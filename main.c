#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  /*screen s;
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
  free_matrix(multTest);*/

  screen s;

  struct matrix *m1;
  struct matrix *m2;
  struct matrix *m3;
  struct matrix *m4;
  struct matrix *mt;

  clear_screen(s);

  char fileName[32];
  char finalFileName[32];
  int f;
  int stat;

  color red = {MAX_COLOR,0,0};
  color green = {0,MAX_COLOR,0};
  color blue = {0,0,MAX_COLOR};
  color yellow = {MAX_COLOR,MAX_COLOR,0};
  color white = {MAX_COLOR,MAX_COLOR,MAX_COLOR};

  double p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;

  double rads = 0;

  for(int degrees = 0; degrees < 90; degrees++){

    m1 = new_matrix(DIMENSIONS, 8);
    m2 = new_matrix(DIMENSIONS, 8);
    m3 = new_matrix(DIMENSIONS, 8);
    m4 = new_matrix(DIMENSIONS, 8);
    mt = new_matrix(DIMENSIONS, 8);
    clear_screen(s);

    sprintf(fileName, "pic_%d.ppm",degrees);
    sprintf(finalFileName, "pic_%d.png",degrees);

    add_edge(m1, -.5, -.5, 0, .5, -.5, 0);
    add_edge(m1, -.5, -.5, 0, -.5, .5, 0);
    add_edge(m1, -.5, .5, 0, .5, .5, 0);
    add_edge(m1, .5, -.5, 0, .5, .5, 0);

    matrix_scale(m1, 50);

    copy_matrix(m1, m2);
    copy_matrix(m1, m3);
    copy_matrix(m1, m4);

    p1x = XRES/2 + (XRES/2 - 35) * cos(rads);
    p1y = YRES/2;
    p2x = XRES/2 + ((XRES/2 - 35) * (sqrt(2)/2)) * cos(rads + M_PI/4);
    p2y = YRES/2 + ((YRES/2 - 35) * (sqrt(2)/2)) * cos(rads + M_PI/4);
    p3x = XRES/2;
    p3y = YRES/2 + (YRES/2 - 35) * cos(rads + M_PI/2);
    p4x = XRES/2 - ((XRES/2 - 35) * (sqrt(2)/2)) * cos(rads + (3*M_PI)/4);
    p4y = YRES/2 + ((YRES/2 - 35) * (sqrt(2)/2)) * cos(rads + (3*M_PI)/4);

    matrix_trans(m1, p1x, p1y, 0);
    matrix_trans(m2, p2x, p2y, 0);
    matrix_trans(m3, p3x, p3y, 0);
    matrix_trans(m4, p4x, p4y, 0);

    add_edge(mt, p1x, p1y, 0, p2x, p2y, 0);
    add_edge(mt, p2x, p2y, 0, p3x, p3y, 0);
    add_edge(mt, p3x, p3y, 0, p4x, p4y, 0);
    add_edge(mt, p4x, p4y, 0, p1x, p1y, 0);

    draw_lines(m1, s, red);
    draw_lines(m2, s, blue);
    draw_lines(m3, s, green);
    draw_lines(m4, s, yellow);
    draw_lines(mt, s, white);


    //display(s);

    free_matrix(m1);
    free_matrix(m2);
    free_matrix(m3);
    free_matrix(m4);
    free_matrix(mt);

    save_ppm(s, fileName);

    rads += (M_PI / 45);

    f = fork();

    if(f){
      waitpid(f,&stat,0);
    } else {
      execlp("convert","convert",fileName,finalFileName,NULL);
    }

    f = fork();
    if(f){
      waitpid(f,&stat,0);
    } else {
      execlp("rm", "rm", fileName, NULL);
    }

  }


}
