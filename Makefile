NAME = converter

CC = -std=c++11
LIBPATH = /usr/local/Cellar/dxflib/2.5.0.0-1/lib
LIB = dxflib

SRC = DXFBlock.cpp \
	  main.cpp \
	  DXFParser.cpp \
	  DXFPline.cpp \
	  Point.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)

$(NAME):
	  clang++ $(SRC) -L$(LIBPATH) $(CC) -l$(LIB)  -o $(NAME)

clean:
	rm -f $(OBJS)

%.o: %.c
	clang++ $(CC) -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: fclean all
