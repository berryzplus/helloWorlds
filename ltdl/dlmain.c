/* dlmain.c -- hello test program that uses simulated dynamic linking
   Copyright (C) 1996-1999 Free Software Foundation, Inc.
   This file is part of GNU Libtool.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
USA. */

#include "foo.h"
#include <stdio.h>

#ifdef HAVE_STRING_H
#include <string.h>
#endif
#include "ltdl.h"

int
main (argc, argv)
     int argc;
     char **argv;
{
  const LT_DLSYM_CONST lt_dlsymlist *s;
  int (*pfoo)() = 0;
  int (*phello)() = 0;
  int *pnothing = 0;
  int errors = 0;

  printf ("Welcome to *modular* GNU Hell!\n");

  /* Initialise preloaded symbol lookup table. */
  LTDL_SET_PRELOADED_SYMBOLS();

  /* Initialise libltdl. */
  errors = lt_dlinit();

  /* Look up the symbols we require for this demonstration. */
  s = lt_preloaded_symbols;
  while (s->name) {
    const char *name;
    if (s->address) {
      name = s->name;
      printf ("found symbol: %s\n", name);
    }

    if (!strcmp ("hello", name)) {
      phello = (int(*)())s->address;
    }
    else if (!strcmp ("foo", name)) {
      pfoo = (int(*)())s->address;
    }
    else if (!strcmp ("nothing", name)) {
#ifndef _WIN32
      /* In an ideal world we could do this... */
      pnothing = (int*) s->address;
#else /* !_WIN32 */
      /* In an ideal world a shared lib would be able to export data */
      pnothing = (int*) &nothing;
#endif
    }
    else {
      printf ("found file: %s\n", s->name);
    }
    ++s;
  }

  /* Try assigning to the nothing variable. */
  if (pnothing) {
    *pnothing = 1;
  }
  else {
    fprintf (stderr, "did not find the `nothing' variable\n");
  }

  /* Just call the functions and check return values. */
  if (pfoo && (*pfoo)() != FOO_RET) {
    return 1;
  }
  else {
    fprintf (stderr, "did not find the `foo' function\n");
  }

  if (phello) {
      if ((*phello) () != HELLO_RET)
    return 3;
  }
  else {
    fprintf(stderr, "did not find the `hello' function\n");
  }
  return 0;
}
