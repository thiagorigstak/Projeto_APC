/*Algoritmos e Programação de Computadores - 2/2019
Aluno(a): < Thiago Rigotto Stachuk >
Matricula: < 190139331 >
Turma: B
Versão do compilador: < gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0 >
Descricao:
< O programa utiliza uma database chamada glass.data para achar a categoria de um copo fornecido pelo usuario comparando com os as caracteristicas dos copos ja existentes na database>
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	double atributo[9];
	int categoria;
}Copo;//* a estrutura servira para guardar os copos do arquivo .data e o copo inserido pelo usuario *//

typedef struct{
	double dist;
	int cat;
}Distancia;//* a estrutura serve para guardar o calculo da distancia manhattan e euclidiana junto da categoria do copo comparado *//

Copo leitura(FILE *DATA,Copo copos[214]){
	int id;
	int i,j=0;
	while(fscanf(DATA,"%d,",&id) != EOF){
		for(i=0;i<9;i++){
			fscanf(DATA,"%lf,",&copos[j].atributo[i]);
		}
		fscanf(DATA,"%d",&copos[j].categoria);
		j++;
	}
	return *copos;
}//* a funcao serve para ler e armazenar os copos e dados contidos no arquivo .data *//

Copo Insert(){
	Copo compara;
	printf("Por favor insira o (RI) do copo : \n");
	scanf("%lf",&compara.atributo[0]);
	printf("Por favor insira o (Na) do copo : \n");
	scanf("%lf",&compara.atributo[1]);
	printf("Por favor insira o (Mg) do copo : \n");
	scanf("%lf",&compara.atributo[2]);
	printf("Por favor insira o (Al) do copo : \n");
	scanf("%lf",&compara.atributo[3]);
	printf("Por favor insira o (Si) do copo : \n");
	scanf("%lf",&compara.atributo[4]);
	printf("Por favor insira o (K)  do copo : \n");
	scanf("%lf",&compara.atributo[5]);
	printf("Por favor insira o (Ca) do copo : \n");
	scanf("%lf",&compara.atributo[6]);
	printf("Por favor insira o (Ba) do copo : \n");
	scanf("%lf",&compara.atributo[7]);
	printf("Por favor insira o (Fe) do copo : \n");
	scanf("%lf",&compara.atributo[8]);
	return compara;
}//* a funcao serve para coletar os dados fornecidos pelo usuario *//

double manhattan(Copo copos, Copo compara){
	int j;
	double lenght=0;
		for(j=0;j<9;j++){
			lenght += fabs(copos.atributo[j]-compara.atributo[j]);
		}
	return lenght;
}//* a funcao efetua o calculo manhattan *//

double euclidiana(Copo copos, Copo compara){
	int i;
	double lenght=0;
	for(i=0;i<9;i++){
		lenght += pow(copos.atributo[i]-compara.atributo[i],2);
	}
	return lenght;
}//* a funcao efetua o calculo euclidiana *//

int verifica(int N, int K){
	if(K%2==0 || K<1 || K>15){
		printf("numero de K copos invalido\n");
		if(N!=1 && N!=2){
			printf("Tipo de conta inexistente\n");
		}
		return 0;
	}
	if(N!=1 && N!=2){
		printf("Tipo de conta inexistente\n");
		return 0;
	}
	return 1;
}//* a funcao verifica se os numeros inseridos pelo usuario sao validos *//

void organiza(Distancia longitude[214]){
	Distancia x;
	int i,j;
	for(i=0;i<214;i++){
		for(j=0;j<213;j++){

			if(longitude[j].dist>longitude[j+1].dist){
				x = longitude[j];
				longitude[j] = longitude[j+1];
				longitude[j+1] = x;
			}
		}
	}
}//* a funcao organiza as distancias da menor para a maior *//

int kvzn(int K,Distancia longitude[214]){
	int i;
	int maiorvizinho[7]={0,0,0,0,0,0,0};
	for(i=0;i<K;i++){
		if(longitude[i].cat == 1){
			maiorvizinho[0]++;
		}else if(longitude[i].cat == 2){
			maiorvizinho[1]++;
		}else if(longitude[i].cat == 3){
			maiorvizinho[2]++;
		}else if(longitude[i].cat == 4){
			maiorvizinho[3]++;
		}else if(longitude[i].cat == 5){
			maiorvizinho[4]++;
		}else if(longitude[i].cat == 6){
			maiorvizinho[5]++;
		}else if(longitude[i].cat == 7){
			maiorvizinho[6]++;
		}
	}
	if(maiorvizinho[0]>maiorvizinho[1] && maiorvizinho[0]>maiorvizinho[2] && maiorvizinho[0]>maiorvizinho[3] && maiorvizinho[0]>maiorvizinho[4] && maiorvizinho[0]>maiorvizinho[5] && maiorvizinho[0]>maiorvizinho[6]){
		return 1;
	}else if(maiorvizinho[1]>maiorvizinho[0] && maiorvizinho[1]>maiorvizinho[2] && maiorvizinho[1]>maiorvizinho[3] && maiorvizinho[1]>maiorvizinho[4] && maiorvizinho[1]>maiorvizinho[5] && maiorvizinho[1]>maiorvizinho[6]){
		return 2;
	}else if(maiorvizinho[2]>maiorvizinho[0] && maiorvizinho[2]>maiorvizinho[1] && maiorvizinho[2]>maiorvizinho[3] && maiorvizinho[2]>maiorvizinho[4] && maiorvizinho[2]>maiorvizinho[5] && maiorvizinho[2]>maiorvizinho[6]){
		return 3;
	}else if(maiorvizinho[3]>maiorvizinho[0] && maiorvizinho[3]>maiorvizinho[1] && maiorvizinho[3]>maiorvizinho[2] && maiorvizinho[3]>maiorvizinho[4] && maiorvizinho[3]>maiorvizinho[5] && maiorvizinho[3]>maiorvizinho[6]){
		return 4;
	}else if(maiorvizinho[4]>maiorvizinho[0] && maiorvizinho[4]>maiorvizinho[1] && maiorvizinho[4]>maiorvizinho[2] && maiorvizinho[4]>maiorvizinho[3] && maiorvizinho[4]>maiorvizinho[5] && maiorvizinho[4]>maiorvizinho[6]){
		return 5;
	}else if(maiorvizinho[5]>maiorvizinho[0] && maiorvizinho[5]>maiorvizinho[1] && maiorvizinho[5]>maiorvizinho[2] && maiorvizinho[5]>maiorvizinho[3] && maiorvizinho[5]>maiorvizinho[4] && maiorvizinho[5]>maiorvizinho[6]){
		return 6;
	}else if(maiorvizinho[6]>maiorvizinho[0] && maiorvizinho[6]>maiorvizinho[1] && maiorvizinho[6]>maiorvizinho[2] && maiorvizinho[6]>maiorvizinho[3] && maiorvizinho[6]>maiorvizinho[4] && maiorvizinho[6]>maiorvizinho[5]){
		return 7;
	}else{
		return longitude[0].cat;
	}
	return 0;
}//* a funcao retorna o numero da categoria do copo inserido pelo usuario *//

int main(){
	Copo copos[214];//* copos sera usado para guardar os copos no arquivo .data *//
	Copo compara;//* compara e o copo inserido pelo usuario *//
	Distancia longitude[214];//* longitude sera usado para armazenar o calculo das distancias e a categoria do copo pertencente a .data comparado *//	
	int i,K,N,C;//* K e N servem para o valor de K vizinhos e tipo da conta que sera utilizada pelo usuario e C serve para armazenar o tipo de copo retornado por kvzn *//
	FILE *DATA;
	DATA = fopen("glass.data","r");
	leitura(DATA,copos);
	compara = Insert();
	printf("Os numeros validos de K sao 1,3,5,7,9,11,13,15.\n");
	printf("Por favor insira o numero de K copos a serem comparados : \n");
	scanf("%d",&K);//* scaneia o numero de Kvizinhos a serem comparados *//
	printf("Por favor escolha o tipo de conta (1)-euclidiana ou (2)-manhattan : \n");
	scanf("%d",&N);//* scaneia o tipo de conta que o usuario deseja que seja implementada *//
	if(verifica(N,K)==0){
		return 0;
	}
	if(N==1){
		for(i=0;i<214;i++){
			longitude[i].dist = euclidiana(copos[i],compara);
			longitude[i].cat = copos[i].categoria;
		}//* caso N seja 1 a conta euclidiana e posta em pratica *//
	}else if(N==2){
		for(i=0;i<214;i++){
			longitude[i].dist = manhattan(copos[i],compara);
			longitude[i].cat = copos[i].categoria;
		}
	}//* caso N seja 2 a conta manhattan sera posta em pratica *//
	organiza(longitude);//* organiza a distancia conservando as categorias *//
	C = kvzn(K,longitude);//* implementa Kvizinhos e lança o resultado *//
	if(C==1){
		printf("O copo inserido pertence a categoria | 1 |-(buildingwindowsfloatprocessed)\n");
	}else if(C==2){
		printf("O copo inserido pertence a categoria | 2 |-(buildingwindowsnonfloatprocessed)\n");
	}else if(C==3){
		printf("O copo inserido pertence a categoria | 3 |-(vehiclewindowsfloatprocessed)\n");
	}else if(C==4){
		printf("O copo inserido pertence a categoria | 4 |-(vehiclewindowsnonfloatprocessed)\n");
	}else if(C==5){
		printf("O copo inserido pertence a categoria | 5 |-(containers)\n");
	}else if(C==6){
		printf("O copo inserido pertence a categoria | 6 |-(tableware)\n");
	}else if(C==7){
		printf("O copo inserido pertence a categoria | 7 |-(headlamps)\n");
	}
	fclose(DATA);
	return 0;
}