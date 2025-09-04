# Makefile
# Build uuidgen
# By J. Stuart McMurray
# Created 20250804
# Last Modified 20250804

COPTS = -Wall -Wextra -Werror --pedantic
MAN   = 
PROG  = uuidgen

all: ${PROG} test
.PHONY: all

test: ${PROG}
	prove --directives
.PHONY: test

.include <bsd.prog.mk>
