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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bioinformatics.h"


/*
 * Count nucleotides in DNA or RNA string nucleic_acid_str
 * Returns a nucleotide_counts struct containing the nucleotide counts from nucleic_acid_str
 */
struct nucleotide_counts count_nucleotides(char *nucleic_acid_str)
{
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



/*
 * Transcribe DNA string into an RNA string
 * Transcription is done on a copy (using strdup) of dna_str
 * Returns a transcibed copy of dna_str
 */
char *transcribe_dna_to_rna(char *dna_str)
{
    char *rna_str = strdup(dna_str);
    uint64_t len = strlen(rna_str);

    for (uint64_t i = 0; i < len; i++) {
        if (rna_str[i] == 't' || rna_str[i] == 'T') {
            rna_str[i] += 1;
        }
    }

    return rna_str;
}


/*
 * Get the complement of a DNA string
 *
 * Returns a pointer to the complemented DNA string.
 * You should free() this pointer when you're done with it.
 *
 * Return NULL if an unexpected charater is encountered in the DNA string.
 *
 * http://rosalind.info/problems/revc/
 */
char *get_dna_complement(char *dna_str)
{
    char *complement = strdup(dna_str);
    uint64_t len = strlen(complement);

    for (uint64_t i = 0; i < len; i++) {
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
