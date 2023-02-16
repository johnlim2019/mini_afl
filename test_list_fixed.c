#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct cell
{
	int v;
	struct cell *next;
} cell;

int main()
{
	cell *list;
	cell *cur = NULL;
	cell *prev = NULL;

	int i = 0;

	while (i < 10)
	{ // can be random length;
		cur = (cell *)malloc(sizeof(cell));
		cur->v = 0;
		cur->next = NULL;

		if (prev == NULL)
		{
			list = cur;
		}
		else
		{
			prev->next = cur;
		}

		prev = cur;
		i++;
	}
	cur = list;

	for (; cur != NULL;)
	{
		printf("%d\n", cur->v);
		cur = cur->next;
	}
}
