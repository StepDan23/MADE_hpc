NAME = mat_mul
FLAGS = -std=c++14
OPT = -O3
DEBUG_FLAG = -g
SRCS = main.cpp matrix.cpp
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	g++ $(FLAGS) $(DEBUG_FLAG) $(OPT) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)_debug

run: $(NAME)
	@./$(NAME) 500
	@./$(NAME) 512
	@./$(NAME) 1000
	@./$(NAME) 1024
	@./$(NAME) 2000
	@./$(NAME) 2048