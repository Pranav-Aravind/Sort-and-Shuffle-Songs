# Sort-and-Shuffle-Songs
Input
I used fgets to read input as scanf ignores the whitespace character and doesn’t input anything entered after the whitespace character, the user may want to want to enter a whitespace character for their artists or songs, for example, for “Taylor Swift”, fgets inputs “Taylor Swift and scanf inputs “Taylor”.
The first for loop in input is to prompt the user to enter an artist name until the limit of 4 artists is reached or until the user presses enter. A switch case is used within this loop to match the artists with their songs to store each artists songs in their respective song arrays and to prompt the user to enter the songs for the artist they just inputted. Inside each case there is a for loop to prompt the user to enter songs for the artist they just inputted until the maximum of 3 songs for each artist is reached or until the user presses enter.

Sorting
I used selection sort as it is simple and the elements to be sorted were simple, so it is suitable, and it works as intended. I have used selection sort before, so I was more comfortable using it again.
I created 2 functions sortArtists and sortSongs using insertion sort. I copied all the artist names from the array artists to the array sortedArtists and called my function sortArtists to sort the artists in the array sortedArtists and I called the function sortSongs 4 times to sort the songs of each artist.
For matching the artists with their songs to print the sorted songs I used 2 for loops to iterate over every element of artists (the array with artist names) array with every element of the array sortedArtists(the array with artist names but sorted) and checked if they matched using strcmp and if they are the same, the artist is printed and using another for loop and switch case their respective songs are printed. 

Shuffling 	
I used the Fisher Yates algorithm. I called srand(time(NULL)) once to start the random number generation and passed the array songsToBeShuffled and the integer numOfSongs into the Fisher Yates block and it shuffles the array iand the shuffling is randomized.. The songsToBeShuffled array is then printed out using a for loop to print all the elements in the array. 
The songsToBeShuffled array is the array containing all the songs given as input twice as the same song must appear twice in the shuffled playslist. The integer numOfSongs is the number of songs in the array songsToBeShuffled.
For all the artists, the artist name and each of their songs are concatenated along with the “-“ symbol in between and copied onto the songsToBeShuffled array. A temporary array tmp is used for this as concatenating 3 different things into a temporary array and then copying it onto the songsToBeShuffled array is easier. This is done for each artist and each of their songs 2 times as the shuffled playlist should have each song twice.

