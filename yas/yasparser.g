parser grammar yasparser;

options {
    language = C;
    output = AST;
    tokenVocab = yaslexer;
}

tokens {
	ADD_TOK;
	REG_TOK;
	EOL;
}

start:
	operation* EOF
	;

operation:
	operation_add EOL+
	;

operation_add:
	ADD_TOK REG_TOK REG_TOK REG_TOK
	;
