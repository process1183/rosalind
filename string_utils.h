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

#ifndef _string_utils_h
#define _string_utils_h


/**
 * strstrip - Remove leading and trailing whitespace from s.
 *
 * Returns a pointer to the first non-whitespace charater in s
 */
char *strstrip(char *s);


/**
 * strrev - Reverse a string
 *
 * Returns a pointer to reversed copy of s
 * You should free() this pointer when you're done with it.
 *
 * Returns NULL if there was a problem allocating memory
 * for the string copy.
 */
char *strrev(char *s);

#endif /* _string_utils_h */
