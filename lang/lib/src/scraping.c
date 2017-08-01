/*
** scraping.c for classifier in /home/remi/neuralNetwork/neuralBrain
**
** Made by Rémi
** Login   <remi@epitech.net>
**
** Started on  Wed Apr  5 00:05:37 2017 Rémi

** Last update Wed Apr  5 00:05:37 2017 Rémi
*/

#include "my.h"

char		*read_html(char *chemin, char *buff)
{
  FILE		*fichier = NULL;
  int		i;

  i = 0;
  if ((fichier = fopen(chemin, "r")) != NULL)
    while ((buff[i] = fgetc(fichier)) != EOF)
      i++;
  else
    my_putstr_error("Error");
  return (buff);
}

char		*delete(char *str)
{
  int		i;
  int		c;
  char		*tmp;

  tmp = malloc(4096 * sizeof (char));
  i = 0;
  c = 0;
  while (str[i] != '\0')
    {
      if (str[i] == 'p' && str[i + 1] == '>')
  	i++;
      tmp[c++] = str[i++];
    }
  i = 0;
  c = 0;
  while (tmp[i] != '\0')
    {
      if (tmp[i] == '>')
  	  i++;
      str[c++] = tmp[i++];
    }
  printf("%s\n", str);
  free(tmp);
  return (str);
}

void		scraping(char *chemin)
{
  char		*buff;
  char		*tmp;
  int		i;
  int		j;
  int		c;

  buff = malloc(4096 * sizeof(char));
  tmp = malloc(4096 * sizeof (char));
  i = 0;
  j = 0;
  buff = read_html(chemin, buff);
  while (buff[i] != '\0')
    if (buff[i] == '<')
      {
	i++;
	c = i;
	if (buff[i] == 'p')
	  while (buff[c++] != '<' && buff[c + 1] != '/')
	    tmp[j++] = buff[c];
      }
    else
      i++;
  buff = delete(tmp);
  printf("%s\n", buff);
}
