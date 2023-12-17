# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
COMMONDIR = src/Helpers
SRCDIRS = src/Day1 src/Day2
INCDIR = include
BINDIR = bin

# Common source files and object files
COMMON_SOURCES = $(wildcard $(COMMONDIR)/*.cpp)
COMMON_OBJECTS = $(patsubst $(COMMONDIR)/%.cpp,$(BINDIR)/common_%.o,$(COMMON_SOURCES))

# Subproject source files and object files
SOURCES = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
OBJECTS = $(patsubst %.cpp,$(BINDIR)/%.o,$(notdir $(SOURCES)))

# Executable names
TARGETS = $(patsubst src/%/main%.cpp,%,$(SOURCES))

# Main target
all: $(addprefix $(BINDIR)/,$(TARGETS))

# Linking for subprojects
$(BINDIR)/%: $(BINDIR)/%.o $(filter %/main%.o,$(OBJECTS)) $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation for subprojects
$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Compilation for common files
$(BINDIR)/common_%.o: $(COMMONDIR)/%.cpp $(INCDIR)/common/%.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Clean target
clean:
	rm -f $(BINDIR)/*.o $(addprefix $(BINDIR)/,$(TARGETS))
