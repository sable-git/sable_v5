# sable_v5
Sable is a software package for solvent accessibility and secondary structure prediction in proteins.

Sable uses Neural Network based regression for real value Relative Solvent Accessibility prediction (one of the pioneering methods in that regard), meta-classifiers for confidence scores, multi-task learning that combines RSA and secondary structure prediction, and has the advantage of biasing the prediction by single sequence derived features (see Adamaczak et al. below). The latter features enables predicting changes in conformational propensities (and thus potential functional consequences) due to point mutations and polymorphisms, and can be used for 'evolutionary threading', i.e., testing of the compatibility between the query sequence and an evolutionary field of a fold (as represented by its PSSM) for the prediction of protein stability and conformational switches, as demontrated in Chen et al., Protein Science 2016). Sable is available as a web server at http://sable.cchmc.org (and has been used by over 40,000 users so far), has been applied in conjunction with pioneering transfer learning for transmembrane domain prediction (http://minnou.cchmc.org) and to provide a novel signal of protein interaction sites in Sppider (http://sppider.cchmc.org).

The current version has several modifications compared to Sable ver. 4, including a hot start from a precomputed PSSM that facilitates the 'evolutionary threading' by effectively placing a query sequence into an evolutionary field (PSSM) of another fold, or simply to avoid repeated generation of PSSM for essentially the same sequence if the effects of point mutations or polymorphisms are to be assessed. The current version is also made available as a Docker container to make it compatible with the current cloud platforms.

For the description of the underlying methodology and references please see/cite:

Combining prediction of secondary structure and solvent accessibility in proteins
R Adamczak, A Porollo, J Meller
Proteins: Structure, Function, and Bioinformatics 59 (3), 467-475

Accurate prediction of solvent accessibility using neural networks–based regression
R Adamczak, A Porollo, J Meller
Proteins: Structure, Function, and Bioinformatics 56 (4), 753-767

Linear regression models for solvent accessibility prediction in proteins
M Wagner, R Adamczak, A Porollo, J Meller
Journal of Computational Biology 12 (3), 355-369

