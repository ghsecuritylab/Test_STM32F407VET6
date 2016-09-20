#ifndef LWIP_PLATFORM_ASSERT_H
#define LWIP_PLATFORM_ASSERT_H
//------------------------------------------------------------------------------------
#include "debug.h"
#include "cc.h"

//------------------------------------------------------------------------------------
// #define LWIP_PLATFORM_ASSERT(x) //do { if(!(x)) while(1); } while(0)

//------------------------------------------------------------------------------------
/*
#define LWIP_PLATFORM_ASSERT(x)                             \
    do {                                                    \
        printf("Assert \"%s\" failed at line %d in %s\n",   \
                x, __LINE__, __FILE__);                     \
        abort();                                            \
    } while (0)
*/
//------------------------------------------------------------------------------------
/*
#ifdef LWIP_ASSERT
    #undef LWIP_ASSERT
#endif

// Поменять тут #include "debug.h"
#define LWIP_ASSERT(message, assertion )        \
    do {                                        \
        if( !(assertion) )                      \
            LWIP_PLATFORM_ASSERT(message)       \
    } while(0)
*/
//------------------------------------------------------------------------------------
/*
#ifdef LWIP_PLATFORM_ASSERT
    #undef LWIP_PLATFORM_ASSERT
#endif


// Поменять тут #include "cc.h"
#define LWIP_PLATFORM_ASSERT(x)                                     \
    do {                                                            \
            printf("Assertion \"%s\" failed at line %d in %s\n",    \
                   x, __LINE__, __FILE__);                          \
            fflush(NULL);                                           \
            abort();                                                \
    } while(0);
*/

//------------------------------------------------------------------------------------
#endif /* LWIP_PLATFORM_ASSERT_H */
