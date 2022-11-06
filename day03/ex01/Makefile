NAME	=	ScavTrap

CC			=	c++
INCLUDES	=	includes
CPPFLAGS	=	-MD -Wall -Werror -Wextra -std=c++98 -I$(INCLUDES)
RM			=	rm -rf

SRCS		=	srcs/ClapTrap.cpp \
				srcs/ScavTrap.cpp \
				srcs/main.cpp

OBJS		=	$(SRCS:%.cpp=%.o)
DEPS		=	$(SRCS:%.cpp=%.d)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "Linked into executable $(NAME)"

.cpp.o:
			@$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(OBJS)
			@$(RM) $(DEPS)
			@echo "Removed object files." 

fclean:		clean
			@$(RM) $(NAME)
			@echo "Removed executable."

re:			fclean 
			make

-include $(DEPS)

.PHONY:		fclean, all, re
