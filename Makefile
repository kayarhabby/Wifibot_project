# Makefile
PROG = 
SRCS= 
OBJECTS = $(SRCS:.cpp=.o)

# Options de compilation
CXXFLAGS = -std=c++11 -pthread
# Options édition de lien
LDFLAGS = -lpthread
# Dépendance gtkmm-3.0
GTKFLAGS = 
GTKLIBS = 


all: $(PROG)
$(PROG): $(SRCS)
	$(CXX) -c $(SRCS) $(CXXFLAGS) $(GTKFLAGS)
	$(CXX) -o $(PROG) $(OBJECTS) $(LDFLAGS) $(GTKLIBS)


.PHONY: clean clean+
clean:
	$(RM) -r $(OBJECTS)

clean+:
	$(RM) -r $(OBJECTS) $(PROG)