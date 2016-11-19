#include <stdio.h>
#include <string.h>

main()
{
	FILE * file1;
	file1 = fopen("out.txt", "w");
	int number_of_mol = 3;
	int molnum = 0;
	int molnum2 = 0;
	
	// Position and velocities arrays (spanning each molecule) in x and y.
    double xpos[number_of_mol], ypos[number_of_mol];
	double xvel[number_of_mol], yvel[number_of_mol];
	
	// Just repeats
	double new_xpos[number_of_mol], new_ypos[number_of_mol];
	double new_xvel[number_of_mol], new_yvel[number_of_mol];
	
    int tstep = 0;
	int tfinal = 20;

	int left_border = -5;
	int top_border = 5;
	int right_border = 5;
	int bot_border = -5;

	// To stop execution later.
	int lol;

scanf("%lf", &xpos[0]);
ypos[0] = 1;
xpos[1] = 2;
ypos[1] = -2;
xpos[2] = -1;
ypos[2] = -1;

xvel[0] = 0;
yvel[0] = -1;
xvel[1] = 0;
yvel[1] = 1; 
xvel[2] = 1;
yvel[2] = 1;

for(tstep = 0; tstep <= tfinal; tstep++)
{
	printf("\n@ %d:  (%lf, %lf) || (%lf, %lf) || (%lf, %lf)", tstep, xpos[0], ypos[0], xpos[1], ypos[1], xpos[2], ypos[2]);
	fprintf(file1, "%lf, %lf, %lf, %lf, %lf, %lf\n",xpos[0], ypos[0], xpos[1], ypos[1], xpos[2], ypos[2]);
	
	// Boundary collisions
	for (molnum = 0; molnum <= number_of_mol; molnum++)
	{
	if(xpos[molnum] < left_border || xpos[molnum] > right_border)
	{
		xvel[molnum] = -1*xvel[molnum];
	}
	if(ypos[molnum] < bot_border || ypos[molnum] > top_border)
	{
		yvel[molnum] = -1*yvel[molnum];
	}
	}
	
	// Inter-particle collisions
	for (molnum = 0; molnum <= number_of_mol; molnum++)
	{
		for (molnum2 = 0; molnum2 <= number_of_mol; molnum2++)
		{
			if(xpos[molnum] == xpos[molnum2] && ypos[molnum] == ypos[molnum2])
			{
				xvel[molnum] = -1*xvel[molnum];
				yvel[molnum] = -1*yvel[molnum];
				xvel[molnum2] = -1*xvel[molnum2];
				yvel[molnum2] = -1*yvel[molnum2];
			}
		
		}
	
	}
	
	
	new_xpos[0] = xpos[0] + xvel[0];
	new_ypos[0] = ypos[0] + yvel[0];
	new_xpos[1] = xpos[1] + xvel[1];
	new_ypos[1] = ypos[1] + yvel[1];
	new_xpos[2] = xpos[2] + xvel[2];
	new_ypos[2] = ypos[2] + yvel[2];
	
	xpos[0] = new_xpos[0];
	ypos[0] = new_ypos[0];
	xpos[1] = new_xpos[1];
	ypos[1] = new_ypos[1];
	xpos[2] = new_xpos[2];
	ypos[2] = new_ypos[2];
}


scanf("%lf", lol);
fclose(file1);
}