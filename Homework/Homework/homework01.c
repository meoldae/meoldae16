#include <string.h>
#include <stdio.h>

int main() {
	char s[100];
	printf("문자를 입력하세요(100자 이내).\n");
	scanf_s("%s", &s, 100);
	printf("\n");
	printf("입력된 문자는 %s 입니다.\n", s);

	system("pause"); // keep terminal open
	return 0;
}
