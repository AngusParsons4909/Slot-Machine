/*
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2024 Media Design School
File Name : SlotMachine.sln // Main.cpp
Description : [One line description of what is the file is for]        // to do
Author : Angus Parsons
Mail : Angus.Parsons@mds.ac.nz
*/

#include <iostream>
int menu(int _chips) //first thing user sees
{
	char option = 0;
	std::cout << "Player's chips: $" << _chips << std::endl;
	std::cout << "1) Play Slots" << std::endl;
	std::cout << "2) Credits" << std::endl;
	std::cout << "3) Quit Slot Machine" << std::endl;
	std::cout << std::endl;
	std::cout << "Please select your option (Enter corresponding number): ";
	std::cin >> option;
	std::system("cls"); // clears screen
	return option;
}

bool ValidInput(int _bet, int _chips) //for validity checks
{
	try
	{
		_bet + 1;
		if (_bet > 0 && _bet <= _chips)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (int num)
	{
		return false;
	}
}

int PlaySlots(int _chips)
{
	int bet = 0;
	std::cout << "Please enter your bet: $";
	std::cin >> bet;
	int num1 = 0, num2 = 0, num3 = 0;
	bool betChecker = ValidInput(bet, _chips); //check user input validity
	if (betChecker)
	{
		srand(time(0)); //sets the seed to be used by random
		num1 = (rand() % 7) + 1;
		num2 = (rand() % 7) + 1;
		num3 = (rand() % 7) + 1;
		std::cout << num1 << std::endl;
		std::cout << num2 << std::endl;
		std::cout << num3 << std::endl;
		_chips = _chips - bet; // decrease total chips by bet
		if (num1 == 7 && num2 == 7 && num3 == 7) // tripple 7
		{
			bet = bet * 10;
		}
		else if (num1 == num2 && num2 == num3) //tripple num
		{
			bet = bet * 5;
		}
		else if (num1 == num2 || num1 == num3 || num2 == num3) // double num
		{
			bet = bet * 3;
		}
		else
		{
			bet = 0;
		}
		_chips = _chips + bet;
		return _chips;
	}
	else
	{
		bet = 0;
		std::cout << "That's not a valid bet" << std::endl;
		return _chips;
	}
}

void Credits()
{
	std::cout << "Made by Angus Parsons" << std::endl;
}

void End(int _chips)
{
	std::cout << "You have " << _chips << " chips remaining" << std::endl;
	if (_chips < 2000)
	{
		std::cout << "You lost " << 2000 - _chips << " chips" << std::endl;
	}
	else if (_chips >= 2000)
	{
		std::cout << "You gained " << _chips - 2000 << " chips" << std::endl;
	}
	std::cout << "Thanks for playing :)";
}

int main()
{
	int chips = 2000;
	while (true)      //continualy queries user for option until option 2 is selected
	{
		char option = menu(chips);
		switch (option)
		{
		case '1':
			chips = PlaySlots(chips);
			break;
		case '2':
			Credits();
			break;
		case '3':
			break;
		default:
			std::cout << "That's not a valid input " << std::endl;
		}
		if (option == '3' || chips <= 0)
		{
			End(chips);
			break;
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return 0;
}