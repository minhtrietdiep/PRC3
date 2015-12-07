#include <iostream>
#include <ctime>

#include "FileStructure.h"
#include "Key.h"
#include "Sorting.h"

int main()
{
	/*
	// Own list
	Key* head = new Key();
	head->setText("aa");
	head->addValue("aaa");
	head->addValue("aac");
	head->addValue("aab");
	
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
		
	head->setNext(c1);
	c1->setNext(c0);
	c0->setNext(NULL);
	*/
	
	FileStructure f;
    Key* head = new Key();
    Value* newCurrVal;
    
    f.loadFile("data/gibberish.bin", (*head));
    
	/*
	 *  Bubble sort
	 */
	/*
	clock_t begin = clock();
	head = BubbleSort(*head);
	Key* curr = head;
	while (curr != NULL) {
		Value* currVal = curr->getValuePtr();
		Value* newCurrVal = BubbleSort(*(currVal));
		curr->setValuePtr(newCurrVal);
		curr = curr->getNext();
	}
	
	clock_t end = clock();
	double duration = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time: " << duration << std::endl;

	
	f.saveFile((*head), "sorted.bin");
    (*head).print();
	
	delete head;
	head = NULL;
    return 0;
	*/
	
	/*
	 *  Merge sort
	 */
	clock_t begin = clock();
	
	head = MergeSort(head);
	
	Key* curr = head;
	while ( curr != NULL) {
		newCurrVal = MergeSort(curr->getValuePtr());
		curr->setValuePtr(newCurrVal);
		curr = curr->getNext();
	}
	
	clock_t end = clock();
	double duration = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time: " << duration << "s" << std::endl;
	// save sorted data into a new file called sorted.bin
    
    std::cout << "Writing to disk..." << std::endl;
    f.saveFile((*head), "sorted.bin");
    
    // Print everything. Do away for more fasts.
    // (*head).print();
	
	delete head;
    std::cout << "Done" << std::endl;    
    return 0;	
}
