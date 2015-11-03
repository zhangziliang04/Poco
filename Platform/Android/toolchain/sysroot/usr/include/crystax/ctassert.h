/*
 * Copyright (c) 2011-2014 CrystaX .NET.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY CrystaX .NET ''AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL CrystaX .NET OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of CrystaX .NET.
 */

#ifndef __CRYSTAX_INCLUDE_CTASSERT_H_1B0DC71F4E814FBC907BDB0132B91BBC
#define __CRYSTAX_INCLUDE_CTASSERT_H_1B0DC71F4E814FBC907BDB0132B91BBC

#include <crystax/id.h>

#ifndef __CRYSTAX_STATIC_ASSERT
# if defined(__cplusplus) && __cplusplus >= 201103L
#  define __CRYSTAX_STATIC_ASSERT(cond, message) static_assert(cond, message)
# else
#  define __CRYSTAX_STATIC_ASSERT(cond, message) __CRYSTAX_STATIC_ASSERT_IMPL(cond, __COUNTER__)
#  define __CRYSTAX_STATIC_ASSERT_IMPL(x, y)     __CRYSTAX_STATIC_ASSERT_IMPL2(x, y)
#  define __CRYSTAX_STATIC_ASSERT_IMPL2(x, y)    typedef char __crystax_static_assert ## y[(x) ? 1 : -1]
# endif
#endif

#endif /* __CRYSTAX_INCLUDE_CTASSERT_H_1B0DC71F4E814FBC907BDB0132B91BBC */
