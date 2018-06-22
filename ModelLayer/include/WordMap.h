#ifndef H_WORDMAP
#define H_WORDMAP

#include <string>
#include <vector>
#include "MapItem.h"

class WordMap
{
private:
	std::vector<MapItem> list;
	struct font_greater_than;
public:
	WordMap();
	bool	isEmpty();
	MapItem	peekNext();
	MapItem popNext();
	void	append(MapItem);
	bool	read(std::string);
	bool	write(std::string);
	void	sizeSort();
	void	randomize();
	~WordMap();
};

#endif