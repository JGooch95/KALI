#include "../include/Loader.h"

const std::vector<std::vector<char>> Loader::LoadLevel(const std::string FileName)
{
	std::vector<std::vector<char>> LevelBits;

	std::ifstream File1;
	std::string sLineFromFile;
	std::string sNumRead;
	int Width;
	int Height;
	bool WidthGained = false;
	bool HeightGained = false;

	File1.open(FileName); //Open File 1

	if (File1.is_open()) //If the file is open.
	{
		//WIDTH AND HEIGHT READER----------------------------------------------------------------------------------------------------------------------
		getline(File1, sLineFromFile); //Gets the first line containing the height and width
		for (int i = 0; i <sLineFromFile.length(); i++) // for every char in the line
		{
			//If its not empty and width and heigh havent been found then push the char to the string
			if ((!WidthGained || !HeightGained) && sLineFromFile[i] != ' ')
			{

				sNumRead.push_back(sLineFromFile[i]);
			}
			//Else make it a num and apply to height or width in its order and reset the string.
			else
			{
				if (WidthGained == false)
				{
					Width = stoi(sNumRead);
					WidthGained = true;
				}
				else if (HeightGained == false)
				{
					Height = stoi(sNumRead);
					HeightGained = true;
				}
				sNumRead = "";
			}
		}
		LevelBits.resize(Height); //Resizes the vector to hold rows of bits
		//----------------------------------------------------------------------------------------------------------------------------------------------

		//BIT READER------------------------------------------------------------------------------------------------------------------------------------
		for (int i = 0; i < Height; i++) //For every row
		{
			getline(File1, sLineFromFile); //Read a line
			for (int j = 0; j < Width; j++){ //For every bit
				LevelBits[i].push_back(sLineFromFile[j]); // Push bit into the vector
			}
		}
		//----------------------------------------------------------------------------------------------------------------------------------------------
}

	else //If the file is not open.
	{
		//Set default Width & Height
		Width = 8;
		Height = 6;

		std::cout << "Could not open file."; //Output an error message

		//Resize the BitHolder
		LevelBits.resize(Height); //Resizes the vector to hold rows of bits
		for (int i = 0; i < LevelBits.size(); i++)
		{
			LevelBits[i].resize(Width); //Resizes the vector to hold each of the bits in the row.
		}

		for (int i = 0; i < Height; i++) //For every row
		{
			for (int j = 0; j < Width; j++) //For every bit
			{
				LevelBits[i].push_back('a');// Push default bits into the vector
			}
		}
	}

	File1.close(); //Close File 1
	return LevelBits;
}