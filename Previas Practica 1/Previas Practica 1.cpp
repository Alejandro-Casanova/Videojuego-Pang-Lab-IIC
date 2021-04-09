#include <stdio.h> 
#include <math.h> 

struct punto{ 
	float x; 
	float y; 
	float radio;
}; 

//Define una estructura vector 2D
struct vec2{
	float x;
	float y;
};

//Calcula el vector que une dos puntos
vec2 getVector(const punto& p1, const punto& p2) {
	vec2 aux;
	aux.x = p2.x - p1.x;
	aux.y = p2.y - p1.y;
	return aux;
}

typedef struct {
	punto p1;
	punto p2;
} segmento;

float Distancia(punto p1, punto p2) { 
	float delta_x=p1.x-p2.x; 
	float delta_y=p1.y-p2.y; 
	float norma=delta_x*delta_x+delta_y*delta_y; 
	float dist=sqrtf(norma); 
	return dist; 
}

//Pide al usuario los parámetros de una circunferencia
void askForCircle(punto& punto, const char* const prompt) {
	printf(prompt);
	scanf_s("%f %f %f", &punto.x, &punto.y, &punto.radio);
}

//Pide al usuario las coordenadas de un segmento
void askForSegment(segmento& segmento, const char* const prompt) {
	printf(prompt);
	printf("Introduzca las coordenadas del primer punto que define el segmento.\n");
	scanf_s("%f %f", &segmento.p1.x, &segmento.p1.y);
	printf("Introduce las coordenadas del segundo punto que define el segmento\n");
	scanf_s("%f %f", &segmento.p2.x, &segmento.p2.y);
}

//Calcula la distancia mínima entre un punto y un segmento
float minDistance(const segmento& segmento, const punto& punto) {
	//Obtiene los vectores que unen los extremos del segmento y el punto
	vec2 AB, BP, AP;
	AB = getVector(segmento.p1, segmento.p2);
	BP = getVector(segmento.p2, punto);
	AP = getVector(segmento.p1, punto);
	//Calcula los productos punto necesarios
	float AB_BP = (AB.x * BP.x + AB.y * BP.y);
	float AB_AP = (AB.x * AP.x + AB.y * AP.y);
	
	//Si la distancia mínima es |BP|
	if (AB_BP > 0) {
		return sqrtf(BP.x * BP.x + BP.y * BP.y);
	}
	//Si la distancia mínima es |AP|
	else if (AB_AP < 0) {
		return sqrtf(AP.x * AP.x + AP.y * AP.y);
	}
	//Si la distancia mínima es perpendicular al segmento
	else {
		float mod = sqrtf(AB.x * AB.x + AB.y * AB.y);
		return fabsf(AB.x * AP.y - AB.y * AP.x) / mod;
	}
}

//Comprueba colisión entre dos círculos
int checkForCollision(const punto& punto1, const punto& punto2) {
	float minDist = punto1.radio + punto2.radio;
	return Distancia(punto1, punto2) < minDist;
}

//Comprueba colisión entre círculo y segmento
int checkForCollision(const punto& punto, const segmento& segmento) {
	return minDistance(segmento, punto) < punto.radio;
}

int main(void) { 
	punto punto1; 
	segmento segmento;

	askForCircle(punto1, "Introduzca las coordenadas y el radio del primer círculo\n");
	askForSegment(segmento, "Introduzca las coordenadas del segmento:\n");
	printf("Distancia Minima: %f\n", minDistance(segmento, punto1));
	
	if (checkForCollision(punto1, segmento)) {
		printf("Existe colision entre el punto y el segmento.\n");
	}
	else {
		printf("No existe colision entre el punto y el segmento\n");
	}

	/*
	punto punto2 punto3;
	askForCircle(punto2, "Introduzca las coordenadas y el radio del segundo punto\n");
	
	float d=Distancia(punto1,punto2); 
	printf("Distancia entre los puntos=%f\n",d); 

	if (checkForCollision(punto1, punto2)) {
		printf("Existe colision.\n");
	}
	else {
		printf("No existe colision\n");
	}
	*/
}