CPP = clang++
SRCS = main.cpp TCore.cpp
##OBJS = $(subst .cpp,.o,$(SRCS))
OBJS = main.o   TCore.o
CPPFLAGS = -std=c++11 -g

##EXE

tt : $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

TCore.o: TCore.cpp TCore.h
	$(CPP) -c $(CPPFLAGS) $<

main.o: main.cpp TCore.h
	$(CPP) -c $(CPPFLAGS) $< 



clean :
	rm tt *.o
