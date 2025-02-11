CPP = c++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

PROGRAM_NAME = PhoneBook

SRCDIR := ./class
INCDIR := ./

SRC := $(wildcard $(SRCDIR)/*.cpp) 
SRC += main.cpp

INCLUDES := -I$(INCDIR)

OBJDIR := objs
OBJS := $(SRC:$(SRCDIR)//%.cpp=$(OBJDIR)/%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/class

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.hpp | $(OBJDIR)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re

#format-----------------------------------------------------------------------

.PHONY: format

format:
	clang-format --style=Google -i $(SRC)