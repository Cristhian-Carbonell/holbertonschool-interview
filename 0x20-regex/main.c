#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

#define TEST_MATCH(s, p)    do {\
	{\
		int res = regex_match(s, p);\
		printf("%s -> %s = %d\n", s, p, res);\
	}\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	TEST_MATCH("", "A*");
	TEST_MATCH("A", "A*");
	TEST_MATCH("AB", "A*");
	TEST_MATCH("", "A");
	TEST_MATCH("A", "AA");
	TEST_MATCH("AZ", "AB*C*D*E*F*G*H*I*J*K*L*M*N*O*P*Q*R*S*T*U*V*W*X*Y*Z");
	TEST_MATCH("AFJLOSWZ", "AB*C*D*E*F*G*H*I*J*K*L*M*N*O*P*Q*R*S*T*U*V*W*X*Y*Z*");
	TEST_MATCH("H", "H");
	TEST_MATCH("HH", "H");
	TEST_MATCH("HH", "H*");
	TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

	TEST_MATCH("Holberton", ".*");
	TEST_MATCH("Alex", ".*");
	TEST_MATCH("Guillaume", ".*");
	TEST_MATCH("Julien", ".*");

	TEST_MATCH("Holberton", "Z*H.*");
	TEST_MATCH("Holberton", "Z*H.*olberton");
	TEST_MATCH("Holberton", "Z*H.*o.");
	TEST_MATCH("Holberton", "Z*H.*o");

	TEST_MATCH("Holberton", "holberton");
	TEST_MATCH("Holberton", ".olberton");

	TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

	return (EXIT_SUCCESS);
}
