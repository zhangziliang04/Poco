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

#ifndef __CRYSTAX_H_4289218d55ff4e74825922c1ca65eaf3
#define __CRYSTAX_H_4289218d55ff4e74825922c1ca65eaf3

#include <crystax/id.h>
#include <crystax/ctassert.h>

#include <sys/cdefs.h>
#include <jni.h>

__BEGIN_DECLS

int crystax_jni_on_load(JavaVM *vm);
void crystax_jni_on_unload(JavaVM *vm);

/*
 * Return pointer to application's Java VM.
 * Return NULL if there is no JVM (standalone executable)
 */
JavaVM *crystax_jvm();

/*
 * Return thread-specific JNIEnv pointer.
 * Return NULL if there is no JVM (standalone executable)
 */
JNIEnv *crystax_jnienv();

/*
 * Save specified JNIEnv to thread-specific storage.
 * This value will then be returned on subsequent calls
 * of crystax_jnienv()
 */
void crystax_save_jnienv(JNIEnv *env);

__END_DECLS

#endif /* __CRYSTAX_H_4289218d55ff4e74825922c1ca65eaf3 */
