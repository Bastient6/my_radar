from random import randint
import sys

try:
    nb_a = int(sys.argv[1])
    nb_b = int(sys.argv[2])
except ValueError:
    print("Wrong argument: insert a integer")
    exit(84)
except IndexError:
    print("to few or much argument")
    
try:
    fichier = open("data_plane.txt", "w")
except:
    print("Vérifier bien d'avoir un fichier nommé 'data_plane.txt' créer et vide")
    exit(84)

for i in range(nb_a):
    fichier.write(f"A {randint(0, 1920)} {randint(0, 1080)} {randint(0, 1920)} {randint(0, 1080)} {randint(50, 100)} 0\n")
for i in range(nb_b):
    fichier.write(f"T {randint(100, 1820)} {randint(50, 980)} {randint(50, 300)}\n")
fichier.close()

print("Le fichier a été correctement créé !")