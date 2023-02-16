#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char *skip_comments_and_blanks(char *p)
{
  while (*p != 0)
  { // if the char pointer is not null

    while (
        (*p == ' ') ||
        (*p == '\n')) // if char point is whitespace or linebreak,  move forward to next char
      ++p;

    if (*p == '#') 
    { 
      ++p;

      while (
          (*p != 0) &&
          (*p != '\n'))
        ++p;

      continue;
    }
    else
      break;
  }

  return p;
}

int test_skip_comments_and_blanks(char *p)
{

  return 0;
}

int main(int argc, char const *argv[])
{
  char *path = argv[1];
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
}
