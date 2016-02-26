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

#include "bioinformatics.h"
#include "string_utils.h"


int32_t main(int32_t argc, char *argv[])
{
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

    char *na_str = strstrip(line_ptr);

    struct nucleotide_counts nt_counts = count_nucleotides(na_str);

    printf("%u %u %u %u\n", nt_counts.a, nt_counts.c, nt_counts.g, nt_counts.t);

    free(line_ptr);
    fclose(inp_fp);
}
