# LANParty Simulation in C ~ TEMA 1 PROIECTAREA ALGORITIMILOR

## Setup ~ COMPLETE
Am realizat setup-ul temei:

-Am setat folderul cu fisierele de intrare/iesire  
-Am creat un fisier .c si unul Makefile pentru a verifica functionalitatea checker-ului  

## TASK 1 ~ COMPLETE
-Am efectuat citirea din fisier de intrare (d.in), creand o lista simplu inlantuita cu echipele participante la LanParty.  
-Pentru acest lucru am creat un header cu apelurile functiilor pentru liste, si inca doua headere pentru declararea structurilor pentru echipa (TEAM) si jucatori (PLAYER).  
-Elementele, adica echipele, au fost adaugate la inceputul listei (O(1)), iar acestea reprezinta structuri de date (declarate in team.h) ce contin: Numele echipei, Numarul de jucatori din echipa, si un vector (alocat dinamic) cu acestia.  
-La randul lui, vectorul contine structuri de date cu informatii despre jucatori (player.h) : firstname , secondname si punctaj.  

## TASK 2 ~ COMPLETE
-Am determinat numarul de echipe (putere a lui 2)ce trebuie sa ramana in competitie.  
-Dupa ce am adaugat o noua componenta in structura echipa (teamPoints), am creat o functie pentru determinarea si eliminarea echipei cu cele mai putine puncte din lista.  
-Astfel am eliminat de mai multe ori din lista pana cand am ramas cu numarul de echipe dorit.  

## TASK 3 ~ INCOMPLETE
-Am adaugat stive.c si cozi.c pentru meciuri si pentru echipele castigatoare/pierzatoare
-
