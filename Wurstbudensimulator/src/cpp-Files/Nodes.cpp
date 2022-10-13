#include "../header-Files/headerlib.hpp"

void nodestest()
{
	std::cout << "Nodes" << std::endl;
}

//ToDo
void nodemanager::reindexAll()
{
	int index, finished;
	finished = 0;
	i = h;
	index = 0;
	while (!finished)
	{
		if (i->index != nodes-1)
		{
			index++;
			i = i->next;
			i->index = index;
			std::cout << i->index << std::endl;
			std::cin.get();
		}
		else
		{
			finished = 1;
		}
	}
}

void nodemanager::initNodes()
{
	n = new node;
	n->name = "head";
	n->index = 0;
	n->bevore = h;
	t = n;
	h = n;
	nodes++;
}

void nodemanager::createNode(const char* name)
{
	n = new node;
	n->name = name;
	n->index = 0;
	n->bevore = t;
	t->next = n;
	t = t->next;
	nodes++;
	reindexAll();
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
	nodes--;
	reindexAll();
}

void nodemanager::getNodeByName(const char* name, node** ptr)
{
	int found = 0;
	t = h;
	do
	{
		t = t->next;
		if (t == n->next)
		{
			std::cerr << "Node <" << name << "> not found!" << std::endl;
			return;
		}
		else if (t->name == name)
		{
			found = 1;
		}
	} while (!found);
	ptr = &t;
}

void nodemanager::saveNodesToFile(const char* filename)
{
	std::cout << "Not jet Implemented." << std::endl;
}

void nodemanager::loadNodesFromFile(const char* filename)
{
	std::cout << "Not jet Implemented." << std::endl;
}