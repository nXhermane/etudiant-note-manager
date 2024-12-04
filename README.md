# **Gestion des Étudiants - C++**

Un projet en C++ développé sous Visual Studio Code  comme exercice pour débutant permettant de gérer des étudiants, leurs notes, et d'effectuer des calculs comme la moyenne ou la note maximale.


## **Notions mises en jeu :**
- Gestion de la mémoire dynamique (`new`, `delete[]`)
- Structures (`struct`)
- Entrées/Sorties avec `std::cin` et `std::cout`
- Boucles (`for`, `while`)
- Pointeurs et manipulation de tableaux
- Calculs mathématiques (moyenne, note maximale)
- Contrôle de flux avec `if`, `switch`, `goto`
- Gestion des erreurs de saisie
- Conventions de codage et bonnes pratiques

## **Fonctionnalités**
- Création d'étudiants avec :
  - Nom.
  - Liste de notes.
- Calcul de la moyenne des notes pour chaque étudiant.
- Détermination de la note maximale d'un étudiant.
- Interface utilisateur via la console avec des commandes interactives.



## **Prérequis**
1. **Environnement de développement** : Visual Studio ou Visual Studio Code.  
2. **Compilateur** : Supportant le standard **C++11** ou supérieur.  
3. **Système d'exploitation** : Windows ou tout OS avec un compilateur C++ compatible.



## **Structure du Projet**
- **`fichierSources/`** : Contient les fichiers sources principaux pour les fonctionnalités du projet.
- **`fichierDeDeclarations/`** : Contient les fichiers d'en-tête.
- **`LICENSE.txt`** : Licence MIT associée au projet.
- **`README.md`** : Documentation du projet.
- **`main.cpp`** : Le point d'entré.


## **Comment Lancer le Projet**
1. **Cloner le dépôt :**
   ```bash
   git clone https://github.com/nXhermane/etudiant-note-manager.git
   cd etudiant-note-manager
   ```

2. **Ouvrir dans Visual Studio Code :**
   - Lancer Visual Studio Code.
   - Ouvrir le dossier du projet.

3. **Compiler et Exécuter :**
   - Ouvrir le terminal intégré dans Visual Studio Code.
   - Lancer la commande suivante :
     ```bash
      g++ -o main mian.cpp fichierSources/*.cpp -I ./fichierDeDeclarations -std=c++11
     ./main
     ```
## **Utilisation**
### **Commandes disponibles :**
- `y` : Calculer la moyenne d'un étudiant.
- `m` : Identifier la note maximale d'un étudiant.
- `q` : Sortir du programme.

## **Licence**
Ce projet est sous licence **MIT**. Consultez le fichier [LICENSE.txt](LICENSE.txt) pour plus de détails.
