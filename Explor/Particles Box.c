#include <stdio.h>
#include <string.h>

main()
{
FILE *file1;
file1 = fopen("out.txt", "w");
    double xpos[2], ypos[2];
	double xvel[2], yvel[2];
	
	double new_xpos[2], new_ypos[2];
	double new_xvel[2], new_yvel[2];
	
    int tstep = 0;
	int tfinal = 10;


fscan("%lf", &xpos[0]);
ypos[0] = 0;
xpos[1] = 2;
ypos[1] = 2;

xvel[0] = 1;
yvel[0] = 0;
xvel[1] = 0;
yvel[1] = 1; 

for(tstep = 0;tstep <= tfinal; t++)
{
	printf("Positions: (%lf, %lf) || (%lf, %lf)", xpos[0], ypos[0], xpos[1], ypos[1]);
	new_xpos[0] = xpos[0] + xvel[0];
	new_ypos[0] = ypos[0] + yvel[0];
	new_xpos[1] = xpos[1] + xvel[1];
	new_ypos[1] = ypos[1] + yvel[1];
	
	xpos[0] = new_xpos[0];
	ypos[0] = new_ypos[0];
	xpos[1] = new_xpos[1];
	ypos[1] = new_ypos[1];
}


fclose( file1);
}