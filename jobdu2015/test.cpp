#include <stdio.h>
#include <stdarg.h>
int sum(int count, ...) {
	if (count <= 0) return 0;

	va_list arg_ptr;
	va_start(arg_ptr, count);

	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += va_arg(arg_ptr, int);
	}
	va_end(arg_ptr);
	return sum;
}

int main(int argc, char* argv[]) {
	printf("%d\n", sum(6, 2, 4, 6, 8, 10, 12));
	printf("%d\n", sum(9, 11, 22, 33, 44, 55, 66, 77, 66, 99));
	return 0;
}