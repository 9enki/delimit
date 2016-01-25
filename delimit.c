#include "delimit.h"
#include "stdio.h"
#include "string.h"

static void initialize_array(char result[][BUFFER_COLUMN_SIZE]);

void getDelimitted(char* input, char result[][BUFFER_COLUMN_SIZE])
{
    unsigned int j = 0;
    unsigned int row = 0;
    unsigned int delimiter = (int)',';
    char* current_ptr = 0;
    char* previous_ptr = 0;

    initialize_array(result);
    previous_ptr = input;
    current_ptr = strchr(previous_ptr, delimiter);
    if (current_ptr != NULL) {
        current_ptr++;
        if (current_ptr != NULL) {
            for (j = 0; j < (current_ptr - previous_ptr - 1); ++j) {
                result[row][j] = previous_ptr[j];
            }
            ++row;
            while (current_ptr != NULL) {
                previous_ptr = current_ptr;
                current_ptr = strchr(previous_ptr, delimiter);
                if (current_ptr != NULL) {
                    current_ptr++;
                    for (j = 0; j < current_ptr - previous_ptr - 1; ++j) {
                        result[row][j] = previous_ptr[j];
                    }
                    row++;
                }
                else {
                    for (j = 0; j < input + strlen(input) - previous_ptr; ++j) {
                        result[row][j] = previous_ptr[j];
                    }
                }
            }
        }
    }
    else {
        return;
    }
}

static void initialize_array(char result[][BUFFER_COLUMN_SIZE])
{
    unsigned int i = 0;
    unsigned int j = 0;

    for (i = 0; i < BUFFER_ROW_SIZE; ++i) {
        for (j = 0; j < BUFFER_COLUMN_SIZE; ++j) {
            result[i][j] = '\0';
        }
    }
}
