#include <stdio.h>
#include <string.h>

main()
{
	FILE * input_par;
	FILE * input_pos;
	FILE * input_vel;
	FILE * out_data;
	
	input_par = fopen("input_parameters.txt", "r");	
	input_pos = fopen("input_positions.txt", "r");	
	input_vel = fopen("input_velocities.txt", "r");
	out_data = fopen("out_data.txt", "w");
	
	int molnum = 0;
	int molnum2 = 0;
	int tstep;
	double xdif;
	double ydif;
	double temp_xvel;
	double temp_yvel;
	double dista;
	
	int tfinal;
	int number_of_mol;
	int collision_size;

	int left_border;
	int top_border;
	int right_border;
	int bot_border;
	
	// Position and velocities arrays (spanning each molecule) in x and y.
    double xpos[number_of_mol], ypos[number_of_mol];
	double xvel[number_of_mol], yvel[number_of_mol];
	
	// Just repeats
	double new_xpos[number_of_mol], new_ypos[number_of_mol];
	double new_xvel[number_of_mol], new_yvel[number_of_mol];
	
	
	
fscanf(input_par, "%d %d %d %d %d %d %d", &tfinal, &number_of_mol, &collision_size, &left_border, &top_border, &right_border, &bot_border);

// Read in velocities and positions of particles (initial conditions)
for(molnum = 0; molnum <= (number_of_mol - 1); molnum++)
{
	fscanf(input_pos, "%lf %lf,", &xpos[molnum], &ypos[molnum]);
}

for(molnum = 0; molnum <= (number_of_mol - 1); molnum++)
{
	fscanf(input_vel, "%lf %lf,", &xvel[molnum], &yvel[molnum]);
}

// Iterate through time for the state of the chamber.
for(tstep = 0; tstep <= tfinal; tstep++)
{
	//if (xvel[molnum] >= 10 || yvel[molnum] >= 10)
	//printf("\nERROR: Vel for %d = (%lf, %lf)", molnum, xvel[molnum], yvel[molnum]);
	//printf("\n@ time %d:", tstep);
	
	for(molnum = 0; molnum <= (number_of_mol - 1); molnum++)
	fprintf(out_data, "%lf, %lf, ", xpos[molnum], ypos[molnum]);
	fprintf(out_data, "\n");
	
	// Apply velocities and update values.
	for(molnum = 0; molnum <= (number_of_mol - 1); molnum++)
	{
	new_xpos[molnum] = xpos[molnum] + xvel[molnum];
	new_ypos[molnum] = ypos[molnum] + yvel[molnum];

	xpos[molnum] = new_xpos[molnum];
	ypos[molnum] = new_ypos[molnum];
	}
	
	// Corrections for if there is a collision.

	// Boundary collisions
	for (molnum = 0; molnum <= number_of_mol; molnum++)
	{
		if(xpos[molnum] < left_border)
		{
			// Reverse the velocity of the particle in the direction
			// that is perpendicular to the plane of the border.
			xvel[molnum] = -1*xvel[molnum];
			// Move the particle to the edge of the border 
			// (in future: base it on the size of molecule)
			xpos[molnum] = left_border;
		}
		else if(xpos[molnum] > right_border)
		{
			xvel[molnum] = -1*xvel[molnum];
			xpos[molnum] = right_border;
		}
		// Now for y (up-down)
		if(ypos[molnum] < bot_border)
		{   
			yvel[molnum] = -1*yvel[molnum];
			ypos[molnum] = bot_border;
		}
		else if (ypos[molnum] > top_border)
		{
			yvel[molnum] = -1*yvel[molnum];
			ypos[molnum] = top_border;
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
				//(in future: calculate based on a sized particle)
				xdif = xpos[molnum] - xpos[molnum2];
				ydif = ypos[molnum] - ypos[molnum2];
				dista = (xdif*xdif) + (ydif*ydif);
				
				if( dista <= collision_size)
				{	
					//printf("\nCollision!");
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
//getchar();
}