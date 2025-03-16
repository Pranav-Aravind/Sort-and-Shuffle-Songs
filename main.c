//Pranav Aravind (23205030)

#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

int main(void)
{
	//The array containing artists names
	char artists[4][80];
	//The array containing the sorted artists
	char sortedArtists[4][80];
	//Songs for Artist 1
	char songsArtist1[3][80];
	//Songs for Artist 2
	char songsArtist2[3][80];
	//Songs for Artist 3
	char songsArtist3[3][80];
	//Songs for Artist 4
	char songsArtist4[3][80];
	//The total number of artists (Note it can be less than 4)
	int numOfArtists = 0;
	//The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
	int numSongsPerArtist[4] = {0};
	//Songs to be shuffled (Note it can be less than 24)
	char songsToBeShuffled[24][80];
	//The total number of songs to be shuffled
	int numOfSongs = 0;

	/*
	 * Use here functions that you should implement
	 * t to insert artists and songs from the standard input.
	 * Note that you also need to track the number of artists and the number of songs for each artist.
	 */

	//for loop to iterate over each artist and keep track of number of artists
	for (numOfArtists = 0; numOfArtists < 4; numOfArtists++)
	{
		//to input artist name
		printf("\nInsert an artist/group name:\n");
		fflush(stdout);
		fgets(artists[numOfArtists], 80, stdin);
		//to break if user presses enter
		if(artists[numOfArtists][1] == '\n')
		{
			break;
		}

		printf("\n");
		fflush(stdout);
		//switch case to match the songs user inputs to the correct artist
		switch (numOfArtists)
		{
			case 0:
				//for loop to iterate over each song for artist1
				for (int i = 0; i < 3; i++)
				{
					//to input songs for artist1
					printf("Insert song %d for %s", i + 1, artists[numOfArtists]);
					fflush(stdout);
					fgets(songsArtist1[i], 80, stdin);
					//to break when if user presses enter
					if(songsArtist1[i][1] == '\n')
					{
						break;
					}
					//to keep track of numberofsongsforartist1
					numSongsPerArtist[numOfArtists]++;
				}	//to break the switch statement
					break;

				case 1:
					for (int i = 0; i < 3; i++)
					{
						printf("Insert song %d for %s", i + 1, artists[numOfArtists]);
						fflush(stdout);
						fgets(songsArtist2[i], 80, stdin);
						if(songsArtist2[i][1] == '\n')
						{
							break;
						}
						numSongsPerArtist[numOfArtists]++;
					}
					break;

				case 2:
					for (int i = 0; i < 3; i++)
					{
						printf("Insert song %d for %s", i + 1, artists[numOfArtists]);
						fflush(stdout);
						fgets(songsArtist3[i], 80, stdin);
						if(songsArtist3[i][1] == '\n')
						{
							break;
						}
						numSongsPerArtist[numOfArtists]++;
					}
						break;

				case 3:
					for (int i = 0; i < 3; i++)
					{
						printf("Insert song %d for %s", i + 1, artists[numOfArtists]);
						fflush(stdout);
						fgets(songsArtist4[i], 80, stdin);
						if(songsArtist4[i][1] == '\n')
						{
							break;
						}
						numSongsPerArtist[numOfArtists]++;
					}
						break;
		}

	}

	/*
	 * Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
	 * Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
	 */

	//to copy all the elements of artists onto sortedArtists
	for(int i = 0; i < numOfArtists; i++)
	{
		strcpy(sortedArtists[i], artists[i]);
	}

	//calling the function sortArtists to sort artists
	sortArtists(sortedArtists, numOfArtists);
	//calling the function sortSongs 4 times to sort songs of artist1, artist2 ,artist3 ,artist4
	sortSongs(songsArtist1, numSongsPerArtist[0]);
	sortSongs(songsArtist2, numSongsPerArtist[1]);
	sortSongs(songsArtist3, numSongsPerArtist[2]);
	sortSongs(songsArtist4, numSongsPerArtist[3]);

	//to print the sorted list of songs
	printf("\nSorted list of songs:\n");
	fflush(stdout);

	//2 for loops to iterate over every element of artists and every element of sortedArtists
	for (int i = 0; i < numOfArtists; i++)
	{
		for(int j = 0; j < numOfArtists; j++)
		{
			//if an element of sortedArtists is the same as an element of artists, strcmp returns 0 so !strcmp returns true
			if(!strcmp(sortedArtists[i], artists[j]))
			{
				//to print the sorted artists
				printf("%s", sortedArtists[i]);
				//for loop to iterate over songs for each artist
				for(int k = 0; k < numSongsPerArtist[j]; k++)
				{
					//switch case to match the sorted songs to the correct artist
					switch(j)
					{
							case 0:
								//to print the sorted songs for artist 1
								printf("   - %s", songsArtist1[k]);
								break;

							case 1:
								printf("   - %s", songsArtist2[k]);
								break;

							case 2:
								printf("   - %s", songsArtist3[k]);
								break;

							case 3:
								printf("   - %s", songsArtist4[k]);
								break;
					}
				}
			}
		}
		printf("\n");
	}

	/*
	 * Use here the function shuffleSongs to shuffle all the songs
	 * Print the list of shuffled songs
	 */

	//to copy all the songs from input in the format "Artist name - song" onto songsToBeShuffled array twice
	//2 for loops to iterate over each artist and each of their songs
	for(int i = 0, c = 0; i < numOfArtists; i++)
	{
		for(int j = 0; j < numSongsPerArtist[i]; j++)
		{
			//for loop to repeat everything twice
			for(int k = 0; k < 2; k++)
			{
				char tmp[80];
				//switch case to match the correct artist name to the songs
				switch(i)
				{
					case 0:
						/*artist name gets copied to tmp array, the tmp array and the "-" symbol is concatenated, the tmp
						  array and a song of the artist is concatenated and the new tmp array with the artist name, -,
						  and a song of the artist is copied onto the songsToBeShuffled array*/
						strcpy(tmp, artists[i]);
						strcat(tmp, " - ");
						strcat(tmp, songsArtist1[j]);
						strcpy(songsToBeShuffled[c++], tmp);
						break;

					case 1:
						strcpy(tmp, artists[i]);
						strcat(tmp, " - ");
						strcat(tmp, songsArtist2[j]);
						strcpy(songsToBeShuffled[c++], tmp);
						break;

					case 2:
						strcpy(tmp, artists[i]);
						strcat(tmp, " - ");
						strcat(tmp, songsArtist3[j]);
						strcpy(songsToBeShuffled[c++], tmp);
						break;

					case 3:
						strcpy(tmp, artists[i]);
						strcat(tmp, " - ");
						strcat(tmp, songsArtist4[j]);
						strcpy(songsToBeShuffled[c++], tmp);
						break;
				}
			}
		}
	}

	//to calculate the number of songs in the songsToBeShuffled array
	numOfSongs = 2 * (numSongsPerArtist[0] + numSongsPerArtist[1] + numSongsPerArtist[2] + numSongsPerArtist[3]);
	//calling the function shuffleSongs to shuffle the songs
	shuffleSongs(songsToBeShuffled, numOfSongs);

	return 0;
}


