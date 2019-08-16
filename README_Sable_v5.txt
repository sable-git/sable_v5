_____________________________________________________________________

This is the SABLE distribution package, version 5.0 as of August 15 2019
_____________________________________________________________________

This version is primarily intendend for Unix platforms, however it should be
easily portable to Windows and other platforms as well. We tested the present
distribution on SuSe Linux 13.2, CentOS (6.4)/RedHat (4.4.6)  and Cygwin under Windows.
In addition, a Docker container is included to run Sable on cloud platforms.

While the method itself is identical to that of sable version 3.0, starting from ver. 4.0, 
this updated distribution makes a number of adjustments to make optimal use of growing 
sequence databases and newer version of blast (2.2.28). The current version also adds
a hot start option for PSSMs to avoid repetead generation of PSSMs for essentially
the same query sequence (e.g., for assessing consequences of mutations), and to enable
placing a qeuery sequence into an evolutionary field of another fold 
for assessment of protein stability and conformational switches (see Chen et al., Protein Science 2016).  

Please refer to the brief documentation below and benchmark files
included in directory TESTS_BENCHMARKS for assessment of improvments due to reduced sequence databases.


In order to learn how to install the package jump to "HOW TO INSTALL SABLE"

______________________

ABOUT THE SABLE METHOD
______________________

The SABLE package can be used for predicting real valued relative 
Solvent AccessiBiLitiEs (RSA) of amino acid residues in proteins, 
and for improved prediction of secondary structures using
evolutionary profiles and predicted relative solvent accessibility
of an amino acid residue as a fingerprint of the overall packing.

The SABLE package provides results consistent with the current
version of the SABLE server available at http://sable.cchmc.org,
provided that the same sequence databases and PsiBLAST version 
are used. The results of SABLE can be represented graphically using 
the POLYVIEW server, available at http://polyview.cchmc.org.

The methods implemented in the SABLE package were developed in the 
group of Jarek Meller, primarily by Rafal Adamczak who developed
non-linear regression models and classification models for sec. struct.,
with help of Aleksey Porollo who developed control sets and elements of 
the server and Michael Wagner who developed the SVR regression models. 
Please, use the following references when referring to SABLE and its results:

R. Adamczak, A. Porollo, J. Meller, 
Accurate Prediction of Solvent Accessibility Using Neural Networks Based Regression, 
Proteins: Structure, Function and Bioinformatics, 56(4):753-67 (2004).

R. Adamczak, A. Porollo, J. Meller, 
Combining Prediction of Secondary Structures and Solvent Accessibility in Proteins,
Proteins: Structure, Function and Bioinformatics, 59(3):467-75 (2005).

M. Wagner, R. Adamczak, A. Porollo, J. Meller, 
Linear Regression Models for Prediction of Solvent Accessibility in Proteins,
J. Comp. Biol. 12(3):355-69 (2005).

To find out more about the method and the interpretation of the results,
please visit http://sable.cchmc.org or http://folding.chmcc.org.

______________________

Copyright 2003, 2004 Jaroslaw Meller, Rafal Adamczak and Aleksey Porollo
______________________

The SABLE program (SABLE package) is distributed free of charge under the terms of 
the GNU General Public License (see the license.txt file for details), 
with the additional explicit restriction that SABLE must not be used for direct 
commercial gain. Use of the SABLE program is at your own risk and no liability is 
accepted for any loss or damage arising through use the SABLE predictions.

SABLE makes use of the PsiBLAST program for sequence alignment
by S. Altschul and colleagues and we hereby thank the authors of PsiBLAST
for making their program available as a public domain package. It is our intention
that SABLE will be used in a similar spirit to advance scientific research.

______________________

HOW TO INSTALL SABLE
______________________


STEP 1. Compilation

First, one needs to compile all the source code files included in the SABLE
distribution. This can be done using the Makefile included in this distribution, 
which is prepared for the gcc compiler (should you need another compiler you
need to modify the Makefile accordingly). Current distribution has executables
for SuSe 9.1 Linux and Windows. If you have one of these systems you may omit 
this step. In order to compile all the files using the default Makefile, simply 
type in the main distribution directory:

make


STEP 2. Installation of the PsiBLAST program and sequence databases

Secondly, one needs to download and install the following software and databases:

1) BLAST+, available for instance from the NCBI web pages
   (ftp://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/). 
   Please refer to the BLAST+  documentation regarding the BLAST+ installation. 
   Please note also that BLAST+ is provided free of charge under specific terms 
   defined elsewhere and it is your responsibility to be in compliance with those 
   terms when downloading BLAST+. The current version was tested with blast version 2.2.28.

2) The nr available from the NCBI web pages (ftp://ftp.ncbi.nlm.nih.gov/blast/db/FASTA/). 

3) Nr database must be formatted by makeblastdb (included in blast package) or one can download database already formated (ftp://ftp.ncbi.nlm.nih.gov/blast/db/)

4) Sable uses two gi index files to define PRIMARY_DATABASE and SECONDARY_DATABASE (see run.sable).
   These index files define subsets of NR database to build multiple alignments. 
   
   If no PRIMARY_DATABASE is defined the entire nr as downloaded by the user 
   (located in directory specified by NR_DIR variable) becomes the primary database.
   Two ready to use gi index files are included in sable distribution (in GI_indexes directory) to define subsets 
   correspoding to swissprot and pfam databases. 

   Should you need another index, e.g. to use a different subset of nr, please prepare another index file 
   following the same format and edit the run script to define the PRIMARY_DATABASE or SECONDARY_DATABASE variable.
   
   Please note that sable expects that the primary database corresponds to a bigger sequence database
   (originally the entire nr). The secondary database, on the other hand, is expected to be a smaller, 
   well annotated sequence database (originally swissprot).
   
   These index files have been introduced to enable reducing growing nr to non-redundant and smaller subsets. Using
   the current pfam index (consisting of about 10 mln sequences that have at least one annotated pfam entry mapped)
   speeds up the computation by a factor of 3 with respect to the full nr, while increasing accuracy of secondary 
   structure prediction by about 1%.

5) Perl - version not lower than 5.6. Perl is a standard tool on Unix platforms, perl for Windows
   is available from http://www.activestate.com/Products/ActivePerl, perl is also available
   in the distribution of cygwin (http://www.cygwin.com/).

STEP 3. Running SABLE

SABLE is being executed by the run.sable (under unix, bash script) or run_sable.bat (under windows), 
which are included in the distribution.
One may need to edit the run.sable (run_sable.bat) file in order to setup appropriate paths and
other variables. These variables (SABLE_DIR,BLAST_DIR,NR_DIR,SWISS_DIR) are set to the following
values: $home/sable_distr, $home/sable_distr/blast, $home/sable_distr/nr, $home/sable_distr/swissprot
on Unix and : C:\sable_distr, C:\sable_distr\blast, C:\sable_distr\nr, C:\sable_distr\swissprot on
Windows, rescpectively.

The query sequences for which secondary structures/ solvent accessibilities are to be generated should be
included in the fasta format input file called "data.seq".

Multiple sequences are allowed as illustrated in example of this file provided
with the distribution. The data.seq file should be in the execution directory (i.e.
in the directory where you are executing sable). If precomputed PSSMs are to be used,
they can be first saved using SAVE_NR_PSSM, SAVE_SWISS_PSSM variables to define
their location, and in subsequent run read using READ_NR_PSSM and READ_SWISS_PSSM variables.

The results will be included in the output files called ${PBS_JOBID}_graph and,
${PBS_JOBID}_res where  ${PBS_JOBID} (default OUT_SABLE) is the value of variable defined in run.sable script. 
The file ${PBS_JOBID}_RES has full description of the results (this file can be submitted to the POLYVIEW
server at http://polyview.cchmc.org in order to obtain graphical represtentation of the results).
The file ${PBS_JOBID}_graph just results without detailed explanation. These files will be created in 
the execution directory.

In order to run sable once all the paths and files are set and installed, simply type:
under unix: run.sable
under windows: run_sable.dat

Good luck and enjoy!
Please report bugs and problems to jmeller@cchmc.org or raad@is.umk.pl. 
