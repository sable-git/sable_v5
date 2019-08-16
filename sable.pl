use File::Copy;

$installDir=$ENV{SABLE_DIR};
$psiBlast="$ENV{BLAST_DIR}/psiblast";
$generate_NR_PSSM=1;
if(defined($ENV{READ_NR_PSSM}))
{
	$generate_NR_PSSM=0;
}

$generate_SWISS_PSSM=1;
if(defined($ENV{READ_SWISS_PSSM}))
{
	$generate_SISS_PSSM=0;
}

if(!defined($ENV{SAVE_NR_PSSM}))
{
	die "You have to provide name of the file name to which pssm from nr will be saved";
}
$nrPSSMName=$ENV{SAVE_NR_PSSM};
if(!defined($ENV{SAVE_SWISS_PSSM}))
{
	die "You have to provide name of the file name to which pssm from swissprot will be saved";
}
$swissPSSMName=$ENV{SAVE_SWISS_PSSM};

$secondaryDatabase=$ENV{SECONDARY_DATABASE};
$nr=$ENV{NR_DIR};
$primary=0;


$secDir="$installDir/networks2";
$netDir="$installDir/networks";
$covDir="$installDir/cov";
$netSADir="$installDir/complexSA";
$covSADir="$installDir/covSA";
$confSADir="$installDir/networksconfSA";


$windowSize=11;

$volDef=1;
$hydroDef=1;
$propDef=1;
$propDef2=1;
$entropyDef=1;


%transCode=(H=>H,G=>H,I=>H,E=>E,B=>E,C=>C,I=>C,X=>C,S=>C,L=>C,T=>C);

%outputCode=(H=>"1 0 0",G=>"1 0 0",I=>"1 0 0",E=>"0 1 0",B=>"0 1 0",C=>"0 0 1",T=>"0 0 1",X=>"0 0 1",S=>"0 0 1",L=>"0 0 1");

%outputCodeCnotC=(H=>"1 0",G=>"1 0",I=>"1 0",E=>"1 0",B=>"1 0",C=>"0 1",T=>"0 1",X=>"0 1",S=>"0 1",L=>"0 1");

%symbolTable=(I=>"",L=>"",V=>"",F=>"",M=>"",C=>"",A=>"",G=>"",P=>"",S=>"",Y=>"",W=>"",Q=>"",N=>"",H=>"",E=>"",D=>"",K=>"",R=>"","-"=>"","."=>"");

%outputSymbol=("1 0 0"=>H,"1 0 0"=>H,"1 0 0"=>H,"0 1 0"=>E,"0 1 0"=>E,"0 0 1"=>C,"0 0 1"=>C,"0 0 1"=>C,"0 0 1"=>C,"0 0 1"=>C);

%outputWin=(4=>1,5=>1,6=>1);
%inputWin=(0=>1,1=>1,2=>1,3=>1,4=>1,5=>1,6=>1,7=>1,8=>1,9=>1,10=>1);

%symbolTable=(I=>"",L=>"",V=>"",F=>"",M=>"",C=>"",A=>"",G=>"",P=>"",S=>"",Y=>"",W=>"",Q=>"",N=>"",H=>"",E=>"",D=>"",K=>"",R=>"","-"=>"","."=>"");

@code=("H","E","C");

#There are two sets of networks that has been created with two different 
#version of perl, unfortunatly sort has not been used sa we have to have
#two version of correct order of amino acids to prepare vectors for networks

@correctOrder=("S","F","T","N","K","Y","E","V","Q","M","C","L","A","W","P","H","D","R","I","G");
@oldOrder=("N","P","Q","A","R","S","C","T","D","E","V","F","W","G","H","Y","I","K","L","M");

#List of networks for the first step of prediction
%networkList=("te"=>"0 0 0 0 0 0 1 232 avrCovPfam_new.dat te_1","te3"=>"0 0 0 0 0 0 1 232 avrCovPfam_new3.dat te_3","te4"=>"0 0 0 0 0 0 1 232 avrCovPfam_new4.dat te_4","EL2"=>"0 0 1 1 1 0 0 268 avrCov268_2 ENTR2","EL4"=>"0 0 1 1 1 0 0 268 avrCov268_4 ENTR4","EL2_W"=>"0 0 1 1 1 0 0 268 avrCov268_2 ENTR2_W","EL4_W"=>"0 0 1 1 1 0 0 268 avrCov268_4 ENTR4_W","tm6"=>"0 0 1 1 1 0 0 268 avrCov268_6 tm_6","EL6_W"=>"0 0 1 1 1 0 0 268 avrCov268_6 ENTR6_W");
%diffList=("te"=>"te3 te4","EL2"=>"EL2_W EL4 EL4_W tm6 EL6_W");

if($ENV{SABLE_VERSION} eq "sable2")
{
    %networkList=("te"=>"0 0 0 0 0 0 1 232 avrCovPfam_new.dat te_S","te3"=>"0 0 0 0 0 0 1 232 avrCovPfam_new3.dat te3_S","te4"=>"0 0 0 0 0 0 1 232 avrCovPfam_new4.dat te4_S","EL2"=>"0 0 1 1 1 0 0 268 avrCov268_2 EL_2_S","EL4"=>"0 0 1 1 1 0 0 268 avrCov268_4 EL_4_S","EL2_W"=>"0 0 1 1 1 0 0 268 avrCov268_2 EL_2_W_S","EL4_W"=>"0 0 1 1 1 0 0 268 avrCov268_4 EL_4_W_S","tm6"=>"0 0 1 1 1 0 0 268 avrCov268_6 tm6_S","EL6_W"=>"0 0 1 1 1 0 0 268 avrCov268_6 EL_6_W_S");

}

%basic_surface = (A=>115, R=>225, D=>150, N=>160, C=>135, 
                  E=>190, Q=>180, G=>75,  H=>195, I=>175,
                  L=>170, K=>200, M=>185, F=>210, P=>145,
                  S=>115, T=>140, W=>255, Y=>230, V=>155, X=>1);

%secNetworkList=("te_1"=>1,"te_3"=>1,"te_4"=>1,"ENTR2"=>1,"ENTR4"=>1,"ENTR2_W"=>1,"ENTR4_W"=>1,"tm_6"=>1,"ENTR6_W"=>1);

#List of networks trained with predicted solvent accessibility
%secListSol=("te_S"=>1,"te3_S"=>1,"te4_S"=>1,"EL_2_S"=>1,"EL_4_S"=>1,"EL_2_W_S"=>1,"EL_4_W_S"=>1,"tm6_S"=>1,"EL_6_W_S"=>1);

#Networks for evaluating confidance factors for SA prediction
@networkListError=("conf_5","conf_2","conf_1","conf_4","conf_3");

#Weighted aproximator networks
if(!$ENV{SA_ACTION})
{
    $ENV{SA_ACTION}="wApproximator";
}

if($ENV{SA_ACTION} eq "wApproximator")
{
    @networkListSA=("wxApp_elRP_2","wxApp_elRP_0","wxApp_elBP_0","wxApp_RP_2","wxApp_RP_1","wxApp_BP_00","wxApp_BP_01","wxApp_BP_02","wxApp_JERP_00");
	if($ENV{SABLE_SA} eq "single")
	{
		$netSADir="$installDir/singleSA";
		@networkListSA=("Pfam_BP_2_6","Pfam_BP_0_4","Pfam_BP_1_2","Pfam_RPn_2_7","Pfam_RPn_0_7","Pfam_RPn_1_8","Pfam_RPreg_all_0_11","Pfam_BP_reg_all_0_12","Pfam_BP_reg_all_1_10");
	}
	
}
elsif($ENV{SA_ACTION} eq "Approximator")
{

    @networkListSA=("Approx_el_1","Approx_1","Pfam_elBP_1_new10new390.net");
}
elsif($ENV{SA_ACTION} eq "Thermometer")
{
#Thermometer networks
    @networkListSA=("Therm_015","Therm_315","Therm_115");
}


%transTable=(
        ALA=>"A",ARG=>"R", ASN=>"N", ASP=>"D", CYS=>"C", GLN=>"Q", GLU=>"E", GLY=>"G",
        HIS=>"H", ILE=>"I", LEU=>"L", LYS=>"K", MET=>"M", PHE=>"F", PRO=>"P", SER=>"S",
        THR=>"T", TRP=>"W", TYR=>"Y", VAL=>"V", GAP=>"-", HYD=>"B", POL=>"O", CHG=>"U",
        CRG=>"U", "CH-"=>"X", CHN=>"X", ALL=>"*", INS=>"+", DEL=>"-", CST=>"J", HST=>"Z",
        USR=>"="); 

%hydrophobic=(A=>1.8,R=>-4.5,N=>-3.5,D=>-3.5,C=>2.5,Q=>-3.5,E=>-3.5,G=>-0.4,H=>-3.2,I=>4.5,
	      L=>3.8,K=>-3.9,M=>1.9,F=>2.8,P=>-1.6,S=>-0.8,T=>-0.7,W=>-0.9,Y=>-1.3,V=>4.2);

%vol=(A=>88.6,R=>173.4,N=>111.1,D=>114.1,C=>108.5,E=>138.4,Q=>143.8,G=>60.1,H=>153.2,I=>166.7,L=>166.7,K=>168.6,M=>162.9,F=>189.9,P=>112.7,S=>89,T=>116.1,W=>227.8,Y=>193.6,V=>140);

%propensity=(A=>" 0 0 0 0 1",E=>" 0 0 0 0 1",L=>" 0 0 0 0 1",V=>" 0 0 0 1 0",I=>" 0 0 0 1 0",S=>" 0 0 1 0 0",N=>" 0 0 1 0 0",P=>" 0 1 0 0 0",G=>" 1 0 0 0 0",X=>" 0 0 0 0 0");

%propensity_type2=(A=>" 0 0 0 0 1",E=>" 0 0 0 0 1",L=>" 0 0 0 0 1",V=>" 0 0 0 1 0",I=>" 0 0 0 1 0",S=>" 0 0 1 0 0",N=>" 0 0 1 0 0",P=>" 0 1 0 0 0",G=>" 1 0 0 0 0");

sub MakePrediction;
sub WindowData;
sub CodeMain();
sub RemSpace;
sub ReadScoringMatrix;
sub TestNetwork;
sub ReadSNNSRes;
sub GetNetOutputProb;
sub ReadPAvrCov;
sub ReadAvrCov();
sub ReadFastaFile;
sub CalculateAccuracy;
sub SecondOutput;
sub CombineResults;
sub FinalPrediction;
sub cat;

sub MakeSAPrediction;
sub JoinTemp;
sub WindowDataSA;
sub ReadResultSA;


if(!(-f $psiBlast))
{
	die "$psiBlast cannot be found. Maybe path in BLAST_DIR variable is incorrectly defined?\n";
}
@nrFiles=glob($nr."*");
if(scalar(@nrFiles)<=1)
{
	die "Cannot find nr database. Check NR_DIR variable if it is corretly defined, the other possibility is that database has not been properly formated (use makeblastdb)\n";
}


#if(!(-f $secondaryDatabase))
#{
	#die "Cannot find secondary database (gi index file). Check SECONDARY_DATABASE variable if it is corretly defined?\n";
#}


open(file_finalRes,">$ENV{PBS_JOBID}_RES") or die "\n File cannot be open";
ReadFastaFile("data.seq");

ReadAvrCov();

$osType=$ENV{OSTYPE};

foreach $qq (sort keys %networkList)
{
    $tmp="$qq"."_sec.dat";
    unlink("$tmp");    
    
}

open(file_graph,">$ENV{PBS_JOBID}_graph") or die "\n File cannot be open";
my @keys=split(/-/,$ENV{SABLE_ACTION});

my %action;
@action{@keys}=(1) x @keys;


foreach $m (sort keys %seqList) #Loop for all sequences that has been found in
{                               #file with fast format
    %res=();

    $mainSeq=$seqList{$m};
    
    #Remove all end lines, it is better not to use chomp
    #because chomp depends on the system and you never know
    #from which system file has been submited
    $mainSeq=~s/\n//;
    $mainSeq=~s/\r//;
    
    $remSeq=$mainSeq;
    
    #We are adding funny beging and end of the sequence
    $mainSeq="EEDL".$mainSeq."EEDL";

    
    CodeMain();
    
    unlink("query");

    open(file_out,">query") or die "\n File query cannot be open";
    print file_out ">$m";
    print file_out "\n$mainSeq";
    close(file_out);
    $m =~ s/>//;
    @ttt=split(/ /,$m);

    printf"$ttt[0]\n";
    @pred=();

    printf file_graph "Query: $m\n$remSeq\n";
    printf file_finalRes "\nQuery: $m\n";

	
    GeneratePSSM("query",$nrPSSMName,"primary") if($generate_NR_PSSM==1);
	

    #Solvent accessibility will be needed fo server 2.0, for simplicity
    #it is always calculated

    %sa=MakeSAPrediction($mainSeq);
    if($ENV{SA_ACTION} eq "SVR")
    {
		%sa=TestSVR();
    }

    $tmp=length($mainSeq);
    if($action{SS})
    {
		%ttt=MakePrediction($mainSeq,\@{$sa{NETRES}});
		%{$pred[0]}=%ttt;
	
		%finalRes=FinalPrediction(\@pred);
		WriteSSPredictionToFile(\%finalRes,$remSeq);
    }
    else
    {
		printf file_graph "\n\n";
    }

    if($action{SA})
    {
		WriteSAPredictionToFile(\%sa,$remSeq);
    }
    else
    {
		printf file_graph "\n\n";
    }
	WriteEntropyToFile($remSeq);
}

close(file_finalRes);
close(file_graph);




sub WriteSAPredictionToFile
{
    my $prediction=shift;
    my $remSeq=shift;
    my ($i,$j,$ii);
    my (@aux,@prob,@real,@vecSeq);
    my ($tmp,$sa,$saReal,$num,$mm);

    printf file_finalRes "SECTION_SA";
    printf file_finalRes "\n\nRelative solvent accessibility prediction\n";		
    printf file_finalRes "0 -> fully Buried\n";
    printf file_finalRes "9 -> fully Exposed\n";
    printf file_finalRes "3rd line -> confidence level (scale from 0 to 9, corresponding to p=0.0 or low confidence and p=0.9 or high confidence, respectively)\n";
    		

    

    printf file_graph "@{$$prediction{NETRES}}\n";

    if($$prediction{PROB})
    {
	$prob=join('',@{$$prediction{PROB}{ROUND}});
	printf file_graph "$prob\n";
    }
    else
    {
	printf file_graph "\n";
    }
    $buf="                                                            ";
    for($i=0,$j=0;$j<scalar(@{$$prediction{NETRES}});$i++,$j+=60)
    {
	$sq=substr($remSeq,$i*60,60);
	if(($i*60+60)>scalar(@{$$prediction{NETRES}}))
	{
	    $end=scalar(@{$$prediction{NETRES}});
	}
	else
	{
	    $end=$i*60+60;
	}
	@aux=();
	@real=();
	@prob=();
	for($ii=$i*60;$ii<$end;$ii++)
	{		
	    if($$prediction{NETRES}[$ii]/10<10)
	    {
		$mm=substr($$prediction{NETRES}[$ii]/10,0,1);
	    }
	    else
	    {
		$mm=9;
	    }
	    push @aux,$mm;
	    push @real,$$prediction{NETRES}[$ii];
	    if($$prediction{PROB})
	    {
		push @prob,$$prediction{PROB}{ROUND}[$ii];
	    }
	    
	}
	$sa=join('',@aux);
	$prob=join('',@prob);
	$saReal=join(' ',@real);
	$tmp=$j+1;
	$num=">    $tmp";
	$tmp=length($num)-5;
	$num=~s/ {$tmp}//;
	printf file_finalRes"\n$num";
#	    $tmp=length($buff)-length($ss);
#	    $buf=~s/ {$tmp}//;
	printf file_finalRes"$buf";
	$num=$j+length($sa);
	$num="    $num";
	$tmp=length($num)-4;
	$num=~s/ {$tmp}//;
	
	printf file_finalRes"$num";
	printf file_finalRes "\n     $sq\n     $sa\n     $prob";

    }
    printf file_finalRes"\nEND_SECTION\n";
    if($ENV{SA_REAL})
    {
	printf file_finalRes "\nSECTION_SA_PERCENT";
	printf file_finalRes "\nRelative solvent accessibility prediction (real values)\n";		
	printf file_finalRes "0 -> fully Buried\n";
	printf file_finalRes "100 -> fully Exposed\n";
	$buf="                                                                                                  ";
	for($i=0,$j=0;$j<scalar(@{$$prediction{NETRES}});$i++,$j+=25)
	{
	    $sq=substr($remSeq,$i*25,25);
	    if(($i*30+30)>scalar(@{$$prediction{NETRES}}))
	    {
		$end=scalar(@{$$prediction{NETRES}});
	    }
	    else
	    {
		$end=$i*25+25;
	    }
	    @aux=();
	    @real=();
	    for($ii=$i*25;$ii<$end;$ii++)
	    {		
		push @real,$$prediction{NETRES}[$ii];
	    }
	    @vecSq=split(//,$sq);
	    $tmp=$j+1;
	    $num=">    $tmp";
	    $tmp=length($num)-5;
	    $num=~s/ {$tmp}//;
	    printf file_finalRes"\n$num";
	    
	    printf file_finalRes"$buf";
	    $num=$j+length($sq);
	    $num="    $num";
	    $tmp=length($num)-4;
	    $num=~s/ {$tmp}//;
	    printf file_finalRes "$num\n     ";
		
	    for($ii=0;$ii<scalar(@vecSq);$ii++)
	    {
		printf file_finalRes "$vecSq[$ii]   ";
	    }
	    printf file_finalRes "\n     ";
	    for($ii=0;$ii<scalar(@vecSq);$ii++)
	    {
		$bb="$real[$ii]   ";
		$ll=length($bb)-4;
#		    printf file_finalRes " len=$ll";
		$bb=~s/ {$ll}//;
		printf file_finalRes "$bb";
	    }
	    printf file_finalRes "\n";
	}
	printf file_finalRes"\nEND_SECTION\n";
    }
#    if($ENV{SA_ABSOLUTE})
    {
	printf file_finalRes "\nSECTION_SA_ABSOLUTE";
	@seqS=split(//,$remSeq);
    	@newSa=();
    	for($i=0;$i<scalar(@{$$prediction{NETRES}});$i++)
	{
		push @newSa,$$prediction{NETRES}[$i]*$basic_surface{$seqS[$i]}/100;
	}
	$buf="";
        $step=5;
	for($i=0;$i<25*($step+1);$i++)
	{
		$buf.=" ";
	}
	for($i=0,$j=0;$j<scalar(@{$$prediction{NETRES}});$i++,$j+=25)
	{
	    $sq=substr($remSeq,$i*25,25);
	    if(($i*30+30)>scalar(@{$$prediction{NETRES}}))
	    {
		$end=scalar(@{$$prediction{NETRES}});
	    }
	    else
	    {
		$end=$i*25+25;
	    }
	    @aux=();
	    @real=();
	    for($ii=$i*25;$ii<$end;$ii++)
	    {		
		push @real,$newSa[$ii];
	    }
	    @vecSq=split(//,$sq);
	    $tmp=$j+1;
	    $num=">    $tmp";
	    printf file_finalRes"\n$num";
	    
	    printf file_finalRes"$buf";
	    $num=$j+length($sq);
	    $num="$num";
	    printf file_finalRes "$num\n     ";
	   
	    for($ii=0;$ii<scalar(@vecSq);$ii++)
	    {
		printf file_finalRes "$vecSq[$ii]";
		for($nn=0;$nn<$step;$nn++)
		{
			printf file_finalRes " ";
		}
	    }
	    printf file_finalRes "\n     ";
	    for($ii=0;$ii<scalar(@vecSq);$ii++)
	    {
		$bb=sprintf "%3.1f",$real[$ii];
		$eend=$step+1-length($bb);
		for($nn=0;$nn<$eend;$nn++)
		{
			$bb.=" ";
		}
		printf file_finalRes "$bb";
	    }
	    printf file_finalRes "\n";
	}
	printf file_finalRes"\nEND_SECTION\n";
    }


#	printf file_finalRes "@{$sa{NETRES}}\n";
}


sub WriteEntropyToFile
{
	my $seq=shift;
	my (@entropy,@vecSq,@temp);
	my ($i,$j,$ii,$ll,$num,$tmp,$maxEntropy,$buf);
	
    printf file_finalRes "\nSECTION_ENTROPY\n";

	$maxEntropy=-20*0.05*log(0.05);

	
	@temp=split(//,$seq);
	for($i=0;$i<scalar(@temp);$i++)
	{
		$entropy[$i]=0;
		$ii=0;
		foreach $j (@correctOrder)
		{

			if($probability[$i+4]{$j})
			{
				$ii=1;
				$entropy[$i]+=-$probability[$i+4]{$j}*log($probability[$i+4]{$j});
			}
			
		}
		$entropy[$i]=$maxEntropy if($ii==0);
	}
    $buf="                                                                                                  ";	
    for($i=0,$j=0;$j<length($seq);$i++,$j+=25)
    {
		$sq=substr($seq,$i*25,25);
		if(($i*30+30)>length($seq))
		{
		    $end=length($seq);
		}
		else
		{
	    	$end=$i*25+25;
		}
		@vecSq=split(//,$sq);
		$tmp=$j+1;
		$num=">    $tmp";
		$tmp=length($num)-5;
		$num=~s/ {$tmp}//;
		printf file_finalRes"\n$num";
	    
		printf file_finalRes"$buf";
		$num=$j+length($sq);
		$num="      $num";
		$tmp=length($num)-6;
		$num=~s/ {$tmp}//;
		printf file_finalRes "$num\n          ";
		for($ii=0;$ii<scalar(@vecSq);$ii++)
		{
	    	printf file_finalRes "$vecSq[$ii]   ";
		}
		printf file_finalRes "\nENTROPY-> ";	
		for($ii=$j;$ii<scalar(@vecSq)+$j;$ii++)
		{

		    $tmp=sprintf "%2.1f   ",$entropy[$ii]/$maxEntropy;
		    $ll=length($tmp)-4;
		    $tmp=~s/ {$ll}//;
		    printf file_finalRes "$tmp";
		}

		printf file_finalRes "\n";
    }
	
    printf file_finalRes"\nEND_SECTION\n";    	
}

sub WriteSSPredictionToFile
{
    my $prediction=shift;
    my $remSeq=shift;
    my (@H,@E,@C);
    my $seq;
    
    $seq=$$prediction{seq};


    printf file_graph "$$prediction{seq}\n";
    printf file_graph "$$prediction{prob}\n";
    printf file_finalRes "SECTION_SS";
    printf file_finalRes "\nSecondary structure prediction\n\n";
    printf file_finalRes "Output format is the following:\n";
    printf file_finalRes "1st line -> query sequence\n";
    printf file_finalRes "2nd line -> predicted secondary structure (H -> helix, E -> beta strand, C -> coil)\n";
    printf file_finalRes "3rd line -> confidence level (scale from 3 to 9, corresponding to p=0.3 or low confidence and p=0.9 or high confidence, respectively)\n";
    
    $buf="                                                            ";
    for($i=0,$j=0;$j<length($$prediction{seq});$i++,$j+=60)
    {
	$sq=substr($remSeq,$i*60,60);
	$ss=substr($$prediction{seq},$i*60,60);
	$sa=substr($$prediction{prob},$i*60,60);
	$tmp=$j+1;
	$num=">    $tmp";
	$tmp=length($num)-5;
	$num=~s/ {$tmp}//;
	printf file_finalRes"\n$num";
	$tmp=length($buff)-length($ss);
	$buf=~s/ {$tmp}//;
	printf file_finalRes"$buf";
	$num=$j+length($ss);
	$num="    $num";
	$tmp=length($num)-4;
	$num=~s/ {$tmp}//;
	
	printf file_finalRes"$num";
	printf file_finalRes "\n     $sq\n     $ss\n     $sa\n";    
    }
    printf file_finalRes"END_SECTION\n";

    printf file_finalRes "\nSECTION_SS_PROBABILITIES";
    printf file_finalRes "\nSecondary structure prediction\n\n";
    printf file_finalRes "Output format is the following:\n";
    printf file_finalRes "1st line -> query sequence\n";
    printf file_finalRes "2nd line -> probability for helix\n";
    printf file_finalRes "3rd line -> probability for beta strand\n";
    printf file_finalRes "4rd line -> probability for coil\n";

    $buf="                                                                                                  ";
    for($i=0,$j=0;$j<length($$prediction{seq});$i++,$j+=25)
    {
	$sq=substr($remSeq,$i*25,25);
	if(($i*30+30)>length($$prediction{seq}))
	{
	    $end=length($$prediction{seq});
	}
	else
	{
	    $end=$i*25+25;
	}
	@aux=();
	@H=();
	@E=();
	@C=();
	for($ii=$i*25;$ii<$end;$ii++)
	{		
	    push @H,$$prediction{H}[$ii]*100;
	    push @E,$$prediction{E}[$ii]*100;
	    push @C,$$prediction{C}[$ii]*100;
	}
	@vecSq=split(//,$sq);
	$tmp=$j+1;
	$num=">    $tmp";
	$tmp=length($num)-5;
	$num=~s/ {$tmp}//;
	printf file_finalRes"\n$num";
	    
	printf file_finalRes"$buf";
	$num=$j+length($sq);
	$num="    $num";
	$tmp=length($num)-4;
	$num=~s/ {$tmp}//;
	printf file_finalRes "$num\n     ";
	
	for($ii=0;$ii<scalar(@vecSq);$ii++)
	{
	    printf file_finalRes "$vecSq[$ii]   ";
	}
	printf file_finalRes "\nH->  ";
	for($ii=0;$ii<scalar(@vecSq);$ii++)
	{
	    $bb=sprintf "%d   ",$H[$ii];
	    $ll=length($bb)-4;
	    $bb=~s/ {$ll}//;
	    printf file_finalRes "$bb";
	}
	printf file_finalRes"\nE->  ";
	for($ii=0;$ii<scalar(@vecSq);$ii++)
	{
#	    $bb="$E[$ii]   ";
	    $bb=sprintf "%d   ",$E[$ii];
	    $ll=length($bb)-4;
	    $bb=~s/ {$ll}//;
	    printf file_finalRes "$bb";
	}
	printf file_finalRes"\nC->  ";
	for($ii=0;$ii<scalar(@vecSq);$ii++)
	{
#	    $bb="$C[$ii]   ";
	    $bb=sprintf "%d   ",$C[$ii];
	    $ll=length($bb)-4;
	    $bb=~s/ {$ll}//;
	    printf file_finalRes "$bb";
	}

	printf file_finalRes "\n";
    }
    printf file_finalRes"\nEND_SECTION\n";    


}

sub MakePrediction
{
    my $query=shift;
    my $solvent=shift;

    my ($seq,$prob);
    my @allProb;


    GeneratePSSM("query",$swissPSSMName,"secondary") if($generate_SWISS_PSSM==1);

    ReadScoringMatrix($swissPSSMName,$generate_SWISS_PSSM);	
    
    WindowData(file_train,$query,\@{$solvent},"swiss");

    #Get  the result for first step of prediction for swiss-prot database
    %predFirst=GetNetOutputProb(\%networkList,$netDir,0,"swiss");

#    die;

    #This is global variable store the resuts form networks before each
    #reading it is better to clean it
    %res=();
    ReadScoringMatrix($nrPSSMName,$generate_NR_PSSM);
    
    WindowData(file_train,$query,\@{$solvent});

#    die;

    #Get  the result for first step of prediction for nr database
    %predFirst=GetNetOutputProb(\%networkList,$netDir,0);
    
    %res=();
    
    #Prepare data for the second step of SS prediction
    SecondOutput();

    if($ENV{SABLE_VERSION} eq "sable2")
    {
	%predSecond=GetNetOutputProb(\%secListSol,$secDir,1);
#	%predSecond=GetNetOutputProb(\%secNetworkList,$secDir,1);

	#To remove results from first step 
	%res=();

	SecondOutput("swiss");
	%predSecond_swiss=GetNetOutputProb(\%secListSol,$secDir,1,"swiss");
#	%predSecond_swiss=GetNetOutputProb(\%secNetworkList,$secDir,1,"swiss");
    }
    else
    {
	%predSecond=GetNetOutputProb(\%secNetworkList,$secDir,1);
	
	%res=();
	SecondOutput("swiss");
	%predSecond_swiss=GetNetOutputProb(\%secNetworkList,$secDir,1,"swiss");
    }

    #Combine results form Nr and swiss-prot database
    %predSecond=CombineResults(\%predSecond,\%predSecond_swiss);
    
    #The second step is not predicting first five and last five residues
    #So final prediction is the prediction from second step and 10 residues 
    #from first step from nr database

    $seq=substr($predFirst{seq},0,5).$predSecond{seq}.substr($predFirst{seq},length($predFirst{seq})-5,5);
    $prob=substr($predFirst{prob},0,5).$predSecond{prob}.substr($predFirst{prob},length($predFirst{prob})-5,5);

    $tmp=scalar(@{$predSecond{allProb}});

    for($i=0;$i<5;$i++)
    {
	%{$allProb[$i]}=%{$predFirst{allProb}[$i]};
    }
    $tmp=scalar(@allProb);

    #The same has to be done for probabilities

    for($i=0;$i<scalar(@{$predSecond{allProb}});$i++)
    {
	%{$allProb[$i+5]}=%{$predSecond{allProb}[$i]};
    }
    $tmp=scalar(@allProb);

    for($j=scalar(@{$predFirst{allProb}})-5;$j<scalar(@{$predFirst{allProb}});$i++,$j++)
    {
	%{$allProb[$i+5]}=%{$predFirst{allProb}[$j]};
    }

    $tmp=scalar(@allProb);
	
    $res{seq}=$seq;
    $res{prob}=$prob;
    @{$res{allProb}}=@allProb;

    return %res;
    
}


sub MakeSAPrediction
{
    my $query=shift;
    my $i;
    my @result;
    my %result;


    $volDef=1;
    $hydroDef=1;
    $propDef=1;
    $propDef2=1;
    $entropyDef=1;


    open(file_test,">testSNNS.dat");
    print file_test "SNNS pattern definition file V3.2";
    print file_test "\ngenerated at Mon Apr 25 15:58:23 1994";

    #-10 beceause window has length 11
    $tmp=length($query)-10;
    
    print file_test "\n\nNo. of patterns : $tmp";
    print file_test "\nNo. of input units : 269";
    
    #For thermometer there is different nodes number in the output
    #of the networks

    if($ENV{SA_ACTION} eq "Thermometer")
    {
	print file_test "\nNo. of output units : 20\n\n";	
    }
    else
    {
	print file_test "\nNo. of output units : 1\n\n";	
    }

    ReadScoringMatrix($nrPSSMName,$generate_NR_PSSM);		
    WindowDataSA(file_test,$query);
    close(file_test);   

    return if($ENV{SA_ACTION} eq "SVR");

    for($i=0;$i<scalar(@networkListSA);$i++)
    {
	TestNetwork("$netSADir/$networkListSA[$i]","testSNNS.dat");
	copy("test.res","$networkListSA[$i]") or die "\nCannot copy the file test.res";
#	system("cp test.res $networkListSA[$i]");
	if($ENV{SA_ACTION} eq "Thermometer")
	{
	    push @result,{ReadResultThermSA("test.res")};
	}
	else
	{
	    push @result,{ReadResultSA("test.res")};
	    
	}
	
    }
    #Average the results of all networks
    
    if($ENV{SA_ACTION} eq "Thermometer")
    {
	%result=JoinTempTherm(\@result);
    }
    else
    {
	%result=JoinTemp(\@result);
	if($ENV{SA_ACTION} eq "wApproximator")
	{
	    %prob=PrepareErrorData(\@result);
	    %{$result{PROB}}=%prob;
	}
    }



    return %result;
}

sub JoinTemp
{
    my $vecS=shift;
    my @prob;
    my (@temp,@orgRes,@netRes);
    my @vec;
    my ($i,$j,$l,$m,$tmp,$rem);
    my %res;

    for($m=0;$m<scalar(@networkListSA);$m++)
    {
    
	for($l=0;$l<scalar(@{$$vecS[$m]{SOLVENT}});$l++)
	{	    
	    #Some of the networks were trained for the reverse order
	    #of output
	    if($networkListSA[$m]=~/_RP_/)
	    {
		$$vecS[$m]{SOLVENT}[$l]=1-$$vecS[$m]{SOLVENT}[$l] ;
	    }

	    $temp[$l]+=$$vecS[$m]{SOLVENT}[$l];	    
	}
    }
    $tmp=scalar(@temp);

    for($l=0;$l<scalar(@temp);$l++)
    {
	$temp[$l]/=scalar(@networkListSA);
	$buff=sprintf"%3.2f",$temp[$l];

	$buff=$buff*100;
	@vec=split(/\./,$buff);
	$prob[$l]=$vec[0];
    }
    
    
    @tmp=($prob[0],@prob,$prob[scalar(@prob)-1]);
    
  
    @{$res{NETRES}}=@tmp;

    return %res;

}


sub JoinTempTherm
{
    my $vecS=shift;
    my $prob;
    my (@temp,@orgRes,@netRes);
    my @vec;
    my ($i,$j,$l,$m,$tmp,$rem);
    my $answer;
    my %res;
    my @field;

    for($m=0;$m<scalar(@networkListSA);$m++)
    {
	for($l=0;$l<scalar(@{$$vecS[$m]{SOLVENT}});$l++)
	{
	    @vec=split(/ /,$$vecS[$m]{SOLVENT}[$l]);
#	    printf"\n $m $l @vec";
	    for($j=0;$j<scalar(@vec);$j++)
	    {
		$temp[$l][$j]+=$vec[$j];
	    }
	}
    }
    
    for($j=0;$j<scalar(@temp);$j++)
    {
	for($l=0;$l<scalar(@{$temp[$j]});$l++)
	{
	    $temp[$j][$l]/=scalar(@networkListSA);
	    
	}
#	printf "\ntemp=@{$temp[$j]}";
    }
    
    

    for($i=0;$i<scalar(@temp);$i++)
    {


	$rem=0;

	#Only nodes with activation bigger then 0.5 are counted as activated 
	#Count those numbers of nodes
	#There is small assumption that all nodes with activation smaller 
	#then 0.5 are in  the same region, mostly it is true

	for($j=0;$j<scalar(@{$temp[$i]});$j++)
	{
	    if($temp[$i][$j]>0.5)
	    {
		$rem=$j ;
	    }
	}

	$rem++;
	$rem*=5;
	
	$rem=100-$rem if(!$reverse);
	push @orgRes,$out;
	push @netRes,$rem;
	$rem/=10;
	$prob.=substr($rem,0,1);
	
	
    }

    @tmp=($netRes[0],@netRes,$netRes[scalar(@netRes)-1]);
   
    @{$res{NETRES}}=@tmp;
    @{$res{FIELD}}=@field;
    return %res;

}

#Data can be prepared only fo wApproximator prediction, because 
#9 predictions is needed, right now only wApp.. has it

sub PrepareErrorData
{
    my $netRes=shift;
    my %prob;
    my ($l,$m,$i);
    my @resultProb,$tmp;
    
    open(file_test,">testSNNS.dat");
    print file_test "SNNS pattern definition file V3.2";
    print file_test "\ngenerated at Mon Apr 25 15:58:23 1994";
    $tmp=scalar(@windowBuff);
    
    print file_test "\n\nNo. of patterns : $tmp";
    print file_test "\nNo. of input units : 278";
    print file_test "\nNo. of output units : 2\n\n";	

    for($l=0;$l<scalar(@windowBuff);$l++)
    {
    	printf file_test "$windowBuff[$l]";
    	for($m=0;$m<scalar(@networkListSA);$m++)
    	{
		printf file_test " $$netRes[$m]{SOLVENT}[$l]";		
#		printf file_test " 0";		
	}	 	
#	printf file_test " 0 0\n";
    }
    close(file_test);
    for($i=0;$i<scalar(@networkListError);$i++)
    {
    		TestNetwork("$confSADir/$networkListError[$i]","testSNNS.dat");
    		push @resultProb,{ReadResultSA("test.res")};

    }
   
    %prob=CalcErrorProb(\@resultProb);

    return %prob;
}
sub CalcErrorProb
{
    my $array=shift;
    my ($i,$j);
    my (@vector,@temp);
    my %prob;
    
    for($i=0;$i<scalar(@networkListError);$i++)
    {
    	for($j=0;$j<scalar(@{$$array[$i]{SOLVENT}});$j++)
    	{
    		@vector=split(/ /,$$array[$i]{SOLVENT}[$j]);

    		$temp[$j][0]+=$vector[0];		
    		$temp[$j][1]+=$vector[1];
    		
    	}
    	
    }
    for($i=0;$i<scalar(@{$$array[0]{SOLVENT}});$i++)
    {
    	
    	$temp[$i][0]/=scalar(@networkListError);
    	$temp[$i][1]/=scalar(@networkListError);
    	$prob{REALV}[$i]=0;
    	$prob{REALV}[$i]=$temp[$i][0]/($temp[$i][0]+$temp[$i][1]) if(($temp[$i][0]+$temp[$i][1])>0);
    	$tmp=$temp[$i][0]/($temp[$i][0]+$temp[$i][1]) if(($temp[$i][0]+$temp[$i][1])>0);

	$prob{ROUND}[$i]=sprintf("%1.0f",$prob{REALV}[$i]*10);
	@vec=split(/\./,$prob{REALV}[$i]*10);
	$prob{ROUND}[$i]=$vec[0];
    }

    @tmp=($prob{REALV}[0],@{$prob{REALV}},$prob{REALV}[scalar(@{$prob{REAL}})-1]);
    @{$prob{REALV}}=@tmp;
    @tmp=($prob{ROUND}[0],@{$prob{ROUND}},$prob{ROUND}[scalar(@{$prob{ROUND}})-1]);
    @{$prob{ROUND}}=@tmp;

    return %prob;
}




sub WindowData
{
    my (@input,@output);   
    my ($i,$k,$j,$n,$w);
    my (@out,@outIndex,@remInput,@newSolvent);
    my $fileName;
    my $copySeq;
    my @windowSeq;
    my @windowScore;
    my $remIndex;
    my $counter=0;
    my %dataSNNS=();
    my %pos=();
    my $fileName=shift;
    my $query=shift;
    my $solvent=shift;
    my $suffix=shift;

    foreach $qq (sort keys %networkList)
    {
	$tmp=$qq;
	if(length($suffix)>0)
	{
	    $tmp="$qq"."_"."$suffix";
	}
	unlink("$tmp");

    }
    
    foreach $qq (sort keys %networkList)
    {
	$tmp=$qq;
	if(length($suffix)>0)
	{	    
	    $tmp="$qq"."_"."$suffix";
	}
	open(file_in,">$tmp") or die "\n Cannot create temporary file!";
	close(file_in);
    }

    @input=split(//,$query);
    @solventBuff=();
    @newSolvent=(0,0,0,0,@{$solvent},0,0,0,0);#it is needed because sequence is longer EEDL...EEDL
    
    for($i=0;$i<scalar(@input);$i++)
    {
	@windowIndex=();
	@out=();

	@outIndex=();
	%pos=();
	%dataSNNS=();
	@remInput=();

	#First prepare all indexes taht are building
	#current window, input and output indexes
	for($j=0,$k=0;$k<$windowSize;$j++)
	{

	    if(($j+$i)<(scalar(@input)))
	    {
		push @windowIndex,$i+$j;

		if($outputWin{$k})
		{
		    push @out,$output[$i+$j];
		    push @outIndex,$i+$j;

		    push @remInput,$input[$i+$j];
#		    $amino=$input[$i+$j];
		}
		$k++;
	    }
	    last if(($j+$i)>=(scalar(@input)-1));

	}
	
	#If the length of the window is the same as requested
	if(scalar(@windowIndex)==$windowSize)
	{
#	    printf"\n";
	    $cystCount=0;
	    for($j=0;$j<$windowSize;$j++)
	    {

		$kw=$newSolvent[$windowIndex[$j]]/100;
		$kw=~s/\n//g;
		$kw=~s/\r//g;
		$kw=1  if($kw>1);
		$solventBuff[$counter].=" $kw";

		#Prepare the data only for those networks that are in the diffList hash
		#rest of them have the same datafiles, coresponding relationships are
		#also defined in diffList hash, this allows to speed up the server

		foreach $qq (sort keys %diffList)
		{

		    #In the networks hashtThere is information about which fetaures 
		    #should be used. Each of the features is immediately standarized
		    #based on the values of averages an standard deviations read from
		    #the file


		    @parameters=split(/ /,$networkList{$qq});
		    
		    $volDef=$parameters[2];
		    $hydroDef=$parameters[3];
		    $propDef=$parameters[4];
		    $propDef2=$parameters[5];
		    
		    if($parameters[6])
		    {
			@tab_order=@correctOrder;
		    }
		    else
		    {
			@tab_order=@oldOrder;
		    }

		    $k=0;
		    $w=0;
		    $entropy=0;
#		$k+=$hydrophobic{$input[$windowIndex[$j]]};
		    foreach $n (@tab_order)
		    {
#		    printf"\n probbability $windowIndex[$j] $n";
			if($probability[$windowIndex[$j]]{$n})
			{
			    $k+=$hydrophobic{$n}*$probability[$windowIndex[$j]]{$n};
			    $w+=$vol{$n}*$probability[$windowIndex[$j]]{$n};

			    $entropy+=-$probability[$windowIndex[$j]]{$n}*log($probability[$windowIndex[$j]]{$n});
			   
			}
			if($inputWin{$j})
			{
			    $dataSNNS{$qq}=$dataSNNS{$qq}.sprintf " %4.3f",($score[$windowIndex[$j]]{$input[$windowIndex[$j]]}{$n}-$avr{$qq}[$pos{$qq}])/$cov{$qq}[$pos{$qq}];
			    $pos{$qq}++;
			}
		    }
		    $cystCount++ if($input[$windowIndex[$j]] eq "C");

		    $dataSNNS{$qq}=$dataSNNS{$qq}.sprintf " %4.3f",($entropy-$avr{$qq}[$pos{$qq}])/$cov{$qq}[$pos{$qq}];
		    $pos{$qq}++;
		    if($hydroDef==1)
		    {
			$dataSNNS{$qq}=$dataSNNS{$qq}.sprintf " %4.3f",($k-$avr{$qq}[$pos{$qq}])/$cov{$qq}[$pos{$qq}];

			$pos{$qq}++;
		    }
		    
		    if($volDef==1)
		    {
			$dataSNNS{$qq}=$dataSNNS{$qq}.sprintf " %4.3f",($w-$avr{$qq}[$pos{$qq}])/$cov{$qq}[$pos{$qq}];

			$pos{$qq}++;
		    }
		}
#		printf" $input[$windowIndex[$j]]";
	    }

	    foreach $qq (sort keys %diffList)
	    {
		@parameters=split(/ /,$networkList{$qq});
		if($parameters[6])
		{
		    $dataSNNS{$qq}=$dataSNNS{$qq}.sprintf" %4.3f",($cystCount/$windowSize-$avr{$qq}[$pos{$qq}])/$cov{$qq}[$pos{$qq}];
		    $pos{$qq}++;
		}
	    }

#	    foreach $qq (sort keys %networkList)
	    foreach $qq (sort keys %diffList)
	    {
		@parameters=split(/ /,$networkList{$qq});
		
		$volDef=$parameters[2];
		$hydroDef=$parameters[3];
		$propDef=$parameters[4];
		$propDef2=$parameters[5];

		if($propDef==1)
		{
		    foreach $jj (@remInput)
		    {
			
			$j=" 0 0 0 0 0";
			$j=$propensity{$jj} if($propensity{$jj});
		    
			@vector=split(/ /,$j);
			for($j=1;$j<scalar(@vector);$j++)
			{
			    $dataSNNS{$qq}=$dataSNNS{$qq}.sprintf" %4.3f",($vector[$j]-$avr{$qq}[$pos{$qq}])/$cov{$qq}[$pos{$qq}];
			    $pos{$qq}++;
			}
		    }
		    
		}
		elsif($propDef2)
		{
		    foreach $jj (@rInput)
		    {
			$j=" 0 0 0 0 0";
			$j=$propensity_type2{$jj} if($propensity_type2{$jj});
			
			@vector=split(/ /,$j);
			for($j=1;$j<scalar(@vector);$j++)
			{
			    
			    $dataSNNS{$qq}=$dataSNNS{$qq}.sprintf " %4.3f",($vector[$j]-$avr{$qq}[$pos{$qq}])/$cov{$qq}[$pos{$qq}];
			    $pos{$qq}++;
			}
			
		    }
		} 

#		foreach $j (@out)
#		{
#			$dataSNNS{$qq}=$dataSNNS{$qq}.sprintf  " 0 0 0";
#		}

		
	    }

	    @vector=keys %networkList;

	    $counter++;
	}

#	foreach $qq (sort keys %networkList)
	foreach $qq (sort keys %diffList)
	{
	    $tmp=$qq;

	    $tmp="$qq"."_"."$suffix" if(length($suffix)>0);
		
	    open(file_out,">>$tmp") or die "\n file $qq can not be open";

	    print file_out "\n$dataSNNS{$qq}" if(length($dataSNNS{$qq})>30);

	    close(file_out);
	}
    }

#    foreach $qq (sort keys %networkList)
    foreach $qq (sort keys %diffList)
    {
	$tmp=$qq;

	$tmp="$qq"."_"."$suffix" if(length($suffix)>0);

	@parameters=split(/ /,$networkList{$qq});

	open(file_out,">test$tmp") or die "\n File cannot be open";
	print file_out "SNNS pattern definition file V3.2";
	print file_out "\ngenerated at Mon Apr 25 15:58:23 1994";
	print file_out "\n\nNo. of patterns : $counter";
	print file_out "\nNo. of input units : $parameters[7]";
	print file_out "\nNo. of output units : 9\n\n";

	close(file_out);
	cat("test$tmp","$tmp","o");
#	system("cat test$tmp $tmp > o");
	copy("o","$tmp");
	unlink("o");

	open(file_out,">header.dat") or die "\n File cannot be open";
	print file_out "SNNS pattern definition file V3.2";
	print file_out "\ngenerated at Mon Apr 25 15:58:23 1994";

	print file_out "\n\nNo. of patterns : $counter";
	print file_out "\nNo. of input units : 81";
	print file_out "\nNo. of output units : 9\n\n";
	close(file_out);

    }   
    for $qq (sort keys %diffList)
    {
	
	
	if(length($diffList{$qq})>4)
	{
	    $tmp=$qq;	    
	    $tmp="$qq"."_"."$suffix" if(length($suffix)>0);
	    foreach $n (split(/ /,$diffList{$qq}))
	    {
		$tmp1=$n;
		$tmp1="$n"."_"."$suffix" if(length($suffix)>0);
		copy("$tmp","$tmp1") or die"\nCanot copy file $tmp";
#		system("cp $tmp $tmp1");
	    }
	}
	
    } 
#    printf"\n aleks=$aleksBuff[0]";
    
    return $counter;
}


sub WindowDataSA
{
    my (@input,@rInput,@outputWin);
    my @windowIndex;
    my ($i,$k,$j,$n,$w,$pos);
    my ($entropy,$cystCount);
    
    my $fileName;
    my $counter=0;

    my $fileName=shift;
    my $query=shift;

    @input=split(//,$query);
    @windowBuff=();

    for($i=0;$i<scalar(@input);$i++)
    {
	@windowIndex=();
	@rInput=();

	for($j=0,$k=0;$k<$windowSize;$j++)
	{

	    if(($j+$i)<scalar(@input))
	    {
		push @windowIndex,$i+$j;
		if($outputWin{$k})
		{
		    push @rInput,$input[$i+$j];
		}

		$k++;
	    }
	    last if(($j+$i)>=(scalar(@input)-1));

	}
	$pos=0;
	if(scalar(@windowIndex)==$windowSize)
	{
	    $cystCount=0;
	    printf $fileName "\n";
	    for($j=0;$j<$windowSize;$j++)
	    {
		$k=0;
		$w=0;
        if($ENV{SA_ACTION} eq "SVR") # My fault I prepared data for
                                     #Michael in a little different way
									 #so additional IF is needed, this has
									 #been checked for NN (I trained NN with these data)
									 #and it has no influence on results
        {
                 $k=$hydrophobic{$input[$windowIndex[$j]]};
                 $w=$vol{$input[$windowIndex[$j]]};
        }
		
		$entropy=0;
		foreach $n (@oldOrder)
		{
		    if($probability[$windowIndex[$j]]{$n})
		    {
			$k+=$hydrophobic{$n}*$probability[$windowIndex[$j]]{$n};
			$w+=$vol{$n}*$probability[$windowIndex[$j]]{$n};
			$entropy+=-$probability[$windowIndex[$j]]{$n}*log($probability[$windowIndex[$j]]{$n});
		    }
		    if($inputWin{$j} && !($remSymbol{$n}))
		    {
			$windowBuff[$counter].=sprintf(" %4.3f",($score[$windowIndex[$j]]{$input[$windowIndex[$j]]}{$n}-$avr{SA}[$pos])/$cov{SA}[$pos]);
			printf $fileName " %4.3f",($score[$windowIndex[$j]]{$input[$windowIndex[$j]]}{$n}-$avr{SA}[$pos])/$cov{SA}[$pos];

			$pos++;
		    }
		}

		$cystCount++ if($input[$windowIndex[$j]] eq "C");
		if($entropyDef==1)
		{
		    $windowBuff[$counter].=sprintf(" %4.3f",($entropy-$avr{SA}[$pos])/$cov{SA}[$pos]);
		    printf $fileName " %4.3f",($entropy-$avr{SA}[$pos])/$cov{SA}[$pos];
		    $pos++;
		}
		if($hydroDef==1)
		{
		    $windowBuff[$counter].=sprintf(" %4.3f",($k-$avr{SA}[$pos])/$cov{SA}[$pos]);
		    printf $fileName " %4.3f",($k-$avr{SA}[$pos])/$cov{SA}[$pos];
		    $pos++;
		}
		if($volDef==1)
		{
		    $windowBuff[$counter].=sprintf(" %4.3f",($k-$avr{SA}[$pos])/$cov{SA}[$pos]);
		    printf $fileName " %4.3f",($w-$avr{SA}[$pos])/$cov{SA}[$pos];
		    $pos++;
		}
	    }
	    $windowBuff[$counter].=sprintf(" %4.3f",$cystCount/$windowSize);
	    printf $fileName " %4.3f",$cystCount/$windowSize;

	    if($propDef==1)
	    {
		foreach $jj (@rInput)
		{
		    $j=" 0 0 0 0 0";
		    $j=$propensity{$jj} if($propensity{$jj});
		    
		    @vector=split(/ /,$j);
		    for($j=1;$j<scalar(@vector);$j++)
		    {
			$windowBuff[$counter].=sprintf(" %4.3f",($vector[$j]-$avr{SA}[$pos])/$cov{SA}[$pos]);
			printf $fileName " %4.3f",($vector[$j]-$avr{SA}[$pos])/$cov{SA}[$pos];
			$pos++;
		    }
		    
		}
	    }

	    $counter++;
	}

	
    }
    return $counter;
}



sub CodeMain()
{
    my ($n,$k);
    my $seq="";

    if(length($mainSeq)>0)
    {
	@vector=split(//,$mainSeq);

	for($n=0;$n<scalar(@vector);$n++)
	{
	    if($vector[$n] ne "." and $vector[$n])
	    {
		$seq=$seq.$vector[$n];
	    }
	}

    }
    $mainSeq=$seq;
}

sub RemSpace
{
my $k=shift;
my $i;
$k=~s/-/ -/g;
$k=~s/ +/ /g;
$k=~s/\n//;
$k=~s/\r//;
return $k;
}
 
sub ReadScoringMatrix
{
    my $fileName=shift;
	my $generated=shift;
    my ($i,$k,$counter);
    my @vector;
    my @amino;

    @score=();
    @probability=();

    open(file_in,$fileName) or die "\n PSSM Matrix has not been created. Possible cause: sequence database (nr) has not been properly formatted";
    $k=<file_in>;
    $k=<file_in>;
    $k=<file_in>;
    $k=RemSpace($k);
    $k=~s/ //;
    @amino=split(/ /,$k);
	$counter=0;
    $k=<file_in>;
    while($k)
    {
	$k=RemSpace($k);
	$k=~s/ //;
	@vector=split(/ /,$k);
	if($generated==0 && $counter<length($mainSeq))
	{
		$vector[1]=$mainSeq[$counter];
		
		$counter++;
	}
	
	for($i=0;$i<20;$i++)
	{
	    $score[$vector[0]-1]{$vector[1]}{$amino[$i]}=$vector[$i+2];
#	    printf"\n score=$vector[0] $vector[1] $amino[$i] $vector[$i+2]";
	}
	for($i=20;$i<40;$i++)
	{
	    $probability[$vector[0]-1]{$amino[$i]}=$vector[$i+2]/100;
	    #printf("prob2=$probability[$vector[0]-1]{$amino[$i]}\n");
	}

	$k=<file_in>;
    }

    close(file_in);
}


#Prepare the batch script for the SNNS to save results of particular network
#for particular data. Results will be stored in test.res file.
sub TestNetwork
{
    my $net=shift;
    my $fileName=shift;
    my $res;
    
    $net.=".exe" if($osType eq "windows");
    if((-f $net) && (-f $fileName))
    {	
	unlink("test.res");
	
	%stat=CheckFileSize("$fileName");
	
	$command="$net $stat{Features} $stat{Vectors} $fileName test.res";
	$res=`$command`;
	die"\nCommand $command execution problem features=$stat{Features} vec=$stat{Vectors} name=$fileName : $res" if(length($res)>1);
    }
    else
    {
	die"\n Error!! file cannot be found $net $fileName";
    }
}

sub ReadSNNSRes
{
    my $netName=shift;
    my $k;
    my $num;
    my @vector;

#    printf file_finalRes "\n $netName";    
    %{$res{$netName}}=();
    open(file_in,"test.res") or die "\n SNNS test.res cannot be open";

    $k=<file_in>;
    while($k)
    {

	while($k && !($k=~/#/))
	{
	    $k=<file_in>;
	}
	@vector=split(/ /,$k);
        $num=$vector[1];
	$k=<file_in>;
	$k=~s/\n//;
	$k=~s/\t//;
	$res{$netName}{INPUT}[$num]=$k;
        $k=<file_in>;
   }

}



sub GetNetOutputProb
{
    my ($k,$i,$j,$n);
    my (@vec,@probabilitySc,@netAns,@prob);
    my ($res,$probAns,$sum,$seq);
    my $netList=shift;
    my $localDir=shift;
    my $flag=shift;
    my $suffix=shift;
    my %probPred;

    %res=();


    #First test newtorks in the List
    #and store results.
    foreach $k (sort keys %{$netList})
    {
#	printf file_finalRes "\n net=$k";
	if(length($suffix)>0)	    
	{
	    $tmp="$k"."_"."$suffix";
	    TestNetwork("$localDir/$k",$tmp);	    	    
	    copy("test.res","$tmp.res") or die"\nCannot copy test.res file";
#	    system("cp test.res $tmp.res > /dev/null");
	    ReadSNNSRes("$tmp");
	    
	}
	else
	{

	    TestNetwork("$localDir/$k",$k);
	    
	    copy("test.res","$tmp.res") or die"\nCannot copy test.res file";
#	    system("cp test.res $k.res");
	    ReadSNNSRes($k);
	}
#	printf file_finalRes " OK";

    }
   

    foreach $k (sort keys %res)
    {
	@probabilitySc=();
	#Average stored results based on three measures
	#of the same residue (moving window)
	for($i=0;$i<scalar(@{$res{$k}{INPUT}});$i++)
	{
	    @vector=split(/ /,$res{$k}{INPUT}[$i]);
	    for($n=0,$p=0;$n<3;$n++)
	    {
		for($j=0;$j<3;$j++,$p++)
		{
		    $probabilitySc[$i+$n][$j]+=$vector[$p];
		    $tt=$i+$n;
		   # printf"\n$probabilitySc[$i+$n][$j] $tt";
		}
		
	    }
	}
	$n=scalar(@probabilitySc);
	    
	$probAns="";
	for($n=0;$n<scalar(@probabilitySc);$n++)
	{
	    $sum=0;

	    #Build propabibilies for each of the class
	    #There are only two classes C,H,E

	    for($j=0;$j<scalar(@{$probabilitySc[$n]});$j++)
	    {
		$probabilitySc[$n][$j]=$probabilitySc[$n][$j]/3;
		$sum+=$probabilitySc[$n][$j];
		
	    }
	    $test=0;
	    for($j=0;$j<scalar(@{$probabilitySc[$n]});$j++)
	    {

		$res=0;
		$res=$probabilitySc[$n][$j]/$sum if($sum>0);
		
		$netAns[$n]{$k}{$code[$j]}=$res;
		
		if($res>0.6)
		{
		    $probAns=$probAns."$code[$j]";
		    $test=1;
		}

	    }
	    $probAns=$probAns."-" if($test==0);
	}
	
	$len=length($probAns);
    }

    $seq="";
    $probSeq="";
#    $seq="----";
    @prob=();
    for($i=0;$i<scalar(@netAns);$i++)
    {
	$rem=0;
	$answer="";
	$diff=0;
	foreach $n (sort keys %{$netAns[$i]})
	{	
	 
	    if($flag)
	    {
		if($i>0 && $i<scalar(@netAns)-1)
		{
		    foreach $j (sort keys %{$netAns[$i]{$n}})
		    {
			printf file_final "%4.3f ",$netAns[$i]{$n}{$j};
		    }
		}
	    }
	    
	    foreach $j (sort keys %{$netAns[$i]{$n}})
	    {
		$prob[$i]{$j}+=$netAns[$i]{$n}{$j};
		$spp{$j}=$netAns[$i]{$n}{$j};
#		printf"\n $netAns[$i]{$n}{$j}";
	    }
	    


	    @resH=sort {$spp{$b}<=>$spp{$a}} keys %spp;
	    if(($spp{$resH[0]}-$spp{$resH[1]})>$diff)
	    {
		%remP=%spp;
		$diff=$spp{$resH[0]}-$spp{$resH[1]};
	    }
	}
	if($flag)
	{
	    if($i>0 && $i<scalar(@netAns)-1)
	    {

#		@vecList=sort keys %{$netList};
		@vecList=sort keys %res;
		
#		printf file_final "$res{$vecList[0]}{OUTPUT}[$i-1]\n";
	    }
	}

	@t=sort keys %res;
	$t=scalar(@t);

	#And the winner is ... the class with highest probability

	@qq=sort {$prob[$i]{$b}<=>$prob[$i]{$a}} keys %{$prob[$i]};
	$answer=$qq[0];

	foreach $gg (sort keys %{$prob[$i]})
	{
	    $rem=$prob[$i]{$gg}/$t;
#	    printf"\n rem=$rem $gg";
	    $probPred{allProb}[$i]{$gg}=$rem;
	}


	$rem=10*$prob[$i]{$answer}/$t;
	$pp=substr($rem,0,1);
	$probSeq=$probSeq."$pp";

	if($rem>0.0)
	{
	    $seq=$seq."$answer";
	}
	else
	{
	    $seq=$seq."-";
	}
    }

    $len=length($seq);

    foreach $j (sort keys %{$prob[0]})
    {
#	printf"\n$j\n";
	for($i=0;$i<scalar(@netAns);$i++)
	{
	    $t=scalar(@t);
	    $rem=10*$prob[$i]{$j}/$t;
	    $pp=substr($rem,0,1);
#	    printf"%4.2f ",$rem;
	}
    }
    $counter=0;
    $counterAll=0;
#    $seq="-----".$seq."-----";
    @vector=split(//,$seq);
    for($i=0;$i<scalar(@vector);$i++)
    {
	@tmp=sort {$probPred{allProb}[$i]{$b}<=>$probPred{allProb}[$i]{$a}} keys %{$probPred{allProb}[$i]};
	if($probPred{allProb}[$i]{$tmp[0]}==$probPred{allProb}[$i]{$tmp[1]})
	{
	    $vector[$i]="H" if($tmp[0] eq "H" || $tmp[1] eq "H");
	    $vector[$i]="E" if($tmp[0] eq "E" || $tmp[1] eq "E");

	}
    }
    $seq=join("",@vector);
    $probPred{seq}=$seq;
    $probPred{prob}=$probSeq;

   

    return %probPred;
}

sub ReadPAvrCov
{
    my $fileName=shift;
    my $name=shift;
    my $k;
    my @vector;
    
    open(file_in,$fileName) or die "\n Cannot find $fileName, where averages and covariances are stored";
    $k=<file_in>;
    while($k)
    {
	@vector=split(/=/,$k);
	if($vector[0] eq "avr")
	{
	    $avr{$name}[$vector[1]]=$vector[2];
	}
	elsif($vector[0] eq "cov")
	{
	    $cov{$name}[$vector[1]]=$vector[2];
	}
	$k=<file_in>;
    }
    
    close(file_in);
}

sub ReadAvrCov()
{
    my ($k,$n);
    my @parameters;

    foreach $n (sort keys %networkList)
    {
	@parameters=split(/ /,$networkList{$n});

	ReadPAvrCov("$covDir/$parameters[8]",$n);
    }
    ReadPAvrCov("$covSADir/avrCov_269.dat","SA");
}

sub ReadFastaFile
{
    my $fileName=shift;
    my $k;
    my $name;
    my $valid = 0;
    my $seq_counter = 0;
    my %allowed = ();
    
    open(file_in,$fileName) or die "\n Cannot read provided fasta file: $fileName";

    # check the secret code
    $valid=1;
    # start read the rest part of file
    $k=<file_in>;
    while($k)
    {
	if($k=~/>/)
	{
	    $seq_counter++;
#	    chomp($k);
	    $k=~s/\n//g;
	    $k=~s/\r//g;
	    
	    $k=~s/> //;
	    $name=$k;
	    $k=<file_in>;
	    while(!($k=~/>/) && $k)
	    {
		$k=~s/\r//g;
		$k=~s/\n//g;
		$seqList{$name}.=$k;
		$k=<file_in>;
	    }
	    $allowed{$name} = $seqList{$name} if $seq_counter == 1;
   
	}
	else
	{
	    $k=<file_in>;
	}
    }

    if ($seq_counter > 1 && !($valid))
    {
	printf file_finalRes "\n\nYou are allowed to submit only one sequence via FASTA file";
	%seqList = %allowed;
    }
    close(file_in);
}
sub ReadResultSA
{
    my $fileName=shift;
    my $k;
    my ($i,$rem,$out);
    my $answer="";
    my @vector;
    my @orgRes;
    my @netRes; 	
    my %res;
   
    
    open(file_in,$fileName) or die"\n File $filename with results of solvent accessibilities cannot be open";
    $k=<file_in>;

    while($k)
    {
	if($k=~/#/)
	   {
	      $k=<file_in>; 
	      chomp($k);
	      $k=~s/\n//g;
	      $k=~s/\r//g;		      
	      $out=$k;

	      push @orgRes,$out;
	      push @netRes,$out;
#	      printf"\n $out";

	      
	   }
	   else
	   {
	       $k=<file_in>;
	   }
    }

    close(file_in);
    @{$res{SOLVENT}}=@orgRes;
    @{$res{NETRES}}=@netRes;

    return %res;
    
}
sub ReadResultThermSA
{
    my $fileName=shift;
    my $k;
    my ($i,$rem,$out);
    my $answer="";
    my @vector;
    my @orgRes;
    my @netRes;
    my %res;
   

    open(file_in,$fileName) or die"\n File cannot be open";


    $k=<file_in>;
    
    while($k)
    {
	if($k=~/#/)
	   {
	       $k=<file_in>; 
	       $k=<file_in>; 
	       $k=<file_in>; 
	       chomp($k);
	       $out=$k;
	       $k=<file_in>; 
	       chomp($k);
	      $out.=" $k";
	       @vector=split(/ /,$out);
#	      printf"\n vec=@vector";
	       $rem=0;
	       for($i=0;$i<scalar(@vector);$i++)
	       {
		   $rem=$i if($vector[$i]>0.5);
	       }
	       $rem++;
	       $rem*=5;

	       $rem=100-$rem;
	       $rem=0 if($rem<0);
	       push @orgRes,$out;
	       push @netRes,$rem;
	       
	   }
	   else
	   {
	       $k=<file_in>;
	   }
       }
	
	close(file_in);

	@{$res{SOLVENT}}=@orgRes;
	printf"\n @netRes";
	@{$res{NETRES}}=@netRes;
	
	return %res;
    
}

sub SecondOutput
{
    my ($k,$i,$j,$i,$m);
    my (@k_input,@k_output);
    my $tmp;
    my $tmp_s;
    my $counter=0;
    my $suffix=shift;



    foreach $qq (sort keys %networkList)
    {
	$tmp=$qq;
	$tmp=$qq."_"."$suffix" if(length($suffix)>0);
	@parameters=split(/ /,$networkList{$qq});
	TestNetwork("$netDir/$qq",$tmp);

	open(file_sec,">$tmp") or die"\n File cannot be open";
	open(file_test,"test.res") or die"\n Test file cannot be open";
	
	$k=<file_test>;
	@k_input=();
	@k_output=();
	$counter=0;
	while($k)
	{
	    if($k=~/\#/)
	       {
		   $k=<file_test>;  
		   chomp($k);
		   $k_input[$counter]=$k;
		   $counter++;
	       }
	       else
	       {
		   $k=<file_test>;
	       }
	}
	    
	for($i=0;$i<$counter-10;$i++)
	{
	    for($j=$i;$j<$i+11;$j++)
	    {
		print file_sec "$k_input[$j] ";
	    }
	    
	    if($ENV{SABLE_VERSION} eq "sable2")
	    {
		print file_sec " $solventBuff[$i+5]";
#		print file_sec " 0 0 0 0 0 0 0 0 0 0 0";
	    }
#	    print file_sec " $k_output[$i+5]\n";
	    print file_sec "\n";
	}

	close(file_test);
	
	close(file_sec);
	
	
	open(file_test,">testSNNS.dat");
	print file_test "SNNS pattern definition file V3.2";
	print file_test "\ngenerated at Mon Apr 25 15:58:23 1994";
	
	$counter-=10;
	print file_test "\n\nNo. of patterns : $counter";
	if($ENV{SABLE_VERSION} eq "sable2")
	{
	    print file_test "\nNo. of input units : 110";
	}
	else
	{
	    print file_test "\nNo. of input units : 99";
	}
	print file_test "\nNo. of output units : 9\n\n";
	
	close (file_test);
	$tmp_s=$parameters[9];
	
	
	if(length($suffix)>0)
	{
	    $tmp_s=$tmp_s."_"."$suffix";
	}
#	system("cat testSNNS.dat  $tmp > $tmp_s");
	cat("testSNNS.dat","$tmp","$tmp_s");
    }
    

}

sub CombineResults
{
    my $resultNr=shift;
    my $resultSwiss=shift;
    my (@vectorNr,@vectorSw,@vectorNrP,@vectorSwP,@allProb);
    my $i;
    my %res;

    @vectorNr=split(//,$$resultNr{seq});
    @vectorSw=split(//,$$resultSwiss{seq});
    @vectorNrP=split(//,$$resultNr{prob});
    @vectorSwP=split(//,$$resultSwiss{prob});
    
    $tmp=scalar(@vectorNr);

    for($i=0;$i<scalar(@vectorNr);$i++)
    {
	if($vectorSwP[$i]>$vectorNrP[$i] && $vectorSwP[$i]>=7)
	{
	    $vectorNrP[$i]=$vectorSwP[$i];
	    $vectorNr[$i]=$vectorSw[$i];
	    foreach $m (sort keys %{$$resultSwiss{allProb}[$i]})
	    {
		$allProb[$i]{$m}=$$resultSwiss{allProb}[$i]{$m};
	    }
	}
	else
	{
	    foreach $m (sort keys %{$$resultNr{allProb}[$i]})
	    {
		$allProb[$i]{$m}=$$resultNr{allProb}[$i]{$m};
	    }
	}
    }


    $res{seq}=join("",@vectorNr);
    $res{prob}=join("",@vectorNrP);    
    @{$res{allProb}}=@allProb;

    
    $tmp=scalar(@allProb);

    return %res;
}

sub FinalPrediction
{
    $mat=shift;
    my ($i,$j);
    my @sum;
    my (@vector,@vectorP,@H,@E,@C);
    my %res;

    for($i=0;$i<scalar(@{$mat});$i++)
    {
#	printf"\n$$mat[$i]{seq}";
	@vectorP=split(//,$$mat[$i]{prob});
	@vector=split(//,$$mat[$i]{seq});
	for($j=0;$j<scalar(@vector);$j++)
	{
	    @tmp=sort keys %{$$mat[$i]{allProb}[$j]};
	    foreach $n (sort keys %{$$mat[$i]{allProb}[$j]})
	    {
		if($sum[$j]{VAL}<$$mat[$i]{allProb}[$j]{$n})
		{
		    $sum[$j]{VAL}=$$mat[$i]{allProb}[$j]{$n};
		    $sum[$j]{WIN}=$n;
		}

#		$sum[$j]{$n}+=$$mat[$i]{allProb}[$j]{$n};
	    }
	    push @H,$$mat[$i]{allProb}[$j]{H};
	    push @E,$$mat[$i]{allProb}[$j]{E};
	    push @C,$$mat[$i]{allProb}[$j]{C};
#	    $sum[$j]{$vector[$j]}+=$vectorP[$j];
	}
	
    }

    
    $res{seq}="";
    $res{prob}="";

    @{$res{H}}=@H;
    @{$res{E}}=@E;
    @{$res{C}}=@C;

    for($j=0;$j<scalar(@sum);$j++)
    {
	$res{seq}.=$sum[$j]{WIN};
	$res{prob}.=substr(sprintf("%4.2f",($sum[$j]{VAL}/scalar(@{$mat})*100)),0,1);
#	printf"%4.2f ",$sum[$j]{VAL}/scalar(@{$mat});
    }

    if($ENV{SABLE_VERSION} eq "sable2")
    {
	$res{seq}=~s/CHC/CCC/g;
    }

    return %res;
}

sub TestSVR()
{
    my ($k,$i);
    my %res;
    my (@vec,@svrModel,@tmp);

    open(file_in,"$installDir/SVR2.model") or die"\n File SVR model cannot be open";

    $k=<file_in>;
    while(!($k=~/feature/))
    {
	$k=<file_in>;
    }
    while($k && $k=~/feature/)
    {
	$k=~s/\t/ /g;
	$k=~s/ +/ /g;
	$k=~s/\n//g;
	$k=~s/\r//g;

	if($k=~/feature/)
	{
	    @vec=split(/ /,$k);
	    push @svrModel,$vec[2];
	}
	$k=<file_in>;	
    }
    $b=<file_in>;	


    close(file_in);

    open(file_in,"testSNNS.dat") or die"\n File for SVR test cannot be open";

    $k=<file_in>;

    while($k)
    {
	$k=~s/^ //;
	@vec=split(/ /,$k);
	if(scalar(@vec)>100)
	{
	    $sum=0;
	    
	    for($i=0;$i<scalar(@svrModel);$i++)
	    {
		$sum+=$svrModel[$i]*$vec[$i];
	    }
	    $sum+=$b;
	    $sum=0 if($sum<0);
		
	    $buff=sprintf"%3.1f",$sum*100;
	    @vec=split(/\./,$buff);
	    $buff=$vec[0];
	    push @{$res{NETRES}},$buff;
	}

	$k=<file_in>;
    }

    close(file_in);
    @tmp=($res{NETRES}[0],@{$res{NETRES}},$res{NETRES}[$#{$res{NETRES}}]);
    @{$res{NETRES}}=@tmp;

    return %res;
}

sub CheckFileSize
{
    my $fileName=shift;
    my %res;
    my $k;

    open(file_in,$fileName) or die "\n File $fileName cannot be open";
    $k=<file_in>;

    while($k && scalar(@{keys %res})<2)
    {
	$k=~s/\n//g;
	$k=~s/\r//g;

	if($k=~/patterns/)
	{
	    @tmp=split(/:/,$k);
	    $res{Vectors}=$tmp[$#tmp];
	}
	if($k=~/input units/)
	{
	    @tmp=split(/:/,$k);
	    $res{Features}=$tmp[$#tmp];
	}
	$k=<file_in>;
    }

    close(file_in);


    return %res;
    
}
sub MakeBLOSUM
{
  my $fileName=shift;
  my $fileOut=shift;
  
  open(file_in,$fileName) or die "$fileName cannot be open";
  open(file_out,">$fileOut") or die "$fileOut cannot be open";
  $name=<file_in>;
  chomp($name);
  $seq=<file_in>;
  
  printf file_out "$name\t$seq";
  
  close(file_in);
  close(file_out);
}

sub cat
{
    $file1=shift;
    $file2=shift;
    $file_out=shift;
    
    open(file_out,">$file_out") or die"\nFile $file_out cannot be open";
    open(file_in,$file1) or die"\nFile cannot be open";
    $k=<file_in>;
    while($k)
    {
    	printf file_out "$k";
    	$k=<file_in>;	
    }
    close(file_in);
    
    open(file_in,$file2) or die"\nFile cannot be open";
    $k=<file_in>;
    while($k)
    {
    	printf file_out "$k";
    	$k=<file_in>;	
    }
    
    close(file_in);
    close(file_out);
    
        
    
}

sub GeneratePSSM
{
  my $query=shift;
  my $pssm=shift;
  my $flag=shift;

  my $psiOut="psi.out";
  
  if($flag eq "secondary")
  {
  	system("$psiBlast -num_threads 2 -query query -comp_based_stats 0 -num_iterations 3 -db $nr -out align.out -out_ascii_pssm $pssm -gilist $secondaryDatabase");
  }
  else
  {
	if(defined($ENV{PRIMARY_DATABASE}))
	{
		system("$psiBlast -num_threads 2 -query query -comp_based_stats 0 -num_iterations 3 -db $nr -out align.out -out_ascii_pssm $pssm -gilist $ENV{PRIMARY_DATABASE}");
	}
	else
	{
	  	system("$psiBlast -num_threads 2 -query query -comp_based_stats 0 -num_iterations 3 -db $nr -out align.out -out_ascii_pssm $pssm");
	}

  }	

  system("cp $pssm $installDir/PSSM_generated/");

}
sub MakeBLOSUM
{
  my $fileName=shift;
  my $fileOut=shift;
  
  open(file_in,$fileName) or die "$fileName cannot be open";
  open(file_out,">$fileOut") or die "$fileOut cannot be open";
  $name=<file_in>;
  chomp($name);
  $seq=<file_in>;
  
  printf file_out "$name\t$seq";
  
  close(file_in);
  close(file_out);
}
