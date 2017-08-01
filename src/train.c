/*
** train.c<neuralBrain> for classifier in /home/remi/neuralNetwork/neuralBrain
**
** Made by Rémi
** Login   <remi@epitech.net>
**
** Started on  Wed Apr  5 17:02:17 2017 Rémi

** Last update Wed Apr  5 17:02:17 2017 Rémi
*/

#include "my.h"

int	main(int argc, char **argv)
{
  const unsigned int num_input = 1;
  const unsigned int num_output = 3;
  const unsigned int num_layers = 3;
  const unsigned int num_neurons_hidden = 3;
  const float desired_error = (const float) 0.001;
  const unsigned int max_epochs = 500000;
  const unsigned int epochs_between_reports = 10000;
  struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

  if (argc == 3)
    create_datas(argv);
  fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
  fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
  fann_train_on_file(ann, "datas/train/freq.data", max_epochs, epochs_between_reports, desired_error);
  fann_save(ann, "datas/train/language_classify.net");
  fann_destroy(ann);
}
