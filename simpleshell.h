#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for the read/write buffers */
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* for the command chaining */
#define CMD_NORM	0
#define CMD_CHAIN	3
#define CMD_OR          1
#define CMD_AND         2

/* 1 if using the system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_MAX	4096
#define HIST_FILE       ".simple_shell_history"

extern char **environ;

/* for the convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo -  contains args to pass a function,
 * @path: path for current command (string)
 * @argc: the args count
 * @line_count: the error count
 * @arg: a string generated from getline containing the args
 * @argv: array of strings generated from args
 * @argc: args count
 * @env: linkedlist save data environment
 * @environ: copy of environ from LL env
 * @history: the history node
 * @linecount_flag: check if line exist and count
 * @fname: program filename
 * @alias: alias node
 * @env_changed: check environ change
 * @status: return status of the last executed command
 * @cmd_buf: the address of pointer to cmd_buf
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the hist line number count
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

/* pointer to the cmd ; chain buffer, for the memory mangement */
	char **cmd_buf;
/* CMD_type ||, &&, ; */
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: a builtin command flag
 * @func: a function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int loophsh(char **);

/* parser.c */
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int is_cmd(info_t *, char *);

/* shloop.c */
int hsh(info_t *, char **);
void fork_cmd(info_t *);
int find_builtin(info_t *);
void find_cmd(info_t *);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* errors.c */
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
void _eputs(char *);

/* tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* memory.c */
int bfree(void **);

/* getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);

/* atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);


int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

#endif
