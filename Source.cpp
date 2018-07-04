#include "stdio.h"
#include "iostream"
#include "ctime"
#include "conio.h"
using namespace std;
void Throw(int Dice)
{
    switch (Dice)
    {
    case 1:
    cout <<"===========" <<endl;
    cout <<"|         |" <<endl;
    cout <<"|    *    |" <<endl;
    cout <<"|         |" <<endl;
    cout <<"===========" <<endl;
        break;
    case 2:
    cout <<"===========" <<endl;
    cout <<"|    *    |" <<endl;
    cout <<"|         |" <<endl;
    cout <<"|    *    |" <<endl;
    cout <<"===========" <<endl;
        break;
    case 3:
    cout <<"===========" <<endl;
    cout <<"|  *      |" <<endl;
    cout <<"|    *    |" <<endl;
    cout <<"|      *  |" <<endl;
    cout <<"===========" <<endl;
        break;
    case 4:
    cout <<"===========" <<endl;
    cout <<"|  *   *  |" <<endl;
    cout <<"|         |" <<endl;
    cout <<"|  *   *  |" <<endl;
    cout <<"===========" <<endl;
        break;
    case 5:
    cout <<"===========" <<endl;
    cout <<"|  *   *  |" <<endl;
    cout <<"|    *    |" <<endl;
    cout <<"|  *   *  |" <<endl;
    cout <<"===========" <<endl;
        break;
    case 6:
    cout <<"===========" <<endl;
    cout <<"|  *   *  |" <<endl;
    cout <<"|  *   *  |" <<endl;
    cout <<"|  *   *  |" <<endl;
    cout <<"===========" <<endl;
        break;
    }
}
int Res()
{
	int Dice_1 = rand() %7;
	Throw(Dice_1);
	int Dice_2 = rand() %7;
	Throw(Dice_2);
	int res;
	res = Dice_1 + Dice_2;
	cout << "Result: " << res << endl << endl;
	return res;
}
void main()
{
	RETURN:
	srand(time(0));
	cout << "Hey wanna play dises?" << endl;
	char Turn;
	int UserScore = 0;
	int MachineScore = 0;
	do
	{
		cout << endl << "Let's see who will start the game. Throw ur dices (press s to throw) " << endl;
		cin >> Turn;
	} while (Turn != 's');
	int UserRes, MachineRes;
	do
	{
		UserRes = Res();
		cout << "Your result: " << UserRes << endl;
		cout << endl <<"Now it's computer turn" << endl;
		MachineRes = Res();
		cout << "Ur opponent has  " << MachineRes << " lol" << endl;
	} while (UserRes == MachineRes);
	if (UserRes>MachineRes)
	{
		cout << endl << "You start then, lucky guy" << endl;
		for (int i = 1; i <= 5; i++)
		{
			do
			{
				cout << "Throw ur dise now, dude (press s to throw again yep)" << endl;
				cin >> Turn;
			} while (Turn != 's');
			UserScore += Res();
			MachineScore += Res();

		}
		cout << "Your total score for now is " << UserScore << endl;
		cout << endl <<"Ur opponent have " << MachineScore << endl;
	}
	else
	{
		cout << endl <<"So ur opponent starts eh" << endl;
		for (int i = 1; i <= 5; i++)
		{
			MachineScore += Res();
			do
			{
				cout << endl << "Throw ur dise now, dude (press s to throw again yep)" << endl;
				cin >> Turn;
			} while (Turn != 's');
			UserScore += Res();

		}
		cout << "Your total score for now is " << UserScore << endl;
		cout << "And opponent have " << MachineScore << endl;
	}
	if (UserScore == MachineScore)
	{
		char restart;
		cin >> restart;
		cout << endl << endl << "Wow nobody won" << endl << "If you want restart the game ind try to win press 'a'" << endl;
		if (restart == 'a')
		{
			goto RETURN;
		}
	}
	else
	{
		if (UserScore > MachineScore)
		{
			cout << endl << endl <<"You beated machine wow humanity have a chance" << endl << endl;
		}
		if (UserScore<MachineScore)
		{
			cout << endl << endl << "Machine won humanity will die out" << endl << endl;
		}
	}
	cout << "Game statistics:" << endl << endl;
	cout << "Your range: " << UserScore / 5.0 << endl;
	cout << "Machine range: " << MachineScore / 5.0 << endl;
	cout << endl;
	_getch();
}