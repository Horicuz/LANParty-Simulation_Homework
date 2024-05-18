# LANParty Simulation in C ~ TEMA 1 PROIECTAREA ALGORITIMILOR

## Setup ~ COMPLETE
Am realizat setup-ul temei:

-Am setat folderul cu fisierele de intrare/iesire
-Am creat un fisier .c si unul Makefile pentru a verifica functionalitatea checker-ului

## TASK 1
-Am efectuat citirea din fisier de intrare (d.in), creand o lista simplu inlantuita cu echipele participante la LanParty.
-Pentru acest lucru am creat un header cu apelurile functiilor pentru liste, si inca doua headere pentru declararea structurilor pentru echipa (TEAM) si jucatori (PLAYER)
-Elementele, adica echipele, au fost adaugate la inceputul listei (O(1)), iar acestea reprezinta structuri de date (declarate in team.h) ce contin: Numele echipei, Numarul de jucatori din echipa, si un vector (alocat dinamic) cu acestia
-La randul lui, vectorul contine structuri de date cu informatii despre jucatori (player.h) : firstname , secondname si punctaj

