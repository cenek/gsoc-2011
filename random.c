#include   <stdio.h>
#include   <stdlib.h>
#include   <math.h>
#include   <sys/time.h>
#include   "random.h"

#define IA	16807
#define IM	2147483647
#define AM	(1.0/IM)
#define IQ	127773
#define IR	2836
#define NTAB	32
#define NDIV	(1+(IM-1)/NTAB)
#define EPSILON	1.2e-7
#define RNMX	(1.0-EPSILON)


static long id;

long set_seed(long id_ext){
  id = id_ext;
  return id;
}

/*float uniform(long *idum)*/
float uniform(){
  int j;
  long k;
  long *idum = &id;
  static long iy=0;
  static long iv[NTAB];
  float temp;
  
  if(*idum <= 0 || !iy){
    if(-(*idum) < 1) *idum=1;
    else
      *idum= -(*idum);
    for(j=NTAB+7; j>=0; j--)
      {
	k=(*idum)/IQ;
	*idum=IA*(*idum-k*IQ)-IR*k;
	if(*idum<0) *idum += IM;
	if(j<NTAB) iv[j]= *idum;
      }
    iy=iv[0];
  }
  
  k=(*idum)/IQ;
  *idum=IA*(*idum-k*IQ)-IR*k;
  if(*idum<0) *idum += IM;
  j=(int )iy/NDIV;
  iy=iv[j];
  iv[j]= *idum;
  if((temp=AM*iy)>RNMX) return RNMX;
  else return temp;
}


/*float normal(long *idum){*/
float normal(){
  static int iset=0;
  static float gset;
  float fac,rsq,v1,v2;
  
  if(iset==0){
    do{
      v1=2.0*uniform()-1.0;
      v2=2.0*uniform()-1.0;
      rsq=v1*v1+v2*v2;
    }while(rsq>=1.0 || rsq==0.0);
    fac=sqrt(-2.0*log(rsq)/rsq);
    gset=v1*fac;
    iset=1;
    return v2*fac;
  } else{
    iset=0;
    return gset;
  }
}

/*float expdev(long *idum){*/
float expdev(){
  float dum;
  do
    dum= uniform();
  while (dum==0.0);
  return -log(dum);
}

int r0n(int n){
  /*  returns a random integer in the interval [0,n-1] */
  return (int )floor((float )n*uniform());
}

int rnm(int n, int m){
/*  returns a random integer in the interval [n,m] */
  int k;

  do{
    k=r0n(m+1);
  }while(k<n || k>m);
  return k;
}

long seed_random (long seed){
  if (seed < 1){
    extern int gettimeofday();
    
    struct timeval tp;
    if (gettimeofday(&tp, (struct timezone *)0) == -1){
      fprintf(stderr, "Could not gettimeofday in knuth_srand().");
      exit(1);
    }
    
    seed = tp.tv_usec;
  }

  id = -seed;
  return id;
}
