# DataStructures-LinkedList
In this assignment, linked lists (of any type except ArrayList) will be used to perform operations on genes, chromosomes, and DNA. A file named Dna.txt will be read, and the chromosomes from the file will be stored in a linked list.

File Structure:
Each line in the file represents a chromosome.
Chromosomes consist of genes separated by spaces.
The program must include the following options:
Crossover
Mutation
Automated Operations
Print to Screen
Exit
Crossover
The user will enter the line numbers of two chromosomes to be selected. Line numbering starts from 0.
After selecting two chromosomes, a crossover will be performed, and the resulting new chromosomes will be added to the population (all chromosomes stored so far).

The crossover process:
The left half of the first chromosome is combined with the right half of the second chromosome to form a new chromosome.
Similarly, the right half of the first chromosome is combined with the left half of the second chromosome to create another new chromosome.
If the number of genes in a chromosome is odd, the middle gene is excluded from both halves.
If the number of genes is even, the chromosome is split exactly in half.
The number of genes in each chromosome may vary.

Mutation
The user will enter:
The chromosome line number
The gene column number
The selected gene will undergo mutation and will be changed to the 'X' character.

Automated Operations
If this option is selected, the program will read a file named Islemler.txt to determine which operations should be performed.
All operations in this file will be executed, and a "Process completed" message will be displayed.
After performing these operations, the final population will be displayed.

Print to Screen
When printing chromosomes, the program will scan from right to left in each chromosome.
The first gene smaller than the leftmost gene will be the only gene displayed for that chromosome.
If no gene smaller than the leftmost gene is found, then the leftmost gene itself will be displayed.
