# Sort-and-Shuffle-Songs  

## Input  
I used `fgets` to read input as `scanf` ignores the whitespace character and doesn’t input anything entered after the whitespace character. The user may want to enter a whitespace character for their artists or songs. For example, for “Taylor Swift”, `fgets` inputs “Taylor Swift” while `scanf` only inputs “Taylor”.  

The first `for` loop in input is to prompt the user to enter an artist name until the limit of 4 artists is reached or until the user presses enter. A `switch case` is used within this loop to match the artists with their songs, storing each artist’s songs in their respective song arrays and prompting the user to enter songs for the artist they just inputted.  

Inside each `case`, there is a `for` loop to prompt the user to enter songs for the artist until the maximum of 3 songs per artist is reached or until the user presses enter.  

## Sorting  
I used **selection sort** as it is simple and well-suited for the given elements. It works as intended, and I was comfortable using it since I have used it before.  

I created two functions:  
- `sortArtists` (uses **insertion sort**)  
- `sortSongs` (also uses **insertion sort**)  

I copied all artist names from the `artists` array to the `sortedArtists` array and called `sortArtists` to sort the artists in `sortedArtists`. I then called `sortSongs` four times to sort the songs of each artist.  

For matching the artists with their songs to print the sorted songs, I used **two `for` loops** to iterate over every element of the `artists` array (original order) with every element of the `sortedArtists` array (sorted order). Using `strcmp`, I checked if they matched. If they were the same, the artist was printed, and using another `for` loop and `switch case`, their respective songs were printed.  

## Shuffling  
I used the **Fisher-Yates algorithm** for shuffling. I called `srand(time(NULL))` once to start random number generation and passed the array `songsToBeShuffled` and the integer `numOfSongs` into the Fisher-Yates block, which randomizes the array. The shuffled `songsToBeShuffled` array is then printed using a `for` loop.  

The `songsToBeShuffled` array contains all the songs given as input **twice** since each song must appear twice in the shuffled playlist. The integer `numOfSongs` represents the number of songs in the `songsToBeShuffled` array.  

For all artists, the artist name and each of their songs are concatenated along with the `"-"` symbol in between and copied into the `songsToBeShuffled` array. A temporary array `tmp` is used for this because concatenating three different elements into a temporary array and then copying it into `songsToBeShuffled` is easier.  

This process is done **for each artist and each of their songs twice** since the shuffled playlist should have each song appear twice.  
