/**
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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bioinformatics.h"


struct nucleotide_counts count_nucleotides(char *nucleic_acid_str)
{
    size_t na_strlen = strlen(nucleic_acid_str);

    struct nucleotide_counts nt_counts = {0};

    for (size_t i = 0; i < na_strlen; i++) {
        switch (nucleic_acid_str[i]) {
            case 'a':
            case 'A':
                nt_counts.A++;
                break;
            case 'c':
            case 'C':
                nt_counts.C++;
                break;
            case 'g':
            case 'G':
                nt_counts.G++;
                break;
            case 't':
            case 'T':
                nt_counts.T++;
                break;
            case 'u':
            case 'U':
                nt_counts.U++;
                break;
            default:
                fprintf(stderr, "count_nucleotides(): Unexpected character: '%c'\n", nucleic_acid_str[i]);
                i = na_strlen;
                break;
        }
    }

    return nt_counts;
}


char *transcribe_dna_to_rna(char *dna_str)
{
    char *rna_str = strdup(dna_str);
    size_t len = strlen(rna_str);

    for (size_t i = 0; i < len; i++) {
        if (rna_str[i] == 't' || rna_str[i] == 'T') {
            rna_str[i] += 1;
        }
    }

    return rna_str;
}


char *get_dna_complement(char *dna_str)
{
    char *complement = strdup(dna_str);
    size_t len = strlen(complement);

    for (size_t i = 0; i < len; i++) {
        switch (complement[i]) {
            case 'a':
            case 'A':
                complement[i] = 'T';
                break;
            case 't':
            case 'T':
                complement[i] = 'A';
                break;
            case 'c':
            case 'C':
                complement[i] = 'G';
                break;
            case 'g':
            case 'G':
                complement[i] = 'C';
                break;
            default:
                free(complement);
                return NULL;
        }
    }

    return complement;
}
