#ifndef __MY_H__
# define __MY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fann.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <libmy.h>
#include "get_next_line.h"

typedef	struct	s_fann
{
  int		inputs;
  int		outputs;
  int		exemples;
  float		freq[26];

}		t_fann;

char		*copy_freq();	/* copie les donées de freq.data pour les réinserer ensuite */
char		*read_html(char *chemin, char *buff); /* lis le ficher html */
char		*delete(char *str);	/* supprime </p> à compléter */

int		get_subject(int arg, char **args);
void		scraping(char *chemin);	/* récupere le texte stockés entre les balises <p> et </p> */
void		write_datas(FILE *f, t_fann *fann, char **tmp); /*  crée l'entête fann et insert les entrées */
void		get_frequance(char *str, float *freq); /* Donne la fréquence d'apparition des lettres dans le texte */
void		create_datas(char **argv);	       /*  */
void		edit(char **arg, t_fann *fann, char **tmp); /* Ajoute  des données */
void		count_freq_mots(char *buff, float *words); /* compte le nombre de fois que le mot apparait */

#endif /* !__MY_H__ */
