# Makefile
PROG = wifibot
SRCS=  *.cpp
OBJECTS = $(SRCS:.cpp=.o)

# Options de compilation
CXXFLAGS = -std=c++11 -pthread
# Options édition de lien
LDFLAGS = -lpthread
# Dépendance gtkmm-3.0
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags`
GTKLIBS = `pkg-config gtkmm-3.0 --libs`


all: $(PROG)
$(PROG): $(SRCS)
	$(CXX) -c $(SRCS) $(CXXFLAGS) $(GTKFLAGS)
	$(CXX) -o $(PROG) $(OBJECTS) $(LDFLAGS) $(GTKLIBS)
	$(RM) -r $(OBJECTS)

.PHONY: clean clean+
clean:
	$(RM) -r $(OBJECTS)

clean+:
	$(RM) -r $(OBJECTS) $(PROG)