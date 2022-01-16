#include "World.h"

#include <algorithm>
#include <iterator>
int Grid[52 * 52];

World::World(int w, int h)
{
	width = w;
	height = h;

	grid = (short *)malloc((width + 2)*(height + 2)*sizeof(short));
	new_grid = (short *)malloc((width + 2)*(height + 2)*sizeof(short));
	new_grid2 = (short*)malloc((width + 2) * (height + 2) * sizeof(short));
	new_grid3 = (short*)malloc((width + 2) * (height + 2) * sizeof(short));

	for (int i = 0; i < (width + 2)*(height + 2); i++)
	{
		grid[i] = 0;
		new_grid[i] = 0;
		new_grid2[i] = 0;
		new_grid3[i] = 0;
	}
}

World::~World(){ 
	free(grid); free(new_grid); 
}



int World::getNewLife(int x, int y)
{ 
	return grid[x*(width + 2) + y]; 
}

void World::setNewLife(int x, int y, int val)
{ 
	new_grid[x*(width + 2) + y] = val; 
}

void World::swapGrids()
{
	std::swap(grid, new_grid);
	std::swap(new_grid, new_grid2);
	std::swap(new_grid2, new_grid3);
}


bool World:: compareGrid() {

	bool similarity = true ;

	for (int i = 0; i < height + 2; i++) {

		for (int j = 0; j < width + 2; j++) {
			
			if (grid[i * (width + 2) + j] != new_grid2[i * (width + 2) + j] )
				
				
				if ( new_grid[i * (width + 2) + j] != new_grid3[i * (width + 2) + j])
					{
								similarity = false;
								break;
						}

		}

		if (similarity == false)
				break;
	}

	return similarity; 
	

}

int World::getNeighbors(int x, int y, int val)
{
	int count = 0;

	//top neighbor
	count += grid[(x-1)*(width + 2) + (y)];

	//left neighbor 
	count += grid[(x)*(width + 2) + (y-1)];

	//top left neighbor 
	count += grid[(x - 1)*(width + 2) + (y-1)];

	// bottom  
	count += grid[(x + 1)*(width + 2) + (y)];

	// right 
	count += grid[(x)*(width + 2) + (y+1)];

	//bottom right 
	count += grid[(x+1)*(width + 2) + (y+1)];

	//bottom left 
	count += grid[(x+1)*(width + 2) + (y-1)];

	// top right
	count += grid[(x - 1)*(width + 2) + (y+1)];
	

	
	return count;


}

int World::getLifeform(int x, int y)
{ 
	return grid[x*(width + 2) + y]; 
}

void World::setLife(int x, int y, int val)
{ 
	grid[x*(width + 2) + y] = val; 
}

void World::print()
{
	for (int i = 1; i <= height; i++)
	{
		cout << endl;
		for (int j = 1; j <= width; j++)
		{
			cout << getLifeform(j, i) << " ";
		}
	}
	cout << endl;

}
