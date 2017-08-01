#include "my.h"

int	main(int argc, char **argv)
{
  float *f;
  int	i = 0;
  f = malloc(4096 * sizeof (float));
  get_frequance(argv[1], f);
  printf("%f\n", f[0]);
  /* while (f[i] != '\0') */
  /*   { */
  /*     printf("OK\n"); */
  /*     printf("%f\n", f[i]); */
  /*     i++; */
  /*   } */
}
