
#include <math.h>
#include "model.h"
#include "callbacks.h"
#include "move.h"

int movingWhichmodelHuman = 0;

void move_modelHuman(World* world) {
	if(movingWhichmodelHuman == 0)
	{
		if(abs((int)(camera.position.x - world->modelHuman1.position.x)) + abs((int)(camera.position.z - world->modelHuman1.position.z)) <
				abs((int)(camera.position.x - world->modelHuman2.position.x)) + abs((int)(camera.position.z - world->modelHuman2.position.z)))
		{
			movingWhichmodelHuman = 1;
		}
		else {
			movingWhichmodelHuman = 2;
		}
	}

	if(abs(camera.position.x) < 170 && abs(camera.position.z) < 170)
	{
		switch (movingWhichmodelHuman) {
			case 1:
				if (abs((int)(camera.position.x - world->modelHuman1.position.x)) < 50 && abs((int)(camera.position.z - world->modelHuman1.position.z)) < 50 && camera.position.y < 150)
				{
					world->modelHuman1.position.x = camera.position.x + 10;
					world->modelHuman1.position.z = camera.position.z + 10;

					world->modelHuman1.material_ambient[0] = camera.position.x / 200;
					world->modelHuman1.material_ambient[1] = camera.position.y / 200;
					world->modelHuman1.material_ambient[2] = camera.position.z / 200;
				}

				break;
			case 2:
				if (abs((int)(camera.position.x - world->modelHuman2.position.x)) < 50 && abs((int)(camera.position.z - world->modelHuman2.position.z)) < 50 && camera.position.y < 150)
				{
					world->modelHuman2.position.x = camera.position.x + 10;
					world->modelHuman2.position.z = camera.position.z + 10;

					world->modelHuman2.material_ambient[0] = camera.position.x / 200;
					world->modelHuman2.material_ambient[1] = camera.position.y / 200;
					world->modelHuman2.material_ambient[2] = camera.position.z / 200;
				}

				break;
		}
	}
}
