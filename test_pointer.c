#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
   int v;
   char c;
}cell;	

int main() {
   cell* list;
   list = (cell *)malloc(sizeof(cell));	
			list->v = 0;
			list->c = 0;
			printf("%d %d\n", list->v, list->c);
			*((char *)list + sizeof(int)) = 1;
			printf("%d %d\n", list->v, list->c);
} 

