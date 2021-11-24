# SoftMax

Spousta dnešního softwaru využívá nějaké formy strojového učení (anglicky machine learning, chcete-li) pro nejrůznější úlohy. Za strojovým učením se samozřejmě skrývá mnoho algoritmů a matematických postupů a vy teď jeden velmi jednoduchý matematický postup naimplementujete.

Jedním z prvních úkolů pro strojové učení byla detekce ručně psaných číslic, které reprezentovaly PSČ na dopisech, které zpracovávala pošta. V principu se daný problém vyřešil tím, že se programu předkládaly jednotlivé obrázky čísel, které počítač “nějak” zpracoval a také se mu řeklo, jaká je požadována odpověď (jaké číslo obsahuje daný obrázek). Když se tento proces opakuje dostatečně dlouho, a za předpokladu, že algoritmus je schopen se “učit” předložené vzory, vede toto na pěkné řešení daného problému. Výsledkem takového procesu je pak tzv. model, který můžeme použít na rozpoznávání nových, ještě neviděných, čísel.

Příklad takovýchto číslic je uveden na obrázku níže:


Image by Josef Steppan - Own work, CC BY-SA 4.0

Pokud pak chceme takový model použít, programu ukážeme nový obrázek číslice a on nám vrátí vektor čísel, který repzentuje sílu odezvy algoritmu na každé naučené číslo. V praxi tedy pro arabské číslice dostáváme vektor 10 čísel s plovoucí desetinnou čárkou (float). Příklad můžeme vidět níže:

-0.76 -3.74 -1.43 1.82 -4.90 0.13 -6.43 9.11 -0.34 2.33
Odpověď modelu je ta, že index 7 má největší odezvu a pravděpodobně se jedná o číslo 7.

Jak se ale rozhodneme, které číslo je vlastně na výstupu algoritmu? Asi nejjednodušší odpovedí bude, že vybereme to číslo, které ma nejvetší hodnotu a podle indexu ve vektoru snadno určíme, které číslo je na vstupu. Toto je realitivně přímočará úvaha, ale jak můžeme vidět na příkladu, na indexech 4 a 9 áme blízké hodnoty. V praxi se osvědčilo použití funkce softmax před tím než vybereme nejvetší odezvu. Pokud aplikujeme funkci softmax na námi obdržený vektor, tak funkce potlačí nevýznamné prvky a zvýrazní ty významné (velké). Prakticky nám “vytáhne” největší hodnotu.

Výpočet funkce softmax
Máme-li na vstupu vektor z, který má K prvků, tak každý z nich je značen jako zi, kde i nabývá hodnot 0…K − 1. Pak výstupem je opět vektor označený jako σ(z), který je předepsaný následujícím vzorcem:


σ(z)i=ezi∑j=0K−1ezj,proi=0…K−1.

Pro ukázkový vektor výše je výsledná hodnota následující:

0.0001 0.0000 0.0000 0.0007 0.0000 0.0001 0.0000 0.9979 0.0001 0.0011
Vašim úkolem je naimplementovat funkci softmax podle výše uvedeného vzorce, která na vstup dostne pole 10 čísel. Pro jistotu si velikost pole pošleme do funkce také. Funkce vytvoří nové pole o zadané velikosti pomocí dynamicky alokované paměti. Toto pole vrátí přes návratový typ, který bude ukazatel na float.

Předpis funkce je následující:

float * softmax( const float * array, const int len );
Identifikace znaku
Z pole, které nám vráti funkce softmax lze pak snadno určit, která čislice (který index) je indentifikována na vstupním obrázku. Pro náš příklad, je to tedy index 7, poněvadž ten obsahuje nejvyšší hodnotu. Prakticky se jedná o implementaci funkce argmax.

Vašim úkolem je naimplementovat funkci argmax, která vrátí index nevvětšího prvku v poli. Předpis funkce je následující:

int argmax( const float * array, const int len );
Vstup programu
Na stdin dostanete přesměrovaný soubor, který na prvním řádku obsahuje jedno celé číslo, které říká, kolik vektorů chceme následně zpracovávat. Následně je uveden na každém řádku jeden vektor.

Co naprogramovat
Výsledný program bude postupovat následovně:

Načte z stdin číslo, které udává počet vektorů, které se bude následně zpracovávat. Každý vektor má dimenzi 10 (10 prvků ve vektoru). K dispozici je text o vstupu a výstupu. Stačí je pak načítat pomocí funkce scanf. Jednotlivé elementy načítejte pomocí cyklu.
Načtěte každý vektor do dynamicky alokovaného pole.
Toto pole pošlete do funkce softmax.
Výslední pole z funkce softmax pošlete do funkce argmax.
Výsledek funkce argmax zapište na standardní výstup (stdout). Za něj pak zapište výsledek z funkce softmax. Každý výsledek bude na samostatném řádku a jednotlivá čísla budou oddělena mezerou. Desetinná čísla zapište s přesností na 4 desetinná čísla.
Příklad výstupu pro náš demonstrační vstup (plný příklad naleznete v záložce Tests):

7 0.0001 0.0000 0.0000 0.0007 0.0000 0.0001 0.0000 0.9979 0.0001 0.0011
