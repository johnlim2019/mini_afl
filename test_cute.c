#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE 100

typedef struct cell
{
   int v;
   struct cell *next;
} cell;

void good()
{
   printf("Good\n");
}

void test_unit(cell *p, int x)
{
   if (x > 0)
   {
      printf("X > 0, x is %d\n", (int)(x - '0'));
      if (p != NULL)
      {
         printf("p != NULL, p->v is %d\n", p->v);
         if (2 * x + 1 == p->v)
         {
            printf("%d == p->v", (2 * x + 1));
            if (p->next == p)
               printf("p->next is p");
            assert(0 && "fatal");
         }
      }
   }

   good();
   return (0);
}

int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("No input file found");
      exit(-1);
   }
   char *path = argv[1];
   FILE *file = fopen(path, "r");
   if (!file)
   {
      perror(path);
      exit(1);
   }
   char line[100] = {0};
   fgets(line, MAX_LINE, file);
   fclose(file);

   char *value = strtok(line, " ");
   int valueInt =(int)(*value - '0');
   printf("%d\n", valueInt);
   char *next = strtok(NULL, " "); // nextptr
   int nextInt = (int)(*next - '0');
   printf("%d\n", nextInt);   
   char *x = strtok(NULL, " "); // nextptr
   int xInt = (int)(*x - '0');
   printf("%d\n", xInt);

   cell *list;
   list = (cell *)malloc(sizeof(cell));
   list->v = valueInt;
   list->next = (__uint32_t)(nextInt);
   test_unit(list, xInt);
}
