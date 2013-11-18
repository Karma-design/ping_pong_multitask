COMP = gcc
EDL = gcc
ECHO = echo
RM =rm
CPPFLAG = 

PATH_LIB= 
PATH_H= 
SRC= $(wildcard *.c)
H= $(wildcard *.h)
OBJETS = $(SRC:.c=.o)

EXE = Pingpong
EFFACE = clean
LIBS= -L$(PATH_LIB)
${EXE}:${OBJETS}
	${ECHO} "edl de ${EXE}"
	${EDL} -o ${EXE} ${OBJETS} #${LIBS}

%.o:%.cpp 
	${ECHO} "compile de <$<>"
	${COMP} -c $<
main.o:main.c

${EFFACE}:
	${RM} ${EXE} ${OBJETS}
