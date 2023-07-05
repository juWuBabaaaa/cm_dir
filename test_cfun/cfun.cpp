#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "- This, a sample string.";
	char * pch;
	printf("Spliting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while(pch != NULL) {
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}


	char key[] = "apple";
	char buffer[80];
	do {
		printf("Guess my favorite fruit?");
		fflush(stdout);
		scanf("%79s", buffer);
	} while (strcmp(key, buffer) !=0);
	puts("Correct answer!");
	return 0;


}





