# Parser
#include <stdio.h>
#include <stdlib.h>

void factor();
void term();
void expr();

void factor() {
  printf("Enter <factor>\n", );

  if (nextToken == IDENT || nextToken == INT_LIT) {
    // Get the next token
    lex();
  } else {
    if (nextToken == LEFT_PAREN) {
      lex();
      expr();
      if (nextToken == RIGHT_PAREN) {
        lex();
      } else {
        error();
      }
    } else {
      error();
    }
  }
  printf("Exit <factor>\n", );
}

void term() {
  printf("Enter <term>\n");

  /* Parse the first factor */
  factor();

  /* As long as the next token is * or /, get the
   next token and parse the next factor */

  while nextToken == MULTI_OP || nextToken == DIV_OP) {
    lex();
    factor();
  }
  printf("Exit <term>\n", );
}

void expr() {
  printf("Enter <expr>\n");

  /* Parse the first term */
  term();

  /* As long as the next token is + or -, get
    the next token and parse the next term */
  while (nextToken == ADD_OP || nextToken == SUB_OP) {
     lex();
     term();
  }

  printf("Exit <expr>\n");

}

int main() {
  FILE *f;
  char c;
  f = fopen("input.txt", "rt");

  fclose(f);
  return 0;
}
