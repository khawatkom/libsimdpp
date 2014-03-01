/*  libsimdpp
    Copyright (C) 2013  Povilas Kanapickas povilas@radix.lt
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBSIMDPP_SIMDPP_DETAIL_INSN_STORE_PACKED4_H
#define LIBSIMDPP_SIMDPP_DETAIL_INSN_STORE_PACKED4_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/align.h>
#include <simdpp/detail/insn/mem_pack.h>
#include <simdpp/core/store.h>
#include <simdpp/null/memory.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace detail {
namespace insn {


// the 256-bit versions are mostly boilerplate. Collect that stuff here.
template<class V>
void v256_store_pack4(char* p, V a, V b, V c, V d);
template<class V>
void v_store_pack4(char* p, V a, V b, V c, V d);

// -----------------------------------------------------------------------------

inline void i_store_packed4(char* p,
                            gint8x16 a, gint8x16 b, gint8x16 c, gint8x16 d)
{
    p = detail::assume_aligned(p, 16);
#if SIMDPP_USE_NULL
    null::store_packed4(p, a, b, c, d);
#elif SIMDPP_USE_SSE2 || SIMDPP_USE_ALTIVEC
    mem_pack4(a, b, c, d);
    i_store(p, a);
    i_store(p+16, b);
    i_store(p+32, c);
    i_store(p+48, d);
#elif SIMDPP_USE_NEON
    uint8x16x4_t t;
    t.val[0] = a;
    t.val[1] = b;
    t.val[2] = c;
    t.val[3] = d;
    vst4q_u8(reinterpret_cast<uint8_t*>(p), t);
#endif
}

#if SIMDPP_USE_AVX2
inline void i_store_packed4(char* p,
                            gint8x32 a, gint8x32 b, gint8x32 c, gint8x32 d)
{
    v256_store_pack4(p, a, b, c, d);
}
#endif

template<unsigned N>
void i_store_packed4(char* p,
                     gint8<N> a, gint8<N> b, gint8<N> c, gint8<N> d)
{
    v_store_pack4(p, a, b, c, d);
}

// -----------------------------------------------------------------------------

inline void i_store_packed4(char* p,
                            gint16x8 a, gint16x8 b, gint16x8 c, gint16x8 d)
{
    p = detail::assume_aligned(p, 16);
#if SIMDPP_USE_NULL
    null::store_packed4(p, a, b, c, d);
#elif SIMDPP_USE_SSE2 || SIMDPP_USE_ALTIVEC
    mem_pack4(a, b, c, d);
    i_store(p, a);
    i_store(p+16, b);
    i_store(p+32, c);
    i_store(p+48, d);
#elif SIMDPP_USE_NEON
    uint16x8x4_t t;
    t.val[0] = a;
    t.val[1] = b;
    t.val[2] = c;
    t.val[3] = d;
    vst4q_u16(reinterpret_cast<uint16_t*>(p), t);
#endif
}

#if SIMDPP_USE_AVX2
inline void i_store_packed4(char* p,
                            gint16x16 a, gint16x16 b, gint16x16 c, gint16x16 d)
{
    v256_store_pack4(p, a, b, c, d);
}
#endif

template<unsigned N>
void i_store_packed4(char* p,
                     gint16<N> a, gint16<N> b, gint16<N> c, gint16<N> d)
{
    v_store_pack4(p, a, b, c, d);
}

// -----------------------------------------------------------------------------

inline void i_store_packed4(char* p,
                            gint32x4 a, gint32x4 b, gint32x4 c, gint32x4 d)
{
    p = detail::assume_aligned(p, 16);
#if SIMDPP_USE_NULL
    null::store_packed4(p, a, b, c, d);
#elif SIMDPP_USE_SSE2 || SIMDPP_USE_ALTIVEC
    mem_pack4(a, b, c, d);
    i_store(p, a);
    i_store(p+16, b);
    i_store(p+32, c);
    i_store(p+48, d);
#elif SIMDPP_USE_NEON
    uint32x4x4_t t;
    t.val[0] = a;
    t.val[1] = b;
    t.val[2] = c;
    t.val[3] = d;
    vst4q_u32(reinterpret_cast<uint32_t*>(p), t);
#endif
}

#if SIMDPP_USE_AVX2
inline void i_store_packed4(char* p,
                            gint32x8 a, gint32x8 b, gint32x8 c, gint32x8 d)
{
    v256_store_pack4(p, a, b, c, d);
}
#endif

template<unsigned N>
void i_store_packed4(char* p,
                     gint32<N> a, gint32<N> b, gint32<N> c, gint32<N> d)
{
    v_store_pack4(p, a, b, c, d);
}

// -----------------------------------------------------------------------------

inline void i_store_packed4(char* p,
                            gint64x2 a, gint64x2 b, gint64x2 c, gint64x2 d)
{
    p = detail::assume_aligned(p, 16);
    transpose2(a, b);
    transpose2(c, d);
    i_store(p, a);
    i_store(p+16, c);
    i_store(p+32, b);
    i_store(p+48, d);
}

#if SIMDPP_USE_AVX2
inline void i_store_packed4(char* p,
                            gint64x4 a, gint64x4 b, gint64x4 c, gint64x4 d)
{
    v256_store_pack4(p, a, b, c, d);
}
#endif

template<unsigned N>
void i_store_packed4(char* p,
                     gint64<N> a, gint64<N> b, gint64<N> c, gint64<N> d)
{
    v_store_pack4(p, a, b, c, d);
}

// -----------------------------------------------------------------------------

inline void i_store_packed4(char* p,
                            float32x4 a, float32x4 b, float32x4 c, float32x4 d)
{
    p = detail::assume_aligned(p, 16);
#if SIMDPP_USE_NULL
    null::store_packed4(p, a, b, c, d);
#elif SIMDPP_USE_SSE2 || SIMDPP_USE_ALTIVEC
    mem_pack4(a, b, c, d);
    i_store(p, a);
    i_store(p+16, b);
    i_store(p+32, c);
    i_store(p+48, d);
#elif SIMDPP_USE_NEON
    float32x4x4_t t;
    t.val[0] = a;
    t.val[1] = b;
    t.val[2] = c;
    t.val[3] = d;
    vst4q_f32(p, t);
#endif
}

#if SIMDPP_USE_AVX
inline void i_store_packed4(char* p,
                            float32x8 a, float32x8 b, float32x8 c, float32x8 d)
{
    v256_store_pack4(p, a, b, c, d);
}
#endif

template<unsigned N>
void i_store_packed4(char* p,
                     float32<N> a, float32<N> b, float32<N> c, float32<N> d)
{
    v_store_pack4(p, a, b, c, d);
}

// -----------------------------------------------------------------------------

inline void i_store_packed4(char* p,
                            float64x2 a, float64x2 b, float64x2 c, float64x2 d)
{
    p = detail::assume_aligned(p, 16);
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    null::store_packed4(p, a, b, c, d);
#elif SIMDPP_USE_SSE2
    mem_pack4(a, b, c, d);
    i_store(p, a);
    i_store(p+16, b);
    i_store(p+32, c);
    i_store(p+48, d);
#endif
}

#if SIMDPP_USE_AVX
inline void i_store_packed4(char* p,
                           float64x4 a, float64x4 b, float64x4 c, float64x4 d)
{
    v256_store_pack4(p, a, b, c, d);
}
#endif

template<unsigned N>
void i_store_packed4(char* p,
                     float64<N> a, float64<N> b, float64<N> c, float64<N> d)
{
    v_store_pack4(p, a, b, c, d);
}

// -----------------------------------------------------------------------------

template<class V>
void v256_store_pack4(char* p, V a, V b, V c, V d)
{
    p = detail::assume_aligned(p, 32);
    mem_pack4(a, b, c, d);
    i_store(p, a);
    i_store(p + 32, b);
    i_store(p + 64, c);
    i_store(p + 96, d);
}

template<class V>
void v_store_pack4(char* p, V a, V b, V c, V d)
{
    unsigned veclen = sizeof(typename V::base_vector_type);

    p = detail::assume_aligned(p, veclen);
    for (unsigned i = 0; i < V::vec_length; ++i) {
        i_store_packed4(p, a[i], b[i], c[i], d[i]);
        p += veclen*4;
    }
}

} // namespace insn
} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

