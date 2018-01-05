/**
 * string_utils
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
#include <stdlib.h>
#include <string.h>

#include "string_utils.h"


/* Mostly copied from lib/string.c in the Linux Kernel */
char *strstrip(char *s)
{
    size_t len = strlen(s);
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


char *strrev(char *s)
{
    size_t s_len = strlen(s);

    char *buf = calloc(s_len + 1, 1);
    if (!buf) {
        return NULL;
    }

    for (size_t i = 0; i < s_len; i++) {
        uint64_t s_index = s_len - 1 - i;
        buf[i] = s[s_index];
    }

    return buf;
}
