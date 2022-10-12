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
	void removeNode(const char* name);
	node* getNodeByName(const char* name);

	void saveNodesToFile(const char* filename);
	void loadNodesFromFile(const char* filename);

private:
	int nodes = 0;
	node* n = NULL;
	node* t = NULL;
	node* t2 = NULL;
	node* h = NULL;
	node* i = NULL;
	void reindexAll();
};

void nodestest();