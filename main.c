/*
 * TEIL 1 - Einführung in C
 *
 * Aufgaben:
 * 1. Wahrheitstabellen
 * 2. Zahlenratespiel
 * 3. Geldautomat-Simulation
 * 4. Größte Zahl bestimmen
 * 5. Schaltjahr-Checker
 * 6. Roboter-Verhaltens-Simulator
 */

#define _CRT_SECURE_NO_WARNINGS  // Unterdrückt bestimmte Visual-Studio-Warnungen.

#include <stdio.h>  // Stellt printf(), scanf() und weitere Ein-/Ausgabefunktionen bereit.

/* Liest eine ganze Zahl ein und gibt sie zurück. */
int read_int(const char* prompt)
{
    int value;

    printf("%s", prompt);  // Gibt die Eingabeaufforderung aus.

    // scanf liest eine ganze Zahl. &value übergibt die Adresse der Variable.
    if (scanf("%d", &value) != 1)
    {
        printf("Ungueltige Eingabe!\n");

        // Ungültige Eingaben aus dem Eingabepuffer entfernen.
        while (getchar() != '\n' && !feof(stdin))
        {
        }

        return 0;
    }

    return value;  // Gibt den eingelesenen Wert zurück.
}

/* Wartet, bis ENTER gedrückt wird. */
void pause_menu(void)
{
    int c;

    printf("\nENTER druecken, um zum Menue zurueckzukehren...");

    // Verbleibende Zeichen bis zum Zeilenende einlesen.
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    getchar();  // Wartet auf ENTER.
}

/* --------------------------------------------------
   AUFGABE 1: WAHRHEITSTABELLEN
   -------------------------------------------------- */

void task1(void)
{
    int a, b;

    printf("\n=== AUFGABE 1: WAHRHEITSTABELLEN ===\n");

    // AND: Beide Werte müssen wahr (1) sein.
    printf("\nAND (A && B)\n");
    printf("A B | Ergebnis\n");

    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            printf("%d %d |    %d\n", a, b, a && b);
        }
    }

    // OR: Mindestens einer der Werte muss wahr sein.
    printf("\nOR (A || B)\n");
    printf("A B | Ergebnis\n");

    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            printf("%d %d |    %d\n", a, b, a || b);
        }
    }

    // XOR: Genau einer der beiden Werte muss wahr sein.
    // ! bedeutet NICHT, && bedeutet UND, || bedeutet ODER.
    printf("\nXOR ((!A && B) || (A && !B))\n");
    printf("A B | Ergebnis\n");

    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            int xor_result = (!a && b) || (a && !b);

            printf("%d %d |    %d\n", a, b, xor_result);
        }
    }

    // NOT kehrt den Wahrheitswert um: 0 wird 1 und 1 wird 0.
    printf("\nNOT (!A)\n");
    printf("A | Ergebnis\n");

    for (a = 0; a <= 1; a++)
    {
        printf("%d |    %d\n", a, !a);
    }
}

/* --------------------------------------------------
   AUFGABE 2: ZAHLENRATESPIEL
   -------------------------------------------------- */

void task2(void)
{
    const int secret = 42;  // const kennzeichnet einen unveränderlichen Wert.
    int guess;

    printf("\n=== AUFGABE 2: ZAHLENRATESPIEL ===\n");
    printf("Errate die geheime Zahl!\n");

    do
    {
        guess = read_int("Dein Tipp: ");

        if (guess < secret)
        {
            printf("Zu klein!\n");
        }
        else if (guess > secret)
        {
            printf("Zu gross!\n");
        }
        else
        {
            printf("Richtig geraten!\n");
        }

    } while (guess != secret);  // Wiederholen, solange die Zahl falsch ist.
}

/* --------------------------------------------------
   AUFGABE 3: GELDAUTOMAT-SIMULATION
   -------------------------------------------------- */

void task3(void)
{
    const double balance = 1000.0;  // Beispiel-Kontostand.
    double amount;

    printf("\n=== AUFGABE 3: GELDAUTOMAT ===\n");
    printf("Kontostand: %.2f EUR\n", balance);

    printf("Abhebungsbetrag eingeben: ");

    // %lf liest eine Zahl vom Typ double ein.
    if (scanf("%lf", &amount) != 1)
    {
        printf("Ungueltige Eingabe!\n");
        return;  // Beendet diese Funktion.
    }

    /*
     * Die Abhebung ist nur erlaubt, wenn alle Bedingungen erfüllt sind:
     * 1. Betrag größer als 0
     * 2. Betrag nicht größer als der Kontostand
     * 3. Betrag höchstens 500 Euro
     */
    if (amount > 0 && amount <= balance && amount <= 500)
    {
        printf("Transaktion genehmigt!\n");
        printf("Neuer Kontostand: %.2f EUR\n", balance - amount);
    }
    else
    {
        printf("Transaktion abgelehnt!\n");

        // Einzelne Gründe für die Ablehnung ausgeben.
        if (amount <= 0)
        {
            printf("- Der Betrag muss positiv sein.\n");
        }

        if (amount > balance)
        {
            printf("- Nicht genuegend Guthaben vorhanden.\n");
        }

        if (amount > 500)
        {
            printf("- Tageslimit von 500 EUR ueberschritten.\n");
        }
    }
}

/* --------------------------------------------------
   AUFGABE 4: GROESSTE ZAHL BESTIMMEN
   -------------------------------------------------- */

void task4(void)
{
    int a, b, c;

    printf("\n=== AUFGABE 4: GROESSTE ZAHL ===\n");

    a = read_int("Erste Zahl: ");
    b = read_int("Zweite Zahl: ");
    c = read_int("Dritte Zahl: ");

    // == vergleicht zwei Werte auf Gleichheit.
    if (a == b && b == c)
    {
        printf("Alle drei Zahlen sind gleich: %d\n", a);
    }
    else if (a >= b && a >= c)
    {
        // a ist größer oder gleich b und c.
        printf("Die groesste Zahl ist %d\n", a);
    }
    else if (b >= a && b >= c)
    {
        printf("Die groesste Zahl ist %d\n", b);
    }
    else
    {
        // Wenn keine vorherige Bedingung stimmt, ist c am größten.
        printf("Die groesste Zahl ist %d\n", c);
    }
}

/* --------------------------------------------------
   AUFGABE 5: SCHALTJAHR-CHECKER
   -------------------------------------------------- */

void task5(void)
{
    int year;

    printf("\n=== AUFGABE 5: SCHALTJAHR ===\n");

    year = read_int("Jahr eingeben: ");

    /*
     * % berechnet den Divisionsrest.
     * Rest 0 bedeutet, dass die Zahl ohne Rest teilbar ist.
     *
     * Schaltjahr:
     * - durch 400 teilbar
     * ODER
     * - durch 4 teilbar, aber nicht durch 100 teilbar.
     */
    if (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0))
    {
        printf("%d ist ein Schaltjahr.\n", year);
    }
    else
    {
        printf("%d ist kein Schaltjahr.\n", year);
    }
}

/* --------------------------------------------------
   AUFGABE 6: ROBOTER-VERHALTENS-SIMULATOR
   -------------------------------------------------- */

void task6(void)
{
    int state;
    int command;

    printf("\n=== AUFGABE 6: ROBOTER-SIMULATOR ===\n");

    printf("\nZustaende:\n");
    printf("1 = Gluecklich\n");
    printf("2 = Traurig\n");
    printf("3 = Muede\n");
    printf("4 = Verwirrt\n");

    printf("\nBefehle:\n");
    printf("1 = Blink\n");
    printf("2 = Spin\n");
    printf("3 = Beep\n");

    state = read_int("\nZustand eingeben: ");
    command = read_int("Befehl eingeben: ");

    // Ungültige Eingaben erkennen.
    if (state < 1 || state > 4 ||
        command < 1 || command > 3)
    {
        printf("Ungueltiger Zustand oder Befehl!\n");
        return;
    }

    /*
     * && bedeutet UND.
     * Beispielsweise muss state == 1 UND command == 1 gelten,
     * damit der erste Fall ausgeführt wird.
     */

    if (state == 1 && command == 1)
    {
        printf("Der glueckliche Roboter blinkt froehlich.\n");
    }
    else if (state == 1 && command == 2)
    {
        printf("Der glueckliche Roboter dreht sich begeistert.\n");
    }
    else if (state == 1 && command == 3)
    {
        printf("Der glueckliche Roboter piept froehlich.\n");
    }
    else if (state == 2 && command == 1)
    {
        printf("Der traurige Roboter blinkt langsam.\n");
    }
    else if (state == 2 && command == 2)
    {
        printf("Der traurige Roboter dreht sich lustlos.\n");
    }
    else if (state == 2 && command == 3)
    {
        printf("Der traurige Roboter piept leise.\n");
    }
    else if (state == 3 && command == 1)
    {
        printf("Der muede Roboter blinkt langsam.\n");
    }
    else if (state == 3 && command == 2)
    {
        printf("Der muede Roboter dreht sich muede.\n");
    }
    else if (state == 3 && command == 3)
    {
        printf("Der muede Roboter piept erschoepft.\n");
    }
    else if (state == 4 && command == 1)
    {
        printf("Der verwirrte Roboter blinkt unregelmaessig.\n");
    }
    else if (state == 4 && command == 2)
    {
        printf("Der verwirrte Roboter dreht sich unsicher.\n");
    }
    else if (state == 4 && command == 3)
    {
        printf("Der verwirrte Roboter piept fragend.\n");
    }
}

/* --------------------------------------------------
   HAUPTMENUE
   -------------------------------------------------- */

int main(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       C-AUFGABEN - TEIL 1\n");
        printf("====================================\n");

        printf("1 - Wahrheitstabellen\n");
        printf("2 - Zahlenratespiel\n");
        printf("3 - Geldautomat-Simulation\n");
        printf("4 - Groesste Zahl bestimmen\n");
        printf("5 - Schaltjahr-Checker\n");
        printf("6 - Roboter-Simulator\n");
        printf("0 - Programm beenden\n");

        choice = read_int("\nAuswahl: ");

        // switch ruft die passende Funktion zur Menüauswahl auf.
        switch (choice)
        {
        case 1:
            task1();
            break;  // Verhindert, dass der nächste case ausgeführt wird.

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        case 4:
            task4();
            break;

        case 5:
            task5();
            break;

        case 6:
            task6();
            break;

        case 0:
            printf("\nProgramm wird beendet.\n");
            break;

        default:
            // default wird bei einer nicht vorhandenen Auswahl ausgeführt.
            printf("\nUngueltige Auswahl! Bitte 0 bis 6 waehlen.\n");
            break;
        }

        // Nach jeder Aufgabe zurück zum Menü; bei 0 direkt beenden.
        if (choice != 0)
        {
            pause_menu();
        }

    } while (choice != 0);  // Menü wiederholen, solange choice nicht 0 ist.

    return 0;  // 0 signalisiert eine erfolgreiche Beendigung.
}