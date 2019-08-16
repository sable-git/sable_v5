CC = gcc
# gcc options
CFLAGS = -O3 -lm
#LFLAGS = -O3 -lm

#
#  files involved in the project
#
NETS =  conf_1 conf_2 conf_3 conf_4 conf_5
all: $(NETS)
conf_1: Main.c conf_1.c
	$(CC) $(CFLAGS) Main.c conf_1.c -o conf_1
conf_2: Main.c conf_2.c
	$(CC) $(CFLAGS) Main.c conf_2.c -o conf_2
conf_3: Main.c conf_3.c
	$(CC) $(CFLAGS) Main.c conf_3.c -o conf_3
conf_4: Main.c conf_4.c
	$(CC) $(CFLAGS) Main.c conf_4.c -o conf_4
conf_5: Main.c conf_5.c
	$(CC) $(CFLAGS) Main.c conf_5.c -o conf_5
clean: 
	rm -f $(NETS)
	rm -f *.o


