#pragma once

struct node
{
	node* next;
	node* bevore;

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
	node* n;
	node* t;
	node* t2;
	node* h;
};

void nodestest();