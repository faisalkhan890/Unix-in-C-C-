Emacemacs CXX = g++
CXXFLAGS = -Wall
CPPFLAGS = -I/home/012/s/sx/sxs172532/tclap-1.2.1/include -I/home/012/s/sx/sxs172532/hws/hw5/rude/include

LDFLAGS = -L/home/012/s/sx/sxs172532/hws/hw5/rude/lib
LDLIBS = -lrudeconfig 

OBJS = program5.o processControl.o parseCommandLine.o parseConfigFile.o signalHandler.o inotifyFunctions.o
EXECFILE = program5

.PHONY: all clean

all: $(EXECFILE)
clean:
	rm -f $(OBJS) *~ $(EXECFILE)

$(EXECFILE): $(OBJS)
	$(CXX) -static -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
