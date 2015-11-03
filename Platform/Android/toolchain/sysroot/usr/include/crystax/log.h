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

#ifndef __CRYSTAX_INCLUDE_CRYSTAX_LOG_H_465350AFAEF0438E893862FF11F27853
#define __CRYSTAX_INCLUDE_CRYSTAX_LOG_H_465350AFAEF0438E893862FF11F27853

#include <crystax/id.h>
#include <sys/cdefs.h>
#include <stdlib.h> /* for abort() */
#include <inttypes.h>
#include <android/log.h>

#ifndef CRYSTAX_DEBUG
#define CRYSTAX_DEBUG 0
#endif

#define CRYSTAX_LOGLEVEL_DBUG ANDROID_LOG_DEBUG
#define CRYSTAX_LOGLEVEL_INFO ANDROID_LOG_INFO
#define CRYSTAX_LOGLEVEL_WARN ANDROID_LOG_WARN
#define CRYSTAX_LOGLEVEL_ERRO ANDROID_LOG_ERROR
#define CRYSTAX_LOGLEVEL_PANI ANDROID_LOG_FATAL

#define CRYSTAX_LEVEL_TAG(level) "CRYSTAX_" #level
#define CRYSTAX_LEVEL_VAL(level) CRYSTAX_LOGLEVEL_ ## level

#if CRYSTAX_DEBUG

#include <pthread.h>

#   define CRYSTAX_LOG(level, fmt, ...) \
        __crystax_log(CRYSTAX_LEVEL_VAL(level), \
                CRYSTAX_LEVEL_TAG(level), \
                "[%08x] ...%s:%-5d: %-15s: " fmt, \
                (unsigned)pthread_self(), \
                __crystax_log_short_file(__FILE__), __LINE__, \
                __FUNCTION__, ##__VA_ARGS__)

#define CRYSTAX_DBG(fmt, ...) CRYSTAX_LOG(DBUG, fmt, ##__VA_ARGS__)

#else /* !CRYSTAX_DEBUG */

#   define CRYSTAX_LOG(level, fmt, ...) \
        __crystax_log(CRYSTAX_LEVEL_VAL(level), \
                CRYSTAX_LEVEL_TAG(level), \
                fmt, ##__VA_ARGS__)

#define CRYSTAX_DBG(...) do {} while (0)

#endif /* !CRYSTAX_DEBUG */

#define CRYSTAX_INFO(fmt, ...)  CRYSTAX_LOG(INFO, fmt, ##__VA_ARGS__)
#define CRYSTAX_WARN(fmt, ...)  CRYSTAX_LOG(WARN, fmt, ##__VA_ARGS__)
#define CRYSTAX_ERR(fmt, ...)   CRYSTAX_LOG(ERRO, fmt, ##__VA_ARGS__)
#define CRYSTAX_PANIC(fmt, ...) \
    do { \
        CRYSTAX_LOG(PANI, fmt, ##__VA_ARGS__); \
        abort(); \
    } while (0)

#define CRYSTAX_TRACE CRYSTAX_DBG("*** TRACE")

__BEGIN_DECLS

const char *__crystax_log_short_file(const char *f);
int __crystax_log(int prio, const char *tag,  const char *fmt, ...) __attribute__ ((format(printf, 3, 4)));

__END_DECLS

#if defined(__cplusplus) && CRYSTAX_DEBUG

namespace crystax
{
class call_frame_tracer
{
public:
    call_frame_tracer(const char *f, int l, const char *fn)
        :file(f), line(l), function(fn)
    {
        __crystax_log(CRYSTAX_LEVEL_VAL(DBUG), CRYSTAX_LEVEL_TAG(DBUG),
                "[%08x] ...%s:%-5d: %-15s: *** ENTER",
                (unsigned)::pthread_self(),
                __crystax_log_short_file(file), line, function);
    }

    ~call_frame_tracer()
    {
        __crystax_log(CRYSTAX_LEVEL_VAL(DBUG), CRYSTAX_LEVEL_TAG(DBUG),
                "[%08x] ...%s:%-5d: %-15s: *** LEAVE",
                (unsigned)::pthread_self(),
                __crystax_log_short_file(file), line, function);
    }

private:
    const char *file;
    int line;
    const char *function;
};
} // namespace crystax

#define CRYSTAX_FRAME_TRACER ::crystax::call_frame_tracer call_frame_tracer_obj_ ## __LINE (__FILE__, __LINE__, __FUNCTION__);

#else /* defined(__cplusplus) && CRYSTAX_DEBUG */

#define CRYSTAX_FRAME_TRACER CRYSTAX_DBG("ENTER")

#endif /* defined(__cplusplus) && CRYSTAX_DEBUG */

#if CRYSTAX_LOG_DEFINE_SHORT_MACROS
#define DBG(fmt, ...)   CRYSTAX_DBG(  fmt, ##__VA_ARGS__)
#define INFO(fmt, ...)  CRYSTAX_INFO( fmt, ##__VA_ARGS__)
#define WARN(fmt, ...)  CRYSTAX_WARN( fmt, ##__VA_ARGS__)
#define ERR(fmt, ...)   CRYSTAX_ERR(  fmt, ##__VA_ARGS__)
#define PANIC(fmt, ...) CRYSTAX_PANIC(fmt, ##__VA_ARGS__)

#define TRACE CRYSTAX_TRACE
#define FRAME_TRACER CRYSTAX_FRAME_TRACER
#endif /* CRYSTAX_LOG_DEFINE_SHORT_MACROS */

#endif /* __CRYSTAX_INCLUDE_CRYSTAX_LOG_H_465350AFAEF0438E893862FF11F27853 */
