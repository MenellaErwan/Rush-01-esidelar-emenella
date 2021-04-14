GCC := gcc -Wall -Wextra -Werror -g3 
OBJECT := srcs/rush.o srcs/gnl.o
FILE := rush
HEADER := srcs/rush.h

all: $(FILE)

$(FILE): $(OBJECT)
	$(GCC) -o $(FILE) $(OBJECT)

%.o: %.c $(HEADER)
	$(GCC) -o $@ -c $<

clean:
	rm -f $(OBJECT)

fclean:
	rm -f $(FILE) $(OBJECT)

re: fclean all