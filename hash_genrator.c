#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    char pass[16];
    char encrypted[100];
    int special = 0;
    int j = 0;

    printf("Enter your password: ");
    scanf("%15s", pass);

    if (pass[0] == '0') {
        printf("Password cannot begin with 0\n");
        return 0;
    }
    for (int i = 0; pass[i] != '\0'; i++) {

        if (ispunct((unsigned char)pass[i])) {
            special = 1;
            break;
        }
    }

    if (!special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Special character found!\n");

    for (int i = 0; pass[i] != '\0'; i++) {

        switch (pass[i]) {

            case 'a':
                encrypted[j++] = '#';
                break;

            case 'c':
                encrypted[j++] = '*';
                break;

            case 'e':
                encrypted[j++] = '!';
                break;

            case 'h':
                encrypted[j++] = '^';
                break;

            case 'j':
                encrypted[j++] = '&';
                break;

            case 'k':
                encrypted[j++] = '$';
                encrypted[j++] = '$';
                break;

            case 's':
                encrypted[j++] = 'D';
                encrypted[j++] = 'G';
                encrypted[j++] = 'g';
                encrypted[j++] = 'g';
                encrypted[j++] = 'f';
                encrypted[j++] = '&';
                break;

            default:
                encrypted[j++] = pass[i];
                break;
        }
    }

    encrypted[j] = '\0';

    printf("Original password: %s\n", pass);
    printf("Encrypted password: %s\n", encrypted);

    return 0;
}