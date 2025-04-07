#include <iostream>   // För in och utmatning (cin, cout)
#include <algorithm>  // För algoritmer som sort, find, swap
#include <random>     // För slumptalsgenerering
#include <cstdlib>    // För systemfunktioner (rand, srand)
#include <ctime>      // För tidshantering (time)

using namespace std;

const int SIZE = 4; // För en 4x4 spelplan

void clearScreen() {
    cout << "\033[2J\033[1;1H"; // Rensar skärmen
}

void shuffleNumbers(int numbers[], int size) {
    srand(time(0)); // Initiera slumpgeneratorn med aktuell tid

    // Fyll arrayen med siffror från 1 till size
    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1;
    }

    // Blanda siffrorna
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Random index mellan 0 och i
        swap(numbers[i], numbers[j]); // Byt plats på siffrorna
    }
}


// Funktion för att skriva ut spelbrädet
void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE], char letterMap[SIZE][SIZE]) {
    clearScreen();  // Rensa skärmen
    const string GREEN = "\033[32m";  // Definiera färgen grön för nummer som användare har använt
    const string RESET = "\033[0m";  // Återställ till standardfärg

    cout << "\nSpelbräde:" << endl;  // Skriv ut rubriken för spelbrädet
    for (int i = 0; i < SIZE; i++) {  // Loopa genom rader
        for (int j = 0; j < SIZE; j++) {  // Loopa genom kolumner
            if (revealed[i][j]) {  // Om rutan är avslöjad
                cout << GREEN << board[i][j] << RESET << "\t";  // Skriv ut numret i grönt
            } else {
                cout << letterMap[i][j] << "\t";  // Skriv ut bokstaven om rutan inte är avslöjad
            }
        }
        cout << endl;  // Ny rad efter varje rad på brädet
    }
}


bool checkBingo(bool revealed[SIZE][SIZE]) {
    // Kontrollera varje rad
    for (int i = 0; i < SIZE; i++) {
        // Kontrollera om alla rutor i raden är markerade
        bool rowBingo = true;
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) { // Om en ruta inte är markerad
                rowBingo = false;  // Det finns inget bingo på denna rad
                break;             // Avbryt kontrollen av raden
            }
        }
        if (rowBingo) return true; // Om hela raden är markerad, returnera true (bingo)

        // Kontrollera varje kolumn
        bool colBingo = true;
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[j][i]) { // Om en ruta i kolumnen inte är markerad
                colBingo = false;  // Det finns inget bingo på denna kolumn
                break;
            }
        }
        if (colBingo) return true; // Om hela kolumnen är markerad, returnera true (bingo)
    }

    // Kontrollera diagonaler
    bool diag1 = true; // Första diagonalen (från vänster till höger)
    bool diag2 = true; // Andra diagonalen (från höger till vänster)

    for (int i = 0; i < SIZE; i++) {
        // Kontrollera den första diagonalen: [0][0], [1][1], [2][2], [3][3]
        if (!revealed[i][i]) {
            diag1 = false; // Om en ruta på diagonalen inte är markerad
        }

        // Kontrollera den andra diagonalen: [0][3], [1][2], [2][1], [3][0]
        if (!revealed[i][SIZE - 1 - i]) {
            diag2 = false; // Om en ruta på den andra diagonalen inte är markerad
        }
    }

    // Returnera true om någon av diagonalerna är helt markerad
    return diag1 || diag2;
}

int main() {
    ios::sync_with_stdio(false); //Stänger av koppling mellan cin/cout för att öka hastigheten
    cin.tie(nullptr);  // Kopplar bort cin från cout för att cin och cout ska inte vara tom aoutamtisk

    int board[SIZE][SIZE]; //Spelbrädet, varje ruta har ett numer
    bool revealed[SIZE][SIZE] = {}; //
    char letterMap[SIZE][SIZE]; //Spelets katra, varje ruta har en bokstav
    char letter = 'A'; 
    int numbers[16]; // Lagras alla nummer som sedan ska slumpass
    shuffleNumbers(numbers, 16);

    int index = 0;

    // Loopa genom varje rad och kolumn i spelbrädet
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[index++]; // Tilldela ett slumpat nummer till spelbrädet
            letterMap[i][j] = letter++; // Tilldela en bokstav (A-P) till letterMap
        }
    }

    int chosenNumbers[16]; // En array för att lagra de valda numren (max 16 nummer).
    int numChosen = 0;  // Sparar hur många attemps spelaren har gjort
    const int maxAttempts = 9; // Max antal försök
    bool bingoAchieved = false; // Har fått bingo ?


    cout << "Välkommen till Bingo! Du har " << maxAttempts << " chanser att få en rad, kolumn eller diagonal" << endl;
    cout << endl;
    cout << "Varje gågn ska du välja ett nummer mellan 1 och 16." << endl;
    cout << endl;
    cout << "Tryck På Enter för att börja spela" << endl;
    cin.ignore(); // Vänta tills spelaren trycker på en knapp
    
    for (int attempt = 1; attempt <= maxAttempts; attempt++) {
        printBoard(board, revealed, letterMap);
        int choice;

        while (true) {
            cin >> choice;

            if (cin.fail()) {  // Om misslyckas
                cin.clear(); // Rensa cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Rensa bort all ogiltig inmatning fram till nästa radbrytning
                cout << "❌ Ogiltig inmatning! Skriv ett nummer mellan 1 och 16 ❌" << endl;
                continue; // Går tillbaka till början av loppen
            }

            if (choice < 1 || choice > 16) { // Kollar om nummert är mellan 1 och 16
                cout << "❌ Ogiltigt val! Ange ett nummer mellan 1 och 16 ❌" << endl;
                continue;  // Går tillbaka till början av loppen
            }

            bool alreadyChosen = false; // Sätter att nummert inte har valts så länge
            for (int i = 0; i < numChosen; i++) {
                if (chosenNumbers[i] == choice) { // Omm valet är lika med ett valt nummer
                    alreadyChosen = true; // Ändra till true
                    break;
                }
            }
            
            if (alreadyChosen) { // Skriva till användaren att nummret har redan valts
                cout << "⚠️ Numret " << choice << " har redan använts, välj ett annat nummer ⚠️" << endl;
                continue;  // Går tillbaka till början av loppen
            }
            break;
        }

        chosenNumbers[numChosen++] = choice; // Lagrar vilket nummer spelaren har användt i vilken val. 

        // Loopa varje rad på spelbrädet
        for (int i = 0; i < SIZE; i++) {
            // Loopa genom varje kolumn på spelbrädet
            for (int j = 0; j < SIZE; j++) {
                // Kontrollera om det valda finns i den rutan (board[i][j])
                if (board[i][j] == choice) {
                    // Om numret finns i rutan, markera rutan som vaald
                    revealed[i][j] = true;
                }
            }
        }

        if (checkBingo(revealed)) { // Kollar om spelaren har fått bingo
            printBoard(board, revealed, letterMap);
            cout << "\n🎉 BINGO! Du vann på " << attempt << " försök!" << endl;
            bingoAchieved = true;
            break; // Sluta loppen
        }
    }

    if (!bingoAchieved) { // Om spelaren inte fick bingo
        printBoard(board, revealed, letterMap);
        cout << "\nTyvärr, du fick inte bingo. Försök igen nästa gång!" << endl;
    }
    
    // En Sammanfattning av spelet
    cout << "\nSammanfattning av ditt spel:" << endl;
    cout << "Valda nummer: ";
    for (int i = 0; i < numChosen; i++){
         cout << chosenNumbers[i] << " "; // Skriver ut alla valda nummer
    }
    cout << endl;

    return 0;
}
