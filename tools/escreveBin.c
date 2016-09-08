#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000
int main(int argc, char **argv){
	if(argc<2){
		printf("\nSintaxe:\nescreveBin <quantidade de numeros> <Arquivo de saida>\n\n");

		return -1;
	}else{
		int i,*v,n = atoi(argv[1]);
		v=(int*)malloc(n*sizeof(int));
		srand(time(NULL));
		for(i=0; i<n; i++){
			v[i]=rand()%MAX;
		}
		fwrite(v,sizeof(int),n,stdout);
		free(v);
		return 0;
	}
}
