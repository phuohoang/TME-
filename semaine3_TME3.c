printf("Hello")
// Semaine3 - TME

// Exercice 16 - Qu'est-ce qu'un pointeur?:

// Question 1:
#include <stdio.h>

void ma_fonction(int *v1, int *v2) {
 	
  	*v2 = *v1 + *v2;
  	*v1 = 2 * *v2;
  	*v2 = 2 * *v2;
}



// Exercice 17 – (CodeRunner) Compter les valeurs positives, négatives et les zéros:

// Question 1:
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 50
#define VMIN -20
#define VMAX 20

int valeur_aleatoire(int min, int max){
	/*Renvoie un entier aléatoirement compris entre min et max*/
	int valeur = rand();
	while ((valeur>max) || (valeur<min)){
		valeur = rand();
	}
  return valeur;
}

// Question 2:
int pos_neg_zero(int k, int *pos, int *neg, int *zero){
	/*Revoie 1 si k est positive, -1 si k est négative et 0 si k est nule*/
	if (k==0){
		return *zero = *zero + 1;
	}
	else{
		if (k>0){
			return *pos = *pos + 1;
		}
		else{
			return *neg = *neg + 1;
		}
	}
}

// Question 3:
// Voir main()



// Exercice 18 – (CodeRunner) Tri de trois valeurs:

// Question 1:
void echange(int *v1, int *v2){
	/*Echange les valeurs pointées par v1 et v2*/
	int t = *v1;
	*v1 = *v2;
	*v2 = t;
}


// Question 2:
void tri(int *v1, int *v2){
	/*Met ans le premier paramètre le plus petit des deux entiers et le plus grand dans la deuxième.*/
	if (*v1>*v2){
		echange(v1, v2);
	}
}


// Question 3:
void tri_3(int *v1, int *v2, int *v3){
	/*Met ans le premier paramètre le plus petit des trois entiers, le plus grand dans le dernier et le troisième entier dans le deuxième paramètre.*/
	tri(v1, v2);
	tri(v1, v3);
	tri(v2, v3);
}



// Exercice 19 – (CodeRunner) Calcul de la moyenne, du minimum et du maximum:

// Question 1:
#define VAL1 2
#define VAL2 7
#define VAL3 5
#define VAL4 9
void min_max(int a, int *min , int *max) {
	if (a<*min){
		*min = a;
	}
	if (a>*max){
		*max = a;
	}
}

// Question 2:
void stats (int v1, int v2, int v3, int v4, int *min, int *max, float *moy) {
	if (v1<=0){
		*min = -1;
		*max = -1;
		*moy = -1.0;
	}
	else{
		if (v2<=0){
			*max = v1;
			*min = v1;
			*moy = v1;
		}
		else{
			if (v3<=0){
			*moy = (v1+v2)/(float)2;
			*max = v1;
			*min = v1;
			min_max(v2, min, max);
			}
			else{
				if (v4<=0){
				*moy = (v1+v2+v3)/(float)3;
				*max = v1;
				*min = v1;
				min_max(v2, min, max);
				min_max(v3, min, max);
				}
				else{
					*moy = (v1+v2+v3+v4)/(float)4;
					*max = v1;
					*min = v1;
					min_max(v2, min, max);
					min_max(v3, min, max);
					min_max(v4, min, max);
				}
			}
		
			
	
		}
	}
}



// Exercice 20 – (CodeRunner) Calcul des Racines d’un polynôme du second degré

// Question 1:
int nb_racines(int a, int b, int c) {
	int delta = (b*b) - (4*a*c);
	
	if (delta<0){
		return 0;
	}
	else{
		if (delta==0){
			return 1;
		}
		else{
			return 2;
		}
	} 
  	
}

// Question 2:
int nb_racines_delta(int a, int b, int c, int *pdelta) {
	*pdelta = (b*b) - (4*a*c);
	
	if (*pdelta<0){
		return 0;
	}
	else{
		if (*pdelta==0){
			return 1;
		}
		else{
			return 2;
		}
	} 
  	
}

// Question 3:
#include <math.h>
int racines (int a, int b, int c, int *pdelta, float *pracine1, float *pracine2) {
	int nb = nb_racines_delta(a, b, c, pdelta);
	if (nb>0){
		*pracine1 = (-b+sqrt(*pdelta))/(float)(2*a);
		*pracine2 = (-b-sqrt(*pdelta))/(float)(2*a);
		 
	}
	else{
		if (nb==0){
			*pracine1 = -b/(float)(2*a);
			*pracine2 = -b/(float)(2*a);		
		}
	}
	return nb;
}

int main() {
	// Exercice 16 - Qu'est-ce qu'un pointeur?:
	printf("Exercice 16 - Qu'est-ce qu'un pointeur?:\n");
	int a = 10;
	int b = 20;
	printf("Avans modification\n");
	printf("a=%d, b=%d\n",a,b);
  	ma_fonction(&a,&b);
  	printf("Après modification\n");
  	printf("a=%d, b=%d\n\n",a,b);
  	
  	
  	
  	// Exercice 17 – (CodeRunner) Compter les valeurs positives, négatives et les zéros:
  	printf("Exercice 17 – (CodeRunner) Compter les valeurs positives, négatives et les zéros:\n");
  	initialisation du générateur de nombres aléatoires
  	srand(time(NULL));
  	printf("Question 1\n");
  	int k;
  	int valeur;
  	
  	int nb_pos = 0;
  	int nb_neg = 0;
  	int nb_zero = 0;
  	
  	for (k=0; k<NB_VALEURS; k++){
  		valeur = valeur_aleatoire(VMIN, VMAX);
  		pos_neg_zero(valeur, &nb_pos, &nb_neg, &nb_zero);
  		printf("%d\n", valeur);
  	}
  	
  	printf("Question 3\n");
  	printf("nb_pos=%d nb_neg=%d nb_zero=%d\n\n\n", nb_pos, nb_neg, nb_zero);
  	
  	
  	
  	//Exercice 18 – (CodeRunner) Tri de trois valeurs:
  	//Question 1:
  	printf("Exercice 18 – (CodeRunner) Tri de trois valeurs:\n");
  	printf("Question 1\n");
  	int x = 1;
  	int y = 2;
  	printf("Avans l'appel: x=%d ; y=%d\n", x, y);
  	echange(&x, &y);
  	printf("Après l'appel: x=%d ; y=%d\n\n", x, y);
  	
  	//Question 2:
  	printf("Question 2\n");
  	int i = 5;
  	int j = 2;
  	printf("Avans l'appel: i=%d ; j=%d\n", i, j);
  	tri(&i, &j);
  	printf("Après l'appel: i=%d ; j=%d\n", i, j);
  	
  	//Question 3:
  	printf("Question 3\n");
  	int e = 3;
  	int f = 5;
  	int g = 2;
  	printf("Avans l'appel: e=%d ; f=%d ; g=%d\n", e, f, g);
  	tri_3(&e, &f, &g);
  	printf("Après l'appel: e=%d ; f=%d ; g=%d\n\n\n", e, f, g);
  	
  	
  	
  	//Exercice 19 – (CodeRunner) Calcul de la moyenne, du minimum et du maximum:
  	//Question 1:
  	printf("Exercice 19 – (CodeRunner) Calcul de la moyenne, du minimum et du maximum:\n");
  	printf("Question 1\n");
  	int max = 8;
  	int min = 5;
  	min_max(VAL1, &min, &max);
  	printf("Pour VAL1=2, on a: max=%d min=%d\n", max, min);
  	min_max(VAL2, &min, &max);
  	printf("Pour VAL2=7, on a: max=%d min=%d\n", max, min);
  	min_max(VAL3, &min, &max);
  	printf("Pour VAL3=5, on a: max=%d min=%d\n", max, min);
  	min_max(VAL4, &min, &max);
  	printf("Pour VAL4=9, on a: max=%d min=%d\n\n", max, min);
  	
  	printf("Question 2\n");
  	int maxi = 0;
  	int mini = 0;
  	float moye = 0.0;
  	stats(2, 7, 5, 9, &mini, &maxi, &moye);
  	printf("v1=2, v2=7, v3=5, v4=9, maximum = %d, minimum = %d, moyenne = %.2f\n", maxi, mini, moye);
  	
  	stats(2, 7, -5, -9, &mini, &maxi, &moye);
  	printf("v1=2, v2=7, v3=-5, v4=-9, maximum = %d, minimum = %d, moyenne = %.1f\n", maxi, mini, moye);  	
  	
  	stats(2, 7, -5, 9, &mini, &maxi, &moye);
  	printf("v1=2, v2=7, v3=-5, v4=9, maximum = %d, minimum = %d, moyenne = %.1f\n", maxi, mini, moye); 
  	
  	stats(2, -7, -5, 9, &mini, &maxi, &moye);
  	printf("v1=2, v2=-7, v3=-5, v4=9, maximum = %d, minimum = %d, moyenne = %.1f\n", maxi, mini, moye);
  	
  	stats(-2, -7, -5, 9, &mini, &maxi, &moye);
  	printf("v1=-2, v2=-7, v3=-5, v4=9, maximum = %d, minimum = %d, moyenne = %.1f\n\n", maxi, mini, moye);
  	
  	printf("Question 3\n");
  	stats(VAL1, VAL2, VAL3, VAL4, &mini, &maxi, &moye);
  	printf("VAL1=2, VAL2=7, VAL3=5, VAL4=9, maximum = %d, minimum = %d, moyenne = %.2f\n\n\n", maxi, mini, moye);
  	
  	
  	
  	printf("Exercice 20 – (CodeRunner) Calcul des Racines d’un polynôme du second degré\n");
  	printf("Question 1\n");
  	printf("Le polynome 4∗x^2 + 4∗x + 1 admet %d racine(s)\n", nb_racines(4,4,1));
  	printf("Le polynome 4∗x^2 + 6∗x + 1 admet %d racine(s)\n", nb_racines(4,6,1));
  	printf("Le polynome -7∗x^2 - 5∗x - 1 admet %d racine(s)\n\n", nb_racines(-7,-5,-1));
  	
  	printf("Question 2\n");
  	int delta;
  	nb_racines_delta(4,4,1,&delta);
  	printf("Le polynome 4∗x^2 + 4∗x + 1 admet %d racine(s) avec delta = %d\n", nb_racines_delta(4,4,1,&delta),delta);
  	
  	nb_racines_delta(4,6,1,&delta);
  	printf("Le polynome 4∗x^2 + 6∗x + 1 admet %d racine(s) avec delta = %d\n", nb_racines_delta(4,6,1,&delta),delta);
  	
  	nb_racines_delta(-7,-5,-1,&delta);
  	printf("Le polynome -7∗x^2 - 5∗x - 1 admet %d racine(s) avec delta = %d\n\n", nb_racines_delta(-7,-5,-1,&delta),delta);
  	
  	printf("Question 2\n");
  	float racine1 = -9.9;
  	float racine2 = -9.9;
  	
  	racines(4,4,1,&delta,&racine1,&racine2);
  	printf("Le polynome 4∗x^2 + 4∗x + 1 admet %d racine(s) avec delta=%d et x1=%.1f x2=%.1f", racines(4,4,1,&delta,&racine1,&racine2), delta, racine1, racine2);
  	return 0;
}
















