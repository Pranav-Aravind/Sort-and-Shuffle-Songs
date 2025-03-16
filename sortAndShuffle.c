#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include <stdlib.h>
#include <time.h>

/*
* This method sorts the artists alphabetically. It takes as input:
* - sortedArtists: the array of artists that that should be sorted
* - numOfArtists: the total number of artists
*
*/

//Selection sort to sort artists
void sortArtists(char sortedArtists[][80], int numOfArtists){
    int i = 0;
    int j = 0;
    int minIndex = 0;
    int minIndexChanged = 0;

    char swap [MAX_LENGHT];

    //to iterate every element of numOfArtists over every element of the same array
    for(i = 0; i < (numOfArtists-1); i ++)
    {
        minIndex = i;
        for(j = i+1; j<numOfArtists; j++)
        {
        	/*to change minIndex to j, and minIndexChanged to 1 if an element of sortedArtists[j] is the same as an element
        	  of sortedArtists[minIndex]*/
            if(strcmp(sortedArtists[j], sortedArtists[minIndex]) < 0)
            {
                minIndex = j;
                minIndexChanged =1;
            }
        }
        	/*to copy sortedArtists[i] to swap, and copy sortedArtists[minIndex] onto sortedArtists[i],and copy swap to
        	  sortedArtists[minIndex], and change minIndexChanged to 0 if minIndexChanged is 1*/
            if(minIndexChanged == 1)
            {
            	memset(swap, '$', MAX_LENGHT-1);
                swap[MAX_LENGHT -1] = '\0';
                strcpy(swap,sortedArtists[i]);
                strcpy(sortedArtists[i], sortedArtists[minIndex]);
                strcpy(sortedArtists[minIndex], swap);
                minIndexChanged =0;
            }

    }
}

/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numOfArtists: the number of artists provided from the standard input
*/

//Selection sort to sort songs
void sortSongs(char songsOfAnArtist[][80], int numOfArtists){
    int i = 0;
    int j = 0;
    int minIndex = 0;
    int minIndexChanged = 0;

    char swap [MAX_LENGHT];

    for(i = 0; i< (numOfArtists-1); i++)
    {
        minIndex = i;
        for(j = i+1; j<numOfArtists; j++)
        {
            if(strcmp(songsOfAnArtist[j], songsOfAnArtist[minIndex]) < 0)
            {
                minIndex = j;
                minIndexChanged =1;
            }
        }

            if(minIndexChanged == 1)
            {
            	memset(swap, '$', MAX_LENGHT-1);
                swap[MAX_LENGHT -1] = '\0';
                strcpy(swap,songsOfAnArtist[i]);
                strcpy(songsOfAnArtist[i], songsOfAnArtist[minIndex]);
                strcpy(songsOfAnArtist[minIndex], swap);
                minIndexChanged =0;
            }

    }
}

/*
* This method shuffles a set of songs. It takes as input:
* - songsToBeShuffled: the array of the songs that should be shuffled
* - numOfSongs: the number of songs to be shuffled
*/

void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs)
{
	int i, j;
	char swap[80];
	//called once to start random number generation
	srand(time(NULL));
	//Fisher Yates block
	for(i = 1; i < numOfSongs; i++)
	{
		//generates a random number between and including 0 and i
		j = rand()%(i+1);

		//if i is not equal to j swaps the elements in position i and j in the array
		if(j!=i)
		{
			strcpy(swap, songsToBeShuffled[j]);
			strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
			strcpy(songsToBeShuffled[i], swap);
		}
	}

	//to print the shuffled list of songs
	printf("Shuffled Playlist:\n");
	fflush(stdout);

	for(i = 0; i < numOfSongs; i++)
	{
		printf("%s", songsToBeShuffled[i]);
		fflush(stdout);
	}

}






