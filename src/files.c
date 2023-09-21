#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "files.h"

char **read_csv_line(char *line, size_t *updated_nb_cols);

Csv *read_csv(char * file_path)
{
    size_t nbRows = 0;
    size_t nbCols = 0;
    char line[1024];

    char ***content = malloc(sizeof(char**));

    FILE *file = fopen(file_path, "r");
    if(file == NULL) {
        return NULL;
    }

    while(fgets(line, 1024, file)) {
        line[strlen(line) - 1] = '\0';
        char ** line_csv = read_csv_line(line, &nbCols);
        content = realloc(content, sizeof(char**) * (nbRows + 1));
        content[nbRows] = line_csv;
        nbRows++;
    }

    fclose(file);

    Csv* result = malloc(sizeof(Csv));
    result->content = content;
    result->nbRows = nbRows;
    result->nbCols = nbCols;

    return result;
}

char **read_csv_line(char *line, size_t *updated_nb_cols)
{
    size_t nb_cols = 0;
    char **line_csv = malloc(0);

    char *token = strtok(line, ";");
    while(token) {
        line_csv = realloc(line_csv, sizeof(char*) * (nb_cols + 1));
        line_csv[nb_cols] = malloc(strlen(token));
        strcpy(line_csv[nb_cols], token);
        nb_cols++;
        token = strtok(NULL, ";");
    }

    *updated_nb_cols = nb_cols;

    return line_csv;
}

void print_csv(Csv *csv)
{
    for(int i = 0; i < csv->nbRows; i++) {
        for(int j = 0; j < csv->nbCols; j++) {
            printf("%s", csv->content[i][j]);
            if(j != csv->nbCols - 1) {
                printf("; ");
            }
        }
        printf("\n");
    }
}
