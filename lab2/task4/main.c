#include<stdio.h>
#include<stdarg.h>
#include<math.h>
double AverageGeo(int cnt, ... ) {
	int c = cnt;
	double res = 1;
	va_list ptr;
	va_start(ptr, cnt);
	for (; cnt > 0; cnt--) {
		res = res * va_arg(ptr, double);
	}
	va_end(ptr);
	
	res = pow(res, 1.0 / c);
	return res;
}
double PowerOfNumber(double digit,int cnt) {

	if (cnt > 0) return digit*PowerOfNumber(digit, cnt-1);
	if (cnt < 0) return (1.0) / (digit * PowerOfNumber(digit,(-cnt)-1));
	return 1;
}

int main() {

	printf("%f\n", AverageGeo(3, 2.0, 2.0, 2.0)); // (ÊÎË-ÂÎ ×ÈÑÅË, X1,X2,..)

	printf("%f\n", PowerOfNumber(25.0,0)); // (×ÈÑËÎ, ÑÒÅÏÅÍÜ)

	return 0;
}
