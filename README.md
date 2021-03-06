# Navy

### Introduction

Le navy est un projet qui consiste à créer un jeu textuel de type bataille naval jouable en multijoueur local via les signaux.



### Signaux

Les signaux sont une fonctionnalité des sytèmes unix. Ils permettent d'échanger des informations entre les différentes applications fonctionnant sur le même système. Voici un petit échantillon des&#x20;

signaux qui existent dans un système unix :

| Id | Nom                                                                | Description                                                                       |
| -- | ------------------------------------------------------------------ | --------------------------------------------------------------------------------- |
| 1  | SIGHUP                                                             | Rupture détectée sur le terminal contrôleur ou mort du processus parent           |
| 2  | [SIGINT](https://fr.wikipedia.org/wiki/SIGINT\_\(POSIX\))          | Interruption du clavier (Ctrl+C dans un terminal)                                 |
| 3  | SIGQUIT                                                            | Arrêt du processus                                                                |
| 4  | SIGILL                                                             | Instruction illégale                                                              |
| 6  | SIGABRT                                                            | Arrêt anormal du processus                                                        |
| 8  | SIGFPE                                                             | Erreur sur un [nombre flottant](https://fr.wikipedia.org/wiki/Virgule\_flottante) |
| 9  | [SIGKILL](https://fr.wikipedia.org/wiki/SIGKILL?tableofcontents=0) | Tue immédiatement le processus                                                    |

Pour faire communiquer des informations de type string entre deux applications, nous avons utilisé les signaux SIGUSER1 et SIGUSER2. Pour chaque caractères dans la string, nous envoyons x fois un signal par exemple pour A on envoie 1 fois un signal, pour B 2 fois un signal, etc. De cette manière en envoyant des milliers de signaux par secondes on a pu faire échanger des strings de manière très rapide entre les deux applications.



### Map

Les dispositions des bateaux sont sauvegardées dans des fichiers texte comme dans l'exemple ci-dessous:

```
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```

Pour chaque lignes il y a 3 informations séparées par des ":". La première information est la taille du bateau, la deuxième la case de début et la dernière la case de fin. L'exemple ci-dessus donne le plateau de jeu suivant:

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



### Connexion

Pour connecter une application à l'autre, il suffit d'entrer son PID.

```
Première instance:

∼/B-PSU-200> ./navy pos1
my_pid: 4242
waiting for enemy connection...
enemy connected
```

```
Deuxième instance:

∼/B-PSU-200> ./navy 4242 pos2
my_pid: 4250
successfully connected
```



### Utilisation

Une fois connecté, il vous suffit d'entrer quelle case attaquer:

```
my positions:
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
enemy’s positions:
|A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .
attack: Z0
wrong position
attack: B6
B6: missed
```
