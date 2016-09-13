CXX = g++
CXXFLAGS = -std=c++0x

OBJS = Barbarian.o BlueMen.o Creature.o Die.o HarryPotter.o Medusa.o Vampire.o ${PROGNAME}.o  HelperClass.o Node.o Queue.o Stack.o

SRCS = Barbarian.cpp  BlueMen.cpp Creature.cpp Die.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp ${PROGNAME}.cpp HelperClass.cpp Node.cpp Queue.cpp Stack.cpp

HEADERS = Barbarian.h BlueMen.h Creature.h Die.h HarryPotter.h HelperClass.h Medusa.h Vampire.h Node.h Queue.h Stack.h

PROGNAME = assingment4


${PROGNAME}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROGNAME}
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean: 
	rm -f *.o *.out ${PROGNAME}
