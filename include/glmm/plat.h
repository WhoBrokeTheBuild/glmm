#ifndef GLMM_PLAT_H
#define GLMM_PLAT_H

// Platform detection and definitions
// Based on: https://github.com/g-truc/glm/blob/master/glm/simd/platform.h

// clang-format off

#define GLMM_PLATFORM_UNKNOWN 0x00000000
#define GLMM_PLATFORM_WINDOWS 0x00010000
#define GLMM_PLATFORM_LINUX   0x00020000
#define GLMM_PLATFORM_APPLE   0x00040000
#define GLMM_PLATFORM_CYGWIN  0x02000000

#ifdef GLMM_FORCE_PLATFORM_UNKNOWN
#   define GLMM_PLATFORM GLMM_PLATFORM_UNKNOWN
#elif defined(__CYGWIN__)
#   define GLMM_PLATFORM GLMM_PLATFORM_CYGWIN
#elif defined(__APPLE__)
#   define GLMM_PLATFORM GLMM_PLATFORM_APPLE
#elif defined(_WIN32)
#   define GLMM_PLATFORM GLMM_PLATFORM_WINDOWS
#elif defined(__linux)
#   define GLMM_PLATFORM GLMM_PLATFORM_LINUX
#else
#   define GLMM_PLATFORM GLMM_PLATFORM_UNKNOWN
#endif

#define GLMM_COMPILER_UNKNOWN 0x00000000

// Visual C++ defines
#define GLMM_COMPILER_VC       0x01000000
#define GLMM_COMPILER_VC12     0x010000B0
#define GLMM_COMPILER_VC14     0x010000C0
#define GLMM_COMPILER_VC15     0x010000D0
#define GLMM_COMPILER_VC16     0x010000E0

// GCC defines
#define GLMM_COMPILER_GCC      0x02000000
#define GLMM_COMPILER_GCC46    0x020000D0
#define GLMM_COMPILER_GCC47    0x020000E0
#define GLMM_COMPILER_GCC48    0x020000F0
#define GLMM_COMPILER_GCC49    0x02000100
#define GLMM_COMPILER_GCC5     0x02000200
#define GLMM_COMPILER_GCC6     0x02000300
#define GLMM_COMPILER_GCC7     0x02000400
#define GLMM_COMPILER_GCC8     0x02000500

// Clang
#define GLMM_COMPILER_CLANG    0x20000000
#define GLMM_COMPILER_CLANG34  0x20000050
#define GLMM_COMPILER_CLANG35  0x20000060
#define GLMM_COMPILER_CLANG36  0x20000070
#define GLMM_COMPILER_CLANG37  0x20000080
#define GLMM_COMPILER_CLANG38  0x20000090
#define GLMM_COMPILER_CLANG39  0x200000A0
#define GLMM_COMPILER_CLANG40  0x200000B0
#define GLMM_COMPILER_CLANG41  0x200000C0
#define GLMM_COMPILER_CLANG42  0x200000D0

// Build model
#define GLMM_MODEL_32 0x00000010
#define GLMM_MODEL_64 0x00000020

// Instruction sets

#define GLMM_ARCH_X86_BIT    0x00000001
#define GLMM_ARCH_SSE2_BIT   0x00000002
#define GLMM_ARCH_SSE3_BIT   0x00000004
#define GLMM_ARCH_SSSE3_BIT  0x00000008
#define GLMM_ARCH_SSE41_BIT  0x00000010
#define GLMM_ARCH_SSE42_BIT  0x00000020
#define GLMM_ARCH_AVX_BIT    0x00000040
#define GLMM_ARCH_AVX2_BIT   0x00000080
#define GLMM_ARCH_AVX512_BIT 0x00000100 // Skylake subset
#define GLMM_ARCH_ARM_BIT    0x00000100
#define GLMM_ARCH_NEON_BIT   0x00000200
#define GLMM_ARCH_MIPS_BIT   0x00010000

#define GLMM_ARCH_PURE   (0x00000000)
#define GLMM_ARCH_X86    (GLMM_ARCH_X86_BIT)
#define GLMM_ARCH_SSE2   (GLMM_ARCH_SSE2_BIT | GLMM_ARCH_X86)
#define GLMM_ARCH_SSE3   (GLMM_ARCH_SSE3_BIT | GLMM_ARCH_SSE2)
#define GLMM_ARCH_SSSE3  (GLMM_ARCH_SSSE3_BIT | GLMM_ARCH_SSE3)
#define GLMM_ARCH_SSE41  (GLMM_ARCH_SSE41_BIT | GLMM_ARCH_SSSE3)
#define GLMM_ARCH_SSE42  (GLMM_ARCH_SSE42_BIT | GLMM_ARCH_SSE41)
#define GLMM_ARCH_AVX    (GLMM_ARCH_AVX_BIT | GLMM_ARCH_SSE42)
#define GLMM_ARCH_AVX2   (GLMM_ARCH_AVX2_BIT | GLMM_ARCH_AVX)
#define GLMM_ARCH_AVX512 (GLMM_ARCH_AVX512_BIT | GLMM_ARCH_AVX2) // Skylake subset
#define GLMM_ARCH_ARM    (GLMM_ARCH_ARM_BIT)
#define GLMM_ARCH_NEON   (GLMM_ARCH_NEON_BIT | GLMM_ARCH_ARM)
#define GLMM_ARCH_MIPS   (GLMM_ARCH_MIPS_BIT)

#if (GLMM_COMPILER & (GLMM_COMPILER_CLANG | GLMM_COMPILER_GCC)) || ((GLMM_COMPILER & GLMM_COMPILER_INTEL) && (GLMM_PLATFORM & GLMM_PLATFORM_LINUX))
//	This is Skylake set of instruction set
#   if defined(__AVX512BW__) && defined(__AVX512F__) && defined(__AVX512CD__) && defined(__AVX512VL__) && defined(__AVX512DQ__)
#      define GLMM_ARCH (GLMM_ARCH_AVX512)
#   elif defined(__AVX2__)
#      define GLMM_ARCH (GLMM_ARCH_AVX2)
#   elif defined(__AVX__)
#      define GLMM_ARCH (GLMM_ARCH_AVX)
#   elif defined(__SSE4_2__)
#      define GLMM_ARCH (GLMM_ARCH_SSE42)
#   elif defined(__SSE4_1__)
#      define GLMM_ARCH (GLMM_ARCH_SSE41)
#   elif defined(__SSSE3__)
#      define GLMM_ARCH (GLMM_ARCH_SSSE3)
#   elif defined(__SSE3__)
#      define GLMM_ARCH (GLMM_ARCH_SSE3)
#   elif defined(__SSE2__)
#      define GLMM_ARCH (GLMM_ARCH_SSE2)
#   elif defined(__i386__) || defined(__x86_64__)
#      define GLMM_ARCH (GLMM_ARCH_X86)
#   elif defined(__ARM_NEON)
#      define GLMM_ARCH (GLMM_ARCH_ARM | GLMM_ARCH_NEON)
#   elif defined(__arm__)
#      define GLMM_ARCH (GLMM_ARCH_ARM)
#   elif defined(__mips__)
#      define GLMM_ARCH (GLMM_ARCH_MIPS)
#   elif defined(__powerpc__)
#      define GLMM_ARCH (GLMM_ARCH_PPC)
#   else
#      define GLMM_ARCH (GLMM_ARCH_PURE)
#   endif
#elif (GLMM_COMPILER & GLMM_COMPILER_VC) || ((GLMM_COMPILER & GLMM_COMPILER_INTEL) && (GLMM_PLATFORM & GLMM_PLATFORM_WINDOWS))
#   if defined(_M_ARM)
#      define GLMM_ARCH (GLMM_ARCH_ARM)
#   elif defined(__AVX2__)
#      define GLMM_ARCH (GLMM_ARCH_AVX2)
#   elif defined(__AVX__)
#      define GLMM_ARCH (GLMM_ARCH_AVX)
#   elif defined(_M_X64)
#      define GLMM_ARCH (GLMM_ARCH_SSE2)
#   elif defined(_M_IX86_FP)
#      if _M_IX86_FP >= 2
#         define GLMM_ARCH (GLMM_ARCH_SSE2)
#      else
#         define GLMM_ARCH (GLMM_ARCH_PURE)
#      endif
#   else
#      define GLMM_ARCH (GLMM_ARCH_PURE)
#   endif
#else
#   define GLMM_ARCH GLMM_ARCH_PURE
#endif

// With MinGW-W64, including intrinsic headers before intrin.h will produce some errors. The problem is
// that windows.h (and maybe other headers) will silently include intrin.h, which of course causes problems.
// To fix, we just explicitly include intrin.h here.
#if defined(__MINGW64__) && (GLMM_ARCH != GLMM_ARCH_PURE)
#include <intrin.h>
#endif

#if GLMM_ARCH & GLMM_ARCH_AVX2_BIT
#include <immintrin.h>
#elif GLMM_ARCH & GLMM_ARCH_AVX_BIT
#include <immintrin.h>
#elif GLMM_ARCH & GLMM_ARCH_SSE42_BIT
#if GLMM_COMPILER & GLMM_COMPILER_CLANG
#include <popcntintrin.h>
#endif
#include <nmmintrin.h>
#elif GLMM_ARCH & GLMM_ARCH_SSE41_BIT
#include <smmintrin.h>
#elif GLMM_ARCH & GLMM_ARCH_SSSE3_BIT
#include <tmmintrin.h>
#elif GLMM_ARCH & GLMM_ARCH_SSE3_BIT
#include <pmmintrin.h>
#elif GLMM_ARCH & GLMM_ARCH_SSE2_BIT
#include <emmintrin.h>
#endif

#if GLMM_ARCH & GLMM_ARCH_SSE2_BIT
typedef __m128 GLMM_vec4;
typedef __m128i GLMM_ivec4;
typedef __m128i GLMM_uvec4;
#endif

#if GLMM_ARCH & GLMM_ARCH_AVX_BIT
typedef __m256d GLMM_dvec4;
#endif

#if GLMM_ARCH & GLMM_ARCH_AVX2_BIT
typedef __m256i GLMM_i64vec4;
typedef __m256i GLMM_u64vec4;
#endif

// clang-format off

#endif // GLMM_PLAT_H
