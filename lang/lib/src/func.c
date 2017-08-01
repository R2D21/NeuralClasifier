
/*
** func.c for classifier in /home/remi/neuralNetwork/neuralBrain
**
** Made by Rémi
** Login   <remi@epitech.net>
**
** Started on  Mon Apr  3 22:48:32 2017 Rémi

** Last update Mon Apr  3 22:48:32 2017 Rémi
*/

#include "my.h"

int		count_letters(char *buff, float *words)
{
  int		i;
  char		c;
  int		num;

  i = 0;
  num  = 0;
  while (buff[i] != '\0')
    {
      c = (int)buff[i];
      if (c >= 'a' &&  c <= 'z')
	words[c - 97]++;
      num++;
      i++;
    }
  return (num);
}

void		get_frequance(char *str, float *freq)
{
  FILE		*fichier = NULL;
  char		*buff;
  unsigned int	num = 0;
  int		i = 0;
  float		*words;

  buff = malloc(4095 * sizeof (char));
  words = malloc(4095 * sizeof (float));
  fichier = fopen(str, "r");
  if (fichier != NULL)
    {
      fgets(buff, 4095, fichier);
      num = count_letters(buff, words);
      fclose(fichier);
      i = 0;
      num = num - 1;
      while (i != 26)
	{
	  freq[i] = words[i] / (double)num;
	  i++;
	}
    }
}

char		*copy_freq()
{
  int		i;
  char		*buff;
  FILE		*f;

  i = 0;
  buff = malloc(4096 * sizeof (char));
  if ((f = fopen("datas/train/freq.data", "r")) != NULL)
    while ((buff[i] = fgetc(f)) != EOF)
      i++;
  buff[i] = '\0';
  return (buff);
}

void		write_datas(FILE *f, t_fann *fann, char **tmp)
{
  int		i;

  i = 1;
  fprintf(f, "%i %i %i\n", (fann->exemples + 1) , fann->inputs, fann->outputs);
  while (*tmp[i] != '\0')
    fprintf(f, "%s\n", tmp[i++]);
  i = 0;
  while (i != 26)
    fprintf(f, "%f ", fann->freq[i++]);
}

void		edit(char **arg, t_fann *fann, char **tmp)
{
  FILE		*f = NULL;

  if ((f = fopen("datas/train/freq.data", "w")) != NULL)
    {
      get_frequance(arg[1], fann->freq);
      if (strcmp(arg[2], "fr") == 0)
	{
	  write_datas(f, fann, tmp);
	  fprintf(f, "\n%i %i %i\n", 1, 0, 0);
	}
      else if  (strcmp(arg[2], "es") == 0)
	{
	  write_datas(f, fann, tmp);
	  fprintf(f, "\n%i %i %i\n", 0, 1, 0);
	}
      else if (strcmp(arg[2], "en") == 0)
	{
	  write_datas(f, fann, tmp);
	  fprintf(f, "\n%i %i %i\n", 0, 0, 1);
	}
      fclose(f);
    }
}

void		create_datas(char **arg)
{
  char		*buff;
  char		*dest;
  char		**tmp = NULL;
  t_fann	*fann;

 if ((fann = malloc(1 * sizeof (*fann))) == NULL)
    exit(1);
 dest = malloc(4096 * sizeof (char));
 dest = copy_freq();
 buff = get_next_line(open("datas/train/freq.data", S_IRUSR));
 tmp = my_wordtab(buff, ' ');
 fann->exemples = atoi(tmp[0]);
 fann->inputs = atoi(tmp[1]);
 fann->outputs = atoi(tmp[2]);
 tmp = my_wordtab(dest, '\n');
 edit(arg, fann, tmp);
}
