CC= g++
# CFLAGS= -Wall -Wextra -Wpedantic -Werror -O3 -pg --save-temps -fPIC
CFLAGS= -Wall

CFILES = *.cpp
OBJ= *.o
TARGET= Tester

all:	exec

exec:	${TARGET}
	./${TARGET}

${TARGET}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o $@

${OBJ}:	${CFILES}
	${CC} ${CFLAGS} -c ${CFILES}

clean:
	rm -rfv ${TARGET} ${OBJ} *.ii *.s *bc gmon.out
