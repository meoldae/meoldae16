#include <string.h>
#include <stdio.h>

int main() {
	char s[100];
	printf("���ڸ� �Է��ϼ���(100�� �̳�).\n");
	scanf_s("%s", &s, 100);
	printf("\n");
	printf("�Էµ� ���ڴ� %s �Դϴ�.\n", s);

	system("pause"); // keep terminal open
	return 0;
}
