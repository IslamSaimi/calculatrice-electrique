// Calculatrice électrique en console
// Auteur : Mohamed Islam SAIMI
//
// Petit programme en C++ pour résoudre des exercices classiques
// d'électricité : loi d'Ohm, résistances en série / parallèle,
// pont diviseur de tension, puissance et constante de temps RC.

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double lireNombre(const string& message) {
    double x;
    cout << message;
    while (!(cin >> x)) {
        cout << "  Valeur invalide, recommencez : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}

vector<double> lireResistances() {
    int n = (int)lireNombre("Nombre de resistances : ");
    vector<double> r;
    for (int i = 0; i < n; i++) {
        r.push_back(lireNombre("  R" + to_string(i + 1) + " (ohms) : "));
    }
    return r;
}

double serie(const vector<double>& r) {
    double total = 0;
    for (double v : r) total += v;
    return total;
}

double parallele(const vector<double>& r) {
    double inverse = 0;
    for (double v : r) inverse += 1.0 / v;
    return 1.0 / inverse;
}

void loiOhm() {
    cout << "\nQue voulez-vous calculer ? 1) U  2) I  3) R : ";
    int c = (int)lireNombre("");
    if (c == 1) {
        double r = lireNombre("R (ohms) : "), i = lireNombre("I (A) : ");
        cout << "=> U = R x I = " << r * i << " V\n";
    } else if (c == 2) {
        double u = lireNombre("U (V) : "), r = lireNombre("R (ohms) : ");
        cout << "=> I = U / R = " << u / r << " A\n";
    } else if (c == 3) {
        double u = lireNombre("U (V) : "), i = lireNombre("I (A) : ");
        cout << "=> R = U / I = " << u / i << " ohms\n";
    }
}

void pontDiviseur() {
    double e = lireNombre("Tension d'entree E (V) : ");
    double r1 = lireNombre("R1 (ohms) : ");
    double r2 = lireNombre("R2 (ohms) : ");
    double s = e * r2 / (r1 + r2);
    cout << "=> Tension de sortie aux bornes de R2 : " << s << " V\n";
}

void puissance() {
    double u = lireNombre("U (V) : "), i = lireNombre("I (A) : ");
    cout << "=> P = U x I = " << u * i << " W\n";
}

void circuitRC() {
    double r = lireNombre("R (ohms) : ");
    double c = lireNombre("C (farads, ex : 0.000001 pour 1 uF) : ");
    double tau = r * c;
    cout << "=> Constante de temps tau = R x C = " << tau << " s\n";
    cout << "   Le condensateur est charge a 63 % apres " << tau << " s\n";
    cout << "   et a 99 % apres environ 5 tau = " << 5 * tau << " s\n";
    cout << "   Frequence de coupure fc = 1 / (2 pi R C) = "
         << 1.0 / (2 * M_PI * tau) << " Hz\n";
}

int main() {
    int choix;
    do {
        cout << "\n===== CALCULATRICE ELECTRIQUE =====\n"
             << "1) Loi d'Ohm\n"
             << "2) Resistances en serie\n"
             << "3) Resistances en parallele\n"
             << "4) Pont diviseur de tension\n"
             << "5) Puissance electrique\n"
             << "6) Circuit RC (constante de temps)\n"
             << "0) Quitter\n";
        choix = (int)lireNombre("Votre choix : ");

        switch (choix) {
            case 1: loiOhm(); break;
            case 2: cout << "=> Req = " << serie(lireResistances()) << " ohms\n"; break;
            case 3: cout << "=> Req = " << parallele(lireResistances()) << " ohms\n"; break;
            case 4: pontDiviseur(); break;
            case 5: puissance(); break;
            case 6: circuitRC(); break;
            case 0: cout << "Au revoir !\n"; break;
            default: cout << "Choix inconnu.\n";
        }
    } while (choix != 0);
    return 0;
}
