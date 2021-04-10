GCC := gcc -Wall -Wextra -Werror -g3 -fsanitize=address
OBJECT := srcs/rush.o
FILE := rush

all: $(FILE)

$(FILE): $(OBJECT)
	$(GCC) -o $(FILE) $(OBJECT)

%.o: %.c
	$(GCC) -o $@ -c $<

clean:
	rm -f $(OBJECT)

fclean:
	rm -f $(FILE) $(OBJECT)

re: fclean all