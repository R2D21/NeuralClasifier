/*
** main.c for classifier in /home/remi/neuralNetwork/neuralBrain
**
** Made by Rémi
** Login   <remi@epitech.net>
**
** Started on  Wed Apr  5 15:59:02 2017 Rémi

** Last update Wed Apr  5 15:59:02 2017 Rémi
*/

#include "my.h"

int		get_subject(int arg, char **args)
{
  float		*words;
  fann_type	*calc_out;

  if (arg == 2)
    {
      struct fann *ann = fann_create_from_file("datas/train/language_classify.net");
      words = malloc(4096 * sizeof(float));
      get_frequance(args[1], words);
      calc_out = fann_run(ann, words);
      if (calc_out[0] >= 0.5)
        return (1);
      else if (calc_out[1] >= 0.5)
	return (2);
      else if (calc_out[2] >= 0.5)
	return (-1);
     else
       return (42);
      fann_destroy(ann);
      /* return (0); */
    }
  return (-42);
}
