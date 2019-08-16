CC = gcc
# gcc options
CFLAGS = -O3 -lm
#LFLAGS = -O3 -lm

#
#  files involved in the project
#
NETS =  EL_2_W_S EL_2_S EL_4_W_S EL_4_S EL_6_W_S ENTR2_W ENTR2 \
	ENTR4_W ENTR4 ENTR6_W te_1 te_S te_3 te3_S te_4 te4_S tm_6 tm6_S 
all: $(NETS)
EL_2_W_S: Main.c EL_2_W_S.c
	$(CC) $(CFLAGS) Main.c EL_2_W_S.c -o EL_2_W_S
EL_2_S: Main.c EL_2_S.c
	$(CC) $(CFLAGS) Main.c EL_2_S.c -o EL_2_S
EL_4_W_S: Main.c EL_4_W_S.c
	$(CC) $(CFLAGS) Main.c EL_4_W_S.c -o EL_4_W_S
EL_4_S: Main.c EL_4_S.c
	$(CC) $(CFLAGS) Main.c EL_4_S.c -o EL_4_S
EL_6_W_S: Main.c EL_6_W_S.c
	$(CC) $(CFLAGS) Main.c EL_6_W_S.c -o EL_6_W_S
ENTR2_W: Main.c ENTR2_W.c
	$(CC) $(CFLAGS) Main.c ENTR2_W.c -o ENTR2_W
ENTR2: Main.c ENTR2.c
	$(CC) $(CFLAGS) Main.c ENTR2.c -o ENTR2
ENTR4_W: Main.c ENTR4_W.c
	$(CC) $(CFLAGS) Main.c ENTR4_W.c -o ENTR4_W
ENTR4: Main.c ENTR4.c
	$(CC) $(CFLAGS) Main.c ENTR4.c -o ENTR4
ENTR6_W: Main.c ENTR6_W.c
	$(CC) $(CFLAGS) Main.c ENTR6_W.c -o ENTR6_W
te_1: Main.c te_1.c
	$(CC) $(CFLAGS) Main.c te_1.c -o te_1
te_S: Main.c te_S.c
	$(CC) $(CFLAGS) Main.c te_S.c -o te_S
te_3: Main.c te_3.c
	$(CC) $(CFLAGS) Main.c te_3.c -o te_3
te3_S: Main.c te3_S.c
	$(CC) $(CFLAGS) Main.c te3_S.c -o te3_S
te_4: Main.c te_4.c
	$(CC) $(CFLAGS) Main.c te_4.c -o te_4
te4_S: Main.c te4_S.c
	$(CC) $(CFLAGS) Main.c te4_S.c -o te4_S
tm_6: Main.c tm_6.c
	$(CC) $(CFLAGS) Main.c tm_6.c -o tm_6
tm6_S: Main.c tm6_S.c
	$(CC) $(CFLAGS) Main.c tm6_S.c -o tm6_S

clean: 
	rm -f $(NETS)
	rm -f *.o

