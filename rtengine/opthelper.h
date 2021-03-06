////////////////////////////////////////////////////////////////
//
//  opthelper.h includes some #defines which help to make optimizations easier and better readable
//
//  copyright (c) 2013  Ingo Weyrich
//
//  this is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////

#ifndef OPTHELPER_H
    #define OPTHELPER_H

    #define pow_F(a,b) (xexpf(b*xlogf(a)))

    #ifdef __SSE2__
        #include "sleefsseavx.c"
    #endif

    #ifdef __GNUC__
        #define RESTRICT    __restrict__
        #if __SIZEOF_POINTER__ == 4 &&  __GNUC__ >= 7 // there seems to be a bug with __builtin_expect on 32bit systems when using gcc >= 7
            #define LIKELY(x)    (x)
            #define UNLIKELY(x)  (x)
        #else
            #define LIKELY(x)   __builtin_expect (!!(x), 1)
            #define UNLIKELY(x) __builtin_expect (!!(x), 0)
        #endif
        #define ALIGNED64 __attribute__ ((aligned (64)))
        #define ALIGNED16 __attribute__ ((aligned (16)))
    #else
        #define RESTRICT
        #define LIKELY(x)    (x)
        #define UNLIKELY(x)  (x)
        #define ALIGNED64
        #define ALIGNED16
    #endif
#endif
