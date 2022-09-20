#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<math.h>
#include<limits.h>

long long pow_mine(int digit,int step);



int main(int argc, char * argv[]) {
	setlocale(LC_ALL, "Rus");

	// œ–≈Œ¡–¿«Œ¬€¬¿≈Ã STR - > INT
	const int x = strlen(argv[1]);
	char tmp[x];
	memcpy(tmp, argv[1], sizeof(argv[1]));
	int result=0,l=0;
	for (int i = x-1; i>=0; i--) {
		int digit = (int)tmp[i] - (int)'0';
		result = result + digit * pow_mine(10, l);
		l++;
	}


	// Œœ–≈ƒ≈À≈Õ»≈  Àﬁ◊¿
	int k=0;
	if (strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "/h") == 0) k = 1;
	else if (strcmp(argv[2], "-p") == 0 || strcmp(argv[2], "/p") == 0) k = 2;
	else if (strcmp(argv[2], "-s") == 0 || strcmp(argv[2], "/s") == 0) k = 3;
	else if (strcmp(argv[2], "-e") == 0 || strcmp(argv[2], "/e") == 0) k = 4;
	else if (strcmp(argv[2], "-a") == 0 || strcmp(argv[2], "/a") == 0) k = 5;
	else if (strcmp(argv[2], "-f") == 0 || strcmp(argv[2], "/f") == 0) k = 6;

	switch (k)
	{
	case 0: 
		printf("FLAG WAS NOT RECOGNIZED");
		break;
	case 1: 
		l = 0;
		for (int i = 1; i <= 100; i++) {
		if (i % result == 0) {
			printf("%d ", i);
			l = 1;
		}
	}
		if (l == 0) printf("NOTHING");
		break;
	case 2:
		if (result != 1) {
			int c = 0;
			for (int i = 2; i < sqrt(result)+1; i++) {
				if (result % i == 0){
					c++;
					break;
				}
			}
			if (c == 0) printf("SIMPLE");
			else printf("COMPOSITE");
		}
		else printf("DIFFERENT");
		break;
	case 3:
		result = 0;
		for (int i = 0; i <x; i++) {
			int digit = (int)tmp[i] - (int)'0';
			printf("%d ", digit);
		}
		break;
	case 4:
		if (result > 10) printf("Out of Range");
		else {
			int i;
			for (i = 1; i <= 10; i++) {
				long long prev = 0;
				printf("\n%d: ", i);
				for (int j = 1; j < result+1; j++) {
					long long digit = pow_mine(i, j);

					if (digit < prev) printf("Out of Range");
					else printf(" %lld ", digit);
					prev = digit;
				}
			}
		}
		break;
	case 5:
		int flag = 0,sum=0;
		sum = (1 + result) * result / 2;

		if (sum < 0) printf("Out of Range");
		else printf("%d\n", sum);
		break;
	case 6:
		int i = 1;
		flag=0;
		sum = 1;
		int prev = 0;
		while (i != result) {
			i++;
			
			sum = sum * i;
			
			if (sum < i || sum<prev) {
				flag = 1;
				break;
			}
			prev = sum;
		}
		if (flag == 1) printf("Out of range");
		else printf("%d", sum);
	}



	return 0;

}
long long pow_mine(int digit,int step) {
long long res=digit;
	if(step!=0)
	while (step != 1) {
		if (res > LLONG_MAX / digit) {
			printf("Overflow");
			res = 0;
			break;
		}
		else {
			res = res * digit;
		}
		step--;
	}

	else if(step==0){
		res = 1;
	}
	return res;
}