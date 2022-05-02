#include "helpers.h"

void parse_args(args_t *args, int argc, char **argv) {
    if (argc < 5) {
        print_error("Not enough arguments\n"
                    "Usage: ./%s NO NH TI TB\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    long NO = strtol(argv[1], NULL, 10);
    long NH = strtol(argv[2], NULL, 10);
    long TI = strtol(argv[3], NULL, 10);
    long TB = strtol(argv[4], NULL, 10);

    if (NO < 0 || NH < 0 || TI < 0 || TB < 0)
        print_error("Arguments must be grater 0\n"
                    "Usage: ./%s NO NH TI TB\n", argv[0]);

    if (TI > 1000 || TB > 1000)
        print_error("TI and TB must be lower than 1000\n"
                    "Usage: ./%s NO NH TI TB\n", argv[0]);

    args->NO = (int) NO;
    args->NH = (int) NH;
    args->TI = (int) TI;
    args->TB = (int) TB;
    args->EO = (int) NO;
    args->EH = (int) NH;

    if (args->NH % 2 == 1) {
        args->EH--;
    }

    if (args->NH >= args->NO * 2) {
        args->EH = args->EO * 2;
    } else {
        args->EO = args->EH / 2;
    }
}

void print_error(char *format, ...) {
    va_list strings;
    va_start(strings, format);

    fprintf(stderr, "[ERROR] ");
    vfprintf(stderr, format, strings);

    va_end(strings);
}

void remove_output() {
    if (remove(OUTPUT_FILE_NAME) != 0)
        ERROR
}

void output_to_file(mem_t *mem, MESSAGE_TYPE type, process_t *process) {
    FILE *output = fopen(OUTPUT_FILE_NAME, OUTPUT_FILE_MODE);
    mem->line += 1;

    switch (type) {
        case ATOM_CREATED:
            fprintf(output, "%d: %c %d: started\n", mem->line, process->atom.type, process->atom.id);
            break;
        case ATOM_TO_QUEUE:
            fprintf(output, "%d: %c %d: going to queue\n", mem->line, process->atom.type, process->atom.id);
            break;
        case ATOM_FROM_QUEUE:
            fprintf(output, "%d: %c %d: creating molecule %u\n", mem->line, process->atom.type, process->atom.id,
                    mem->m_id);
            break;
        case ATOM_READY:
            fprintf(output, "%d: %c %d: molecule %d created\n", mem->line, process->atom.type, process->atom.id,
                    mem->m_id);
            break;
        case ATOM_INSUFFICIENT_H:
            fprintf(output, "%d: %c %d: not enough O or H\n", mem->line, process->atom.type, process->atom.id);
            break;
        case ATOM_INSUFFICIENT_O:
            fprintf(output, "%d: %c %d: not enough H\n", mem->line, process->atom.type, process->atom.id);
            break;
        default:
            break;
    }

    fclose(output);
}
