/*
** main.c for classifier in /home/remi/neuralNetwork/neuralBrain
**
** Made by Rémi
** Login   <remi@epitech.net>
**
** Started on  Mon Apr  3 20:42:03 2017 Rémi

** Last update Mon Apr  3 20:42:03 2017 Rémi
*/

#include "my.h"

int	main(int argc, char **argv)
{
  fann_type *calc_out;

  if (argc != 2)
    printf("Error\n");
    else
      {
	struct fann *ann = fann_create_from_file("datas/train/language_classify.net");
	float  freq[26];

	get_frequance(argv[1], freq);
	calc_out = fann_run(ann, freq);
	if (calc_out[0] >= 0.5)
	  my_putstr("Français\n");
	else if (calc_out[1] >= 0.5)
	  my_putstr("Espagnol\n");
	else if (calc_out[2] >= 0.5)
	  my_putstr("Anglais\n");
	else
	  printf("Français  %f Espagnol %f Anglais%f \n", calc_out[0], calc_out[1], calc_out[2]);
	fann_destroy(ann);
      }
  return 0;
}
