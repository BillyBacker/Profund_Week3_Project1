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

bool any_word(char In[256], char str[2048]) {
	int check = 0;
	//printf("%s %s %d %d\n", In, str, len(In), len(str));
	for (int sector = 0; sector < len(str); sector++) {
		//printf("Sector : %d\n", sector);
		for (int Char = 0; Char < len(In); Char++) {
			//printf("char : %d\n", Char);
			//printf("%c : %c\n", In[Char], str[Char+sector]);
			if (check == len(In)) {
				return true;
			}
			if (In[Char] == str[Char + sector]) {
				check++;
				//printf("found 1 -----------\n");
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
	scanf("%s", &a);
	printf("Enter Search key word (Max 255 charactors) : ");
	scanf("%s", &b);
	if (any_word(b, a)) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}