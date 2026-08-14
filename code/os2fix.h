/*
 * os2fix.h - Force-included first in every TU via -include to neutralize
 * legacy OS/2 memory-model keywords that GCC 9 no longer recognises.
 *
 * Do NOT define _cdecl or _System; GCC 9 already defines those as
 * built-ins and redefining them produces harmless but noisy warnings.
 */

#ifndef _54321_OS2FIX_H_
#define _54321_OS2FIX_H_

#ifndef _FAR_
#define _FAR_
#endif
#ifndef _far
#define _far
#endif
#ifndef _near
#define _near
#endif
#ifndef _huge
#define _huge
#endif

#endif /* _54321_OS2FIX_H_ */
