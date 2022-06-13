SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall
TARGET = libmy.a
HEADER_NAME = my.h

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rc $(TARGET) $(OBJ)
	cp $(HEADER_NAME) ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re : fclean all
