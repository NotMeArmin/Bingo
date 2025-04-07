# 🎲 Konsolbaserat Bingo spel (C++)

# 📜 Sammanfattning
Välkommen till ett enkelt men roligt konsolbaserat Bingo-spel! 
Spelet är byggt i C++ och går ut på att spelaren har 16 försök på sig att hitta en rad, kolumn eller diagonal med rätt siffror för att uppnå BINGO.


# 📁 Bakgrund
Målet med projektet var att skapa ett interaktivt spel som tränar både logik och programmeringsförmåga. Bingo är ett välkänt spel som är enkelt att förstå men ändå roligt att spela. Min motivation var att bygga något som är användarvänligt, samtidigt som det innehåller grundläggande element från programmering, som loops och arrays.


# 🕹️ Spelbeskrivning
- Spelbrädet är en 4x4 matris fylld med slumpade siffror från 1 till 16.
- Varje ruta representeras av en unik bokstav från A till P.
- Spelaren gissar ett nummer i taget.
- Om numret finns på brädet avslöjas det.
- Spelet avslutas när spelaren får en rad, kolumn eller diagonal, eller när alla 16 chanser är förbrukade.


# 🧠 Nyckelaspekter
| **Funktion**        | **Beskrivning**                                                  |
|---------------------|------------------------------------------------------------------|
| `shuffleNumbers()`  | Slumpar talen från 1 till 16                                     |
| `printBoard()`      | Skriver ut spelbrädet, visar gissade nummer i grönt             |
| `checkBingo()`      | Kollar om en rad, kolumn eller diagonal är full                 |
| `main()`            | Huvudlogik för spelgången, hanterar inmatning och spelstatus    |


# ⚡ Hur används programmet
- Kompilera koden med en C++-kompilator.
- Tryck på **Enter** för att starta spelet.
- Ange ett nummer mellan **1 och 16** för att välja en ruta.
- Du har **16 försök** att få en rad, kolumn eller diagonal markerad.
- Om du får Bingo skrivs ett meddelande ut. Om du inte lyckas visas en sammanfattning av dina val.

# 🎬 Exempel
![image](https://github.com/user-attachments/assets/29c65d3d-aea1-427e-b882-917bd6b1bbfd)
