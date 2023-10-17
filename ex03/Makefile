TARGET  = a.out

CC      = c++

OBJDIR  = obj

CPPFLAG = -Werror -Wall -Wextra -std=c++98 #-g3 -fsanitize=address

SRC     =	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJ     = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CPPFLAG) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -fr $(TARGET) $(OBJDIR)

re: fclean $(TARGET)

.PHONY: clean fclean re
