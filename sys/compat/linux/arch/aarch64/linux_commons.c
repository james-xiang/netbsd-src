/*	$NetBSD: linux_commons.c,v 1.2 2021/10/12 08:36:28 andvar Exp $	*/

/*
 * This file includes C files from the common
 * area to decrease the number of files to compile
 * in order to make building a kernel go faster.
 *
 * Option headers and headers which depend on
 * certain options being set need to be included
 * here.  This ensures that a header file sees
 * the options it needs even if one of included
 * C files doesn't use it.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: linux_commons.c,v 1.2 2021/10/12 08:36:28 andvar Exp $");

#if defined(_KERNEL_OPT)
#include "opt_sysv.h"
#endif

#include <sys/param.h>
#include <sys/mount.h>
#include <sys/signal.h>
#include <sys/syscallargs.h>

#include <compat/linux/common/linux_signal.h>
#include <compat/linux/common/linux_types.h>
#include <compat/linux/common/linux_ipc.h>
#include <compat/linux/common/linux_sem.h>

#include <compat/linux/linux_syscallargs.h>

#include "../../common/linux_pipe.c"
#include "../../common/linux_file64.c"
#include "../../common/linux_misc_notalpha.c"
#include "../../common/linux_fadvise64.c"
