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

#ifndef _bioinformatics_h
#define _bioinformatics_h

#include <stdint.h>


struct nucleotide_counts {
    uint64_t A;
    uint64_t C;
    uint64_t G;
    uint64_t T;
    uint64_t U;
};


/**
 * Count nucleotides in DNA or RNA string, s
 *
 * Returns a nucleotide_counts struct containing the nucleotide
 * counts from nucleic_acid_str
 */
struct nucleotide_counts count_nucleotides(char *nucleic_acid_str);


/**
 * Transcribe DNA string into an RNA string
 *
 * Transcription is done on a copy (using strdup) of dna_str
 *
 * Returns a transcibed copy of dna_str
 */
char *transcribe_dna_to_rna(char *dna_str);


/**
 * Get the complement of a DNA string
 *
 * Returns a pointer to the complemented DNA string.
 * You should free() this pointer when you're done with it.
 *
 * Return NULL if an unexpected charater is encountered in the DNA string.
 *
 * http://rosalind.info/problems/revc/
 */
char *get_dna_complement(char *dna_str);

#endif /* _bioinformatics_h */
