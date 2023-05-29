#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define UNUSED __attribute__((unused))
#define BUFFER_SIZE 1024
#define MAX_ARG_LEN 1000
#define true 1
#define false 0

/**
 * struct stack_s - struct of the stack
 * @n: integer or data of node
 * @prev: pointer to previous element in stack
 * @next: pointer to next element in stack
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *list_head;
extern stack_t *list_tail;
extern int line_number;
extern int format;

/* stack functions */
int empty(void);
void push_back(int value);
void push_front(int value);
void pop_back(void);
void pop_front(void);
int front(void);
int back(void);
void free_list(void);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* instruction functions */
int op_pall(void);
int op_push(char *value);
int op_pint(char *opcode);
int op_pop(void);
int op_swap(char *opcode);
int op_maths(char *opcode);
int pchar(char *opcode);

/* string functions */
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *str, int ch);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_substr(char *src, int m, int n);
int _atoi(char *str);
char *_itoa(int num);
int is_numeric(char *s);
int is_digit(char c);

/* memory functions */
void _memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, unsigned int old_size,
		unsigned int new_size);
void *_memchr(char *s, char c, int n);
void *_calloc(size_t count, size_t size);
void *_recalloc(void *ptr, unsigned int old_size,
		unsigned int new_size);

/* print functions */
void print_str(char *s);
void print_err(char *s);

/* file functions */
int process_file(char *file, int *fd);

/* error handlers */
void error_file(char *file);
int error_instruction(char *opcode);
void error_malloc(void);
void error_push(void);
void error_empty(char *opcode);
void error_pop(void);
void error_short_stack(char *opcode);
void error_div_zero(void);
void error_ascii(void);

/* getline functions */
int _getline(char **lineptr, size_t *n, int stream);

/* parsers */
void parse_instruction(char **opcode, char **value, char *line_buffer);

#endif
