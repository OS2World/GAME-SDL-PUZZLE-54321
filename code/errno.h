/*
 * errno.h - Shadow of the system errno.h for OS/2 GCC 9.
 *
 * The system C:/usr/include/errno.h has no include guards and declares:
 *   extern int _near _cdecl volatile errno;
 * GCC's include-fixed stdlib.h already defines errno as (*_errno()) via a
 * macro, so the variable declaration expands to a conflicting type.
 *
 * Intercepted via -I $(CODE) (searched before system directories).
 */

#ifndef _54321_ERRNO_H_
#define _54321_ERRNO_H_

#ifndef errno
extern int * _errno(void);
#define errno (*_errno())
#endif

#ifndef EPERM
#define EPERM         1
#define ENOENT        2
#define ESRCH         3
#define EINTR         4
#define EIO           5
#define ENXIO         6
#define E2BIG         7
#define ENOEXEC       8
#define EBADF         9
#define ECHILD       10
#define EAGAIN       11
#define ENOMEM       12
#define EACCES       13
#define EFAULT       14
#define EBUSY        16
#define EEXIST       17
#define EXDEV        18
#define ENODEV       19
#define ENOTDIR      20
#define EISDIR       21
#define EINVAL       22
#define ENFILE       23
#define EMFILE       24
#define ENOTTY       25
#define EFBIG        27
#define ENOSPC       28
#define ESPIPE       29
#define EROFS        30
#define EMLINK       31
#define EPIPE        32
#define EDOM         33
#define ERANGE       34
#define EDEADLK      36
#define ENAMETOOLONG 38
#define ENOLCK       39
#define ENOSYS       40
#define ENOTEMPTY    41
#define ELOOP        114
#define ENOTSUP      129
#endif /* EPERM */

#endif /* _54321_ERRNO_H_ */
