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

  G_wait_click(q);

  G_rgb(0,1,0);
  G_line(p[0],p[1] , q[0],q[1]);

  //distance of line
  double deltaX = p[0]-q[0];
  double deltaY = p[1]-q[1];

  double dist = sqrt((deltaX*deltaX)+(deltaY*deltaY));
  double r = dist/16;

  //original circles
  G_rgb(1,0,0);
  G_fill_circle(p[0],p[1],r);
  G_fill_circle(q[0],q[1],r);
  //midpoint cicle
  double midx = (p[0]+q[0])/2;
  double midy = (p[1]+q[1])/2;

  G_fill_circle(midx,midy,r);

  //midpoint again
  double midx1 = (p[0]+midx)/2;
  double midy1 = (p[1]+midy)/2;

  double midx2 = (q[0]+midx)/2;
  double midy2 = (q[1]+midy)/2;

  G_fill_circle(midx1,midy1,r);
  G_fill_circle(midx2,midy2,r);





  G_wait_key();
  G_save_to_bmp_file("demo.bmp");
}
