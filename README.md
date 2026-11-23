# Calculatrice électrique (C++)

Programme en console écrit en **C++** pour résoudre rapidement des exercices
d'**électricité** vus en cours (Électricité et magnétisme, Électrotechnique
fondamentale) et vérifier mes résultats de TD.

## Fonctionnalités

| Choix | Calcul |
|---|---|
| 1 | Loi d'Ohm : calcul de U, I ou R |
| 2 | Résistance équivalente en **série** |
| 3 | Résistance équivalente en **parallèle** |
| 4 | **Pont diviseur** de tension |
| 5 | **Puissance** électrique P = U × I |
| 6 | Circuit **RC** : constante de temps τ et fréquence de coupure |

Les saisies sont vérifiées : si l'utilisateur tape une lettre au lieu d'un
nombre, le programme redemande la valeur.

## Compiler et lancer

```bash
g++ main.cpp -o calculatrice
./calculatrice
```

(Sous Windows : `g++ main.cpp -o calculatrice.exe` puis `calculatrice.exe`)

## Exemple

```
===== CALCULATRICE ELECTRIQUE =====
...
Votre choix : 3
Nombre de resistances : 2
  R1 (ohms) : 100
  R2 (ohms) : 100
=> Req = 50 ohms
```

## Formules utilisées

- Loi d'Ohm : `U = R × I`
- Série : `Req = R1 + R2 + ... + Rn`
- Parallèle : `1/Req = 1/R1 + 1/R2 + ... + 1/Rn`
- Pont diviseur : `Vs = E × R2 / (R1 + R2)`
- Circuit RC : `τ = R × C` et `fc = 1 / (2πRC)`

## Pistes d'amélioration

- Ajouter les circuits RL et RLC (fréquence de résonance)
- Calcul d'impédance en régime sinusoïdal (nombres complexes)
- Sauvegarder l'historique des calculs dans un fichier

---
Auteur : **Mohamed Islam SAIMI** — Étudiant en Licence 2 Télécommunications
