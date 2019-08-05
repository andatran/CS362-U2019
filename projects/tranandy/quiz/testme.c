#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Printable ASCII characters begin at 32 and end at 126 inclusive
// upper case alphabet begins at 65 and ends at 90
// lower case alphabet begins at 97 and ends at 122

char inputChar()
{
	int charCode;
	char randChar;

	// generate an integer between 32 and 126 inclusive
	charCode = (rand() % (126 - 32 + 1)) + 32;

	// cast to char
	randChar = (char) charCode;

	//return random char
    return randChar;
}

char *inputString()
{
	int charCode;
	char randChar;
	char *myString = malloc((5+1)*sizeof(char));

	// create strings of fixed length 5 composed of all lower case ascii alphabet characters
	for (int i = 0; i < 5; i++){

		// generate an integer between 97 and 122 inclusive
		charCode = (rand() % (122 - 97 + 1)) + 97;
		randChar = (char) charCode;

		// build string
		myString[i] = randChar;
	}

    return myString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
	//free memory
	free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
