NAME	=	ShowMemory

CC			=	c++
CPPFLAGS	=	-MD -Wall -Werror -Wextra -std=c++98 
RM			=	rm -rf

SRCS		=	main.cpp
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

DEPS		=	$(SRCS:%.cpp=%.d)

re:			fclean all