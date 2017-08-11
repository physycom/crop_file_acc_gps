
FILES = crop_file.cpp

EXES = $(addsuffix .exe, $(basename $(FILES)))

OPT = -std=c++11 


all: $(EXES)


%.exe: src/%.cpp
	$(CXX) $(OPT) -o $@ $< -lboost_filesystem -lboost_system

clean:
	rm -f $(EXES) *~ .*~ 

cleanall: clean

