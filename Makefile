all:
	gcc -g main.c liste.c functions.c cozi.c stive.c BST.c -o lanParty 

clean:
	rm -f lanParty
