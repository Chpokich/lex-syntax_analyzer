PARSER = syntax_analysis
ANALYSIS = analysis

$(ANALYSIS) : main.o $(PARSER).o 
	gcc main.o $(PARSER).o -o $(ANALYSIS)
main.o : main.c 
	gcc -c -g main.c -o main.o
$(PARSER).o : $(PARSER).c 
	gcc -c -g $(PARSER).c -o $(PARSER).o
clean : 
	rm $(ANALYSIS) *.o


