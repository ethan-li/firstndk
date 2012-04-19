#ifndef NDK_TYPES_H__INCLUDED__
#define NDK_TYPES_H__INCLUDED__

/**
 * file ndk_types.h
 *
 * NDK types.  This file contains common types that are platform specific.
 */
 
#include <jni.h>

#if 0
typedef unsigned int    ndk_uint32;   /* Unsigned 32-bit integer */
typedef signed int      ndk_sint32;   /* Signed 32-bit integer */
typedef unsigned short  ndk_uint16;   /* Unsigned 16-bit integer */
typedef signed short    ndk_sint16;   /* Signed 16-bit integer */
typedef unsigned char   ndk_uint8;    /* Unsigned 8-bit byte */
typedef signed char     ndk_sint8;    /* Signed 8-bit byte */
typedef char            ndk_char;     /* Single character */

typedef double          ndk_real;
#else
typedef unsigned int    ndk_uint32;   /* Unsigned 32-bit integer */
typedef jint	      	ndk_sint32;   /* Signed 32-bit integer */
typedef jchar			ndk_uint16;   /* Unsigned 16-bit integer */
typedef jshort    		ndk_sint16;   /* Signed 16-bit integer */
typedef jboolean		ndk_uint8;    /* Unsigned 8-bit byte */
typedef jbyte		    ndk_sint8;    /* Signed 8-bit byte */
typedef char            ndk_char;     /* Single character */

typedef jdouble         ndk_real;
#endif

#endif

