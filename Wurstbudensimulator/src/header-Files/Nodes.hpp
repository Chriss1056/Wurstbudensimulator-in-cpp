#pragma once

struct node
{
	node* next;
	node* bevore;
	int index;

	const char* name;
	int inStock;
	float ekp;
	float vkp;
};

class nodemanager
{
public:
	void initNodes();

	void createNode(const char* name);
	void removeNodeByName(const char* name);
	void removeNodeByIndex(int index);
	node* getNodeByName(const char* name);
	node* getNodeByIndex(int index);

	void saveNodesToFile(const char* filename);
	void loadNodesFromFile(const char* filename);

	int getNodesCount();

private:
	int nodes = 0;
	node* n = NULL;
	node* t = NULL;
	node* h = NULL;
	void reindexAll();
};

void nodestest();