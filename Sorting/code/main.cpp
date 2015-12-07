#include <iostream>

#include "FileStructure.h"
#include "Key.h"
#include "Sorting.h"

int main()
{
	// Eigen lijst
	/*Key* cHead = new Key();
	cHead->setText("aa");
	cHead->addValue("aaa");
	cHead->addValue("aac");
	cHead->addValue("aab");
	
	Key* c0 = new Key();
	c0->setText("ab");
	c0->addValue("abb");
	c0->addValue("abc");
	c0->addValue("aba");
	
	Key* c1 = new Key();
	c1->setText("ac");
	c1->addValue("acc");
	c1->addValue("acb");
	c1->addValue("aca");
		
	cHead->setNext(c1);
	c1->setNext(c0);
	c0->setNext(NULL);
	
	cHead = BubbleSort(*cHead);
	Key* curr = cHead;	
	while (curr != NULL) {
		Value* currVal = curr->getValuePtr();
		Value* newCurrVal = BubbleSort(*(currVal));
		curr->setValuePtr(newCurrVal);
		curr = curr->getNext();
	}
	
	cHead->print();
	delete cHead;
	cHead = NULL;
	return 0;*/
	
	FileStructure f;
    Key* head = new Key();
    
    f.loadFile("data/gibberish.bin", (*head));

    // next line is only to show what kind of data we're working with
    // remove this line to increase performance!
    // head.print();
    
    // sort all data
    // todo: your code here!
    
	// Het onderstaande werkt
	head = BubbleSort(*head);
	Key* curr = head;
	while (curr != NULL) {
		Value* currVal = curr->getValuePtr();
		Value* newCurrVal = BubbleSort(*(currVal));
		curr->setValuePtr(newCurrVal);
		curr = curr->getNext();
	}
	
    // save sorted data into a new file called sorted.bin
    f.saveFile((*head), "sorted.bin");
    //(*head).print();
	
	delete head;
	head = NULL;
    return 0;
	
	// Merge sort
	/*
	head = MergeSort(head);
	
	Key* curr = head;
	while ( curr->getNext() != NULL) {
		Value* currVal = curr->getValuePtr();
		Value* newCurrVal = MergeSort(currVal);
		curr->setValuePtr(newCurrVal);
		curr = curr->getNext();
	}
	
	// save sorted data into a new file called sorted.bin
    f.saveFile((*head), "sorted.bin");
    //(*head).print();
	
	delete head;
	head = NULL;
    return 0;
	
	*/
}
