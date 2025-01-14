/*	$NetBSD: linux_misc_notalpha.c,v 1.113 2021/09/23 11:28:47 christos Exp $	*/

/*-
 * Copyright (c) 1995, 1998, 2008, 2020 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Frank van der Linden and Eric Haszlakiewicz; by Jason R. Thorpe
 * of the Numerical Aerospace Simulation Facility, NASA Ames Research Center.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: linux_misc_notalpha.c,v 1.113 2021/09/23 11:28:47 christos Exp $");

/*
 * Note that we must NOT include "opt_compat_linux32.h" here,
 * the maze of ifdefs below relies on COMPAT_LINUX32 only being
 * defined when this file is built for linux32.
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/mbuf.h>
#include <sys/namei.h>
#include <sys/proc.h>
#include <sys/prot.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/resourcevar.h>
#include <sys/time.h>
#include <sys/vfs_syscalls.h>
#include <sys/wait.h>
#include <sys/kauth.h>

#include <sys/syscallargs.h>

#include <compat/linux/common/linux_types.h>
#include <compat/linux/common/linux_fcntl.h>
#include <compat/linux/common/linux_misc.h>
#include <compat/linux/common/linux_mmap.h>
#include <compat/linux/common/linux_signal.h>
#include <compat/linux/common/linux_util.h>
#include <compat/linux/common/linux_ipc.h>
#include <compat/linux/common/linux_sem.h>
#include <compat/linux/common/linux_statfs.h>

#include <compat/linux/linux_syscallargs.h>

/*
 * This file contains routines which are used
 * on every linux architechture except the Alpha.
 */

/* Used on: arm, aarch64, i386, m68k, mips, ppc, sparc, sparc64 */
/* Not used on: alpha */

#ifdef DEBUG_LINUX
#define DPRINTF(a)	uprintf a
#else
#define DPRINTF(a)
#endif

#ifndef COMPAT_LINUX32
#if !defined(__aarch64__)
/*
 * Alarm. This is a libc call which uses setitimer(2) in NetBSD.
 * Do the same here.
 */
int
linux_sys_alarm(struct lwp *l, const struct linux_sys_alarm_args *uap, register_t *retval)
{
	/* {
		syscallarg(unsigned int) secs;
	} */
	struct proc *p = l->l_proc;
	struct itimerval itv, oitv;
	int error;

	timerclear(&itv.it_interval);
	itv.it_value.tv_sec = SCARG(uap, secs);
	itv.it_value.tv_usec = 0;
	if (itv.it_value.tv_sec < 0) {
		return EINVAL;
	}

	if ((error = dogetitimer(p, ITIMER_REAL, &oitv)) != 0) {
		return error;
	}
	if (oitv.it_value.tv_usec) {
		oitv.it_value.tv_sec++;
	}

	if ((error = dosetitimer(p, ITIMER_REAL, &itv)) != 0) {
		return error;
	}

	*retval = oitv.it_value.tv_sec;
	return 0;
}
#endif
#endif /* !COMPAT_LINUX32 */

#if !defined(__aarch64__) && !defined(__amd64__)
int
linux_sys_nice(struct lwp *l, const struct linux_sys_nice_args *uap, register_t *retval)
{
	/* {
		syscallarg(int) incr;
	} */
	struct proc *p = l->l_proc;
	struct sys_setpriority_args bsa;
	int error;

	SCARG(&bsa, which) = PRIO_PROCESS;
	SCARG(&bsa, who) = 0;
	SCARG(&bsa, prio) = p->p_nice - NZERO + SCARG(uap, incr);

	error = sys_setpriority(l, &bsa, retval);
	return (error) ? EPERM : 0;
}
#endif /* !__aarch64__ && !__amd64__ */

#ifndef COMPAT_LINUX32
#if !defined(__aarch64__) && !defined(__amd64__)
/*
 * The old Linux readdir was only able to read one entry at a time,
 * even though it had a 'count' argument. In fact, the emulation
 * of the old call was better than the original, because it did handle
 * the count arg properly. Don't bother with it anymore now, and use
 * it to distinguish between old and new. The difference is that the
 * newer one actually does multiple entries, and the reclen field
 * really is the reclen, not the namelength.
 */
int
linux_sys_readdir(struct lwp *l, const struct linux_sys_readdir_args *uap, register_t *retval)
{
	/* {
		syscallarg(int) fd;
		syscallarg(struct linux_dirent *) dent;
		syscallarg(unsigned int) count;
	} */
	int error;
	struct linux_sys_getdents_args da;

	SCARG(&da, fd) = SCARG(uap, fd);
	SCARG(&da, dent) = SCARG(uap, dent);
	SCARG(&da, count) = 1;

	error = linux_sys_getdents(l, &da, retval);
	if (error == 0 && *retval > 1)
		*retval = 1;

	return error;
}
#endif /* !aarch64 && !amd64 */

#if !defined(__aarch64__)
/*
 * I wonder why Linux has gettimeofday() _and_ time().. Still, we
 * need to deal with it.
 */
int
linux_sys_time(struct lwp *l, const struct linux_sys_time_args *uap, register_t *retval)
{
	/* {
		syscallarg(linux_time_t) *t;
	} */
	struct timeval atv;
	linux_time_t tt;
	int error;

	microtime(&atv);

	tt = atv.tv_sec;
	if (SCARG(uap, t) && (error = copyout(&tt, SCARG(uap, t), sizeof tt)))
		return error;

	retval[0] = tt;
	return 0;
}
#endif

#if !defined(__aarch64__)
/*
 * utime(). Do conversion to things that utimes() understands,
 * and pass it on.
 */
int
linux_sys_utime(struct lwp *l, const struct linux_sys_utime_args *uap, register_t *retval)
{
	/* {
		syscallarg(const char *) path;
		syscallarg(struct linux_utimbuf *)times;
	} */
	int error;
	struct timeval tv[2], *tvp;
	struct linux_utimbuf lut;

	if (SCARG(uap, times) != NULL) {
		if ((error = copyin(SCARG(uap, times), &lut, sizeof lut)))
			return error;
		tv[0].tv_usec = tv[1].tv_usec = 0;
		tv[0].tv_sec = lut.l_actime;
		tv[1].tv_sec = lut.l_modtime;
		tvp = tv;
	} else
		tvp = NULL;

	return do_sys_utimes(l, NULL, SCARG(uap, path), FOLLOW,
			   tvp,  UIO_SYSSPACE);
}
#endif

#if !defined(__aarch64__) && !defined(__amd64__)
/*
 * waitpid(2).  Just forward on to linux_sys_wait4 with a NULL rusage.
 */
int
linux_sys_waitpid(struct lwp *l, const struct linux_sys_waitpid_args *uap, register_t *retval)
{
	/* {
		syscallarg(int) pid;
		syscallarg(int *) status;
		syscallarg(int) options;
	} */
	struct linux_sys_wait4_args linux_w4a;

	SCARG(&linux_w4a, pid) = SCARG(uap, pid);
	SCARG(&linux_w4a, status) = SCARG(uap, status);
	SCARG(&linux_w4a, options) = SCARG(uap, options);
	SCARG(&linux_w4a, rusage) = NULL;

	return linux_sys_wait4(l, &linux_w4a, retval);
}
#endif /* !aarch64 && !amd64 */

int
linux_sys_setresgid(struct lwp *l, const struct linux_sys_setresgid_args *uap, register_t *retval)
{
	/* {
		syscallarg(gid_t) rgid;
		syscallarg(gid_t) egid;
		syscallarg(gid_t) sgid;
	} */

	/*
	 * Note: These checks are a little different than the NetBSD
	 * setregid(2) call performs.  This precisely follows the
	 * behavior of the Linux kernel.
	 */
	return do_setresgid(l, SCARG(uap,rgid), SCARG(uap, egid),
			    SCARG(uap, sgid),
			    ID_R_EQ_R | ID_R_EQ_E | ID_R_EQ_S |
			    ID_E_EQ_R | ID_E_EQ_E | ID_E_EQ_S |
			    ID_S_EQ_R | ID_S_EQ_E | ID_S_EQ_S );
}

int
linux_sys_getresgid(struct lwp *l, const struct linux_sys_getresgid_args *uap, register_t *retval)
{
	/* {
		syscallarg(gid_t *) rgid;
		syscallarg(gid_t *) egid;
		syscallarg(gid_t *) sgid;
	} */
	kauth_cred_t pc = l->l_cred;
	int error;
	gid_t gid;

	/*
	 * Linux copies these values out to userspace like so:
	 *
	 *	1. Copy out rgid.
	 *	2. If that succeeds, copy out egid.
	 *	3. If both of those succeed, copy out sgid.
	 */
	gid = kauth_cred_getgid(pc);
	if ((error = copyout(&gid, SCARG(uap, rgid), sizeof(gid_t))) != 0)
		return (error);

	gid = kauth_cred_getegid(pc);
	if ((error = copyout(&gid, SCARG(uap, egid), sizeof(gid_t))) != 0)
		return (error);

	gid = kauth_cred_getsvgid(pc);

	return (copyout(&gid, SCARG(uap, sgid), sizeof(gid_t)));
}

#if !defined(__aarch64__) && !defined(__amd64__)
/*
 * I wonder why Linux has settimeofday() _and_ stime().. Still, we
 * need to deal with it.
 */
int
linux_sys_stime(struct lwp *l, const struct linux_sys_stime_args *uap, register_t *retval)
{
	/* {
		syscallarg(linux_time_t) *t;
	} */
	struct timespec ats;
	linux_time_t tt;
	int error;

	if ((error = copyin(SCARG(uap, t), &tt, sizeof tt)) != 0)
		return error;

	ats.tv_sec = tt;
	ats.tv_nsec = 0;

	if ((error = settime(l->l_proc, &ats)))
		return (error);

	return 0;
}

/*
 * Implement the fs stat functions. Straightforward.
 */
int
linux_sys_statfs64(struct lwp *l, const struct linux_sys_statfs64_args *uap, register_t *retval)
{
	/* {
		syscallarg(const char *) path;
		syscallarg(size_t) sz;
		syscallarg(struct linux_statfs64 *) sp;
	} */
	struct statvfs *sb;
	struct linux_statfs64 ltmp;
	int error;

	if (SCARG(uap, sz) != sizeof ltmp)
		return (EINVAL);

	sb = STATVFSBUF_GET();
	error = do_sys_pstatvfs(l, SCARG(uap, path), ST_WAIT, sb);
	if (error == 0) {
		bsd_to_linux_statfs64(sb, &ltmp);
		error = copyout(&ltmp, SCARG(uap, sp), sizeof ltmp);
	}
	STATVFSBUF_PUT(sb);
	return error;
}

int
linux_sys_fstatfs64(struct lwp *l, const struct linux_sys_fstatfs64_args *uap, register_t *retval)
{
	/* {
		syscallarg(int) fd;
		syscallarg(size_t) sz;
		syscallarg(struct linux_statfs64 *) sp;
	} */
	struct statvfs *sb;
	struct linux_statfs64 ltmp;
	int error;

	if (SCARG(uap, sz) != sizeof ltmp)
		return (EINVAL);

	sb = STATVFSBUF_GET();
	error = do_sys_fstatvfs(l, SCARG(uap, fd), ST_WAIT, sb);
	if (error == 0) {
		bsd_to_linux_statfs64(sb, &ltmp);
		error = copyout(&ltmp, SCARG(uap, sp), sizeof ltmp);
	}
	STATVFSBUF_PUT(sb);
	return error;
}
#endif /* !aarch64 && !__amd64__ */
#endif /* !COMPAT_LINUX32 */
