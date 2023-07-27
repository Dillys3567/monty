#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;
/**
 * main - monty entry
 * @argc: number of args
 * @argv: pointer to array
 * Return: exit success or failure
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (use_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
