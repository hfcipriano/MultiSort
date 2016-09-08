#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
	if(argc<3){
		printf("\nSintaxe:\nleBin <Arquivo> <quantidade de numeros> \n\n");
		return -1;
	}else{
		int i,*v,n = atoi(argv[2]);
		char *filename=argv[1];
		FILE *arq;
		v=(int*)malloc(n*sizeof(int));
		arq=fopen(filename,"rb+");
		fread(v,sizeof(int),n,arq);
		for(i=0; i<n; i++){
			printf("%d ",v[i]);
		}
		printf("\n");
		free(v);
		fclose(arq);
		return 0;
	}
}
