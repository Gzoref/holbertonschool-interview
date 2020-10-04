#include "menger.h"

/**
* menger - Prints an N sized Menger Sponge
*
* @level: Menger level to print
*
* Return: Void
*/

void menger(int level)
{

	int size = level * 3;

	if (level < 0)
	{
		return;
	}

	if (level == 0)
	{
		printf("#");
	}
}
