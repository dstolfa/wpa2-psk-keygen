#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUF_SIZE 64

int
main(int argc, const char *argv[])
{
	char buf[BUF_SIZE] = {0};
	uint16_t num_choices = 0;
	const char *choices = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_=-{}:`'/.\\|,[]<>?";
	uint16_t i = 0;
	uint16_t size = 0;

	if (argc <= 1) {
		printf("Usage: wpa-psk-keygen <size>\n");
		return 0;
	}	

	size = atoi(argv[1]);

	if (size >= BUF_SIZE) {
		printf("Size too large, exiting..\n");
		return 1;
	}
	if (size <= 0) {
		printf("Size must be greater than 0\n");
		return 1;
	}

	num_choices = strlen(choices);
	for (i = 0; i < size; i++) {
		buf[i] = choices[arc4random_uniform(num_choices)];
	}
	buf[i] = '\0';

	printf("Generated random string: %s\n", buf);

	return 0;
}
