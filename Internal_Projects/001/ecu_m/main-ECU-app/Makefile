IDIR	= include
SDIR	= src
ODIR	= obj
CC		= gcc
LDFLAGS	= -I${IDIR} -lpthread

OBJ =	${ODIR}/MainApplication.o \
		${ODIR}/CanLib.o \
		${ODIR}/TestLib.o

${ODIR}/%.o: ${SDIR}/%.c
	${CC} -c -o $@ $< ${LDFLAGS}

MainApplication: ${OBJ}
	${CC} -o $@ $^ ${LDFLAGS}

.PHONY: clean

clean:
	rm -f ${ODIR}/*.o MainApplication
