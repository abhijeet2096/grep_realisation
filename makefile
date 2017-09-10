object = grep.o function.o
compiler = gcc
flags = -lpthread -o 	
target = grep
$(target) : $(object)
	$(compiler) $(flags) $(target) $(object)
	make refresh

main.o : grep.c function.h

function.o : function.c function.h

refresh :
	rm -f *.o
	rm -f /testcase/Output/*

clean :
	rm -f *.o
	rm -f $(target)
