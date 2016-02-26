/*
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


/*
 * Remove leading and trailing whitespace from string s
 * Returns a pointer to the first non-whitespace charater in s
 *
 * Copied from Linux Kernel
 * https://git.kernel.org/cgit/linux/kernel/git/stable/linux-stable.git/tree/lib/string.c#n446
*/
char *strstrip(char *s)
{
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
 * Reverse a string
 *
 * Returns a pointer to reversed copy of s
 * You should free() this pointer when you're done with it.
 *
 * Returns NULL if there was a problem allocating memory for the string copy.
 */
char *strrev(char *s)
{
    uint64_t s_len = strlen(s);

    char *buf = calloc(s_len + 1, 1);
    if (!buf) {
        return NULL;
    }

    for (uint64_t i = 0; i < s_len; i++) {
        uint64_t s_index = s_len - 1 - i;
        buf[i] = s[s_index];
    }

    return buf;
}
