CC = gcc
# gcc options
CFLAGS = -O3 -lm
#LFLAGS = -O3 -lm

#
#  files involved in the project
#
NETS =  EL2_W EL2 EL4_W EL4 EL6_W te te3 te4 tm6 

all: $(NETS)

EL2_W: Main.c EL2_W.c
	$(CC) $(CFLAGS) Main.c EL2_W.c -o EL2_W
EL2: Main.c EL2.c
	$(CC) $(CFLAGS) Main.c EL2.c -o EL2
EL4_W: Main.c EL4_W.c
	$(CC) $(CFLAGS) Main.c EL4_W.c -o EL4_W
EL4: Main.c EL4.c
	$(CC) $(CFLAGS) Main.c EL4.c -o EL4
EL6_W: Main.c EL6_W.c
	$(CC) $(CFLAGS) Main.c EL6_W.c -o EL6_W
te: Main.c te.c
	$(CC) $(CFLAGS) Main.c te.c -o te
te3: Main.c te3.c
	$(CC) $(CFLAGS) Main.c te3.c -o te3
te4: Main.c te4.c
	$(CC) $(CFLAGS) Main.c te4.c -o te4
tm6: Main.c tm6.c
	$(CC) $(CFLAGS) Main.c tm6.c -o tm6

clean: 
	rm -f $(NETS)
	rm -f *.o


