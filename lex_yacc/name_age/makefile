
APP=name_age
CC=gcc
YACC_FILE=y.tab.c y.tab.h
LEX_FILE=lex.yy.c

${APP}: ${YACC_FILE} ${LEX_FILE}
	${CC} $^ -o $@

${YACC_FILE}:name.y
	yacc -d $<

${LEX_FILE}:name.lex
	lex $^

clean:
	rm ${YACC_FILE} ${LEX_FILE} ${APP}
