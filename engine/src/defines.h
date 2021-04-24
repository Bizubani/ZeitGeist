/*Set global definitions for the project*/
#pragma once

/*Cross platfrom type alias*/
/// Unsigned int types, 1 byte, 2 bytes, 4 bytes and 8 bytes
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

///Signed int types, 1 byte, 2 bytes, 4 bytes and 8 bytes
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

///floating point types, 4 bytes and 8 bytes
typedef float f32;
typedef double f64;

///Boolean types, 1 byte and 4 bytes
typedef int b32;
typedef char b8;

//Properly define static assertions accross compilers
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert //gcc
#else
#define STATIC_ASSERT static_assert //clang
#endif

//Ensure that the types are the correct size
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes");
 
STATIC_ASSERT(sizeof(b8) == 1, "Expected b8 to be 1 byte");
STATIC_ASSERT(sizeof(b32) == 4, "Expected b32 to be 4 byte");

#define TRUE 1
#define FALSE 0

///Platfrom detection code. Works on Windows, Linux and MacOs. Others will be added as necessary
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
//Windows OS
#define ZPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit windows is a requirement!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
//Linux OS
#define ZPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define ZPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
//catch other unix based platforms
#define ZPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
//Posix
#define ZPLATFORM_POSIX 1
#elif __APPLE__
//Apple platforms
#define ZPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define ZPLATFORM_IOS 1
#define ZPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define ZPLATFORM_IOS 1
//iOS device
#elif TARGET_OS_MAC
//Other kinds of Mac Os
#else
#error "Unknown Apple Platform"
#endif
#else
#error "Unknown OS" 
#endif