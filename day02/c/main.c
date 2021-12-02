#include <stdio.h>
#include <string.h>

void navigate(char *file_name, int h0, int v0, int a0, int *h, int *v, int *a,
              int aim) {
  *h = h0;
  *v = v0;
  *a = a0;
  FILE *fp = fopen(file_name, "r");
  if (!fp) {
    printf("could not open file %s\n", file_name);
    return;
  }
  char command[20];
  int step;
  while (fscanf(fp, "%s %d", command, &step) != EOF) {

    if (!strcmp(command, "forward")) {
      *h += step;
      if (aim) {
        *v += *a * step;
      }
    } else if (!strcmp(command, "down")) {

      *a += step;
      if (!aim) {
        *v += step;
      }

    } else if (!strcmp(command, "up")) {

      *a -= step;
      if (!aim) {
        *v -= step;
      }
    }
  }
  fclose(fp);
}

int main(int argc, char **args) {
  char *file_name;
  int h, v, a;
  file_name = "input.txt";
  if (argc > 1) {
    file_name = args[1];
  }

  printf("PART 1\n");
  navigate(file_name, 0, 0, 0, &h, &v, &a, 0);
  printf("final location horizontal: %d\t vertical: %d\n", h, v);
  printf("final answer: %d\n", h * v);

  printf("\nPART 2\n");
  navigate(file_name, 0, 0, 0, &h, &v, &a, 1);
  printf("final location horizontal: %d\t vertical: %d\n", h, v);
  printf("final answer: %d\n", h * v);
}