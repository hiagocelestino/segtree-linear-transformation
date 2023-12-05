CC := g++
SRCDIR := src
OBJDIR := obj
BINDIR := bin

EXE := bin/main.out
MAIN := src/main.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f \( -name *.$(SRCEXT) ! -name main.cpp \) )
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# -g debug
CFLAGS := -g -Wall -O0 -std=c++14 -pg
INC := -I include/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/tp3.out

all: main

run: main
	$(BINDIR)/tp3.out

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno *.zip

