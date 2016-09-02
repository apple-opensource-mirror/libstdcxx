/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-tailr-details" } */
int
t(char *a)
{
	static char p[100];
	if (a)
		return t(p);
	else
		return 0;
}
/* { dg-final { scan-tree-dump-times "Eliminated tail recursion" 1 "tailr"} } */
