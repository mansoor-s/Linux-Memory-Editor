#ifndef GLOBAL_H
#define GLOBAL_H

/* determine what regions we need */
enum {
    REGION_ALL,                            /* each of them */
    REGION_HEAP_STACK_EXECUTABLE,          /* heap, stack, executable */
    REGION_HEAP_STACK_EXECUTABLE_BSS       /* heap, stack, executable, bss */
};

 /*
  * Our standard datatypes that the user will be able to search for
  */
enum {
    BOOLEAN,
    CHARACTER,
    SHORT_INTEGER,
    INTEGER,
    LONG_INTEGER,
    FLOAT,
    DOUBLE,
    STRING,
    UNICODE_CHARECTER,
    UNICODE_STRING
};
 /*
  *
  * Search types
  *
  */
enum {
    EXACT,
    GREATER,
    LESSER,
    CHANGED,
    UNCHANGED,
    UNKNOWN
//BETWEEN   7  // yet to be implemented. Let's get easy stuff working first :p
};

typedef unsigned char* BYTE;

#endif // GLOBAL_H
