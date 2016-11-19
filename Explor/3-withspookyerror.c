#include <stdio.h>
#include <string.h>

main()
{
	FILE * out_data;
	FILE * input_vel;
	out_data = fopen("out_data.txt", "w");
	input_vel = fopen("input_velocities.txt", "r");
	
	int number_of_mol = 4;
	int molnum = 0;
	int molnum2 = 0;
	
	// Position and velocities arrays (spanning each molecule) in x and y.
    double xpos[number_of_mol], ypos[number_of_mol];
	double xvel[number_of_mol], yvel[number_of_mol];
	
	// Just repeats
	double new_xpos[number_of_mol], new_ypos[number_of_mol];
	double new_xvel[number_of_mol], new_yvel[number_of_mol];
	
    int tstep = 0;
	int tfinal = 200;

	int left_border = -800;
	int top_border = 400;
	int right_border = 800;
	int bot_border = -400;

	double xdif;
	double ydif;
	double temp_xvel;
	double temp_yvel;
	double dista;
	
	// To stop execution later.
	int lol;

xpos[0] = 200;
ypos[0] = 400;
xpos[1] = -200;
ypos[1] = 100;
xpos[2] = -10;
ypos[2] = -200;
xpos[3] = 200;
ypos[3] = -300;


for(molnum = 0; molnum <= (number_of_mol - 1); molnum++)
{
fscanf(input_vel, "%lf %lf,", &xvel[molnum], &yvel[molnum]);
}

for(tstep = 0; tstep <= tfinal; tstep++)
{
	printf("\n@ time %d:", tstep);
	
	for(molnum = 0; molnum <= (number_of_mol - 1); molnum++)
	if (xvel[molnum] >= 10 || yvel[molnum] >= 10)
	printf("\nERROR: Vel for %d = (%lf, %lf)", molnum, xvel[molnum], yvel[molnum]);
	
	fprintf(out_data, "%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", xpos[0], ypos[0], xpos[1], ypos[1], xpos[2], ypos[2], xpos[3], ypos[3]);
	
	// Apply velocities and update values.
	for(molnum = 0; molnum <= (number_of_mol - 1); molnum++)
	{
	new_xpos[molnum] = xpos[molnum] + xvel[molnum];
	new_ypos[molnum] = ypos[molnum] + yvel[molnum];

	xpos[molnum] = new_xpos[molnum];
	ypos[molnum] = new_ypos[molnum];
	}
	
	// Boundary collisions
	for (molnum = 0; molnum <= number_of_mol; molnum++)
	{
		if(xpos[molnum] < left_border || xpos[molnum] > right_border)
		{
			// Reverse the velocity of the particle in the direction
			// that is perpendicular to the plane of the border.
			xvel[molnum] = -1*xvel[molnum];
			
			// Go back a step with new velocity
			new_xpos[molnum] = xpos[molnum] + xvel[molnum];
			xpos[molnum] = new_xpos[molnum];
			
			// Go back a step manually.
			new_ypos[molnum] = ypos[molnum] - yvel[molnum];
			ypos[molnum] = new_ypos[molnum];
		}
		if(ypos[molnum] < bot_border || ypos[molnum] > top_border)
		{   //Same as last if, but reversed for x versus y.
			yvel[molnum] = -1*yvel[molnum];
			
			new_ypos[molnum] = ypos[molnum] + yvel[molnum];
			ypos[molnum] = new_ypos[molnum];
			
			new_xpos[molnum] = xpos[molnum] - xvel[molnum];
			xpos[molnum] = new_xpos[molnum];
		}
	}
	
	// Inter-particle collisions
	for (molnum = 0; molnum <= (number_of_mol - 1 - 1); molnum++)
	{
		for (molnum2 = molnum; molnum2 <= (number_of_mol - 1); molnum2++)
		{
			if(molnum != molnum2)
			{
				// Find the distance between each of the two molecules
				xdif = xpos[molnum] - xpos[molnum2];
				ydif = ypos[molnum] - ypos[molnum2];
				dista = (xdif*xdif) + (ydif*ydif);
				
				if( dista <= 1100)
				{	
					printf("\nCollision!");
					// Swap velocities (temporarily store second molecule velocity).
					temp_xvel = xvel[molnum2];
					temp_yvel = yvel[molnum2];
					xvel[molnum2] = xvel[molnum];
					yvel[molnum2] = yvel[molnum];
					xvel[molnum] = temp_xvel;
					yvel[molnum] = temp_yvel;
				}
			}
		}
	}

}

fclose(input_vel);
fclose(out_data);
getchar();
}