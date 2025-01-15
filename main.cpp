#include <iostream>
#include <string>

struct Achievement
{
	float score = 0.0f;
	std::string title;
	std::string description;
};

struct Game
{
	Achievement* achievements = nullptr;
	int achievementCount = 0;
	std::string name;
	std::string publisher;
	std::string developer;
};

struct Platform
{
	Game* games = nullptr;
	int gameCount = 0;
	std::string name;
	std::string manufacturer;
};

// -Stores players
// -Each player can have multiple weapons
// -Each weapon can have multiple attachments
// 
// *Must declare objects in reverse-order*
// -Weapon needs to know what a Attachement is
// -Player needs to know what a Weapon is
int main()
{
	int platformCount = 0;
	printf("Enter the number of platforms.\n");
	std::cin >> platformCount;
	std::cin.ignore();
	printf("You have played on %i platforms.\n", platformCount);

	Platform* platforms = new Platform[platformCount];
	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		int platformNumber = i + 1;
		printf("Creating platform %i.\n", platformNumber);

		printf("What is the name of platform %i?\n", platformNumber);
		std::cin >> platform.name;
		std::cin.ignore();
		printf("Platform %i is named %s. \n", platformNumber, platform.name);

		printf("What is the name of the manufactuer of platform %i?\n");
		std::cin >> platform.manufacturer;
		std::cin.ignore();

		printf("How many games have you played on platform %i?\n", platformNumber);
		std::cin >> platform.gameCount;
		std::cin.ignore();

		platform.games = new Game[platform.gameCount];
		printf("Platform %i has %i games.\n", platformNumber, platform.gameCount);

		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			int gameNumber = j + 1;
			printf("Creating game %i.\n", gameNumber);
			printf("What is the name of game %i?\n", gameNumber);
			std::cin >> game.name;
			std::cin.ignore();
			printf("Game %i is named %s.\n", gameNumber, game.name.c_str());

			// TODO -- In your homework, you'll need a 3rd loop to define achievements.
			// Ensure you've allocated memory for achievements before defining them!
		}

		//delete[] player.weapons;
	}
	//delete[] players;

	// Remember to call delete[] when you're done with your dynamic memory!
	// (I commented out delete[] calls because I wanted to inspect my memory in the debugger)
	return 0;
}
