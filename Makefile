SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -W -Wextra -Wall -I./include
LDFLAGS = -L./lib/my -lmy
TARGET = navy
COMMIT=default

all : lib_make $(TARGET)

lib_make:
	make -C lib/my

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ) $(LDFLAGS)

clean :
	rm -f $(OBJ)
	make clean -C lib/my

fclean : clean
	rm -f $(TARGET)
	make fclean -C lib/my

re : fclean all
	make re -C lib/my

push : fclean
	git add .
	git commit -m $(COMMIT)
	git push