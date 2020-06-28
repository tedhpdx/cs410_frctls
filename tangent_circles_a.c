#include "FPToolkit.c"

int main()
{

  int swidth = 600;
  int sheight = 600;

  G_init_graphics (swidth, sheight);

  G_rgb(0.3,0.3,0.3);
  G_clear();

  double p[2], q[2];

  G_rgb(1,0,0);

  G_wait_click(p);
  G_fill_circle(p[0],p[1],20);

  G_wait_click(q);
  G_fill_circle(q[0],q[1],20);

  G_rgb(0,1,0);
  G_line(p[0],p[1] , q[0],q[1]);

  //midpoint cicle
  double midx = (p[0]+q[0])/2;
  double midy = (p[1]+q[1])/2;

  G_rgb(1,0,0);
  G_fill_circle(midx,midy,20);


  //distance of line
  double deltaX = p[0]-q[0];
  double deltaY = p[1]-q[1];

  double dist = sqrt((deltaX*deltaX)+(deltaY*deltaY));


  G_wait_key();
  G_save_to_bmp_file("demo.bmp");
}
