#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *@t_cmd - holds the typed command by user
 *@pos - stores index to traverse index of tokens
 *@len - size of the typed command
 *read - stores the value returned by getline() func
 *@sep_ret - stores the result of the strtok()
 *
 */
int main (void)

{
  int pos = 0;
  char *t_cmd = NULL;
  size_t len = 10;
  ssize_t  read =0;
  int *tok_read =0;
  char **sep_ret = NULL;

  t_cmd = malloc(sizeof(char)*len);//malloc allocates size of the typed command

  if(!t_cmd)//if NULL do the follow or alternative use perror()
    {
      write(1,"failed to allocate memory", 30);
      return(0);
    }

  write (1, "shell# ",7);//what user sees at the prompt
  read = getline(&t_cmd, &len, stdin);//gets user from input

  write(1, t_cmd , read);//testing if it works by printing to display

  sep_ret = malloc(strlen(t_cmd));//getting string length and allocating memory
  if(!sep_ret)//if memory allocated is NULL
    {
      write(1, "failed to allocate memory", 30);
      return(0);
    }
   
  sep_ret[pos] = strtok(t_cmd, " ");//If user has typed a command tokenize it(whitespace is delimeter)
  while(sep_ret[pos++])//iterating through each string
     {
       sep_ret[pos] = strtok(NULL, " ");//NULL since the 1st token is already in use
       }
  pos = 0;//resetting index to 0 for printing purposes
  while(sep_ret[pos])
    {
      //      tok_read = malloc(strlen(sep_ret[pos]));//size of each token
      printf("%s\n", sep_ret[pos]);
      // write(1, sep_ret[pos],tok_read);//how to get each token
      pos++;
    }
   return(0);
}
