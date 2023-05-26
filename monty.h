#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define UNUSED __attribute__((unused))
#define BUFFER_SIZE 1024
#define MAX_ARG_LEN 1000

/* global variabes */
extern int line_number;

/* type definitions */
typedef struct stack_s stack_t;

typedef void (*push_back_fn)(stack_t *stack, int value);
typedef void (*push_front_fn)(stack_t *stack, int value);
typedef int (*pop_back_fn)(stack_t *stack);
typedef int (*pop_front_fn)(stack_t *stack);
typedef int (*front_fn)(stack_t *stack);
typedef int (*back_fn)(stack_t *stack);

/* stack functions */
void init_stack(stack_t *stack);

/* structure of the stack */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * @push_back: function pointer to push_back function
 * @push_front: function pointer to push_front function
 * @pop_back: function pointer to pop_back function
 * @pop_front: function pointer to pop_front function
 * @front: function pointer to front function
 * @back: function pointer to back function
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
	push_back_fn push_back;
	push_front_fn push_front;
	pop_back_fn pop_back;
	pop_front_fn pop_front;
	front_fn front;
	back_fn back;
};

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
void error_instruction(char *opcode);
void error_malloc(void);

/* getline functions */
int _getline(char **lineptr, size_t *n, int stream);

#endif
