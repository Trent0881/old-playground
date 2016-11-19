#include <stdio.h>
#include <string.h>

main()
{
	int number_of_mol = 3;
	int molnum = 0;
    double xpos[number_of_mol], ypos[number_of_mol];
	double xvel[number_of_mol], yvel[number_of_mol];
	
	double new_xpos[number_of_mol], new_ypos[number_of_mol];
	double new_xvel[number_of_mol], new_yvel[number_of_mol];
	
    int tstep = 0;
	int tfinal = 20;

	int left_border = -4;
	int top_border = 4;
	int right_border = 4;
	int bot_border = -4;

	int lol;

scanf("%lf", &xpos[0]);
ypos[0] = 0;
xpos[1] = 2;
ypos[1] = -2;

xvel[0] = 1;
yvel[0] = 0;
xvel[1] = 0;
yvel[1] = 1; 

for(tstep = 0;tstep <= tfinal; tstep++)
{
	printf("\n@ %d:  (%lf, %lf) || (%lf, %lf)", tstep, xpos[molnum], ypos[molnum], xpos[molnum], ypos[molnum]);
	
	// Boundary collisions
	for (molnum; molnum <= number_of_mol; molnum++)
	{
	if(xpos[molnum] < left_border || xpos[molnum] > right_border)
		xvel[molnum] = -1*xvel[molnum];
	if(ypos[molnum] < bot_border || ypos[molnum] > top_border)
		yvel[molnum] = -1*yvel[molnum];
	}
	
	// Inter-particle collisions
	for (molnum
	if(xpos[0] == xpos[1] && ypos[0] == ypos[1])
	{
		xvel[0] = -1*xvel[0];
		yvel[0] = -1*yvel[0];

	}
	
	}
	new_xpos[0] = xpos[0] + xvel[0];
	new_ypos[0] = ypos[0] + yvel[0];
	new_xpos[1] = xpos[1] + xvel[1];
	new_ypos[1] = ypos[1] + yvel[1];
	
	
	xpos[0] = new_xpos[0];
	ypos[0] = new_ypos[0];
	xpos[1] = new_xpos[1];
	ypos[1] = new_ypos[1];
}


scanf("%lf", lol);
}