#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int net(float *in, float *out, int init);


float **data;
int features, vec_number;


int SaveResults(char *fileName)
{
  int i,j;
  float out[20];
  FILE *fileWrite;

  fileWrite=fopen(fileName,"w");
  
  if(!fileWrite)
    return 1;

  for(i=0;i<vec_number;i++)
  {
      printf("\n# %d\n",i);
      for(j=0;j<features;j++)
      {
	  printf(" %f",data[i][j]);
      }
      net(data[i],out,0);
      
      for(j=0;j<20;j++)
      {
	  fprintf(fileWrite,"%f ",out[j]);
      }
      fprintf(fileWrite,"\n");
  }

  
  fclose(fileWrite);

  return 0;

}


int ReadFile(char *fileName)
{
  FILE *fileRead;
  int i,j;
  
  fileRead=fopen(fileName,"r");


  if(!fileRead)
    return 1;


  data=malloc(sizeof(float *)*vec_number);
  for(i=0;i<vec_number;i++)
    data[i]=malloc(sizeof(float)*features);


  for(i=0;i<vec_number;i++)
    for(j=0;j<features;j++)
      fscanf(fileRead,"%f",&data[i][j]);

  fclose(fileRead);


  for(i=0;i<vec_number;i++)
  {
    free(data[i]);
  }

  free(data);

  return 0;
}

/*##############################################################
###Parameters: number of features, number of vectors, file name
##############################################################*/
int main(int argc,char *argv[])
{
  int res;

  if(argc<4)
  {
    printf("Number of parameters have to be 4\n");
    printf("number of features\nnumber of vectors\ndata file name\noutput file nmae\n");
    exit(-1);
  }


  features=atoi(argv[1]);
  vec_number=atoi(argv[2]);

  printf("\n features=%d vec_num=%d",features,vec_number);

  res=ReadFile(argv[3]);
  if(res)
  {
    printf("Reading file %s ERROR\n",argv[3]);
    exit(-1);
  }
  res=SaveResults(argv[4]);
  if(res)
  {
    printf("Result file %s ERROR\n",argv[4]);
    exit(-1);
  }
    
    
  
}
