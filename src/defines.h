// MIT License

// Copyright (c) 2017 Vadim Grigoruk @nesbox // grigoruk@gmail.com

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#define COUNT_OF(x)         ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#define MIN(a,b)            ((a) < (b) ? (a) : (b))
#define MAX(a,b)            ((a) > (b) ? (a) : (b))
#define CLAMP(v,a,b)        (MIN(MAX(v,a),b))
#define SWAP(a, b, type)    do { type temp = a; a = b; b = temp; } while (0)
#define ZEROMEM(p)          memset(&p, 0, sizeof p)
#define MOVE(...)           memmove(malloc(sizeof __VA_ARGS__), &__VA_ARGS__, sizeof __VA_ARGS__)
#define DEF2STR2(x)         #x
#define DEF2STR(x)          DEF2STR2(x)
#define STRLEN(str)         (sizeof str - 1)
#define CONCAT2(a, b)       a ## b
#define CONCAT(a, b)        CONCAT2(a, b)
#define MACROVAR(name)      CONCAT(name, __LINE__)
#define DEFER(start, end)  	for(start, *MACROVAR(_i_) = NULL; !MACROVAR(_i_); ++MACROVAR(_i_), end)
#define SCOPE(exp)          for(int MACROVAR(_i_) = 0; !MACROVAR(_i_); ++MACROVAR(_i_), exp)
#define FOR(type,it,list)   for(type it = list, *MACROVAR(_end_) = it + COUNT_OF(list); it != MACROVAR(_end_); ++it)
#define RFOR(type,it,list)  for(type it = list + (COUNT_OF(list) - 1), *MACROVAR(_end_) = list; it >= MACROVAR(_end_); --it)
#define FREE(ptr)           do { if(ptr) free(ptr); } while (0)

#define BITSET(a,b)         ((a) | (1ULL<<(b)))
#define BITCLEAR(a,b)       ((a) & ~(1ULL<<(b)))
#define BITFLIP(a,b)        ((a) ^ (1ULL<<(b)))
#define BITCHECK(a,b)       (!!((a) & (1ULL<<(b))))
#define _BITSET(a,b)        ((a) |= (1ULL<<(b)))
#define _BITCLEAR(a,b)      ((a) &= ~(1ULL<<(b)))
#define _BITFLIP(a,b)       ((a) ^= (1ULL<<(b)))
