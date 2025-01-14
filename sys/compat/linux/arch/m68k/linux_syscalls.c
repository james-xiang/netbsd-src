/* $NetBSD: linux_syscalls.c,v 1.112 2021/09/20 02:20:31 thorpej Exp $ */

/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	NetBSD: syscalls.master,v 1.99 2021/09/20 02:20:02 thorpej Exp
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: linux_syscalls.c,v 1.112 2021/09/20 02:20:31 thorpej Exp $");

#if defined(_KERNEL_OPT)
#if defined(_KERNEL_OPT)
#include "opt_compat_netbsd.h"
#include "opt_compat_43.h"
#endif
#include <sys/param.h>
#include <sys/poll.h>
#include <sys/systm.h>
#include <sys/signal.h>
#include <sys/mount.h>
#include <sys/sched.h>
#include <sys/syscallargs.h>
#include <compat/linux/common/linux_types.h>
#include <compat/linux/common/linux_signal.h>
#include <compat/linux/common/linux_siginfo.h>
#include <compat/linux/common/linux_machdep.h>
#include <compat/linux/common/linux_mmap.h>
#include <compat/linux/linux_syscallargs.h>
#else /* _KERNEL_OPT */
#include <sys/null.h>
#endif /* _KERNEL_OPT */

const char *const linux_syscallnames[] = {
	/*   0 */	"syscall",
	/*   1 */	"exit",
	/*   2 */	"fork",
	/*   3 */	"read",
	/*   4 */	"write",
	/*   5 */	"open",
	/*   6 */	"close",
	/*   7 */	"waitpid",
	/*   8 */	"creat",
	/*   9 */	"link",
	/*  10 */	"unlink",
	/*  11 */	"execve",
	/*  12 */	"chdir",
	/*  13 */	"time",
	/*  14 */	"mknod",
	/*  15 */	"chmod",
	/*  16 */	"chown16",
	/*  17 */	"#17 (obsolete break)",
	/*  18 */	"#18 (obsolete ostat)",
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  19 */	"lseek",
#else
	/*  19 */	"#19 (unimplemented compat_43_sys_lseek)",
#endif
	/*  20 */	"getpid",
	/*  21 */	"#21 (unimplemented mount)",
	/*  22 */	"#22 (obsolete umount)",
	/*  23 */	"linux_setuid16",
	/*  24 */	"linux_getuid16",
	/*  25 */	"stime",
	/*  26 */	"ptrace",
	/*  27 */	"alarm",
	/*  28 */	"#28 (obsolete ofstat)",
	/*  29 */	"pause",
	/*  30 */	"utime",
	/*  31 */	"#31 (obsolete stty)",
	/*  32 */	"#32 (obsolete gtty)",
	/*  33 */	"access",
	/*  34 */	"nice",
	/*  35 */	"#35 (obsolete ftime)",
	/*  36 */	"sync",
	/*  37 */	"kill",
	/*  38 */	"__posix_rename",
	/*  39 */	"mkdir",
	/*  40 */	"rmdir",
	/*  41 */	"dup",
	/*  42 */	"pipe",
	/*  43 */	"times",
	/*  44 */	"#44 (obsolete prof)",
	/*  45 */	"brk",
	/*  46 */	"linux_setgid16",
	/*  47 */	"linux_getgid16",
	/*  48 */	"signal",
	/*  49 */	"linux_geteuid16",
	/*  50 */	"linux_getegid16",
	/*  51 */	"acct",
	/*  52 */	"#52 (unimplemented umount)",
	/*  53 */	"#53 (obsolete lock)",
	/*  54 */	"ioctl",
	/*  55 */	"fcntl",
	/*  56 */	"#56 (obsolete mpx)",
	/*  57 */	"setpgid",
	/*  58 */	"#58 (obsolete ulimit)",
	/*  59 */	"#59 (unimplemented oldolduname)",
	/*  60 */	"umask",
	/*  61 */	"chroot",
	/*  62 */	"#62 (unimplemented ustat)",
	/*  63 */	"dup2",
	/*  64 */	"getppid",
	/*  65 */	"getpgrp",
	/*  66 */	"setsid",
	/*  67 */	"sigaction",
	/*  68 */	"siggetmask",
	/*  69 */	"sigsetmask",
	/*  70 */	"setreuid16",
	/*  71 */	"setregid16",
	/*  72 */	"sigsuspend",
	/*  73 */	"sigpending",
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  74 */	"sethostname",
#else
	/*  74 */	"#74 (unimplemented compat_43_sys_sethostname)",
#endif
	/*  75 */	"setrlimit",
	/*  76 */	"getrlimit",
	/*  77 */	"getrusage",
	/*  78 */	"gettimeofday",
	/*  79 */	"settimeofday",
	/*  80 */	"getgroups16",
	/*  81 */	"setgroups16",
	/*  82 */	"oldselect",
	/*  83 */	"symlink",
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  84 */	"oolstat",
#else
	/*  84 */	"#84 (unimplemented compat_43_sys_lstat)",
#endif
	/*  85 */	"readlink",
#ifdef EXEC_AOUT
	/*  86 */	"uselib",
#else
	/*  86 */	"#86 (unimplemented sys_uselib)",
#endif
	/*  87 */	"swapon",
	/*  88 */	"reboot",
	/*  89 */	"readdir",
	/*  90 */	"old_mmap",
	/*  91 */	"munmap",
	/*  92 */	"truncate",
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  93 */	"ftruncate",
#else
	/*  93 */	"#93 (unimplemented compat_43_sys_ftruncate)",
#endif
	/*  94 */	"fchmod",
	/*  95 */	"fchown16",
	/*  96 */	"getpriority",
	/*  97 */	"setpriority",
	/*  98 */	"profil",
	/*  99 */	"statfs",
	/* 100 */	"fstatfs",
	/* 101 */	"#101 (unimplemented ioperm)",
	/* 102 */	"socketcall",
	/* 103 */	"#103 (unimplemented syslog)",
	/* 104 */	"setitimer",
	/* 105 */	"getitimer",
	/* 106 */	"stat",
	/* 107 */	"lstat",
	/* 108 */	"fstat",
	/* 109 */	"#109 (unimplemented olduname)",
	/* 110 */	"#110 (unimplemented iopl)",
	/* 111 */	"#111 (unimplemented vhangup)",
	/* 112 */	"#112 (unimplemented idle)",
	/* 113 */	"#113 (unimplemented vm86old)",
	/* 114 */	"wait4",
	/* 115 */	"swapoff",
	/* 116 */	"sysinfo",
	/* 117 */	"ipc",
	/* 118 */	"fsync",
	/* 119 */	"sigreturn",
	/* 120 */	"clone",
	/* 121 */	"setdomainname",
	/* 122 */	"uname",
	/* 123 */	"cacheflush",
	/* 124 */	"#124 (unimplemented adjtimex)",
	/* 125 */	"mprotect",
	/* 126 */	"sigprocmask",
	/* 127 */	"#127 (unimplemented create_module)",
	/* 128 */	"#128 (unimplemented init_module)",
	/* 129 */	"#129 (unimplemented delete_module)",
	/* 130 */	"#130 (unimplemented get_kernel_syms)",
	/* 131 */	"#131 (unimplemented quotactl)",
	/* 132 */	"getpgid",
	/* 133 */	"fchdir",
	/* 134 */	"#134 (unimplemented bdflush)",
	/* 135 */	"#135 (unimplemented sysfs)",
	/* 136 */	"personality",
	/* 137 */	"#137 (unimplemented afs_syscall)",
	/* 138 */	"linux_setfsuid16",
	/* 139 */	"linux_setfsgid16",
	/* 140 */	"llseek",
	/* 141 */	"getdents",
	/* 142 */	"select",
	/* 143 */	"flock",
	/* 144 */	"__msync13",
	/* 145 */	"readv",
	/* 146 */	"writev",
	/* 147 */	"getsid",
	/* 148 */	"fdatasync",
	/* 149 */	"__sysctl",
	/* 150 */	"mlock",
	/* 151 */	"munlock",
	/* 152 */	"mlockall",
	/* 153 */	"munlockall",
	/* 154 */	"sched_setparam",
	/* 155 */	"sched_getparam",
	/* 156 */	"sched_setscheduler",
	/* 157 */	"sched_getscheduler",
	/* 158 */	"sched_yield",
	/* 159 */	"sched_get_priority_max",
	/* 160 */	"sched_get_priority_min",
	/* 161 */	"#161 (unimplemented sched_rr_get_interval)",
	/* 162 */	"nanosleep",
	/* 163 */	"mremap",
	/* 164 */	"setresuid16",
	/* 165 */	"getresuid16",
	/* 166 */	"#166 (unimplemented vm86)",
	/* 167 */	"#167 (unimplemented query_module)",
	/* 168 */	"poll",
	/* 169 */	"#169 (unimplemented nfsservctl)",
	/* 170 */	"setresgid16",
	/* 171 */	"getresgid16",
	/* 172 */	"#172 (unimplemented prctl)",
	/* 173 */	"rt_sigreturn",
	/* 174 */	"rt_sigaction",
	/* 175 */	"rt_sigprocmask",
	/* 176 */	"rt_sigpending",
	/* 177 */	"rt_sigtimedwait",
	/* 178 */	"rt_queueinfo",
	/* 179 */	"rt_sigsuspend",
	/* 180 */	"pread",
	/* 181 */	"pwrite",
	/* 182 */	"lchown16",
	/* 183 */	"__getcwd",
	/* 184 */	"#184 (unimplemented capget)",
	/* 185 */	"#185 (unimplemented capset)",
	/* 186 */	"sigaltstack",
	/* 187 */	"#187 (unimplemented sendfile)",
	/* 188 */	"#188 (unimplemented getpmsg)",
	/* 189 */	"#189 (unimplemented putpmsg)",
	/* 190 */	"__vfork14",
	/* 191 */	"ugetrlimit",
#define linux_sys_mmap2_args linux_sys_mmap_args
	/* 192 */	"mmap2",
	/* 193 */	"truncate64",
	/* 194 */	"ftruncate64",
	/* 195 */	"stat64",
	/* 196 */	"lstat64",
	/* 197 */	"fstat64",
	/* 198 */	"__posix_chown",
	/* 199 */	"getuid",
	/* 200 */	"getgid",
	/* 201 */	"geteuid",
	/* 202 */	"getegid",
	/* 203 */	"setreuid",
	/* 204 */	"setregid",
	/* 205 */	"getgroups",
	/* 206 */	"setgroups",
	/* 207 */	"__posix_fchown",
	/* 208 */	"setresuid",
	/* 209 */	"getresuid",
	/* 210 */	"setresgid",
	/* 211 */	"getresgid",
	/* 212 */	"__posix_lchown",
	/* 213 */	"setuid",
	/* 214 */	"setgid",
	/* 215 */	"setfsuid",
	/* 216 */	"setfsgid",
	/* 217 */	"#217 (unimplemented / * unused * /)",
	/* 218 */	"#218 (unimplemented / * unused * /)",
	/* 219 */	"#219 (unimplemented / * unused * /)",
	/* 220 */	"getdents64",
	/* 221 */	"gettid",
	/* 222 */	"tkill",
	/* 223 */	"setxattr",
	/* 224 */	"lsetxattr",
	/* 225 */	"fsetxattr",
	/* 226 */	"getxattr",
	/* 227 */	"lgetxattr",
	/* 228 */	"fgetxattr",
	/* 229 */	"listxattr",
	/* 230 */	"llistxattr",
	/* 231 */	"flistxattr",
	/* 232 */	"removexattr",
	/* 233 */	"lremovexattr",
	/* 234 */	"fremovexattr",
	/* 235 */	"futex",
	/* 236 */	"#236 (unimplemented sendfile64)",
	/* 237 */	"mincore",
	/* 238 */	"madvise",
	/* 239 */	"fcntl64",
	/* 240 */	"#240 (unimplemented readahead)",
	/* 241 */	"#241 (unimplemented io_setup)",
	/* 242 */	"#242 (unimplemented io_destroy)",
	/* 243 */	"#243 (unimplemented io_getevents)",
	/* 244 */	"#244 (unimplemented io_submit)",
	/* 245 */	"#245 (unimplemented io_cancel)",
	/* 246 */	"fadvise64",
	/* 247 */	"#247 (unimplemented exit_group)",
	/* 248 */	"#248 (unimplemented lookup_dcookie)",
	/* 249 */	"#249 (unimplemented epoll_create)",
	/* 250 */	"#250 (unimplemented epoll_ctl)",
	/* 251 */	"#251 (unimplemented epoll_wait)",
	/* 252 */	"#252 (unimplemented remap_file_pages)",
	/* 253 */	"set_tid_address",
	/* 254 */	"timer_create",
	/* 255 */	"timer_settime",
	/* 256 */	"timer_gettime",
	/* 257 */	"timer_getoverrun",
	/* 258 */	"timer_delete",
	/* 259 */	"clock_settime",
	/* 260 */	"clock_gettime",
	/* 261 */	"clock_getres",
	/* 262 */	"clock_nanosleep",
	/* 263 */	"statfs64",
	/* 264 */	"fstatfs64",
	/* 265 */	"tgkill",
	/* 266 */	"utimes",
	/* 267 */	"fadvise64_64",
	/* 268 */	"#268 (unimplemented mbind)",
	/* 269 */	"#269 (unimplemented get_mempolicy)",
	/* 270 */	"#270 (unimplemented set_mempolicy)",
	/* 271 */	"#271 (unimplemented mq_open)",
	/* 272 */	"#272 (unimplemented mq_unlink)",
	/* 273 */	"#273 (unimplemented mq_timedsend)",
	/* 274 */	"#274 (unimplemented mq_timedreceive)",
	/* 275 */	"#275 (unimplemented mq_notify)",
	/* 276 */	"#276 (unimplemented mq_getsetattr)",
	/* 277 */	"#277 (unimplemented waitid)",
	/* 278 */	"#278 (unimplemented vserver)",
	/* 279 */	"#279 (unimplemented add_key)",
	/* 280 */	"#280 (unimplemented request_key)",
	/* 281 */	"#281 (unimplemented keyctl)",
	/* 282 */	"#282 (unimplemented ioprio_set)",
	/* 283 */	"#283 (unimplemented ioprio_get)",
	/* 284 */	"#284 (unimplemented inotify_init)",
	/* 285 */	"#285 (unimplemented inotify_add_watch)",
	/* 286 */	"#286 (unimplemented inotify_rm_watch)",
	/* 287 */	"#287 (unimplemented migrate_pages)",
	/* 288 */	"openat",
	/* 289 */	"mkdirat",
	/* 290 */	"mknodat",
	/* 291 */	"fchownat",
	/* 292 */	"#292 (unimplemented futimesat)",
	/* 293 */	"fstatat64",
	/* 294 */	"unlinkat",
	/* 295 */	"renameat",
	/* 296 */	"linkat",
	/* 297 */	"symlinkat",
	/* 298 */	"readlinkat",
	/* 299 */	"fchmodat",
	/* 300 */	"faccessat",
	/* 301 */	"pselect6",
	/* 302 */	"ppoll",
	/* 303 */	"#303 (unimplemented unshare)",
	/* 304 */	"__futex_set_robust_list",
	/* 305 */	"__futex_get_robust_list",
	/* 306 */	"#306 (unimplemented splice)",
	/* 307 */	"#307 (unimplemented sync_file_range)",
	/* 308 */	"#308 (unimplemented tee)",
	/* 309 */	"#309 (unimplemented vmsplice)",
	/* 310 */	"#310 (unimplemented move_pages)",
	/* 311 */	"sched_setaffinity",
	/* 312 */	"sched_getaffinity",
	/* 313 */	"#313 (unimplemented kexec_load)",
	/* 314 */	"#314 (unimplemented getcpu)",
	/* 315 */	"#315 (unimplemented epoll_wait)",
	/* 316 */	"utimensat",
	/* 317 */	"#317 (unimplemented signalfd)",
	/* 318 */	"timerfd_create",
	/* 319 */	"eventfd",
	/* 320 */	"fallocate",
	/* 321 */	"timerfd_settime",
	/* 322 */	"timerfd_gettime",
	/* 323 */	"#323 (unimplemented signalfd4)",
	/* 324 */	"eventfd2",
	/* 325 */	"#325 (unimplemented epoll_create1)",
	/* 326 */	"dup3",
	/* 327 */	"pipe2",
	/* 328 */	"#328 (unimplemented inotify_init1)",
	/* 329 */	"preadv",
	/* 330 */	"pwritev",
	/* 331 */	"#331 (unimplemented rt_tgsigqueueinfo)",
	/* 332 */	"#332 (unimplemented perf_counter_open)",
	/* 333 */	"#333 (unimplemented set_thread_area)",
	/* 334 */	"#334 (unimplemented get_thread_area)",
	/* 335 */	"#335 (unimplemented atomic_cmpxchg_32)",
	/* 336 */	"#336 (unimplemented atomic_barrier)",
	/* 337 */	"#337 (unimplemented fanotify_init)",
	/* 338 */	"#338 (unimplemented fanotify_mark)",
	/* 339 */	"#339 (unimplemented prlimit64)",
	/* 340 */	"#340 (unimplemented name_to_handle_at)",
	/* 341 */	"#341 (unimplemented open_by_handle_at)",
	/* 342 */	"#342 (unimplemented clock_adjtime)",
	/* 343 */	"#343 (unimplemented syncfs)",
	/* 344 */	"#344 (unimplemented setns)",
	/* 345 */	"#345 (unimplemented process_vm_readv)",
	/* 346 */	"#346 (unimplemented process_vm_writev)",
	/* 347 */	"#347 (unimplemented kcmp)",
	/* 348 */	"#348 (unimplemented finit_module)",
	/* 349 */	"#349 (unimplemented sched_setattr)",
	/* 350 */	"#350 (unimplemented sched_getattr)",
	/* 351 */	"#351 (unimplemented renameat2)",
	/* 352 */	"#352 (unimplemented getrandom)",
	/* 353 */	"#353 (unimplemented memfd_create)",
	/* 354 */	"#354 (unimplemented bpf)",
	/* 355 */	"#355 (unimplemented execveat)",
	/* 356 */	"#356 (unimplemented socket)",
	/* 357 */	"#357 (unimplemented socketpair)",
	/* 358 */	"#358 (unimplemented bind)",
	/* 359 */	"#359 (unimplemented connect)",
	/* 360 */	"#360 (unimplemented listen)",
	/* 361 */	"accept4",
	/* 362 */	"#362 (unimplemented getsockopt)",
	/* 363 */	"#363 (unimplemented setsockopt)",
	/* 364 */	"#364 (unimplemented getsockname)",
	/* 365 */	"#365 (unimplemented getpeername)",
	/* 366 */	"#366 (unimplemented sendto)",
	/* 367 */	"#367 (unimplemented sendmsg)",
	/* 368 */	"#368 (unimplemented recvfrom)",
	/* 369 */	"#369 (unimplemented recvmsg)",
	/* 370 */	"#370 (unimplemented shutdown)",
	/* 371 */	"recvmmsg",
	/* 372 */	"sendmmsg",
	/* 373 */	"#373 (unimplemented userfaultfd)",
	/* 374 */	"#374 (unimplemented membarrier)",
	/* 375 */	"#375 (unimplemented mlock2)",
	/* 376 */	"#376 (unimplemented copy_file_range)",
	/* 377 */	"#377 (unimplemented preadv2)",
	/* 378 */	"#378 (unimplemented pwritev2)",
	/* 379 */	"# filler",
	/* 380 */	"# filler",
	/* 381 */	"# filler",
	/* 382 */	"# filler",
	/* 383 */	"# filler",
	/* 384 */	"# filler",
	/* 385 */	"# filler",
	/* 386 */	"# filler",
	/* 387 */	"# filler",
	/* 388 */	"# filler",
	/* 389 */	"# filler",
	/* 390 */	"# filler",
	/* 391 */	"# filler",
	/* 392 */	"# filler",
	/* 393 */	"# filler",
	/* 394 */	"# filler",
	/* 395 */	"# filler",
	/* 396 */	"# filler",
	/* 397 */	"# filler",
	/* 398 */	"# filler",
	/* 399 */	"# filler",
	/* 400 */	"# filler",
	/* 401 */	"# filler",
	/* 402 */	"# filler",
	/* 403 */	"# filler",
	/* 404 */	"# filler",
	/* 405 */	"# filler",
	/* 406 */	"# filler",
	/* 407 */	"# filler",
	/* 408 */	"# filler",
	/* 409 */	"# filler",
	/* 410 */	"# filler",
	/* 411 */	"# filler",
	/* 412 */	"# filler",
	/* 413 */	"# filler",
	/* 414 */	"# filler",
	/* 415 */	"# filler",
	/* 416 */	"# filler",
	/* 417 */	"# filler",
	/* 418 */	"# filler",
	/* 419 */	"# filler",
	/* 420 */	"# filler",
	/* 421 */	"# filler",
	/* 422 */	"# filler",
	/* 423 */	"# filler",
	/* 424 */	"# filler",
	/* 425 */	"# filler",
	/* 426 */	"# filler",
	/* 427 */	"# filler",
	/* 428 */	"# filler",
	/* 429 */	"# filler",
	/* 430 */	"# filler",
	/* 431 */	"# filler",
	/* 432 */	"# filler",
	/* 433 */	"# filler",
	/* 434 */	"# filler",
	/* 435 */	"# filler",
	/* 436 */	"# filler",
	/* 437 */	"# filler",
	/* 438 */	"# filler",
	/* 439 */	"# filler",
	/* 440 */	"# filler",
	/* 441 */	"# filler",
	/* 442 */	"# filler",
	/* 443 */	"# filler",
	/* 444 */	"# filler",
	/* 445 */	"# filler",
	/* 446 */	"# filler",
	/* 447 */	"# filler",
	/* 448 */	"# filler",
	/* 449 */	"# filler",
	/* 450 */	"# filler",
	/* 451 */	"# filler",
	/* 452 */	"# filler",
	/* 453 */	"# filler",
	/* 454 */	"# filler",
	/* 455 */	"# filler",
	/* 456 */	"# filler",
	/* 457 */	"# filler",
	/* 458 */	"# filler",
	/* 459 */	"# filler",
	/* 460 */	"# filler",
	/* 461 */	"# filler",
	/* 462 */	"# filler",
	/* 463 */	"# filler",
	/* 464 */	"# filler",
	/* 465 */	"# filler",
	/* 466 */	"# filler",
	/* 467 */	"# filler",
	/* 468 */	"# filler",
	/* 469 */	"# filler",
	/* 470 */	"# filler",
	/* 471 */	"# filler",
	/* 472 */	"# filler",
	/* 473 */	"# filler",
	/* 474 */	"# filler",
	/* 475 */	"# filler",
	/* 476 */	"# filler",
	/* 477 */	"# filler",
	/* 478 */	"# filler",
	/* 479 */	"# filler",
	/* 480 */	"# filler",
	/* 481 */	"# filler",
	/* 482 */	"# filler",
	/* 483 */	"# filler",
	/* 484 */	"# filler",
	/* 485 */	"# filler",
	/* 486 */	"# filler",
	/* 487 */	"# filler",
	/* 488 */	"# filler",
	/* 489 */	"# filler",
	/* 490 */	"# filler",
	/* 491 */	"# filler",
	/* 492 */	"# filler",
	/* 493 */	"# filler",
	/* 494 */	"# filler",
	/* 495 */	"# filler",
	/* 496 */	"# filler",
	/* 497 */	"# filler",
	/* 498 */	"# filler",
	/* 499 */	"# filler",
	/* 500 */	"# filler",
	/* 501 */	"# filler",
	/* 502 */	"# filler",
	/* 503 */	"# filler",
	/* 504 */	"# filler",
	/* 505 */	"# filler",
	/* 506 */	"# filler",
	/* 507 */	"# filler",
	/* 508 */	"# filler",
	/* 509 */	"# filler",
	/* 510 */	"# filler",
	/* 511 */	"# filler",
};


/* libc style syscall names */
const char *const altlinux_syscallnames[] = {
	/*   0 */	"nosys",
	/*   1 */	NULL, /* exit */
	/*   2 */	NULL, /* fork */
	/*   3 */	NULL, /* read */
	/*   4 */	NULL, /* write */
	/*   5 */	NULL, /* open */
	/*   6 */	NULL, /* close */
	/*   7 */	NULL, /* waitpid */
	/*   8 */	NULL, /* creat */
	/*   9 */	NULL, /* link */
	/*  10 */	NULL, /* unlink */
	/*  11 */	NULL, /* execve */
	/*  12 */	NULL, /* chdir */
	/*  13 */	NULL, /* time */
	/*  14 */	NULL, /* mknod */
	/*  15 */	NULL, /* chmod */
	/*  16 */	NULL, /* chown16 */
	/*  17 */	NULL, /* obsolete break */
	/*  18 */	NULL, /* obsolete ostat */
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  19 */	NULL, /* lseek */
#else
	/*  19 */	NULL, /* unimplemented compat_43_sys_lseek */
#endif
	/*  20 */	NULL, /* getpid */
	/*  21 */	NULL, /* unimplemented mount */
	/*  22 */	NULL, /* obsolete umount */
	/*  23 */	"setuid",
	/*  24 */	"getuid",
	/*  25 */	NULL, /* stime */
	/*  26 */	NULL, /* ptrace */
	/*  27 */	NULL, /* alarm */
	/*  28 */	NULL, /* obsolete ofstat */
	/*  29 */	NULL, /* pause */
	/*  30 */	NULL, /* utime */
	/*  31 */	NULL, /* obsolete stty */
	/*  32 */	NULL, /* obsolete gtty */
	/*  33 */	NULL, /* access */
	/*  34 */	NULL, /* nice */
	/*  35 */	NULL, /* obsolete ftime */
	/*  36 */	NULL, /* sync */
	/*  37 */	NULL, /* kill */
	/*  38 */	NULL, /* __posix_rename */
	/*  39 */	NULL, /* mkdir */
	/*  40 */	NULL, /* rmdir */
	/*  41 */	NULL, /* dup */
	/*  42 */	NULL, /* pipe */
	/*  43 */	NULL, /* times */
	/*  44 */	NULL, /* obsolete prof */
	/*  45 */	NULL, /* brk */
	/*  46 */	"setgid",
	/*  47 */	"getgid",
	/*  48 */	NULL, /* signal */
	/*  49 */	"geteuid",
	/*  50 */	"getegid",
	/*  51 */	NULL, /* acct */
	/*  52 */	NULL, /* unimplemented umount */
	/*  53 */	NULL, /* obsolete lock */
	/*  54 */	NULL, /* ioctl */
	/*  55 */	NULL, /* fcntl */
	/*  56 */	NULL, /* obsolete mpx */
	/*  57 */	NULL, /* setpgid */
	/*  58 */	NULL, /* obsolete ulimit */
	/*  59 */	NULL, /* unimplemented oldolduname */
	/*  60 */	NULL, /* umask */
	/*  61 */	NULL, /* chroot */
	/*  62 */	NULL, /* unimplemented ustat */
	/*  63 */	NULL, /* dup2 */
	/*  64 */	NULL, /* getppid */
	/*  65 */	NULL, /* getpgrp */
	/*  66 */	NULL, /* setsid */
	/*  67 */	NULL, /* sigaction */
	/*  68 */	NULL, /* siggetmask */
	/*  69 */	NULL, /* sigsetmask */
	/*  70 */	NULL, /* setreuid16 */
	/*  71 */	NULL, /* setregid16 */
	/*  72 */	NULL, /* sigsuspend */
	/*  73 */	NULL, /* sigpending */
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  74 */	NULL, /* sethostname */
#else
	/*  74 */	NULL, /* unimplemented compat_43_sys_sethostname */
#endif
	/*  75 */	NULL, /* setrlimit */
	/*  76 */	NULL, /* getrlimit */
	/*  77 */	NULL, /* getrusage */
	/*  78 */	NULL, /* gettimeofday */
	/*  79 */	NULL, /* settimeofday */
	/*  80 */	NULL, /* getgroups16 */
	/*  81 */	NULL, /* setgroups16 */
	/*  82 */	NULL, /* oldselect */
	/*  83 */	NULL, /* symlink */
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  84 */	"lstat",
#else
	/*  84 */	NULL, /* unimplemented compat_43_sys_lstat */
#endif
	/*  85 */	NULL, /* readlink */
#ifdef EXEC_AOUT
	/*  86 */	NULL, /* uselib */
#else
	/*  86 */	NULL, /* unimplemented sys_uselib */
#endif
	/*  87 */	NULL, /* swapon */
	/*  88 */	NULL, /* reboot */
	/*  89 */	NULL, /* readdir */
	/*  90 */	NULL, /* old_mmap */
	/*  91 */	NULL, /* munmap */
	/*  92 */	NULL, /* truncate */
#if !defined(_KERNEL) || defined(COMPAT_43)
	/*  93 */	NULL, /* ftruncate */
#else
	/*  93 */	NULL, /* unimplemented compat_43_sys_ftruncate */
#endif
	/*  94 */	NULL, /* fchmod */
	/*  95 */	NULL, /* fchown16 */
	/*  96 */	NULL, /* getpriority */
	/*  97 */	NULL, /* setpriority */
	/*  98 */	NULL, /* profil */
	/*  99 */	NULL, /* statfs */
	/* 100 */	NULL, /* fstatfs */
	/* 101 */	NULL, /* unimplemented ioperm */
	/* 102 */	NULL, /* socketcall */
	/* 103 */	NULL, /* unimplemented syslog */
	/* 104 */	NULL, /* setitimer */
	/* 105 */	NULL, /* getitimer */
	/* 106 */	NULL, /* stat */
	/* 107 */	NULL, /* lstat */
	/* 108 */	NULL, /* fstat */
	/* 109 */	NULL, /* unimplemented olduname */
	/* 110 */	NULL, /* unimplemented iopl */
	/* 111 */	NULL, /* unimplemented vhangup */
	/* 112 */	NULL, /* unimplemented idle */
	/* 113 */	NULL, /* unimplemented vm86old */
	/* 114 */	NULL, /* wait4 */
	/* 115 */	NULL, /* swapoff */
	/* 116 */	NULL, /* sysinfo */
	/* 117 */	NULL, /* ipc */
	/* 118 */	NULL, /* fsync */
	/* 119 */	NULL, /* sigreturn */
	/* 120 */	NULL, /* clone */
	/* 121 */	NULL, /* setdomainname */
	/* 122 */	NULL, /* uname */
	/* 123 */	NULL, /* cacheflush */
	/* 124 */	NULL, /* unimplemented adjtimex */
	/* 125 */	NULL, /* mprotect */
	/* 126 */	NULL, /* sigprocmask */
	/* 127 */	NULL, /* unimplemented create_module */
	/* 128 */	NULL, /* unimplemented init_module */
	/* 129 */	NULL, /* unimplemented delete_module */
	/* 130 */	NULL, /* unimplemented get_kernel_syms */
	/* 131 */	NULL, /* unimplemented quotactl */
	/* 132 */	NULL, /* getpgid */
	/* 133 */	NULL, /* fchdir */
	/* 134 */	NULL, /* unimplemented bdflush */
	/* 135 */	NULL, /* unimplemented sysfs */
	/* 136 */	NULL, /* personality */
	/* 137 */	NULL, /* unimplemented afs_syscall */
	/* 138 */	"setfsuid",
	/* 139 */	"setfsgid",
	/* 140 */	NULL, /* llseek */
	/* 141 */	NULL, /* getdents */
	/* 142 */	NULL, /* select */
	/* 143 */	NULL, /* flock */
	/* 144 */	"msync",
	/* 145 */	NULL, /* readv */
	/* 146 */	NULL, /* writev */
	/* 147 */	NULL, /* getsid */
	/* 148 */	NULL, /* fdatasync */
	/* 149 */	NULL, /* __sysctl */
	/* 150 */	NULL, /* mlock */
	/* 151 */	NULL, /* munlock */
	/* 152 */	NULL, /* mlockall */
	/* 153 */	NULL, /* munlockall */
	/* 154 */	NULL, /* sched_setparam */
	/* 155 */	NULL, /* sched_getparam */
	/* 156 */	NULL, /* sched_setscheduler */
	/* 157 */	NULL, /* sched_getscheduler */
	/* 158 */	NULL, /* sched_yield */
	/* 159 */	NULL, /* sched_get_priority_max */
	/* 160 */	NULL, /* sched_get_priority_min */
	/* 161 */	NULL, /* unimplemented sched_rr_get_interval */
	/* 162 */	NULL, /* nanosleep */
	/* 163 */	NULL, /* mremap */
	/* 164 */	NULL, /* setresuid16 */
	/* 165 */	NULL, /* getresuid16 */
	/* 166 */	NULL, /* unimplemented vm86 */
	/* 167 */	NULL, /* unimplemented query_module */
	/* 168 */	NULL, /* poll */
	/* 169 */	NULL, /* unimplemented nfsservctl */
	/* 170 */	NULL, /* setresgid16 */
	/* 171 */	NULL, /* getresgid16 */
	/* 172 */	NULL, /* unimplemented prctl */
	/* 173 */	NULL, /* rt_sigreturn */
	/* 174 */	NULL, /* rt_sigaction */
	/* 175 */	NULL, /* rt_sigprocmask */
	/* 176 */	NULL, /* rt_sigpending */
	/* 177 */	NULL, /* rt_sigtimedwait */
	/* 178 */	NULL, /* rt_queueinfo */
	/* 179 */	NULL, /* rt_sigsuspend */
	/* 180 */	NULL, /* pread */
	/* 181 */	NULL, /* pwrite */
	/* 182 */	NULL, /* lchown16 */
	/* 183 */	NULL, /* __getcwd */
	/* 184 */	NULL, /* unimplemented capget */
	/* 185 */	NULL, /* unimplemented capset */
	/* 186 */	NULL, /* sigaltstack */
	/* 187 */	NULL, /* unimplemented sendfile */
	/* 188 */	NULL, /* unimplemented getpmsg */
	/* 189 */	NULL, /* unimplemented putpmsg */
	/* 190 */	"vfork",
	/* 191 */	NULL, /* ugetrlimit */
#define linux_sys_mmap2_args linux_sys_mmap_args
	/* 192 */	NULL, /* mmap2 */
	/* 193 */	NULL, /* truncate64 */
	/* 194 */	NULL, /* ftruncate64 */
	/* 195 */	NULL, /* stat64 */
	/* 196 */	NULL, /* lstat64 */
	/* 197 */	NULL, /* fstat64 */
	/* 198 */	NULL, /* __posix_chown */
	/* 199 */	NULL, /* getuid */
	/* 200 */	NULL, /* getgid */
	/* 201 */	NULL, /* geteuid */
	/* 202 */	NULL, /* getegid */
	/* 203 */	NULL, /* setreuid */
	/* 204 */	NULL, /* setregid */
	/* 205 */	NULL, /* getgroups */
	/* 206 */	NULL, /* setgroups */
	/* 207 */	NULL, /* __posix_fchown */
	/* 208 */	NULL, /* setresuid */
	/* 209 */	NULL, /* getresuid */
	/* 210 */	NULL, /* setresgid */
	/* 211 */	NULL, /* getresgid */
	/* 212 */	NULL, /* __posix_lchown */
	/* 213 */	NULL, /* setuid */
	/* 214 */	NULL, /* setgid */
	/* 215 */	NULL, /* setfsuid */
	/* 216 */	NULL, /* setfsgid */
	/* 217 */	NULL, /* unimplemented / * unused * / */
	/* 218 */	NULL, /* unimplemented / * unused * / */
	/* 219 */	NULL, /* unimplemented / * unused * / */
	/* 220 */	NULL, /* getdents64 */
	/* 221 */	NULL, /* gettid */
	/* 222 */	NULL, /* tkill */
	/* 223 */	NULL, /* setxattr */
	/* 224 */	NULL, /* lsetxattr */
	/* 225 */	NULL, /* fsetxattr */
	/* 226 */	NULL, /* getxattr */
	/* 227 */	NULL, /* lgetxattr */
	/* 228 */	NULL, /* fgetxattr */
	/* 229 */	NULL, /* listxattr */
	/* 230 */	NULL, /* llistxattr */
	/* 231 */	NULL, /* flistxattr */
	/* 232 */	NULL, /* removexattr */
	/* 233 */	NULL, /* lremovexattr */
	/* 234 */	NULL, /* fremovexattr */
	/* 235 */	NULL, /* futex */
	/* 236 */	NULL, /* unimplemented sendfile64 */
	/* 237 */	NULL, /* mincore */
	/* 238 */	NULL, /* madvise */
	/* 239 */	NULL, /* fcntl64 */
	/* 240 */	NULL, /* unimplemented readahead */
	/* 241 */	NULL, /* unimplemented io_setup */
	/* 242 */	NULL, /* unimplemented io_destroy */
	/* 243 */	NULL, /* unimplemented io_getevents */
	/* 244 */	NULL, /* unimplemented io_submit */
	/* 245 */	NULL, /* unimplemented io_cancel */
	/* 246 */	NULL, /* fadvise64 */
	/* 247 */	NULL, /* unimplemented exit_group */
	/* 248 */	NULL, /* unimplemented lookup_dcookie */
	/* 249 */	NULL, /* unimplemented epoll_create */
	/* 250 */	NULL, /* unimplemented epoll_ctl */
	/* 251 */	NULL, /* unimplemented epoll_wait */
	/* 252 */	NULL, /* unimplemented remap_file_pages */
	/* 253 */	NULL, /* set_tid_address */
	/* 254 */	NULL, /* timer_create */
	/* 255 */	NULL, /* timer_settime */
	/* 256 */	NULL, /* timer_gettime */
	/* 257 */	NULL, /* timer_getoverrun */
	/* 258 */	NULL, /* timer_delete */
	/* 259 */	NULL, /* clock_settime */
	/* 260 */	NULL, /* clock_gettime */
	/* 261 */	NULL, /* clock_getres */
	/* 262 */	NULL, /* clock_nanosleep */
	/* 263 */	NULL, /* statfs64 */
	/* 264 */	NULL, /* fstatfs64 */
	/* 265 */	NULL, /* tgkill */
	/* 266 */	NULL, /* utimes */
	/* 267 */	NULL, /* fadvise64_64 */
	/* 268 */	NULL, /* unimplemented mbind */
	/* 269 */	NULL, /* unimplemented get_mempolicy */
	/* 270 */	NULL, /* unimplemented set_mempolicy */
	/* 271 */	NULL, /* unimplemented mq_open */
	/* 272 */	NULL, /* unimplemented mq_unlink */
	/* 273 */	NULL, /* unimplemented mq_timedsend */
	/* 274 */	NULL, /* unimplemented mq_timedreceive */
	/* 275 */	NULL, /* unimplemented mq_notify */
	/* 276 */	NULL, /* unimplemented mq_getsetattr */
	/* 277 */	NULL, /* unimplemented waitid */
	/* 278 */	NULL, /* unimplemented vserver */
	/* 279 */	NULL, /* unimplemented add_key */
	/* 280 */	NULL, /* unimplemented request_key */
	/* 281 */	NULL, /* unimplemented keyctl */
	/* 282 */	NULL, /* unimplemented ioprio_set */
	/* 283 */	NULL, /* unimplemented ioprio_get */
	/* 284 */	NULL, /* unimplemented inotify_init */
	/* 285 */	NULL, /* unimplemented inotify_add_watch */
	/* 286 */	NULL, /* unimplemented inotify_rm_watch */
	/* 287 */	NULL, /* unimplemented migrate_pages */
	/* 288 */	NULL, /* openat */
	/* 289 */	NULL, /* mkdirat */
	/* 290 */	NULL, /* mknodat */
	/* 291 */	NULL, /* fchownat */
	/* 292 */	NULL, /* unimplemented futimesat */
	/* 293 */	NULL, /* fstatat64 */
	/* 294 */	NULL, /* unlinkat */
	/* 295 */	NULL, /* renameat */
	/* 296 */	NULL, /* linkat */
	/* 297 */	NULL, /* symlinkat */
	/* 298 */	NULL, /* readlinkat */
	/* 299 */	NULL, /* fchmodat */
	/* 300 */	NULL, /* faccessat */
	/* 301 */	NULL, /* pselect6 */
	/* 302 */	NULL, /* ppoll */
	/* 303 */	NULL, /* unimplemented unshare */
	/* 304 */	NULL, /* __futex_set_robust_list */
	/* 305 */	NULL, /* __futex_get_robust_list */
	/* 306 */	NULL, /* unimplemented splice */
	/* 307 */	NULL, /* unimplemented sync_file_range */
	/* 308 */	NULL, /* unimplemented tee */
	/* 309 */	NULL, /* unimplemented vmsplice */
	/* 310 */	NULL, /* unimplemented move_pages */
	/* 311 */	NULL, /* sched_setaffinity */
	/* 312 */	NULL, /* sched_getaffinity */
	/* 313 */	NULL, /* unimplemented kexec_load */
	/* 314 */	NULL, /* unimplemented getcpu */
	/* 315 */	NULL, /* unimplemented epoll_wait */
	/* 316 */	NULL, /* utimensat */
	/* 317 */	NULL, /* unimplemented signalfd */
	/* 318 */	NULL, /* timerfd_create */
	/* 319 */	NULL, /* eventfd */
	/* 320 */	NULL, /* fallocate */
	/* 321 */	NULL, /* timerfd_settime */
	/* 322 */	NULL, /* timerfd_gettime */
	/* 323 */	NULL, /* unimplemented signalfd4 */
	/* 324 */	NULL, /* eventfd2 */
	/* 325 */	NULL, /* unimplemented epoll_create1 */
	/* 326 */	NULL, /* dup3 */
	/* 327 */	NULL, /* pipe2 */
	/* 328 */	NULL, /* unimplemented inotify_init1 */
	/* 329 */	NULL, /* preadv */
	/* 330 */	NULL, /* pwritev */
	/* 331 */	NULL, /* unimplemented rt_tgsigqueueinfo */
	/* 332 */	NULL, /* unimplemented perf_counter_open */
	/* 333 */	NULL, /* unimplemented set_thread_area */
	/* 334 */	NULL, /* unimplemented get_thread_area */
	/* 335 */	NULL, /* unimplemented atomic_cmpxchg_32 */
	/* 336 */	NULL, /* unimplemented atomic_barrier */
	/* 337 */	NULL, /* unimplemented fanotify_init */
	/* 338 */	NULL, /* unimplemented fanotify_mark */
	/* 339 */	NULL, /* unimplemented prlimit64 */
	/* 340 */	NULL, /* unimplemented name_to_handle_at */
	/* 341 */	NULL, /* unimplemented open_by_handle_at */
	/* 342 */	NULL, /* unimplemented clock_adjtime */
	/* 343 */	NULL, /* unimplemented syncfs */
	/* 344 */	NULL, /* unimplemented setns */
	/* 345 */	NULL, /* unimplemented process_vm_readv */
	/* 346 */	NULL, /* unimplemented process_vm_writev */
	/* 347 */	NULL, /* unimplemented kcmp */
	/* 348 */	NULL, /* unimplemented finit_module */
	/* 349 */	NULL, /* unimplemented sched_setattr */
	/* 350 */	NULL, /* unimplemented sched_getattr */
	/* 351 */	NULL, /* unimplemented renameat2 */
	/* 352 */	NULL, /* unimplemented getrandom */
	/* 353 */	NULL, /* unimplemented memfd_create */
	/* 354 */	NULL, /* unimplemented bpf */
	/* 355 */	NULL, /* unimplemented execveat */
	/* 356 */	NULL, /* unimplemented socket */
	/* 357 */	NULL, /* unimplemented socketpair */
	/* 358 */	NULL, /* unimplemented bind */
	/* 359 */	NULL, /* unimplemented connect */
	/* 360 */	NULL, /* unimplemented listen */
	/* 361 */	NULL, /* accept4 */
	/* 362 */	NULL, /* unimplemented getsockopt */
	/* 363 */	NULL, /* unimplemented setsockopt */
	/* 364 */	NULL, /* unimplemented getsockname */
	/* 365 */	NULL, /* unimplemented getpeername */
	/* 366 */	NULL, /* unimplemented sendto */
	/* 367 */	NULL, /* unimplemented sendmsg */
	/* 368 */	NULL, /* unimplemented recvfrom */
	/* 369 */	NULL, /* unimplemented recvmsg */
	/* 370 */	NULL, /* unimplemented shutdown */
	/* 371 */	NULL, /* recvmmsg */
	/* 372 */	NULL, /* sendmmsg */
	/* 373 */	NULL, /* unimplemented userfaultfd */
	/* 374 */	NULL, /* unimplemented membarrier */
	/* 375 */	NULL, /* unimplemented mlock2 */
	/* 376 */	NULL, /* unimplemented copy_file_range */
	/* 377 */	NULL, /* unimplemented preadv2 */
	/* 378 */	NULL, /* unimplemented pwritev2 */
	/* 379 */	NULL, /* filler */
	/* 380 */	NULL, /* filler */
	/* 381 */	NULL, /* filler */
	/* 382 */	NULL, /* filler */
	/* 383 */	NULL, /* filler */
	/* 384 */	NULL, /* filler */
	/* 385 */	NULL, /* filler */
	/* 386 */	NULL, /* filler */
	/* 387 */	NULL, /* filler */
	/* 388 */	NULL, /* filler */
	/* 389 */	NULL, /* filler */
	/* 390 */	NULL, /* filler */
	/* 391 */	NULL, /* filler */
	/* 392 */	NULL, /* filler */
	/* 393 */	NULL, /* filler */
	/* 394 */	NULL, /* filler */
	/* 395 */	NULL, /* filler */
	/* 396 */	NULL, /* filler */
	/* 397 */	NULL, /* filler */
	/* 398 */	NULL, /* filler */
	/* 399 */	NULL, /* filler */
	/* 400 */	NULL, /* filler */
	/* 401 */	NULL, /* filler */
	/* 402 */	NULL, /* filler */
	/* 403 */	NULL, /* filler */
	/* 404 */	NULL, /* filler */
	/* 405 */	NULL, /* filler */
	/* 406 */	NULL, /* filler */
	/* 407 */	NULL, /* filler */
	/* 408 */	NULL, /* filler */
	/* 409 */	NULL, /* filler */
	/* 410 */	NULL, /* filler */
	/* 411 */	NULL, /* filler */
	/* 412 */	NULL, /* filler */
	/* 413 */	NULL, /* filler */
	/* 414 */	NULL, /* filler */
	/* 415 */	NULL, /* filler */
	/* 416 */	NULL, /* filler */
	/* 417 */	NULL, /* filler */
	/* 418 */	NULL, /* filler */
	/* 419 */	NULL, /* filler */
	/* 420 */	NULL, /* filler */
	/* 421 */	NULL, /* filler */
	/* 422 */	NULL, /* filler */
	/* 423 */	NULL, /* filler */
	/* 424 */	NULL, /* filler */
	/* 425 */	NULL, /* filler */
	/* 426 */	NULL, /* filler */
	/* 427 */	NULL, /* filler */
	/* 428 */	NULL, /* filler */
	/* 429 */	NULL, /* filler */
	/* 430 */	NULL, /* filler */
	/* 431 */	NULL, /* filler */
	/* 432 */	NULL, /* filler */
	/* 433 */	NULL, /* filler */
	/* 434 */	NULL, /* filler */
	/* 435 */	NULL, /* filler */
	/* 436 */	NULL, /* filler */
	/* 437 */	NULL, /* filler */
	/* 438 */	NULL, /* filler */
	/* 439 */	NULL, /* filler */
	/* 440 */	NULL, /* filler */
	/* 441 */	NULL, /* filler */
	/* 442 */	NULL, /* filler */
	/* 443 */	NULL, /* filler */
	/* 444 */	NULL, /* filler */
	/* 445 */	NULL, /* filler */
	/* 446 */	NULL, /* filler */
	/* 447 */	NULL, /* filler */
	/* 448 */	NULL, /* filler */
	/* 449 */	NULL, /* filler */
	/* 450 */	NULL, /* filler */
	/* 451 */	NULL, /* filler */
	/* 452 */	NULL, /* filler */
	/* 453 */	NULL, /* filler */
	/* 454 */	NULL, /* filler */
	/* 455 */	NULL, /* filler */
	/* 456 */	NULL, /* filler */
	/* 457 */	NULL, /* filler */
	/* 458 */	NULL, /* filler */
	/* 459 */	NULL, /* filler */
	/* 460 */	NULL, /* filler */
	/* 461 */	NULL, /* filler */
	/* 462 */	NULL, /* filler */
	/* 463 */	NULL, /* filler */
	/* 464 */	NULL, /* filler */
	/* 465 */	NULL, /* filler */
	/* 466 */	NULL, /* filler */
	/* 467 */	NULL, /* filler */
	/* 468 */	NULL, /* filler */
	/* 469 */	NULL, /* filler */
	/* 470 */	NULL, /* filler */
	/* 471 */	NULL, /* filler */
	/* 472 */	NULL, /* filler */
	/* 473 */	NULL, /* filler */
	/* 474 */	NULL, /* filler */
	/* 475 */	NULL, /* filler */
	/* 476 */	NULL, /* filler */
	/* 477 */	NULL, /* filler */
	/* 478 */	NULL, /* filler */
	/* 479 */	NULL, /* filler */
	/* 480 */	NULL, /* filler */
	/* 481 */	NULL, /* filler */
	/* 482 */	NULL, /* filler */
	/* 483 */	NULL, /* filler */
	/* 484 */	NULL, /* filler */
	/* 485 */	NULL, /* filler */
	/* 486 */	NULL, /* filler */
	/* 487 */	NULL, /* filler */
	/* 488 */	NULL, /* filler */
	/* 489 */	NULL, /* filler */
	/* 490 */	NULL, /* filler */
	/* 491 */	NULL, /* filler */
	/* 492 */	NULL, /* filler */
	/* 493 */	NULL, /* filler */
	/* 494 */	NULL, /* filler */
	/* 495 */	NULL, /* filler */
	/* 496 */	NULL, /* filler */
	/* 497 */	NULL, /* filler */
	/* 498 */	NULL, /* filler */
	/* 499 */	NULL, /* filler */
	/* 500 */	NULL, /* filler */
	/* 501 */	NULL, /* filler */
	/* 502 */	NULL, /* filler */
	/* 503 */	NULL, /* filler */
	/* 504 */	NULL, /* filler */
	/* 505 */	NULL, /* filler */
	/* 506 */	NULL, /* filler */
	/* 507 */	NULL, /* filler */
	/* 508 */	NULL, /* filler */
	/* 509 */	NULL, /* filler */
	/* 510 */	NULL, /* filler */
	/* 511 */	NULL, /* filler */
};
