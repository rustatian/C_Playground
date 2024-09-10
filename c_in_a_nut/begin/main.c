#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>


#define fabs(X) \
_Generic((X),\
	float: fabsf, \
	long double: fabsl, \
	default: fabs)(X)

double curcularArea(double r);

int test_func(char *s) {
	if (s == NULL) {
		fprintf(stderr, "%s: received null pointer arg\n", __func__);
		return -1;
	}

	return 0;
}

int main() {
	test_func(NULL);
	double radius = 1.0, area = 0.0;
	printf("Areas of Circles\n\n");
	printf("Radius Area\n\n"
	"------------------------\n");

	wchar_t wc = L'\x3B1';
	char mbStr[10] = "";
	int nBytes = 0;
	nBytes = wctomb(mbStr, wc);
	if (nBytes < 0)
		puts("not a valid multibyte char in your locale");

	// char alpha = '\u03B1';
	// wchar_t alpha2 = '\u03B1';
	int arr<::> = <% 10, 20, 30 %>;
	printf("second: <%d>.\n", arr<:1:>);
		
	int arr2[] = {10, 20, 30};
	printf("second: <%d>.\n", arr2[1]);

	auto var = 5;
}

