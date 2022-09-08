#include "../header-Files/headerlib.hpp"

void nodestest()
{
	std::cout << "Nodes" << std::endl;
}

void nodemanager::initNodes()
{
	n = new node;
	n->bevore = h;
	t = n;
	h = n;
}

void nodemanager::createNode(const char* name)
{
	n = new node;
	n->name = name;
	n->bevore = t;
	t->next = n;
	t = t->next;
}

void nodemanager::removeNode(const char* name)
{
	node* fordeletion;
	int found = 0;
	t = h;
	do
	{
		t = t->next;
		if (t->name == name)
		{
			found = 1;
		}
	} while (!found);
	t2 = t;
	fordeletion = t;
	t2 = t2->bevore;
	t = t->next;
	t2->next = t;
	t->bevore = t2;
	delete(fordeletion);
}

node* nodemanager::getNodeByName(const char* name)
{
	int found = 0;
	t = h;
	do
	{
		t = t->next;
		if (t == n->next)
		{
			std::cerr << "Node <" << name << "> not found!" << std::endl;
			return NULL;
		}
		else if (t->name == name)
		{
			found = 1;
		}
	} while (!found);
	return t;
}

void nodemanager::saveNodesToFile(const char* filename)
{
	std::cout << "Not jet Implemented." << std::endl;
}

void nodemanager::loadNodesFromFile(const char* filename)
{
	std::cout << "Not jet Implemented." << std::endl;
}