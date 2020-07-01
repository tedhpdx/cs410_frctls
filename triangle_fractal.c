#include "FPToolkit.c"

int main()
{

  int swidth;
  int sheight;
  int start_point_x = 50;
  int start_point_y = 50;
  int point_size = 1;
  int depth = 2;
  int temp_x = 0;
  int temp_y = 0;
  int triangle_width;
  double p1[2];
  double p2[2];
  double p3[3];

  printf("Please enter the size of the canvas: ");
  scanf("%d", &swidth);

  printf("Please enter the depth of the picture: ");
  scanf("%d", &depth);

  triangle_width = swidth - 100;
  sheight = swidth;

  G_init_graphics (swidth, sheight);

  G_rgb(0.3,0.3,0.3);
  G_clear();


  p1[0] = start_point_x;
  p1[1] = start_point_y;

  p2[0] = start_point_x + triangle_width;
  p2[1] = start_point_y;

  p3[0] = (triangle_width/2) + start_point_x;
  p3[1] = (triangle_width/2) * sqrt(3);

  G_rgb(1,0,0);
  G_fill_circle(p1[0], p1[1], point_size);
  G_fill_circle(p2[0], p2[1], point_size);
  G_fill_circle(p3[0], p3[1], point_size);

  G_line(p1[0],p1[1] , p2[0],p2[1]);
  G_line(p2[0],p2[1] , p3[0],p3[1]);
  G_line(p3[0],p3[1] , p1[0],p1[1]);

  for (int i = 0; i < depth; i++){
    temp_x = p1[0];
    temp_y = p1[1];

    p1[0] = (p1[0]+p2[0])/2;
    p1[1] = (p1[1]+p2[1])/2;

    p2[0] = (p2[0]+p3[0])/2;
    p2[1] = (p2[1]+p3[1])/2;

    p3[0] = (p3[0]+temp_x)/2;
    p3[1] = (p3[1]+temp_y)/2;

    G_rgb(1,0,0);
    G_fill_circle(p1[0], p1[1], point_size);
    G_fill_circle(p2[0], p2[1], point_size);
    G_fill_circle(p3[0], p3[1], point_size);

    G_line(p1[0],p1[1] , p2[0],p2[1]);
    G_line(p2[0],p2[1] , p3[0],p3[1]);
    G_line(p3[0],p3[1] , p1[0],p1[1]);
  }




  G_wait_key();

}
