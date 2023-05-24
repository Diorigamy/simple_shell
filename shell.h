#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 600
#define FREE_ADDRESSES ((void *)3)
#define ARRAY_SIZE(ARRAY) (sizeof(ARRAY) / sizeof((ARRAY)[0]))
/**
 * ctrl_buf - structure for controlling buffer
 * @ptr: pointer the buffer
 * @buff: size of the buffer
 * @curr: current point in buffer to check for multiple command passes
 */
typedef struct ctrl_buf
{
	char *ptr;
	unsigned int buff;
	unsigned int curr;
} ctrl_buf;
/**
 * blt_in - lookup structure for builtin functions
 * @fncl: string name user types to call function
 * @pfn: function pointer to that function
 */
typedef struct blt_in
{
	char *name;
	int (*func)();
} blt_in;
/**
 * sv_add - List for saving addresses for freeing on exit
 * @add: an address of any type
 * @next: the next node in the list
 */
typedef struct sv_add
{
	void *addr;
	struct sv_add *nxt;
} sv_add;

/**
 * struct hist_s - history linked list for saving commands
 * @t_cmd: command given as input
 * @nxt: pointer to next node on list
 */

typedef struct hist
{
	char *t_cmd;
	struct hist *nxt;
} hist;

extern char **my_env;
/**
 * struct env - structure for each environmental variable
 * @val: value of the environmental variable
 * @nxt: next environmental variable
 */

typedef struct env
{
	char *val;
	struct env *nxt;
} env;
/**
 * struct c_alias - structure for holding aliases
 * @key: key to search for when matching
 * @val: value to replace matched keys
 * @nxt: next node in the list
 */
typedef struct c_alias
{
	char *key;
	char *val;
	struct c_alias *nxt;
} c_alias;

typedef void (*c_signh)(int);
void signh (int sig);

/* hist.c */            
void svd_hist(char *t_cmd, env *env_n, char typ);
void pt_hist1(hist *hpt);

/* func_hist.c*/
void mk_hist(hist *mkht, env *env_n);
int rd_input(env *env_n, char **ptr);
hist *addh(hist *new, char *t_cmd);
void pt_hist(hist *new);
char *my_path(char **path, char *fnm, char *key, env *env_n);

/* func_hist2.c*/
void cmhst(hist *histr, char *cmd);
void rem_top(hist *new);
int wrhst(env *env_n, hist *history);
char *i2s(int dig, int modetyp);

/* main.c */
int t_cmds(ctrl_buf *b, int val_return);
void trim_cmd(ctrl_buf *b);

/* vexp.c */
void vaxpan(ctrl_buf *b, env *env_n, int val_return);
char *_getpid(void);
char *_getTok(char *stat, int n);

/* execute.c */
int _rexec(char **list, env *env_r, int length);
int _fexec(char *command, char **list, env *env_n);

/* linked.c*/
env *mk_lenv();
env *envadd(env **top, char *s);
void remonv(env *top, int idx);
void renv(env *env_n, char *update, char *valu, int length);
void penv(env *top);

/* getenv.c */
void pinp(void);
void *maloc(size_t size);
void werr(char *s);
void frarg(char **largs);
char *delv(env *env_v, char *arg, int lenp);
char *retenv(env *env_g, char *nm);

/* gstdo.c */
void rw(char *s);
char *upath(char **lsarg, env *env_r, char *path, int lenp);
char **lsarr(env *env_a);
int scmp(char *s1, char *s2);
char *scpy(char *dest, char *src);

/* manips.c*/
char *mcpy(char *dest, char *src, unsigned int n);
char *mset(char *s, char b, unsigned int n);
char *scat(char *dest, char *src);
char *sncat(char *dest, char *src, int n);
char *ssew(char *shtack, char *nd);

/* convs.c */
char *sdup(char *str);
char *schr(char *s, char c);
int slen(char *s);
int smach(char *s1, char *s2);
int smanch(char *s1, char *s2);
int s2i(char *s);

/* checks.c */
int sewint(char *shtack, char *nd);
int sbrk(char *s, char *nds);
int smachic(char *s1, char *s2);
int salpha(char c);
int digits(char c);

/* match4.c */
int stach(char *s1, char *s2, char *delim);
int chach(char c, char *nds);

/* rdline.c */
int rd_cmd(ctrl_buf *b, int fd, env *env_r);
int rd_end(char *s);
int rd_file(ctrl_buf *b, env *env_r);

/* b_manip.c */
void brocate(ctrl_buf *b);
void berase(ctrl_buf *b, int n);
void bins(ctrl_buf *b, char *s, int n);

/* halias.c */
int alias(char *int*argv, env *env_a, int typ);
char *falias(c_alias *list, char *arg);
int pallias(c_alias *list);
int palias(c_alias *list, char **argv);
int addalias(c_alias *list, char **argv);

/* cd_fun.c */
char *pach(char **largs, env *env_p, int lenp);

/* fun_path.c */
int gpath(char *path, env *list);
char **patok(char **fpath, char *path, int len);
int mpath(char *t_cmd, char **fpath);

/* tokenz.c */
void tok_cmd(ctrl_buf *pt, char ***av);
void avint(char *ptr, char ***av);
void nadd(char *ptr);
int chesp(char c);
int cmend(char c);

/* blt_in.c */
int blt_rin(char **largs, env *env_r, int lenp);

/* xalias.c */
int expalias(ctrl_buf *b, env *env_a);

/* maloc.c */
void fr(void *add);
void freed(void *add);
int clead(sv_add *list, void *add);
void addred(sv_add *list, void *add);
void fread(sv_add *list);

/* builtin functions */
int int henv(char **list, env *env_n);
int _setenv(char **arg, env *env_b, int lenp);
int _unsetenv(char **arg, env *env_b);
int ccd(char **list, env *env_n, int length);
int _help(char **list);
int _exit(char **list, env *env_n, int length);
int _hist(char **arg, env *env_b, int lenp);

/* list of builtin help printouts */
int h_exit_help(void);
int h_env_help(void);
int shetenv(void);
int hunsetenv(void);
int ccd_help(void);
int hisht(void);
int halias(void);
int heelp_help(void);
#endif
