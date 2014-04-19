#ifndef TILEDIMAGE_H
#define TILEDIMAGE_H

#include <deque>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

/*	Dimensional properties of a single tile. Can also
	be used as a parametrization of a set of uniform
	tiles.
*/
class TileParams
{
public:
	TileParams (sf::Vector2u prop = sf::Vector2u(0,0),
				sf::Vector2u orig = sf::Vector2u(0,0),
				sf::Vector2u offs = sf::Vector2u(0,0), 
				sf::Vector2u padd = sf::Vector2u(0,0))
		: proportions(prop), offset(offs), padding(padd), origin(orig)
	{}

	/* 	The size of each tile 
	*/
	sf::Vector2u proportions;
	
	/* 	The location of the top-left tile's 
		top-left corner 
	*/
	sf::Vector2u offset;
	
	/* 	Amount of empty space on the right and 
		bottom sides
	*/
	sf::Vector2u padding;
	
	/*	Center point for transformations
	*/
	sf::Vector2u origin;

	/*	Calculates the number of tiles required to 
		populate a given width
	*/
	int tileCountHorizontal(int surfaceWidth) const;
	
	/*	Calculates the number of tiles required to 
		populate a given height
	*/
	int tileCountVertical(int surfaceHeight) const;
	
	/*	Returns a rectangle representing the location
		of the indexed tile - tiles are counted first
		horizontally, then vertically as they exceed
		the right boundary.
	*/
	sf::IntRect getTile(int index, int surfaceWidth, int surfaceHeight, bool adjustSize=true) const;

private:
	/*	Check that proportions are valid
	*/
	//bool checkProportions() const { return (proportions.x > 0 && proportions.y > 0);}
	
};

/* 	A simple set of unique tiles which may or may
	not overlap.
*/
class TileSet :
	public std::deque<sf::IntRect>
{
public:
	TileSet();
	
	/* 	Populates with tiles uniformly spread (after
		taking offset into account) across a sheet 
		of given size. If max > 0, the tiling process
		will stop at the index indicated. The combination
		of height <= 0 and max > 0 will result in 
		unbounded height.
	*/
	TileSet(const TileParams&, int width, int height, int max = 0);
	sf::Vector2u origin;
};

/* 	An implementation of an sf::Image which includes
	tiling information and is convertible to different
	forms of textures (ie. images on graphics card 
	memory).
*/
class TiledImage :
	public sf::Image
{
public:
	TiledImage();
	TiledImage(const std::string& filename, const TileParams& params);
	void loadTiles(const TileSet&);
	TileSet tiles;
};

class TiledTexture :
	public sf::Texture
{
public:
	TiledTexture();
	void loadTiles(const TileSet&);
	TileSet tiles;
};

#endif // TILEDIMAGE_H