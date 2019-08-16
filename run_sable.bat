@Echo off
@Cls


rem Where sable has been installed?
set SABLE_DIR=C:\sable_distr
rem Where the blastpgp file is?
set BLAST_DIR=C:\dist_sable\blast
rem Where Nr database is installed?
set NR_DIR=C:\dist_sable\nr\nr
rem File with list of GI indexes, if not specified (this line is commented) full nr database will be used as primary database
set PRIMARY_DATABASE="/users/radamcza/work/newSable/sable_distr/pfam_index" 
rem File with GI indexes for secondary database (usually indexes from swissprot database)
set SECONDARY_DATABASE="/users/radamcza/work/newSable/sable_distr/swissprot_index"; 

set OSTYPE=windows
rem PSSM will be saved in PSSM_generated
set SAVE_NR_PSSM="pssm_nr_test" 
rem PSSM will be saved in PSSM_generated
set SAVE_SWISS_PSSM="pssm_swiss_test" 

rem PSSM will not be generated but readed from this file
rem set READ_NR_PSSM="pssm_nr_test" 
rem PSSM will not be generated but readed from this file
rem set READ_SWISS_PSSM="pssm_swiss_test" 

rem version of sable you want to there are two possible values:
rem sable1 or sable2(sable2 is using solvent accessibility for secondary structure prediction and usually
rem is giving better results)

set SABLE_VERSION=sable2

rem name of the temporary directory where all files needed by sable will be created
rem also it is the root name for final output files (PBS_JOBID.res and PBS_JOBID_graph)

set PBS_JOBID=OUT_SABLE

rem There are three possibilities for this option: SS (secondary structure prediction), 
rem SA (solvent accessibility prediction), SS-SA (both secondary structure and solvent accessibility)

set SABLE_ACTION=SS-SA


rem type of approximator, for solvent accessibility prediction, that will be used, there are following possible values:
rem wApproximator, Thermometer, Approximator, SVR. The default value is wApproximator. 
rem Be aware that solvent accessibility prediction is also used in secondary structure prediction for sable2 version.
set SA_ACTION=wApproximator

rem what networks use to predict solevnt accessibility trained on data with complexes (complex)
rem or trained on sigle chains (single) this option is valid onlu for wApproximator
set SABLE_SA=complex	    


mkdir %PBS_JOBID%
copy data.seq %PBS_JOBID%
cd %PBS_JOBID%

perl %SABLE_DIR%\sable.pl


set file=%PBS_JOBID%_graph
copy %file% ..
set file=%PBS_JOBID%_res
copy %file% ..

cd ..
