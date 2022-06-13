# Navy

### Introduction

Le navy est un projet qui conciste à créer un jeu textuel de type bataille naval jouable en multijoueur local via les signaux.



### Signaux

Les signaux est une fonctionnalité des sytèmes unix. Ils permettent d'échanger des informations entre les différentes applications fonctionnantes sur le même système. Voici un petit échantillon des signaux qui existent dans un système unix:

| Id | Nom                                                                | Description                                                                       |
| -- | ------------------------------------------------------------------ | --------------------------------------------------------------------------------- |
| 1  | SIGHUP                                                             | Rupture détectée sur le terminal contrôleur ou mort du processus parent           |
| 2  | [SIGINT](https://fr.wikipedia.org/wiki/SIGINT\_\(POSIX\))          | Interruption du clavier (Ctrl+C dans un terminal)                                 |
| 3  | SIGQUIT                                                            | Arrêt du processus                                                                |
| 4  | SIGILL                                                             | Instruction illégale                                                              |
| 6  | SIGABRT                                                            | Arrêt anormal du processus                                                        |
| 8  | SIGFPE                                                             | Erreur sur un [nombre flottant](https://fr.wikipedia.org/wiki/Virgule\_flottante) |
| 9  | [SIGKILL](https://fr.wikipedia.org/wiki/SIGKILL?tableofcontents=0) | Tue immédiatement le processus                                                    |

Pour faire communiquer des informations de type string entre deux applications nous avons utilisés  les signaux SIGUSER1 et SIGUSER2. Pour chaques caractères dans la string nous envoyons x fois un signal par exemple pour A on envoie 1 fois un signal, pour B 2 fois un signal etc. De cette manière en envoyant des milliers de signaux par secondes on a pu faire echanger des strings de \
manière très rapide entre les deux applications.

###

### Map

Les dispositions des bateaux sont sauvegardés dans des fichiers texte comme dans l'exemple ci-dessous:

```
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```

Pour chaques lignes il y a 3 informations séparées par des ":". La permière information est la taille du bateau, la deuxième la case de début et la dernière la case de fin. L'exemple ci-dessus donne le plateau de jeu suivant:

```
|A B C D E F G H
-+---------------
1|. . 2 . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 3 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .
```

