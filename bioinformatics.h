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

#ifndef _bioinformatics_h
#define _bioinformatics_h

#include <stdint.h>


char *strstrip(char *s);

struct nucleotide_counts {
    uint32_t a;
    uint32_t c;
    uint32_t g;
    uint32_t t;
    uint32_t u;
};

struct nucleotide_counts count_nucleotides(char *nucleic_acid_str);

#endif // _bioinformatics_h
