#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t numFromFile(char* file) {
	FILE *fp;
	fp = fopen(file, "rb");
	if (fp==NULL) {exit(1);}

	char buf[5];
	fread(buf, 1, 4, fp);
	uint32_t* p = reinterpret_cast<uint32_t*>(buf);
	fclose(fp);

	return ntohl(*p);
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Usage :\%s <file1> <file2>\n", argv[0]);
		exit(1);
	}

	uint32_t num1 = numFromFile(argv[1]);
	uint32_t num2 = numFromFile(argv[2]);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);

	return 0;
}
