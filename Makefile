# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g


SRCDIR = src
INCDIR = include
BINDIR = bin

all: Day1 Day2

Day1:
	$(info Building: $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR)/Helpers/ -o $(BINDIR)/$@.exe $(wildcard $(SRCDIR)/$@/*.cpp) $(wildcard $(SRCDIR)/Helpers/*.cpp)

Day2:
	$(info Building: $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR)/Helpers/ -I$(INCDIR)/$@/ -o $(BINDIR)/$@.exe $(wildcard $(SRCDIR)/$@/*.cpp) $(wildcard $(SRCDIR)/Helpers/*.cpp)

Day3:
	$(info Building: $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR)/Helpers/ -I$(INCDIR)/$@/ -o $(BINDIR)/$@.exe $(wildcard $(SRCDIR)/$@/*.cpp) $(wildcard $(SRCDIR)/Helpers/*.cpp)

# Clean target
clean:
	del $(subst /,\,$(wildcard $(BINDIR)/*.exe))
