/* ctype.h - Shadow header for ArcaOS/EMX
 *
 * The EMX <ctype.h> macros reference the __ctype symbol which wlink
 * cannot resolve from the C runtime import library.  This shadow provides
 * the same functionality using simple character arithmetic.
 *
 * Intercepted via -I $(CODE) in CFLAGS.
 */
#ifndef _54321_CTYPE_H_
#define _54321_CTYPE_H_

#define isdigit(c)  ((unsigned char)(c) >= '0' && (unsigned char)(c) <= '9')
#define islower(c)  ((unsigned char)(c) >= 'a' && (unsigned char)(c) <= 'z')
#define isupper(c)  ((unsigned char)(c) >= 'A' && (unsigned char)(c) <= 'Z')
#define isalpha(c)  (isupper(c) || islower(c))
#define isalnum(c)  (isdigit(c) || isalpha(c))
#define isspace(c)  ((unsigned char)(c) == ' '  || \
                     (unsigned char)(c) == '\t' || \
                     (unsigned char)(c) == '\n' || \
                     (unsigned char)(c) == '\r' || \
                     (unsigned char)(c) == '\f' || \
                     (unsigned char)(c) == '\v')
#define isprint(c)  ((unsigned char)(c) >= ' ' && (unsigned char)(c) <= '~')
#define iscntrl(c)  (((unsigned char)(c) >= 0 && (unsigned char)(c) <= 31) || \
                     (unsigned char)(c) == 127)
#define isxdigit(c) (isdigit(c) || \
                     ((unsigned char)(c) >= 'A' && (unsigned char)(c) <= 'F') || \
                     ((unsigned char)(c) >= 'a' && (unsigned char)(c) <= 'f'))
#define ispunct(c)  (isprint(c) && !isalnum(c) && !isspace(c))
#define isgraph(c)  (isprint(c) && !isspace(c))
#define isblank(c)  ((unsigned char)(c) == ' ' || (unsigned char)(c) == '\t')

#define tolower(c)  (isupper(c) ? (int)((unsigned char)(c) - 'A' + 'a') : (int)(c))
#define toupper(c)  (islower(c) ? (int)((unsigned char)(c) - 'a' + 'A') : (int)(c))

#endif /* _54321_CTYPE_H_ */
