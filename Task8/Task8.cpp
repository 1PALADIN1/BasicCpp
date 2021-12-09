
// Запрограммировать игру крестики нолики(человек против компьютера) на поле 3х3.
// Для джуниоров : не обязательно делать крутой искусственный интеллект в игре.
// Но у вас должны корректно работать все основные моменты в игре, как например и главный цикл игры в main.
// Челендж для опытных и продвинутых : сделать решение на поле 4х4 или 5х5 или на динамическом поле, размер которого ввел пользователь.
// Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3 - 5.

#include <iostream>

// ------------------------------------------ основные типы ------------------------------------------

enum class Cell : char
{
    CROSS = 'X',
    ZERO = '0',
    EMPTY = '_'
};

enum class GameState
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

struct Coord
{
    size_t y;
    size_t x;
};

#pragma pack(push, 1)
struct Game
{
    Cell** ppField = nullptr;
    const size_t SIZE{ 3 };
    GameState gameState = GameState::IN_PROGRESS;
    Cell human = Cell::EMPTY;
    Cell ai = Cell::EMPTY;
    size_t turn{ 0 }; // четные - ходит человек, нечётные - ПК
};
#pragma pack(pop)

// ------------------------------------------

// ------------------------------------------ описание функций ------------------------------------------

void clearScreen();
bool isFirstTurnPlayer();

void initGame(Game& game);
void deinitGame(Game& game);
void renderGame(const Game& game);
void congrats(const Game& game);
GameState updateGameState(const Game& game);
Coord getHumanCoord(const Game& game);
Coord getAiCoord(Game& game);

// ------------------------------------------

int main()
{
    Game* game = new (std::nothrow) Game();

    if (game == nullptr)
    {
        std::cout << "Error! Not enough memory for a game :(" << std::endl;
        return -1;
    }

    initGame(*game);
    
    clearScreen();
    renderGame(*game);

    //main cycle
    do
    {
        if (game->turn % 2 == 0)
        {
            //human turn
            Coord c = getHumanCoord(*game);
            game->ppField[c.y][c.x] = game->human;
        }
        else
        {
            //ai turn
            Coord c = getAiCoord(*game);
            game->ppField[c.y][c.x] = game->ai;
        }

        game->turn++;
        game->gameState = updateGameState(*game);

        clearScreen();
        renderGame(*game);

    } while (game->gameState == GameState::IN_PROGRESS);

    congrats(*game);

    deinitGame(*game);

    delete game;
    game = nullptr;

    return 0;
}


// ------------------------------------------ игровые функции ------------------------------------------

void clearScreen()
{
    std::system("cls");
}

bool isFirstTurnPlayer()
{
    srand(time(0));
    int randNum = rand() % 100;
    return randNum < 50;
}

void initGame(Game& game)
{
    game.ppField = new Cell* [game.SIZE];
    for (size_t i = 0; i < game.SIZE; i++)
    {
        game.ppField[i] = new Cell[game.SIZE];
    }

    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            game.ppField[y][x] = Cell::EMPTY;
        }
    }

    if (isFirstTurnPlayer())
    {
        game.human = Cell::CROSS;
        game.ai = Cell::ZERO;
        game.turn = 0;
        return;
    }

    game.human = Cell::ZERO;
    game.ai = Cell::CROSS;
    game.turn = 1;
}

void deinitGame(Game& game)
{
    for (size_t i = 0; i < game.SIZE; i++)
    {
        delete[] game.ppField[i];
    }

    delete[] game.ppField;
}

void renderGame(const Game& game)
{
    std::cout << "     ";
    for (size_t x = 0; x < game.SIZE; x++)
    {
        std::cout << x + 1 << "   ";
    }
    std::cout << std::endl;

    for (size_t y = 0; y < game.SIZE; y++)
    {
        std::cout << y + 1 << " | ";
        for (size_t x = 0; x < game.SIZE; x++)
        {
            std::cout << (char)game.ppField[y][x] << " | ";
        }

        std::cout << std::endl;
    }

    std::cout << "Human: " << (char)game.human << std::endl;
    std::cout << "AI: " << (char)game.ai << std::endl;
}

void congrats(const Game& game)
{
    if (game.gameState == GameState::WON_HUMAN)
    {
        std::cout << "Human won! :) " << std::endl;
        return;
    }

    if (game.gameState == GameState::WON_AI)
    {
        std::cout << "AI won! :( " << std::endl;
        return;
    }

    std::cout << "DRAW :/ " << std::endl;
}

GameState updateGameState(const Game& game)
{
    //победа в строках
    for (size_t y = 0; y < game.SIZE; y++)
    {
        if (game.ppField[y][0] == game.ppField[y][1] && game.ppField[y][0] == game.ppField[y][2])
        {
            if (game.ppField[y][0] == game.human)
                return GameState::WON_HUMAN;
            if (game.ppField[y][0] == game.ai)
                return GameState::WON_AI;
        }
    }

    //победа в столбцах
    for (size_t x = 0; x < game.SIZE; x++)
    {
        if (game.ppField[0][x] == game.ppField[1][x] && game.ppField[0][x] == game.ppField[2][x])
        {
            if (game.ppField[0][x] == game.human)
                return GameState::WON_HUMAN;
            if (game.ppField[0][x] == game.ai)
                return GameState::WON_AI;
        }
    }

    //победа в диагоналях
    if (game.ppField[0][0] == game.ppField[1][1] && game.ppField[0][0] == game.ppField[2][2])
    {
        if (game.ppField[1][1] == game.human)
            return GameState::WON_HUMAN;
        if (game.ppField[1][1] == game.ai)
            return GameState::WON_AI;
    }

    if (game.ppField[2][0] == game.ppField[1][1] && game.ppField[0][2] == game.ppField[1][1])
    {
        if (game.ppField[1][1] == game.human)
            return GameState::WON_HUMAN;
        if (game.ppField[1][1] == game.ai)
            return GameState::WON_AI;
    }

    //проверка на свободные клетки
    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            if (game.ppField[y][x] == Cell::EMPTY)
                return GameState::IN_PROGRESS;
        }
    }

    //ничья
    return GameState::DRAW;
}

Coord getHumanCoord(const Game& game)
{
    Coord c;

    std::cout << "================ USER TURN ================" << std::endl;
    do
    {
        std::cout << "Enter X(1.." << game.SIZE << "): ";
        std::cin >> c.x;
        std::cout << "Enter Y(1.." << game.SIZE << "): ";
        std::cin >> c.y;

        c.x--;
        c.y--;

        if (c.x > game.SIZE - 1)
            std::cout << "X is invalid!" << std::endl;

        if (c.y > game.SIZE - 1)
            std::cout << "Y is invalid!" << std::endl;

        if (c.x < game.SIZE && c.y < game.SIZE && game.ppField[c.y][c.x] != Cell::EMPTY)
            std::cout << "Cell: [" << c.x + 1 << ", " << c.y + 1 << "] is already set!" << std::endl;

    } while (c.x > game.SIZE - 1 || c.y > game.SIZE - 1 || game.ppField[c.y][c.x] != Cell::EMPTY);

    return c;
}

Coord getAiCoord(Game& game)
{
    // 1. Можем ли мы выиграть
    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            if (game.ppField[y][x] != Cell::EMPTY)
                continue;

            game.ppField[y][x] = game.ai;
            if (updateGameState(game) == GameState::WON_AI)
            {
                game.ppField[y][x] = Cell::EMPTY;
                return { y, x };
            }

            game.ppField[y][x] = Cell::EMPTY;
        }
    }
    
    // 2. Мешаем человеку выиграть
    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            if (game.ppField[y][x] != Cell::EMPTY)
                continue;

            game.ppField[y][x] = game.human;
            if (updateGameState(game) == GameState::WON_HUMAN)
            {
                game.ppField[y][x] = Cell::EMPTY;
                return { y, x };
            }

            game.ppField[y][x] = Cell::EMPTY;
        }
    }
    
    // 3. Ход по приоритетам
    // анализируем центр
    if (game.ppField[1][1] == Cell::EMPTY)
        return { 1, 1 };

    // анализируем углы
    Coord buf[4];
    size_t n{ 0 };

    if (game.ppField[0][0] == Cell::EMPTY)
    {
        buf[n] = { 0, 0 };
        n++;
    }
    if (game.ppField[2][2] == Cell::EMPTY)
    {
        buf[n] = { 2, 2 };
        n++;
    }
    if (game.ppField[0][2] == Cell::EMPTY)
    {
        buf[n] = { 0, 2 };
        n++;
    }
    if (game.ppField[2][0] == Cell::EMPTY)
    {
        buf[n] = { 2, 0 };
        n++;
    }

    if (n > 0)
    {
        const size_t index = rand() % n; // случайный индекс угла
        return buf[index];
    }

    // анализируем другие координаты
    n = 0;
    if (game.ppField[1][0] == Cell::EMPTY)
    {
        buf[n] = { 1, 0 };
        n++;
    }
    if (game.ppField[1][2] == Cell::EMPTY)
    {
        buf[n] = { 1, 2 };
        n++;
    }
    if (game.ppField[0][1] == Cell::EMPTY)
    {
        buf[n] = { 0, 1 };
        n++;
    }
    if (game.ppField[2][1] == Cell::EMPTY)
    {
        buf[n] = { 2, 1 };
        n++;
    }

    if (n > 0)
    {
        const size_t index = rand() % n;
        return buf[index];
    }

    return { 0, 0 };
}

// ------------------------------------------
