//#include <stdlib.h>
//#include <string.h>
//#include <strstrea.h>
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include "time.h"
//#include <hash_set>
#include "Simon.h"
#include "Speck.h"
//#include "Equations.h"

#include <inttypes.h>

typedef int64_t s64;
typedef uint64_t u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;


#define ROTL( n, X )    ( ( ( X ) << n ) | ( ( X ) >> ( 32 - n ) ) )

#define ROTL2( n, X, L )    ( ( ( X ) << ( n + 64 - L ) >> (64-L)) | ( ( X ) >> ( L - n ) ) )
