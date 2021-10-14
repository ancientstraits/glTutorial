#include <stdio.h>
#include <stdlib.h>

#include "util.h"

char* read_file(const char* file_path) {
	FILE* fp = fopen(file_path, "r");
	if (!fp) {
		perror(file_path);
		return NULL;
	}

	size_t file_size;
	char* file_content;

	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	file_content = malloc(file_size + 1);
	fread(file_content, 1, file_size, fp);
	file_content[file_size] = '\0';

	fclose(fp);
	return file_content;
}

