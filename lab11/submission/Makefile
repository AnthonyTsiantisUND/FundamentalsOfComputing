CMP = gcc
MAIN = project
FUNC = flappyBlocFunc
EXEC = project

$(EXEC): $(FUNC).o $(MAIN).o 
	$(CMP) $(FUNC).o $(MAIN).o gfx.o -lX11 -lm -o $(EXEC)

$(FUNC).o: $(FUNC).c $(FUNC).h 
	$(CMP) -c $(FUNC).c -lX11 -o $(FUNC).o 

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -c $(MAIN).c -lX11 -o $(MAIN).o 

clean:
	rm $(FUNC).o
	rm $(MAIN).o
	rm $(EXEC)

