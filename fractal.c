#include "FPToolkit.c"

int main()
{

  int swidth;
  int sheight;
  int start_point_x = 50;
  int start_point_y = 50;
  int point_size = 10;
  int depth = 2;
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

  double p4[2];
  double p5[2];
  double p6[2];

  double p7[2];
  double p8[2];
  double p9[2];

  double p10[2];
  double p11[2];
  double p12[2];

  double p13[2];
  double p14[2];
  double p15[2];

  /*
  //inner midpoint
  p4[0] = (p2[0]+p1[0])/2;
  p4[1] = (p2[1]+p1[1])/2;

  //side midpoint
  p5[0] = (p2[0]+p3[0])/2;
  p5[1] = (p2[1]+p3[1])/2;

  //side midpoint
  p6[0] = (p1[0]+p3[0])/2;
  p6[1] = (p1[1]+p3[1])/2;

  G_rgb(1,1,0);
  G_triangle (p4[0],p4[1], p5[0],p5[1], p6[0],p6[1]);
  */

  double temp_p1[2];
  double temp_p3[2];
  double orig_p3[2];

  orig_p3[0] = p3[0];
  orig_p3[1] = p3[1];

  for (int i = 0; i < depth; i++){


    temp_p1[0] = p1[0];
    temp_p1[1] = p1[1];
    temp_p3[0] = p3[0];
    temp_p3[1] = p3[1];

    switch(i % 2){
      case 0:
        //inner midpoint
        p3[0] = (p1[0]+p2[0])/2;
        p3[1] = (p1[1]+p2[1])/2;

        //side midpoint
        p2[0] = (p2[0]+temp_p3[0])/2;
        p2[1] = (p2[1]+temp_p3[1])/2;

        //side midpoint
        p1[0] = (p1[0]+temp_p3[0])/2;
        p1[1] = (p1[1]+temp_p3[1])/2;

        G_rgb(1,1,0);
        G_triangle (p3[0],p3[1], p2[0],p2[1], p1[0],p1[1]);
        break;
      case 1:
        //inner midpoint
        p3[0] = orig_p3[0];
        p3[1] = orig_p3[1];
        G_fill_circle(p3[0], p3[1], point_size);

        //side midpoint
        p2[0] = (p2[0]+temp_p3[0])/2;
        p2[1] = (p2[1]+temp_p3[1])/2;
        G_fill_circle(p2[0], p2[1], point_size);

        //side midpoint
        p1[0] = (p1[0]+temp_p3[0])/2;
        p1[1] = (p1[1]+temp_p3[1])/2;
        G_fill_circle(p1[0], p1[1], point_size);

        G_rgb(1,1,0);

        G_rgb(1,1,0);
        G_triangle (p3[0],p3[1], p2[0],p2[1], p1[0],p1[1]);
        break;
      default:
        printf("pass");
    }

    /*
    //inner midpoint
    p7[0] = (p1[0]+p4[0])/2;
    p7[1] = (p1[1]+p4[1])/2;

    //side midpoint
    p8[0] = (p4[0]+p6[0])/2;
    p8[1] = (p4[1]+p6[1])/2;

    //side midpoint
    p9[0] = (p1[0]+p6[0])/2;
    p9[1] = (p1[1]+p6[1])/2;

    G_rgb(1,1,0);
    G_fill_triangle (p7[0],p7[1], p8[0],p8[1], p9[0],p9[1]);

    //inner midpoint
    p10[0] = (p6[0]+p5[0])/2;
    p10[1] = (p6[1]+p5[1])/2;

    //side midpoint
    p11[0] = (p5[0]+p3[0])/2;
    p11[1] = (p5[1]+p3[1])/2;

    //side midpoint
    p12[0] = (p3[0]+p6[0])/2;
    p12[1] = (p3[1]+p6[1])/2;

    G_rgb(1,1,0);
    G_fill_triangle (p10[0],p10[1], p11[0],p11[1], p12[0],p12[1]);

    //inner midpoint
    p13[0] = (p4[0]+p2[0])/2;
    p13[1] = (p4[1]+p2[1])/2;

    //side midpoint
    p14[0] = (p5[0]+p2[0])/2;
    p14[1] = (p5[1]+p2[1])/2;

    //side midpoint
    p15[0] = (p4[0]+p5[0])/2;
    p15[1] = (p4[1]+p5[1])/2;

    G_rgb(1,1,0);
    G_fill_triangle (p13[0],p13[1], p14[0],p14[1], p15[0],p15[1]);

    //reassign values
    p1[0] = p1[0];
    p1[1] = p1[1];

    p6[0] = (p3[0]+p1[0])/2;
    p6[1] = (p3[1]+p1[1])/2;

    p5[0] = (p3[0]+p2[0])/2;
    p5[1] = (p3[1]+p2[1])/2;

    p4[0] = (p1[0]+p2[0])/2;
    p4[1] = (p1[1]+p2[1])/2;

    p3[0] = p6[0];
    p3[1] = p6[1];

    p2[0] = p4[0];
    p2[1] = p4[1];

*/


    /*
       temp_mid[0] = (p1[0]+p2[0])/2;
       temp_mid[1] = (p1[1]+p2[1])/2;;


    //finding midpoints

    p2[0] = (p2[0]+p3[0])/2;
    p2[1] = (p2[1]+p3[1])/2;

    p4[0] = (p2[0]+p3[0])/2;
    p4[1] = (p2[1]+p3[1])/2;

    p1[0] = (p1[0]+p3[0])/2;
    p1[1] = (p1[1]+p3[1])/2;

    p5[0] = (p1[0]+p3[0])/2;
    p5[1] = (p1[1]+p3[1])/2;

    p3[0] = p1[0];
    p3[1] = p1[0];

    p6[0] = (p2[0]+p1[0])/2;
    p6[1] = (p2[1]+p1[1])/2;

    G_rgb(1,1,0);

    G_fill_triangle (p4[0],p4[1], p5[0],p5[1], p6[0],p6[1]);
    G_fill_triangle (p2[0],p2[1], p1[0],p1[1], temp_mid[0],temp_mid[1]);

    G_fill_circle(p4[0], p4[1], point_size);
    G_fill_circle(p5[0], p5[1], point_size);
    G_fill_circle(p6[0], p6[1], point_size);
    */
    /*
    //draw points
    G_rgb(1,0,0);
    G_fill_circle(p1[0], p1[1], point_size);
    G_fill_circle(p2[0], p2[1], point_size);
    G_fill_circle(p3[0], p3[1], point_size);
    //draw lines
    G_line(p1[0],p1[1] , p2[0],p2[1]);
    G_line(p2[0],p2[1] , p3[0],p3[1]);
    G_line(p3[0],p3[1] , p1[0],p1[1]);
    */

  }

  G_wait_key();
}
