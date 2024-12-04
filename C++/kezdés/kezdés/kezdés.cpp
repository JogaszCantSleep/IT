#include <iostream>     //Könyvtár, ami engedi használni az inputot és az outputot!
#include <string>       //Könyvtár, ami engedi, hogy használjuk a stringeket!
#include <cmath>        //Könyvtár, ami engedi, hogy matematikai függvényeket használjunk!

using namespace std;    //Engedi, hogy neveket használjunk objektumokhoz és változókhoz

int main()
{
    cout << "Hello World!\n";  //cout-tal ("see-out"-tal) jelenítünk meg szöveget. <<-el választunk el. \n-nel törünk sort (vagy endl-el)
    cout << "Hello World!" << "\t" << "How you doin\'?\n";     //Vízszintes hely kialakítása \t-vel
    int num = 5;    //Változó (integer)
    cout << "Today\'s winning number is..." << "\t" << num << "!" << endl;
    /*Több soros komment
    Több soros...*/

    /*Változók!!!
    Változó készítése:
    típus + név + egyenlőségjel + érték*/

    int integer = 10 + 26;   //int(eger) típusú változó, egész számok tárolására
    double decimals = -8.56;    //floating típusú változó tört számok tárolására
    char character = 'g';   //char(acter) típusú változó egy karakter tárolására (egy-egy macskaköröm kell hozzá), (számok esetén ASCII-val vált karakterre)
    string text = "What\'s up?";     //string typusú változó szöveg tárolására
    bool state = true;      //bool(ean) typusú változó kettő allapot tárolására: true és false (kiiratásnál true értéke 1, false értéke 0)
    
    int x = 38, y = 4, z = -78;   //Több változó megadása egyszerre, elválasztva vesszővel!
    int k, u, p;    //Egy érték több változóhoz
    k = u = p = 98;

    //Változó nevek nem tartalmazhatnak szünetet, !-et, #-et, %-et, stb...

    const int constant = 23;    //Const(ant) változók meg nem változtatható, állandó értéktartó változók
    const double Pi = 3.14;     //Akkor használjuk, amikor nagy valószínűséggel a változó nem fog változni

    double l;
    cout << "What\'s the value of \"Pi?\"" << "\t";
    cin >> l;   //Cin-nel (see-in)-nel kérünk be adatot a felhasználótól. >>-al választunk el
    cout << "The value of \"Pi\" is..." << "\t" << l << "!\n";

    //Operátorok!!!
    x = 5;
    y = 3;
    cout << (x > y) << "\n";    //1-et ad vissza (true), mert x (5) nagyobb, mint y (3)

    //Logikai operátorok:
    cout << (x > 3 && x < 10) << "\n";      //&&: ÉS (több állítást vizsgál meg egyszerre, és visszaad egy értéket, ha mind igaz (true), vagy mind hamis (false))
    cout << (x > 3 || x < 4) << "\n";       //||: LEGALÁBB EGY (több állítást vizsgál meg, és true-t ad vissza, ha legalább egy állítás igaz)
    cout << (!(x > 3 && x < 10)) << "\n";   //!: LOGIKAI NEM (Egy allítás elé ! tétele megfordítja a kimenetelt (ha az állítás igaz, hamist ad vissza)

    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "The length of the \"txt\" string is: " << txt.length() << "\n";    //A visszaadott eredmény 26, mert a .length() visszaadja a txt változóban tárolt szöveg hosszát

    txt = "Hello";
    cout << txt[0] << "\n";     //A visszaadott érték H lesz, mert a txt változó nulladik ([0]) elemét vesszük, ami a Hello-ból a H

    txt[0] = 'J';
    cout << txt << "\n";    //A visszaadott érték Jello lesz, mert megváltoztattuk a txt tartalmának első karakterét J-re

    cout << "Type your full name: ";
    cin >> txt;
    cout << "Your name is: " << txt << "\n";    //Hiába adtad meg a teljes nevedet (Bíró Benjámin), a cin csak egy szót tud eltárolni, így a végeredmény Bíró lesz
    //Erre használjuk a getline() funkciót
    cout << "Type your full name: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    /*A puffer! (ideiglenes memória)
    Van egy ideiglenes memória, ami adatbekéréskor dolgozik.
    A fenti sorban bekértük a felhasználó nevét, de mivel a cin csak egy szót tud tárolni,
    így a pufferban maradt a szóköz, Benjámin, és az enter által generált \n sortörés.
    Amikor a getline() funckióval akarunk bekérni egy új adatot a felhasználótól, belenéz a pufferba,
    és beolvassa az összes adatot az első /n-ig. Így nem enged minket adatot bekérni, és abban a pillanatban
    visszaadja az ott maradt adatot, tehát a szóközt és a Benjámin-t
    Ehhez kell nekünk a cin.ignore(numeric_limits<streamsize>::max(), '\n'), ami kiűríti a puffer tartalmát*/
    getline(cin, txt);      //Megadjuk a cin-t első paraméterként, és a változót (tárolót) második paraméterként, így olvashatunk be egy egész sort
    cout << "Your name is: " << txt << "\n";

    //Matek
    cout << max(5, 10) << "\n";     //max(): Két vagy több érték közt a legnagyobb
    cout << min(5, 10) << "\n";     //min(): Két vagy több érték közt a legnkisebbet
    cout << sqrt(64) << "\n";       //sqrt(): Egy érték gyöke
    cout << round(2.6) << "\n";     //round(): Kerekítés tört számról
    cout << log(2) << "\n";         //log(): Egy érték természetes logaritmusa

    x = 37;
    y = 18;

    if (x >= y) {
        cout << "Old enough to vote!" << "\n";
    } else {
        cout << "Not old enough to vote!" << "\n";
    }

    //Ternary Operator (short hand if...else)
    //variable = (condition) ? expressionTrue : expressionFalse;

    x = 20;
    string result = (x < 18) ? "Good day." : "Good evening.";
    cout << result << "\n";

    //Switch
    //Több lehetőség közül választ egyet értéknek megfelelően

    x = 6;
    switch (x) {
    case 1:
        cout << "Monday";
        break;                  //Megtöri a blokkot, ha talál egy egyező állítást
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:                    //Ha nincs egyezés, akkor a default segítségével adhatunk meg egy kódot, ami lefut
        cout << "Looking forward to the Weekend";
    }                           //Visszaadja a case 6-et "Saturday", mert "x" értéke 6, így a 6-os lehetőséget adja vissza

    x = 10;
    y = 20;

    do {
        cout << "It runs at least once" << "\n";
        x++;
    } while (y > x);        //A do/while ciklus lefut legalább egyszer, utána pedig csak akkor többször, ha a feltétel igaz

    int myNums[5] = { 10, 20, 30, 40, 50 };
    for (int i : myNums) {      //For-each ciklus, amit arra találtak ki, hogy átmenjenek egy array-en
        cout << i << "\n";
    }
    
    cout << sizeof(myNums) << "\n";     //A sizeof() visszaadja az elemek mennyiségének értékét egy array-ben
    /*DE!!!
    Itt a sizeof() 20-at ad vissza 5 helyett
    Azért, mert egy int(eger) általában 4 byte, és mivel 5 elem található az array-ben,
    5*4=20
    Ezért kell elosztanunk az array hosszát az adattípus mennyiségével*/
    cout << (sizeof(myNums) /*array hossza*/ / sizeof(int)) /*int hossza*/ << "\n";

    //Struktúra:

    struct car {    //Struktúrákat használhatunk változók szeparálására
        int year;
        string brand;
        string model;
    };  //Két féle kéépen adhatunk meg neki változókat. Vagy ide a végére (} myCar1;), vagy később:

    car myCar1;     //Itt. Hozzárendeljük a "car" struktúrához a myCar1 változót, majd később paraméterekt csatolunk hozzájuk.
    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;

    //Enumeráció:

    enum Level {    //Szinteket adhatunk meg neki, majd későb dolgozhatunk vele
        LOW = 25,
        MEDIUM = 50,
        HIGH = 75
    };

    enum Level myVar = MEDIUM;
    cout << myVar;  //A visszaadott érték 50 lesz

    return 0;   //Befejezzük a funkciót
}
