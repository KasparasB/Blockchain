# KappaCoin Blockchain
***

## Paleidimas

``` g++ -o test Source.cpp Functions.cpp hash.cpp Header.cpp ```

## Veikimo principas

1. Sukuriamas blockchain'as su Genesis Block'u.
2. Sukuriamas tam tikras skaičius (1000) vartotojų.
3. Sukuriamas tam tikras skaičius operacijų (1000), kurios vyksta tarp vartotojų.
4. Kasami blokai tol, kol yra validus transakcijų kiekis.

Pastebėjimai:
⋅⋅1. Vieną bloką sudaro 100 transakcijų, todėl transakcijų kiekis privalo būti dalus iš 100 be liekanos.
⋅⋅2. Naudojamas SHA256 algoritmas, nes savo hash'inimo algoritmo nepritaikiau šiai užduočiai (yra ateities planuose :D).

## Klasės

**Block**

Bloko klasė. Nariai - indeksas, nonce'as, duomenys iš 100 transakcijų, hash'as, laiko žymė.

Funkcija Calculatehash() sujungia visus duomenis į vieną string'ą ir sukuria blokui hash'ą, kuris atitiktų Difficulty reikalavimus.
Turi tris public funkcijas. Viena grąžina esamą hashą, kita buvusį, o trečia mine'ina blocką.

**Blockchain**

Blockchain'o klasė. Nariai - Difficulty, klasės Block vektorius.

Funkcija GetLastBlock() grąžina paskutinį bloko narį. AddBlock() sukuria nauja bloką.

**User**

Vartotojo klasė. Nariai - vardas, public_key (suhashintas vardas), kappaCoin'ų skaičius.

Funkcijomis galima keisti vartotojo vardą, key, balansą, gauti vardą, key, balansą, pridėti ir atimti coin'ų.

**Transaction**

Transakcijos klasė. Nariai - ID, siuntėjo, gavėjo raktai, suma.




