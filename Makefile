all:
	gcc main.c liste.c functions.c cozi.c stive.c -o lanParty 

clean:
	rm -f lanParty