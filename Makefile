NAME = converter

CC = -std=c++0x
LIBPATH = dxflib-3.17.0-src/src
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
	  g++ $(SRC) -L$(LIBPATH) $(CC) -l$(LIB)  -o $(NAME)

clean:
	rm -f $(OBJS)

%.o: %.c
	g++ $(CC) -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: fclean all
