muz(homer).
muz(abraham).
muz(bart).
muz(herb).
muz(donald).
zena(marge).
zena(mona).
zena(clancy).
zena(jackie).
zena(selma).
zena(lisa).
zena(maggie).
zena(patty).
zena(ling).

rodic(homer, bart).
rodic(homer, lisa).
rodic(homer, maggie).
rodic(marge, lisa).
rodic(marge, bart).
rodic(marge, maggie).
rodic(abraham, herb).
rodic(abraham, homer).
rodic(mona, herb).
rodic(mona, homer).
rodic(clancy, marge).
rodic(clancy, patty).
rodic(clancy. selma).
rodic(jackie, marge).
rodic(jackie, patty).
rodic(jackie, selma).
rodic(jackie, donald).
rodic(selma, ling).

stary_rodic(X, Y):- rodic(X, Z), rodic(Z, Y).
otec(X, Y):- rodic(X, Y), muz(X).
matka(X, Y):- rodic(X, Y), zena(X).
dieta(X, Y):- rodic(Y, X).
syn(X, Y):- dieta(X, Y), muz(X).
dcera(X, Y):- dieta(X, Y), zena(X).
surodenec(X, Y):- dieta(X, Z), dieta(Y, Z). X \= Y.
brat(X, Y):- surodenec(X, Y), muz(X).
sestra(X, Y):- surodenec(X, Y), zena(Y).
stary_otec(X, Y):- stary_rodic(X, Y), muz(X). 
stara_mama(X, Y):- stary_rodic(X, Y), zena(X).
vnuk(X, Y):- stary_rodic(Y, X), muz(X).
vnucka(X, Y):- stary_rodic(Y, X), zena(X).
bratranec(X, Y):- rodic(Y, Z), rodic(X, V), surodenec(Z, V), muz(X).
sesternica(X, Y):- rodic(Y, Z), rodic(X, V), surodenec(Z, V), zena(X).
stryko(X, Y):- brat(X, Z), otec(Z, Y).
ujo(X, Y):- brat(X, Z), matka(Z, Y).
teta(X, Y):- sestra(X, Z), rodic(Z, Y).
manzel(X, Y):- X \= Y, otec(X, Z), matka(Y, Z).
manzelka(X, Y):- X \= Y, matka(X, Z), otec(Y, Z).
stryna(X, Y):- manzelka(X, Z), stryko(Z, Y).
ujcina(X, Y):- manzelka(X, Z), ujo(Z, Y).
svako(X, Y):- manzel(X, Z), teta(Z, Y).

