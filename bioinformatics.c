/*
 * rosalind - bioinformatics
 * http://rosalind.info/
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

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "bioinformatics.h"


/*
 * Remove leading and trailing whitespace from string s
 * Returns a pointer to the first non-whitespace charater in s
 *
 * Copied from Linux Kernel
 * https://git.kernel.org/cgit/linux/kernel/git/stable/linux-stable.git/tree/lib/string.c#n446
*/
char *strstrip(char *s) {
    uint64_t len = strlen(s);
    if (!len) {
        return s;
    }

    char *end = s + len - 1;

    while (end >= s && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    while (*s && isspace(*s)) {
        s++;
    }

    return s;
}


/*
 * Count nucleotides in DNA or RNA string nucleic_acid_str
 * Returns a nucleotide_counts struct containing the nucleotide counts from nucleic_acid_str
 */
struct nucleotide_counts count_nucleotides(char *nucleic_acid_str) {
    uint32_t na_strlen = strlen(nucleic_acid_str);

    struct nucleotide_counts nt_counts = {0};

    for (uint32_t i = 0; i < na_strlen; i++) {
        switch (nucleic_acid_str[i]) {
            case 'a':
            case 'A':
                nt_counts.a++;
                break;
            case 'c':
            case 'C':
                nt_counts.c++;
                break;
            case 'g':
            case 'G':
                nt_counts.g++;
                break;
            case 't':
            case 'T':
                nt_counts.t++;
                break;
            case 'u':
            case 'U':
                nt_counts.u++;
                break;
            default:
                fprintf(stderr, "count_nucleotides(): Unexpected character: '%c'\n", nucleic_acid_str[i]);
                i = na_strlen;
                break;
        }
    }

    return nt_counts;
}
