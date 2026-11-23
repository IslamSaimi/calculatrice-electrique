/*
 * Calculatrice électrique en console
 * Auteur : Mohamed Islam SAIMI
 *
 * Petit programme en C pour résoudre des exercices classiques
 * d'électricité : loi d'Ohm, résistances en série / parallèle,
 * pont diviseur de tension, puissance et constante de temps RC.
 */

#include <stdio.h>

#define PI 3.14159265358979
#define MAX_RESISTANCES 20

/* Lit un nombre réel ; redemande tant que la saisie est invalide */
double lireNombre(const char *message)
{
    double x;
    printf("%s", message);
    while (scanf("%lf", &x) != 1) {
        printf("  Valeur invalide, recommencez : ");
        while (getchar() != '\n');   /* vide le buffer clavier */
    }
    return x;
}

/* Lit n résistances dans le tableau r et renvoie n */
int lireResistances(double r[])
{
    int n, i;
    do {
        n = (int)lireNombre("Nombre de resistances (1 a 20) : ");
    } while (n < 1 || n > MAX_RESISTANCES);

    for (i = 0; i < n; i++) {
        printf("  R%d (ohms) : ", i + 1);
        r[i] = lireNombre("");
    }
    return n;
}

double serie(double r[], int n)
{
    double total = 0;
    int i;
    for (i = 0; i < n; i++)
        total += r[i];
    return total;
}

double parallele(double r[], int n)
{
    double inverse = 0;
    int i;
    for (i = 0; i < n; i++)
        inverse += 1.0 / r[i];
    return 1.0 / inverse;
}

void loiOhm(void)
{
    int c = (int)lireNombre("\nQue voulez-vous calculer ? 1) U  2) I  3) R : ");
    double u, i, r;

    if (c == 1) {
        r = lireNombre("R (ohms) : ");
        i = lireNombre("I (A) : ");
        printf("=> U = R x I = %.3f V\n", r * i);
    } else if (c == 2) {
        u = lireNombre("U (V) : ");
        r = lireNombre("R (ohms) : ");
        printf("=> I = U / R = %.3f A\n", u / r);
    } else if (c == 3) {
        u = lireNombre("U (V) : ");
        i = lireNombre("I (A) : ");
        printf("=> R = U / I = %.3f ohms\n", u / i);
    } else {
        printf("Choix inconnu.\n");
    }
}

void pontDiviseur(void)
{
    double e  = lireNombre("Tension d'entree E (V) : ");
    double r1 = lireNombre("R1 (ohms) : ");
    double r2 = lireNombre("R2 (ohms) : ");
    printf("=> Tension de sortie aux bornes de R2 : %.3f V\n", e * r2 / (r1 + r2));
}

void puissance(void)
{
    double u = lireNombre("U (V) : ");
    double i = lireNombre("I (A) : ");
    printf("=> P = U x I = %.3f W\n", u * i);
}

void circuitRC(void)
{
    double r = lireNombre("R (ohms) : ");
    double c = lireNombre("C (farads, ex : 0.000001 pour 1 uF) : ");
    double tau = r * c;

    printf("=> Constante de temps tau = R x C = %g s\n", tau);
    printf("   Le condensateur est charge a 63 %% apres %g s\n", tau);
    printf("   et a 99 %% apres environ 5 tau = %g s\n", 5 * tau);
    printf("   Frequence de coupure fc = 1 / (2 pi R C) = %.2f Hz\n", 1.0 / (2 * PI * tau));
}

int main(void)
{
    int choix, n;
    double r[MAX_RESISTANCES];

    do {
        printf("\n===== CALCULATRICE ELECTRIQUE =====\n");
        printf("1) Loi d'Ohm\n");
        printf("2) Resistances en serie\n");
        printf("3) Resistances en parallele\n");
        printf("4) Pont diviseur de tension\n");
        printf("5) Puissance electrique\n");
        printf("6) Circuit RC (constante de temps)\n");
        printf("0) Quitter\n");
        choix = (int)lireNombre("Votre choix : ");

        switch (choix) {
            case 1: loiOhm(); break;
            case 2:
                n = lireResistances(r);
                printf("=> Req = %.3f ohms\n", serie(r, n));
                break;
            case 3:
                n = lireResistances(r);
                printf("=> Req = %.3f ohms\n", parallele(r, n));
                break;
            case 4: pontDiviseur(); break;
            case 5: puissance(); break;
            case 6: circuitRC(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix inconnu.\n");
        }
    } while (choix != 0);

    return 0;
}
