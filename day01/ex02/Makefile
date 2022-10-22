NAME	=	ShowMemory

CC			=	clang++
CPPFLAGS	=	-Wall -Werror -Wextra 
RM			=	rm -rf

SRCS		=	main.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "Linked into executable $(NAME)"

.cpp.o:
			@$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(OBJS)
			@echo "Removed object files." 

fclean:		clean
			@$(RM) $(NAME)
			@echo "Removed executable."

re:			fclean all