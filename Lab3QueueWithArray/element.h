#ifndef ELEMENT_H
#define ELEMENT_H
struct Element {
    int int_value;
    float float_value;
};
typedef struct Element Element;
#endif

// #ifndef ELEMENT ... #endif is a common pattern to prevent multiple
// inclusion of a header file.  It is not necessary in this case, but
// it is good practice to use it anyway.