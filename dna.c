/*
 * rosalind - dna
 * http://rosalind.info/problems/dna/
 *
 * Copyright (C) 2016 Josh Gadeken
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see {http://www.gnu.org/licenses/}.
 */
#define _GNU_SOURCE
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int32_t main(int32_t argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dataset file>\n", argv[0]);
        return 1;
    }

    FILE *inp_fp = fopen(argv[1], "r");
    if (inp_fp == NULL) {
        char *err_msg;
        asprintf(&err_msg, "Failed to open \"%s\"", argv[1]);
        perror(err_msg);
        free(err_msg);
        return 1;
    }

    char *line_ptr = NULL;
    size_t line_len = 0;
    ssize_t read_len = 0;

    read_len = getline(&line_ptr, &line_len, inp_fp);
    if (read_len == -1) {
        char *err_msg;
        asprintf(&err_msg, "Failed to get line from \"%s\"", argv[1]);
        perror(err_msg);
        free(err_msg);
        return 1;
    }

    uint32_t base_counts[4] = {0};
    for (uint32_t i = 0; i < read_len; i++) {
        switch (line_ptr[i]) {
            case 'a':
            case 'A':
                base_counts[0]++;
                break;
            case 'c':
            case 'C':
                base_counts[1]++;
                break;
            case 'g':
            case 'G':
                base_counts[2]++;
                break;
            case 't':
            case 'T':
                base_counts[3]++;
                break;
            case '\r':
            case '\n':
                i = read_len;
                break;
            default:
                fprintf(stderr, "Unexpected character: '%c'\n", line_ptr[i]);
                i = read_len;
                break;
        }
    }

    printf("%u %u %u %u\n", base_counts[0], base_counts[1], base_counts[2], base_counts[3]);

    free(line_ptr);
    fclose(inp_fp);
}
