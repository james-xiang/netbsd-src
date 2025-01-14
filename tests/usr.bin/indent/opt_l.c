/* $NetBSD: opt_l.c,v 1.1 2021/10/22 20:54:36 rillig Exp $ */
/* $FreeBSD$ */

#indent input
/*
 * With a line length of 38, this comment and the next one are broken.
 */

/* The options -l and -lc produce the same output. */
#indent end

#indent run -l38
/*
 * With a line length of 38, this
 * comment and the next one are
 * broken.
 */

/*
 * The options -l and -lc produce the
 * same output.
 */
#indent end
#indent run-equals-prev-output -lc38


#indent input
int decl; /* comment comment comment comment */
#indent end

#indent run -di8 -c17 -lc32
int	decl;	/* comment comment comment comment */
#indent end

#indent run -di8 -c17 -l32
int	decl;	/* comment comment
		 * comment comment */
#indent end


/*
 * FIXME: Even though the line length is limited with -l38,
 * the overly long lines in the code are not broken.
 */
#indent input
void
example(int a, int b, int c, const char *cp)
{
	for (const char *p = cp; *p != '\0'; p++)
		if (*p > a)
			if (*p > b)
				if (*p > c)
					return;

	function(1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}
#indent end

#indent run-equals-input -l38
