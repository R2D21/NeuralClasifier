#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

void            my_putchar(char c);
void            my_putstr(char *str);
char            *get_next_line(const int fd);
/* static int      my_strlen(char *str); */
char     *my_strncpy(char *dest, char *src, int n);
void     *my_malloc(unsigned int size);
char     *add_to_line(char *line, int treat, char *buff, int *start);

# define MEM_SIZE 4095 // a vous de jouer avec le buffer :)

#endif /* !GET_NEXT_LINE_H_ */
