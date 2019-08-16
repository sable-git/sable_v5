CC = gcc
# gcc options
CFLAGS = -O3 -lm
#LFLAGS = -O3 -lm

#
#  files involved in the project
#
NETS =  Approx_1 Approx_el_1 Therm_015 Therm_115 Therm_315 wxApp_BP_00\
	wxApp_BP_01 wxApp_BP_02 wxApp_JERP_00 wxApp_RP_1 wxApp_RP_2\
	wxApp_elBP_0 wxApp_elBP_1 wxApp_elRP_0 wxApp_elRP_2

all: $(NETS)
Approx_1: Main_App.c Approx_1.c
	$(CC) $(CFLAGS) Main_App.c Approx_1.c -o Approx_1
Approx_el_1: Main_App.c Approx_el_1.c
	$(CC) $(CFLAGS) Main_App.c  Approx_el_1.c -o Approx_el_1
Therm_115: Main_Therm.c Therm_115.c
	$(CC) $(CFLAGS) Main_Therm.c Therm_115.c -o Therm_115
Therm_015: Main_Therm.c Therm_015.c
	$(CC) $(CFLAGS) Main_Therm.c Therm_015.c -o Therm_015
Therm_315: Main_Therm.c Therm_315.c
	$(CC) $(CFLAGS) Main_Therm.c Therm_315.c -o Therm_315
wxApp_BP_00: Main_App.c wxApp_BP_00.c
	$(CC) $(CFLAGS) Main_App.c wxApp_BP_00.c -o wxApp_BP_00
wxApp_BP_01: Main_App.c wxApp_BP_00.c
	$(CC) $(CFLAGS) Main_App.c wxApp_BP_01.c -o wxApp_BP_01
wxApp_BP_02: Main_App.c wxApp_BP_00.c
	$(CC) $(CFLAGS) Main_App.c wxApp_BP_02.c -o wxApp_BP_02
wxApp_JERP_00: Main_App.c wxApp_JERP_00.c
	$(CC) $(CFLAGS) Main_App.c wxApp_JERP_00.c -o wxApp_JERP_00
wxApp_RP_1: Main_App.c wxApp_RP_1.c
	$(CC) $(CFLAGS) Main_App.c wxApp_RP_1.c -o wxApp_RP_1
wxApp_RP_2: Main_App.c wxApp_RP_2.c
	$(CC) $(CFLAGS) Main_App.c wxApp_RP_2.c -o wxApp_RP_2
wxApp_elBP_0: Main_App.c wxApp_elBP_0.c
	$(CC) $(CFLAGS) Main_App.c wxApp_elBP_0.c -o wxApp_elBP_0
wxApp_elBP_1: Main_App.c wxApp_elBP_1.c
	$(CC) $(CFLAGS) Main_App.c wxApp_elBP_1.c -o wxApp_elBP_1
wxApp_elRP_0: Main_App.c wxApp_elRP_0.c
	$(CC) $(CFLAGS) Main_App.c wxApp_elRP_0.c -o wxApp_elRP_0
wxApp_elRP_2: Main_App.c wxApp_elRP_2.c
	$(CC) $(CFLAGS) Main_App.c wxApp_elRP_2.c -o wxApp_elRP_2

clean: 
	rm -f $(NETS)
	rm -f *.o


