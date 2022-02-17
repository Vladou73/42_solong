Fonctions externes autorisées • open, close, read, write, printf, malloc, free, perror, strerror, exit
• Toutes les fonctions de la MiniLibX



Conseils
minilibix sur mac : 
gcc -I /usr/local/include/mlx.h nom_de_votre_fichier.c -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit


the linker searches and processes libraries and object files in the order they are specified. Thus, ‘foo.o -lz bar.o’ searches library ‘z’ after file foo.o but before bar.o. If bar.o refers to functions in ‘z’, those functions may not be loaded.

https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
https://aurelienbrabant.fr/blog
