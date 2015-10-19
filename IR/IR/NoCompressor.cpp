#include "NoCompressor.h"

void NoCompressor::compress(ofstream outputInvertedFile, list<DocumentTerm>* postingList)
{
	DocumentTerm * docTermTable = (DocumentTerm*)malloc(sizeof(DocumentTerm)*(postingList->size()));
	list<DocumentTerm>::iterator it;
	int i = 0;
	for (it = postingList->begin(); it != postingList->end(); ++it)
	{
		docTermTable[i++] = *it;
	}
	outputInvertedFile.write((const char *)docTermTable, (sizeof(DocumentTerm)*(postingList->size())));
	free(docTermTable);
}

void NoCompressor::decompress(ifstream inputInvertedFile, DocumentTerm ** postingList, int size)
{
	*postingList = (DocumentTerm*)malloc(sizeof(DocumentTerm)*size);
	inputInvertedFile.read((char *)*postingList, sizeof(DocumentTerm)*size);
}
