#include <stdio.h>
#include <string.h>
void removeMatchedCharacters(char* str1, char* str2) {
    for (int i = 0; i < strlen(str1); i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j] && str1[i] != '*') {
                str1[i] = '*';
                str2[j] = '*';
                break;
            }
        }
    }
}
int countRemainingCharacters(char* str1, char* str2) {
    int count = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] != '*') count++;
    }
    for (int i = 0; i < strlen(str2); i++) {
        if (str2[i] != '*') count++;
    }
    return count;
}
const char* flamesResult(int count) {
    char flames[] = "FLAMES";
    int len = strlen(flames);
    int pos = 0;

    for (int i = len; i > 1; i--) {
        pos = (pos + count - 1) % i;
        for (int j = pos; j < i - 1; j++) {
            flames[j] = flames[j + 1];
        }
        flames[i - 1] = '\0';
    }

    switch (flames[0]) {
        case 'F': return "Friends";
        case 'L': return "Love";
        case 'A': return "Affection";
        case 'M': return "Marriage";
        case 'E': return "Enemy";
        case 'S': return "Siblings";
    }

    return "";
}
int main() {
    char name1[100], name2[100];
    printf("Enter the first name: ");
    scanf("%s", name1);
    printf("Enter the second name: ");
    scanf("%s", name2);

    removeMatchedCharacters(name1, name2);
    int remainingCount = countRemainingCharacters(name1, name2);
    const char* result = flamesResult(remainingCount);

    printf("The result of FLAMES is: %s\n", result);
    return 0;
}
