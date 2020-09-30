
#include "slide_line.h"

/**
* slide_left - Slides array to left
*
* @line: Points to an array of integers containing size elements
*
* @size: Size of the array
*
* Return: Void
*/

void slide_left(int *line, size_t size)
{
	size_t index, position = 0, temp;

	for (index = 0; index < size && position; index++)
	{
		while (line[position] == 0 && (position < size) && (position + 1 < size))
		{
			position++;
		}
		if (!line[index])
		{
			temp = line[position];
			line[position] = line[index];
			line[index] = temp;
		}
		position++;
	}
}

/**
* slide_right - Slides array to right
*
* @line: Points to an array of integers containing size elements
*
* @size: Size of the array
*
* Return: Void
*/

void slide_right(int *line, size_t size)
{
	int index, position = 0, temp;

	for (index = size - 1; index >= 0 && position >= 0; index--)
	{
		while (line[position] == 0 && position > 0)
		{
			position--;
		}
		if (!line[index])
		{
			temp = line[position];
			line[position] = line[index];
			line[index] = temp;
		}
		position--;
	}
}

/**
* slide_line - Reproduces 2048 on one line
*
* @line: Points to an array of integers containing size elements
*
* @size: Size of the array
*
* @direction: Direction to slide
*
* Return: 1 on success, 0 on failure
*/

int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		slide_left(line, size);
		return (1);
	} else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1;  i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		slide_right(line, size);
		return (1);
	}
	return (0);
}
