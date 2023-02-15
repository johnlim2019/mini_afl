#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80

int add(int x, int y)
{
  return (int)(x - '0') + (int)(y - '0');
}
int test_add(x,y)
{
  assert(isdigit(x) > 0);
  assert(isdigit(y) > 0);
  int value = add(x,y);
  if (value < 5)
  {
    return 1; 
  }
  printf("SUM %d\n",value);
  return(0);
}

int main(int argc, char **argv)
{

  char* path = argv[1];
  FILE *file = fopen(path, "r");

  if (!file)
  {
    perror(path);
    return EXIT_FAILURE;
  }
  printf("Reading file at %s\n", path);

  char line[MAX_LINE_LENGTH] = {0};
  int line_count = 0;
  while (fgets(line, MAX_LINE_LENGTH, file))
  {
    printf("line[%06d]: %s", ++line_count, line);
  }
  // if there is not trailing line break add it
  if (line[strlen(line) - 1] != '\n')
  {
    printf("\n");
  }

  if (fclose(file))
  {
    return EXIT_FAILURE;
    perror(path);
  }
  printf("File closed\n");

  char *ptr1 = strtok(line, " ");
  printf("%s\n", ptr1);
  char *ptr2 = strtok(NULL, " "); // nextptr
  printf("%s\n", ptr2);

  // int value = add(*ptr1, *ptr2);
  // printf("SUM: %d\n", value);

  // run test 
  if (test_add(*ptr1,*ptr2) != 0){
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
