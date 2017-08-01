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

void		count_freq_keys(char *buff, float *words, char **keys)
{
  int		i;
  int		j;
  int		c;
  int		f;
  char		**tab = NULL;

  i = 0;
  j = 0;
  c = 0;
  f = 0;
  tab = my_wordtab(buff, ' ');
  keys = keys;
  while (buff[i] != '\0')
    {
      while (*keys[f] != '\0')
	{
	  /* printf("%s\n", keys[f]); */
	  while (*tab[j] != '\0')
	    {
	      if (strcmp(tab[j], keys[f]) == 0)
		words[c] = words[c] + 1;
	      j++;
	    }
	  j = 0;
	  f++;
	}
      c++;
      j = 0;
      i++;
    }
}

int		count_words(char *buff)
{
  int		i;
  char		**tab;

  i = 0;
  tab = my_wordtab(buff, ' ');
  while (*tab[i] != '\0')
    i++;
  return (i);
}

void		get_frequance(char *str, float *freq)
{
  FILE		*fichier = NULL;
  char		*buff;
  char		**tab = NULL;
  int		num = 0;
  int		i = 0;
  float		*words;

  buff = malloc(4096 * sizeof (char));
  words = malloc(4095 * sizeof (float));
  fichier = fopen(str, "r");
  if (fichier != NULL)
    {
      while ((buff[i] = fgetc(fichier)) != EOF)
	i++;
      buff[i] = '\0';
      num = count_words(buff);
      tab = my_wordtab("hardware hardware reseau neurones L'intelligence artificielle robot rasperry pi chatbot develloper synthese vocale software bug programme humanoide plat pâtes sauce carbonara repas délicieux boeuf brochettes frites steak cheval ", ' ');
      count_freq_keys(buff, words, tab);
      i = 0;
      while (i != num)
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
      if (strcmp(arg[2], "log") == 0)
	{
	  write_datas(f, fann, tmp);
	  fprintf(f, "\n%i %i %i\n", 1, 0, 0);
	}
      else if  (strcmp(arg[2], "mat") == 0)
	{
	  write_datas(f, fann, tmp);
	  fprintf(f, "\n%i %i %i\n", 0, 1, 0);
	}
      else if (strcmp(arg[2], "cuisine") == 0)
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
