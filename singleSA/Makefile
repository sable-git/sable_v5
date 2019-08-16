CC = gcc
# gcc options
CFLAGS = -O3 -lm
#LFLAGS = -O3 -lm

#
#  files involved in the project
#
NETS =  Pfam_BP_0_4 Pfam_BP_1_2 Pfam_BP_2_6 Pfam_RPn_0_7 Pfam_RPn_1_8 Pfam_RPn_2_7 Pfam_RPreg_all_0_11 Pfam_BP_reg_all_0_12 Pfam_BP_reg_all_1_10

all: $(NETS)
Pfam_BP_0_4: Main_App.c Pfam_BP_all_0_4.c
	$(CC) $(CFLAGS) Main_App.c Pfam_BP_all_0_4.c -o Pfam_BP_0_4
Pfam_BP_1_2: Main_App.c Pfam_BP_all_1_2.c
	$(CC) $(CFLAGS) Main_App.c  Pfam_BP_all_1_2.c -o Pfam_BP_1_2
Pfam_BP_2_6: Main_App.c Pfam_BP_all_2_6.c 
	$(CC) $(CFLAGS) Main_App.c Pfam_BP_all_2_6.c  -o Pfam_BP_2_6
Pfam_RPn_0_7: Main_App.c Pfam_RP_all_0_7.c
	$(CC) $(CFLAGS) Main_App.c Pfam_RP_all_0_7.c -o Pfam_RPn_0_7
Pfam_RPn_1_8: Main_App.c Pfam_RP_all_1_8.c
	$(CC) $(CFLAGS) Main_App.c Pfam_RP_all_1_8.c -o Pfam_RPn_1_8
Pfam_RPn_2_7: Main_App.c Pfam_RP_all_2_7.c
	$(CC) $(CFLAGS) Main_App.c Pfam_RP_all_2_7.c -o Pfam_RPn_2_7
Pfam_RPreg_all_0_11: Main_App.c Pfam_RP_reg_all_0_11.c
	$(CC) $(CFLAGS) Main_App.c Pfam_RP_reg_all_0_11.c -o Pfam_RPreg_all_0_11
Pfam_BP_reg_all_0_12: Main_App.c Pfam_BP_reg_all_0_12.c
	$(CC) $(CFLAGS) Main_App.c Pfam_BP_reg_all_0_12.c -o Pfam_BP_reg_all_0_12
Pfam_BP_reg_all_1_10: Main_App.c Pfam_BP_reg_all_1_10.c
	$(CC) $(CFLAGS) Main_App.c Pfam_BP_reg_all_1_10.c -o Pfam_BP_reg_all_1_10
	
	

clean: 
	rm -f $(NETS)
	rm -f *.o


