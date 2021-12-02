//Section : Basic lifetime of a shell
int main (int argc, char **argv)
{
	//run command loop
	lsh_loop();

	//performing shutdown/cleanup
	return EXIT_SUCCESS;
}


//Section : Basic loop of a shell
void lsh_loop(void)
{
	char *line;
	char **args;
	int status; 

	do {
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
}

