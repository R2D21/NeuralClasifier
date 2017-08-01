#include "my.h"

int	main(int argc, char ** argv)
{
  int	subject;

  subject = 0;
  if ((subject = get_subject(argc, argv)) == 1)
    printf("Informatique\n");
  else if (subject == 2)
    printf("Cuisine\n");
  else if (subject == -42)
    printf("Le programme prends un ficher en paramettre\n");
  return (0);
}
