#include "startscene.h"
#include "gamescene.h"
#include "function.h"
#include <fstream>

Stage* stage;

extern int currentWidth;
extern int currentHeight;

startscene::startscene()
{
    stage = new Stage();
}

startscene::~startscene()
{
}

void startscene::Update(float eTime)
{
    char answer;
    int temp;
    do
    {
        answer = IsUserReady();
        if (answer == 'n')
            exit(0);
        temp = (int)answer - 49;
    } while (temp < 0 || temp > 2);

    stage->setNowStage((int)answer - 49);

    ChangeScene(new GameScene());
}

void startscene::Render()
{
}

void startscene::ClearCentre(float x, float y)
{
    clear(); // clear the screen if the game is played for the 2nd time
    initscr();
    noecho();
    getmaxyx(stdscr, maxheight, maxwidth);

    //myFunction�� �ִ� ����
    getmaxyx(stdscr, currentHeight, currentWidth);

    move((maxheight / y), (maxwidth / x));
}

// receive user confirmation
int startscene::UserInput()
{
    int UserInput = getch();
    refresh();
    endwin();
    clear();

    return UserInput;
}

void startscene::Load()
{
    std::ifstream readFile;
    string src = "scene/WaitingScene.txt";

    readFile.open(src);
    int height = 0;

    while (!readFile.eof())
    {
        char temp[120];
        readFile.getline(temp, 120);

        for (int width = 0; width < 62; width++)
        {
            if (temp[width] == '-')
            {
                move(height, width);
                addch('-');
            }

            else if (temp[width] == '0')
            {
                move(height, width);
                addch(char(219));
            }

            else if (temp[width] == ' ')
            {
                move(height, width);
                addch(' ');
            }
        }

        height++;
    }
}

// print start menu
int startscene::IsUserReady()
{
    ClearCentre(3, 2.5);

    Load();

    move(25, 0);
    printw("Welcome to the Snake Game. Press 1 or 2 or 3 to start or 'n'");
    move(30, 14);
    return UserInput();
}
