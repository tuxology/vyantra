#include <stdio.h>
#include "yasparser.h"
#include "yaslexer.h"
#include <assert.h>

int main(int argc, char *argv[]) {
	pANTLR3_INPUT_STREAM input;
	pANTLR3_COMMON_TOKEN_STREAM tokens;
	pyasparser parser;
	pyaslexer lexer;

	input = antlr3AsciiFileStreamNew((pANTLR3_UINT8) argv[1]);
	assert(input != NULL);
	lexer = yaslexerNew(input);
	assert(lexer != NULL);
	tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
	assert(tokens != NULL);
	parser = yasparserNew(tokens);
	assert(parser != NULL);



	parser->start(parser);

	printf("DONE\n");

	parser->free(parser);
	tokens->free(tokens);
	lexer->free(lexer);
	input->close(input);

	return 0;
}
