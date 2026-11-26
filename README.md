# Hra Lodě – Konzolová hra v C++

**Předmět:** BPC-PC1T
**Projekt:** Hra Lodě  
**Autor:** Adéla Svobodová (283557)

---

## 1. Popis projektu

Hra Lodě je konzolová implementace klasické strategické hry pro jednoho nebo dva hráče, vytvořená v programovacím jazyce C++.

Cílem hry je potopit všechny soupeřovy lodě pomocí postupného tipování jejich pozic na hracím poli. Každý hráč disponuje vlastní hrací plochou o velikosti 5 × 5 polí, na kterou rozmístí celkem 5 lodí.

Hra nabízí dva herní režimy – singleplayer proti počítači a multiplayer pro dva hráče na jednom zařízení. Hráči mohou využít automatické nebo ruční rozmístění lodí.

## 2. Použité technologie

- **C++** – hlavní programovací jazyk.
- **time.h** – práce s časem a inicializace generátoru náhodných čísel.
- **windows.h** – využití funkce Sleep() pro časové prodlevy a práce s konzolí.
- **rand()** – generování náhodných pozic pro rozmístění lodí a střelbu počítače.

## 3. Struktura programu

Program je rozdělen do několika funkcí, které zajišťují jednotlivé části herní logiky.

Hlavní části programu zahrnují:

- Inicializaci a správu hracích polí.
- Výpis hracích polí do konzole.
- Ruční a automatické rozmístění lodí.
- Zpracování souřadnic a kontrolu platnosti vstupů.
- Vyhodnocování zásahů a minutí.
- Střelbu hráče a počítače.
- Kontrolu zbývajících lodí a vyhodnocení vítěze.
- Herní smyčky pro jednotlivé herní režimy.

## 4. Reprezentace hrací plochy

Hrací plocha je reprezentována dvourozměrnými poli (maticemi) o velikosti 5 × 5.

Program využívá tři samostatná pole:

- `mojePole` – hrací pole prvního hráče.
- `aiPole` – hrací pole počítače.
- `hrac2Pole` – hrací pole druhého hráče.

Jednotlivé buňky matice mohou obsahovat následující hodnoty:

| Hodnota | Význam |
|---|---|
| `0` | Prázdné pole |
| `1` | Loď |
| `2` | Zásah |
| `3` | Voda (minutí) |

Před zahájením nové hry dochází k vynulování příslušných polí pomocí funkce `vynulujPole()`.

Pro zobrazení hrací plochy jsou využívány funkce `vypisMojePole()` a `vypisAIPoleProHrace()`, které zajišťují rozdílné zobrazení vlastního pole a soupeřova pole.

## 5. Rozmístění lodí

Hráč má možnost zvolit si jeden ze dvou způsobů rozmístění celkem pěti lodí.

**Automatické rozmístění (`automatickeLode`)**

- Náhodný výběr řádku a sloupce pomocí funkce `rand()`.
- Kontrola, zda je vybrané pole volné.
- Opakování výběru, dokud není rozmístěno všech pět lodí.

**Ruční rozmístění (`rucniLode`)**

- Zadávání souřadnic ve formátu například A1, B4 nebo E5.
- Převod písmenné a číselné souřadnice na indexy matice.
- Kontrola platnosti zadaných souřadnic.
- Kontrola, zda na vybrané pozici již není umístěna jiná loď.

Výběr způsobu rozmístění zajišťuje funkce `rozmistilLode()`.

## 6. Střelba a herní logika

Střelba probíhá zadáváním souřadnic cílového pole. Program následně vyhodnocuje výsledek střelby a podle něj upravuje obsah příslušné matice.

Zpracování střelby zajišťuje funkce `strelbaDoPole()`, která kontroluje:

- Platnost zadaných souřadnic.
- Zda na dané pozici již nebylo stříleno.
- Zda se na vybrané pozici nachází loď, nebo voda.
- Zda hráč získává možnost pokračovat v tahu.

Při zásahu je hodnota buňky změněna na `2`, při minutí na `3`. Opakovanou střelbu po zásahu zajišťuje cyklus `do-while`.

**Střelba počítače (`aiStrelba`)**

Počítač vybírá souřadnice náhodně pomocí funkce `rand()`. Před každým výstřelem kontroluje, zda na danou pozici již nebylo stříleno.

Stejně jako hráč může i počítač při zásahu pokračovat v dalším tahu.

## 7. Herní režimy

Program nabízí dva herní režimy.

**Singleplayer – hráč proti počítači**

- Počítač automaticky rozmístí své lodě.
- Hráč si zvolí způsob rozmístění vlastních lodí.
- Hráč a počítač se střídají ve střelbě.
- Hráč vidí vlastní lodě a výsledky střelby na soupeřově poli.
- Počítač využívá náhodný výběr souřadnic pro střelbu.

Herní režim zajišťuje funkce `hraSingle()`.

**Multiplayer – dva hráči**

- Oba hráči si samostatně rozmístí své lodě.
- Hráči se střídají ve střelbě.
- Každý hráč vidí vlastní lodě a pouze zásahy a minutí na soupeřově poli.
- Mezi jednotlivými tahy dochází k vymazání obrazovky, aby zůstaly pozice lodí soupeře skryté.

Herní režim zajišťuje funkce `hraMultiplayer()`.

## 8. Vyhodnocení hry

Po každém tahu program kontroluje počet zbývajících lodí soupeře pomocí funkce `zbyvajiLode()`.

Pokud počet zbývajících lodí dosáhne nuly, hra je ukončena a je vyhlášen vítěz.

V režimu singleplayer může zvítězit hráč nebo počítač. V režimu multiplayer je vítězem ten z hráčů, který jako první potopí všech pět soupeřových lodí.

## 9. Spuštění projektu

Projekt je určen pro prostředí Windows a vyžaduje překladač jazyka C++ podporující knihovnu `windows.h`.

Zdrojový soubor lze přeložit například pomocí překladače MinGW (G++):

```bash
g++ <nazev_souboru>.cpp -o HraLode.exe
```

Po úspěšné kompilaci lze hru spustit příkazem:

```bash
HraLode.exe
```

## 10. Autor

**Adéla Svobodová (283557)**  
VUT v Brně
Předmět BPC-PC1T

---

Projekt byl vytvořen v rámci školní výuky programovacího jazyka C++ a zaměřuje se na praktické využití dvourozměrných polí, funkcí, cyklů, podmínek, práce se vstupy a generování náhodných čísel.
