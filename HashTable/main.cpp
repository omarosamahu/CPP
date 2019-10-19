#include "hash.h"

int main() {
	Hash *table = new Hash();

	table->addItem("Omar", "Sahy n3na3");
	table->addItem("Osman", "Bond2 zyada");
	table->addItem("Men3em", "3enab");
	table->addItem("3mad", "Sahy");
	table->addItem("Monib", "Shisha");


	//table->printTable();
	table->printItemsInsideIndex(9);
	return EXIT_SUCCESS;
}