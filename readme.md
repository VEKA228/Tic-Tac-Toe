# Tic-Tac-Toe

## Descrierea Proiectului
Tic-Tac-Toe este un joc clasic pe tablă de două persoane. Este un joc turn-based unde fiecare jucător plasează X-uri sau O-uri pe tablă 3 pe 3. Scopul jocului constă în formarea a unei linii constante pe orizontală, deiagonală sau verticală cu X sau O. Jucătorul care formează această linie cu simbolul lui, este acel câștigător.

### Regulile jocului
1. Jucătorii aleg semnul X sau O;
2. Fiecare jucător își plasează simbolul pe tablă cu scopul de a obține o linie continuă de trei simboluri (X sau O) pe orizontală, verticală sau diagonală;
3. Jucătorii plasează pe rând simbolurile pe tablă, într-un spațiu liber;
4. Jocul este terminat când un jucător câștigă, când acesta aliniază trei simboluri în lilnie. Dacă tabloul se umple complet fără câștigător, jocul se termină în egalitate.

#### Tipuri de date declarate
1. enum class Player  - reprezintă jucătorii în joc. Poate fi fie Player::X sau Player::O;
2. class Baord - reprezintă tabla de joc care conține un tablou de caractere 3x3 care indică starea fiecărei celule: X, O sau gol;
3. class Game - reprezintă logica jocului Tic-Tac-Toe. Gestionează mutările jucătorilor, verifică câte linii de câte simboluri sunt completate și determină câștigătorul sau dacă jocul a fost terminat la egalitate.