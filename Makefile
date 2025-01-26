PARSER = syntax_analysis
WRITE_OUTPUT = write_to_output_file
COMPILER = compiler

$(COMPILER) : main.o $(PARSER).o $(WRITE_OUTPUT).o 
	gcc main.o $(PARSER).o $(WRITE_OUTPUT).o -o $(COMPILER)
main.o : main.c 
	gcc -c -g main.c -o main.o
$(PARSER).o : $(PARSER).c 
	gcc -c -g $(PARSER).c -o $(PARSER).o
$(WRITE_OUTPUT).o : $(WRITE_OUTPUT).c 
	gcc -c -g $(WRITE_OUTPUT).c -o $(WRITE_OUTPUT).o
clean : 
	rm $(COMPILER) *.o


