CC = gcc
# gcc options
CFLAGS = -O3 -lm
#LFLAGS = -O3 -lm

#
#  files involved in the project
#
NETS = net net2 singSA compSA netconfSA
all: $(NETS)
net: 
	cd networks && $(MAKE)
net2:
	cd networks2 && $(MAKE)
singSA:
	cd singleSA && $(MAKE)	
compSA:
	cd complexSA && $(MAKE)
netconfSA:
	cd networksconfSA && $(MAKE)
clean: clean_net clean_net2 clean_singleSA clean_complexSA clean_netconf
clean_net:
	cd networks && $(MAKE) clean
clean_net2:
	cd networks2 && $(MAKE) clean
clean_singleSA:
	cd singleSA && $(MAKE) clean
clean_complexSA:
	cd complexSA && $(MAKE) clean	
clean_netconf:
	cd networksconfSA && $(MAKE) clean

	

