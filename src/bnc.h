#ifndef BNC_H
#define BNC_H

// [entry macro replace main function]
#define ENTRY int main(int argc, char* argv[]){
#define EXIT return 0; }

// [datatypes]
// char
typedef char charvar;
typedef char* stringvar;

// int
typedef charvar int8var;
typedef unsigned char uint8var;
typedef short int16var;
typedef unsigned short uint16var;
typedef int int32var;
typedef unsigned int uint32var;
typedef long long int int64var;
typedef unsigned long long int uint64var;
typedef int32var intvar;

// real
typedef float real32var;
typedef double real64var;
typedef real64var realvar;

#endif

