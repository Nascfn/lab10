#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


const int numChilds = 26;

// Trie structure
struct Trie
{
	struct Trie* childList[numChilds];
	bool isTerminal;
};

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
	int count = 0;
	
}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
}

// Initializes a trie structure
struct Trie *createTrie()
{
	struct Trie* newTrie = (struct Trie*)malloc(sizeof(struct Trie));

	for(int i = 0; i < numChilds; i++)
	{
		newTrie->childList[i] = NULL;
	}

	newTrie->isTerminal = false;

	return newTrie;
}

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word)
{
	struct Trie* newTrie = pTrie;
	for(int i = 0; i < strlen(word); i++)
	{
		int letterIdx = word[i] - 'a';
		if(newTrie->childList[letterIdx] == NULL)
		{
			newTrie->childList[letterIdx] = createTrie();
		}
	}

	newTrie->isTerminal = true;

	return;

}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
	FILE* fp = fopen(filename, "r");
	int counter = 0;
	char* temp = (char*)malloc(sizeof(char)*30);
	*pInWords = (char*)malloc(sizeof(256));

	while(fscanf(fp, "%s", temp) != EOF)
	{
		strcat(*pInWords,temp);
		counter++;
	}

	return counter;
}

int main(void)
{
	char** inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("/Users/paulofn/Desktop/CS1/labo10/dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
		printf(" i is = %d \n", i);
	}
	
	struct Trie *pTrie = createTrie();
	insert(pTrie,"12");
	insert(pTrie,"not");
	insert(pTrie,"note");
	insert(pTrie,"ucf");
	insert(pTrie,"notaword");
	insert(pTrie,"notawordeither");
	insert(pTrie,"notaword");
	insert(pTrie,"ucf");
	insert(pTrie,"note");
	insert(pTrie,"ucf");
	insert(pTrie,"notawordeithereither");
	insert(pTrie,"not");
	insert(pTrie,"ucf");
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}

/*
int main(void)
{
	char** inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("/Users/paulofn/Desktop/CS1/labo10/dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
		printf(" i is = %d \n", i);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}
*/