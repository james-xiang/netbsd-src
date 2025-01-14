/* $NetBSD: opt_ci.c,v 1.3 2021/11/01 23:44:08 rillig Exp $ */
/* $FreeBSD$ */

/*
 * Tests for the option '-ci', which controls the indentation of continuation
 * lines in statements and declarations, but only inside a function.
 */

/*
 * Top level expressions with and without parentheses.
 */
#indent input
int top_level = 1 +
 2;
int top_level = (1 +
 2 + (
  3));
#indent end

#indent run -ci0
int		top_level = 1 +
2;
int		top_level = (1 +
			     2 + (
				  3));
#indent end
#indent run-equals-prev-output -ci2
#indent run-equals-prev-output -ci4
#indent run-equals-prev-output -ci8

#indent run -ci0 -nlp
int		top_level = 1 +
2;
int		top_level = (1 +
	2 + (
		3));
#indent end

#indent run -ci2 -nlp
int		top_level = 1 +
2;
int		top_level = (1 +
  2 + (
    3));
#indent end

/*
 * Since '-ci4' is half an indentation level, indent all continuations using
 * the same level, no matter how many parentheses there are. The rationale for
 * this may have been to prevent that the continuation line has the same
 * indentation as a follow-up statement, such as in 'if' statements.
 */
#indent run -ci4 -nlp
int		top_level = 1 +
2;
int		top_level = (1 +
    2 + (
    3));
#indent end

/*
 * Declarations in functions without parentheses.
 */
#indent input
int
sum(int a, int b)
{
	return a +
	 b;
	return first +
	 second;
}
#indent end

#indent run -ci0
int
sum(int a, int b)
{
	return a +
		b;
	return first +
		second;
}
#indent end

#indent run -ci2
int
sum(int a, int b)
{
	return a +
	  b;
	return first +
	  second;
}
#indent end

#indent run -ci4
int
sum(int a, int b)
{
	return a +
	    b;
	return first +
	    second;
}
#indent end

#indent run -ci8
int
sum(int a, int b)
{
	return a +
		b;
	return first +
		second;
}
#indent end


/*
 * Continued statements with expressions in parentheses.
 */
#indent input
int
sum(int a, int b)
{
	return (a +
	b);
	return (first +
	second + (
	third));
}
#indent end

#indent run -ci0
int
sum(int a, int b)
{
	return (a +
		b);
	return (first +
		second + (
			  third));
}
#indent end
#indent run-equals-prev-output -ci2
#indent run-equals-prev-output -ci4
#indent run-equals-prev-output -ci8

#indent run -ci2 -nlp
int
sum(int a, int b)
{
	return (a +
	  b);
	return (first +
	  second + (
	    third));
}
#indent end

/*
 * Since '-ci4' is half an indentation level, indent all continuations using
 * the same level, no matter how many parentheses there are. The rationale for
 * this may have been to prevent that the continuation line has the same
 * indentation as a follow-up statement, such as in 'if' statements.
 */
#indent run -ci4 -nlp
int
sum(int a, int b)
{
	return (a +
	    b);
	return (first +
	    second + (
	    third));
}
#indent end

#indent run -ci8 -nlp
int
sum(int a, int b)
{
	return (a +
		b);
	return (first +
		second + (
			third));
}
#indent end
