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


# 🗻 Utmaningar

En utmaning i projektet var att skriva koden så att den var lätt att förstå, men ändå hade all funktion som spelet behöver. 
Det var lite svårt att kontrollera om spelaren vunnit (alltså om en rad, kolumn eller diagonal var markerad), utan att koden blev för lång eller krånglig.
En annan utmaning var att få spelet att visa vilka nummer som redan har valts, och att visa dem i grön färg så att spelaren lätt kan se vad som är markerat.


# 💹 Härnäst
Det finns många sätt att förbättra spelet i framtiden. Ett sätt är att göra en finare version med knappar och färger, alltså ett grafiskt gränssnitt istället för bara text.
Man skulle också kunna lägga till fler spellägen, som större spelplaner (t.ex. 5x5). 
Man kan också lägga till statistik, som att spara hur många försök det tog att vinna, eller att visa rekord.


# ⚡ Hur används programmet
- Kompilera koden med en C++-kompilator.
- Tryck på **Enter** för att starta spelet.
- Ange ett nummer mellan **1 och 16** för att välja en ruta.
- Du har **16 försök** att få en rad, kolumn eller diagonal markerad.
- Om du får Bingo skrivs ett meddelande ut. Om du inte lyckas visas en sammanfattning av dina val.

# 🎬 Exempel
![image](https://github.com/user-attachments/assets/29c65d3d-aea1-427e-b882-917bd6b1bbfd)
