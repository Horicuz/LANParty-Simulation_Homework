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

## TASK 3 ~ COMPLETE
-Am adaugat stive.c si cozi.c pentru meciuri si pentru echipele castigatoare/pierzatoare.  
-Am creat o coada pentru meciuri, unde Matchnodurile/elementele au ca si valoare o structura de tip MATCH ce contine team1 si team2 adica 2 noduri din lista initiala. (Se refera la aceleasi noduri nu am luat valoarea acestora si le-am duplicat).  
-Dupa crearea cozii cu ajutorul functiei enQueue, am verificat in cadrul fiecarui meci, nodul castigator si cel pierzator.  
-Nodurile pierzatoarea sunt adaugate (push) intr-o stiva separata de cea de invigatori unde, evident, sunt adaugate in aceeasi maniera nodurile castigatoare
-Dupa terminarea meciurilor dintr-o runda, stiva de pierzatori este golita (DeleteStack).  
-Din stiva invingatorilor dau PopMove pentru toate elemtele sale. Aceasta procedura imi scoate nodul din stiva fara al elibera (free), pentru a-l putea adauga din nou in coada de meciuri impreuna cu adversarul sau (enQueue din nou)
-Efectuez aceste operatii pana la aflarea castigatorului, afisand pe ecran meciurile si castigatorii fiecarei runde.  
-De asemenea cand ultimile 8 echipe sunt aflate, creez o lista noua unde le voi adauga pe acestea pentru taskul 4. Aici eu fac copie la fiecare dintre cele 8 noduri, alocand memorie, pentru ca mai departe in competitie acestea ar fi fost altfel eliberate.  
-Diferite functii  precum printMatch, printWinner, isLetterOrNumber(Task 3), createTeam, etc.. au fost adaugate in fisierul functions.c si apelurile acestora in functions.h, pentru a modulariza programul.  

## TASK 4 ~ INCOMPLETE
