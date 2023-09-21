typedef struct {
    char *** content;
    size_t nbRows;
    size_t nbCols;
} Csv;

Csv *read_csv(char * file_path);
void print_csv(Csv *csv);
