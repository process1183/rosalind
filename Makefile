# rosalind
# Copyright (C) 2016 Josh Gadeken
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see {http://www.gnu.org/licenses/}.

# https://www.gnu.org/software/make/manual/make.html
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC := gcc
RM := rm -f
CFLAGS := -std=gnu99 -Wall -Wextra -pedantic -g $(OPTFLAGS)
LDLIBS := $(OPTLIBS)

OBJ := bioinformatics.o string_utils.o

ALL_PROGRAMS := \
	dna \
	rna \
	revc

.PHONY: all
all: $(ALL_PROGRAMS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(ALL_PROGRAMS): $(OBJ)

.PHONY: clean
clean:
	$(RM) *.o $(ALL_PROGRAMS)
