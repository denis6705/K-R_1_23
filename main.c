#include <stdio.h>
#include <string.h>
/* this program is solution of K&R 1.23 */
#define MAX_S 100

int main(void) {

	int in_comment = 0; /* we are in comment ? */
	int in_quotes = 0; /* are we in quotes ? */
	int c;
	char s[MAX_S];
	int i;
	size_t len;

	while ( fgets(s, MAX_S, stdin) != NULL ) {

		len = strlen(s);
		for (i = 0; i < len; ++i) {
			if( s[i] == '"' && !in_quotes && !in_comment){
				in_quotes = 1;
				putchar(s[i]);
			}
			else if( s[i] == '"' && in_quotes && !in_comment){
				in_quotes = 0;
				putchar(s[i]);
			}
			else if( s[i] == '/' && !in_quotes && !in_comment && s[i + 1] == '*')
			{
				in_comment = 1;
				i++;
			}
			else if( s[i] =='*' && in_comment && s[i+1] == '/')
			{
				in_comment = 0;
				i++;
			}
			else if(in_comment) 
				;
			else if(!in_comment) putchar(s[i]);

		}

	}
	return 0;
}
