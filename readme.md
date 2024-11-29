# Tic-Tac-Toe

## Descrierea Proiectului
Tic-Tac-Toe este un joc clasic pe tablă de două persoane. Este un joc turn-based unde fiecare jucător plasează X-uri sau O-uri pe tablă 3 pe 3. Scopul jocului constă în formarea a unei linii constante pe orizontală, deiagonală sau verticală cu X sau O. Jucătorul care formează această linie cu simbolul lui, este acel câștigător.

### Regulile jocului
1. Jucătorii aleg semnul X sau O;
2. Fiecare jucător își plasează simbolul pe tablă cu scopul de a obține o linie continuă de trei simboluri (X sau O) pe orizontală, verticală sau diagonală;
3. Jucătorii plasează pe rând simbolurile pe tablă, într-un spațiu liber;
4. Jocul este terminat când un jucător câștigă, când acesta aliniază trei simboluri în lilnie. Dacă tabloul se umple complet fără câștigător, jocul se termină în egalitate.

## Dependențe
- Compilator: GCC 6.3.0
- Biblioteci: <iostream>, <memory>, <vector>
- Sistem: MinGW/Windows

# Cerințe pentru construirea jocului

- MinGW (sau orice alt compilator C++ compatibil)
- Git

## Metoda de construcție

Pentru a construi proiectul, urmați acești pași:

1. Deschideți terminalul 
2. Navigați în directorul proiectului: cd C:\...\Tic-Tac-Toe
3. Rulați comanda pentru a compila proiectul:  mingw32-make
4. Rulați aplicația: TicTacToe.exe
5. Pentru a curăța fișierele obiect și executabilele: mingw32-make clean