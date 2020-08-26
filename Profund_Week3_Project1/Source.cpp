#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int len(const char In[256]) {
	int count = 0;
	for (count = 0; count < 256; count++) {
		if (In[count] == 0) {
			break;
		}
	}
	return count;
}

bool any(char In[256], char str[2048]) {
	int check = 0;
	for (int sector = 0; sector < len(str); sector++) {
		for (int Char = 0; Char < len(In); Char++) {
			if (check == len(In)) {
				return true;
			}
			if (In[Char] == str[Char + sector]) {
				check++;
			}
			else {
				check = 0;
			}
		}
	}
	return false;
}

int main() {
	char a[2048];
	char b[256];
	char c;
	printf("Enter Text (Max 2047 charactors) : ");
	scanf("%[^\n]", &a);
	printf("Enter Search key word (Max 255 charactors) : ");
	scanf("%s", &b);
	if (any(b, a)) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}