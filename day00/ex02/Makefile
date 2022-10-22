NAME	=	Accounting

SRCS		=	srcs/Account.cpp \
				tests.cpp
OBJS		=	$(SRCS:.cpp=.o)
INCLUDES	=	includes

CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDES)

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

.PHONY:		fclean, all, re