#include "game.h"

Game::Game()
{
    Logger::out("Function start", "Game::Game");
    menu = 0;
    choice = 0;
    gameLang = 0;
    playing = true;
    ptrCurrentLocation = nullptr;
}

Game::~Game()
{   
    Logger::out("Function start", "Game::~Game");
}

void Game::run()
{
    Function::nameGame("CYBERPUNK Text Game v.1.0");
    Function::initSpecialChars("polish");

    while (getPlaying())
    {
        Logger::out("Function start", "Game::run");
        selectLanguage();
        welcome();
        writeLogo();
        mainMenu();
        end();
        Logger::out("Function end", "Game::run");
    }
}

void Game::selectLanguage()
{
    Logger::out("Function start", "Game::selectLanguage");

    while (gameLang != en && gameLang != pl)
    {
        Function::clearScreen();
        std::cout << std::endl;
        Function::write("\tSelect your language: ", 25);
        std::cout << std::endl;
        Function::write("\t[1] EN", 25);
        std::cout << std::endl;
        Function::write("\t[2] PL", 25);
        std::cout << std::endl;
        Function::write("\t> ", 25);
        std::cin >> gameLang;

        if (gameLang != en && gameLang != pl) Logger::error("Invalid value of 'gameLang'", "Game::selectLanguage");
    }

    if (getLang() == en) Logger::out("Game language is English", "Game::selectLanguage");
    else if (getLang() == pl) Logger::out("Game language is Polish", "Game::selectLanguage");

    Function::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function start", "Game::welcome");
    std::cout << std::endl;
    Sleep(500); 

    if (getLang() == pl) Function::write("\tRADOS�AW 'DOIC' MICHALAK PREZENTUJE GR� TEKSTOW� POD TYTU�EM", 40);
    else Function::write("\tRADOS�AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Function::clearScreen();
}

void Game::writeLogo()
{
    Logger::out("Function start", "Game::writeLogo");
    Function::changeConsoleColor(yellow);
    std::cout << "" << std::endl;
    Function::write("\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==", 1);
    std::cout << std::endl;
    Function::write("\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   == ", 1);
    std::cout << std::endl;
    Function::write("\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==  ", 1);
    std::cout << std::endl;
    Function::write("\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====   ", 1);
    std::cout << std::endl;
    Function::write("\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==  ", 1);
    std::cout << std::endl;
    Function::write("\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   == ", 1);
    std::cout << std::endl;
    Function::write("\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==", 1);
    std::cout << std::endl;
    std::cout << "" << std::endl;
    Function::changeConsoleColor();
    Function::write("\t\t\t\t\t\t\t\t\tDemo Build", 2);
    std::cout << std::endl;
    std::cout << "" << std::endl;
}

void Game::logo()
{
    Logger::out("Function start", "Game::logo");
    Function::changeConsoleColor(yellow);
    std::cout << "" << std::endl;
    std::cout << "\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==" << std::endl;
    std::cout << "\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   == " << std::endl;
    std::cout << "\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==  " << std::endl;
    std::cout << "\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====   " << std::endl;
    std::cout << "\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==  " << std::endl;
    std::cout << "\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   == " << std::endl;
    std::cout << "\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==" << std::endl;
    std::cout << "" << std::endl;
    Function::changeConsoleColor();
    std::cout << "\t\t\t\t\t\t\t\t\tDemo Build" << std::endl;
    std::cout << "" << std::endl;
    mainMenu();
}

void Game::mainMenu()
{
    Logger::out("Function start", "Game::mainMenu");
    Function::changeConsoleColor();
    std::cout << "" << std::endl;

    if (getLang() == pl)
    {
        Function::write("\t[1] Nowa gra", 25);
        std::cout << std::endl;
        Function::write("\t[2] Kontynuuj gr�", 25);
        std::cout << std::endl;
        Function::write("\t[3] Zmie� j�zyk", 25);
        std::cout << std::endl;
        Function::write("\t[4] Napisy", 25);
        std::cout << std::endl;
        Function::write("\t[5] Wyjd� z gry", 25);
        std::cout << std::endl;
        Function::write("\t> ", 25);
    }
    else
    {
        Function::write("\t[1] New game", 25);
        std::cout << std::endl;
        Function::write("\t[2] Continue game", 25);
        std::cout << std::endl;
        Function::write("\t[3] Change language", 25);
        std::cout << std::endl;
        Function::write("\t[4] Credits", 25);
        std::cout << std::endl;
        Function::write("\t[5] Quit game", 25);
        std::cout << std::endl;
        Function::write("\t> ", 25);
    }

    do
    {
        std::cin >> menu;
        switch (menu) {
        case 1:
            newGame();
            break;
        case 2:
            continueGame();
            break;
        case 3:
            changeLanguage();
            break;
        case 4:
            credits();
            break;
        case 5:
            endGame();
            break;
        }
    } while (menu > 5 || menu <= 0);
}

void Game::newGame()
{
    Logger::out("Function start", "Game::newGame");
    Event::initAll();
    Function::clearScreen();
    //setCurrentLocation(DarkAlley);
    Event::darkAlley();
}

void Game::continueGame()
{
    Logger::out("Function start", "Game::continueGame");
    Sleep(500);
    Function::clearScreen();
    std::cout << std::endl;
    Function::changeConsoleColor(lightblue);

    if (getLang() == pl) Function::write("\tNic tu nie ma. Ta funkcja jest obecnie niedost�pna.\n\n", 25);
    else Function::write("\tThere's nothing here. This feature is currently unavailable.\n\n", 25);

    Function::changeConsoleColor();
    Sleep(1000);
    Function::pauseGame();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::changeLanguage()
{
    Logger::out("Function start", "Game::changeLanguage");

    int change = 0;

    while (change != en && change != pl)
    {
        Function::clearScreen();
        std::cout << std::endl;

        if (getLang() == en) Function::write("\tSelect your language: ", 25);
        else if (getLang() == pl) Function::write("\tWybierz sw�j j�zyk: ", 25);

        std::cout << std::endl;
        Function::write("\t[1] EN", 25);
        std::cout << std::endl;
        Function::write("\t[2] PL", 25);
        std::cout << std::endl;
        Function::write("\t> ", 25);
        
        std::cin >> change;

        if (change != en && change != pl) Logger::error("Invalid value of 'gameLang'", "Game::changeLanguage");
    }

    gameLang = change;

    if (getLang() == en) Logger::out("Game language is English", "Game::changeLanguage");
    else if (getLang() == pl) Logger::out("Game language is Polish", "Game::changeLanguage");

    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::endGame()
{
    Logger::out("Function start", "Game::endGame");

    do
    {
        if (getLang() == pl)
        {
            Sleep(500);
            Function::clearScreen();
            std::cout << std::endl;
            Function::write("\tJeste� pewien, �e chcesz wyj�� z gry?", 25);
            std::cout << std::endl;
            Function::write("\t[1] Tak", 25);
            std::cout << std::endl;
            Function::write("\t[2] Nie", 25);
            std::cout << std::endl;
            Function::write("\t> ", 25);
        }
        else
        {
            Sleep(500);
            Function::clearScreen();
            std::cout << std::endl;
            Function::write("\tAre you sure you want to end the game?", 25);
            std::cout << std::endl;
            Function::write("\t[1] Yes", 25);
            std::cout << std::endl;
            Function::write("\t[2] No", 25);
            std::cout << std::endl;
            Function::write("\t> ", 25);
        }

        std::cin >> choice;

        switch (choice) {
        case 1:
            end();
            break;
        case 2:
            Function::clearScreen();
            Sleep(500); 
            logo();
            mainMenu();
            break;
        }
    } while (choice != 1 && choice != 2);
}

void Game::credits()
{
    Logger::out("Function start", "Game::credits");
    Sleep(500);
    Function::clearScreen();
    std::cout << std::endl;

    if (getLang() == pl)
    {
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tAUTOR\n");
        Function::changeConsoleColor();
        Function::write("\tRados�aw 'Doic' Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t       TESTERZY\n");
        Function::changeConsoleColor();
        Function::write("\t    Pawe� Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t     PODZI�KOWANIA\n");
        Function::changeConsoleColor();
        Function::write("\t   Dominik Szpilski\n\t     Daniel Ob��k\n\n");
    }
    else
    {
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tAUTHOR\n");
        Function::changeConsoleColor();
        Function::write("\tRados�aw 'Doic' Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tTESTERS\n");
        Function::changeConsoleColor();
        Function::write("\t   Pawe� Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tTHANKS\n");
        Function::changeConsoleColor();
        Function::write("\t   Dominik Szpilski\n\t     Daniel Ob��k\n\n");
    }

    Sleep(1000);
    Function::pauseGame();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::test()
{
    Logger::out("Function start", "Game::test");
}