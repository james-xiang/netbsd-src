/*	$NetBSD: fmt_else_comment.c,v 1.1 2021/10/22 19:27:53 rillig Exp $	*/
/* $FreeBSD: head/usr.bin/indent/tests/elsecomment.0.pro 314613 2017-03-03 20:15:22Z ngie $ */

/* See r303484 and r309342 */

#indent input
void t(void) {
	/* The two if statements below excercise two different code paths. */

	if (1) /* a */ int a; else /* b */ int b;

	if (1) /* a */
		int a;
	else /* b */
		int b;

	if (1) {

	}



	/* Old indent would remove the 3 blank lines above, awaiting "else". */

	if (1) {
		int a;
	}


	else if (0) {
		int b;
	}
	/* test */
	else
		;

	if (1)
		;
	else /* Old indent would get very confused here */
	/* We also mustn't assume that there's only one comment */
	/* before the left brace. */
	{


	}
}
#indent end

#indent run -bl
void
t(void)
{
	/* The two if statements below excercise two different code paths. */

	if (1)			/* a */
		int		a;
	else			/* b */
		int		b;

	if (1)			/* a */
		int		a;
	else			/* b */
		int		b;

	if (1)
	{

	}



	/*
	 * Old indent would remove the 3 blank lines above, awaiting "else".
	 */

	if (1)
	{
		int		a;
	} else if (0)
	{
		int		b;
	}
	/* test */
	else
		;

	if (1)
		;
	else			/* Old indent would get very confused here */
		/* We also mustn't assume that there's only one comment */
		/* before the left brace. */
	{


	}
}
#indent end
