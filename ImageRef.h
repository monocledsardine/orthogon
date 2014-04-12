#ifndef IMAGEREF_H
#define IMAGEREF_H
#include "TiledImage.h"
#include <string>
#include <map>

struct ImageRef
{
public:
	enum name 
	{
	BG_1				=0, 
	BG_2				=1,
	BG_3				=2,
	BLOCK_2				=3,
	BLOCK_BOUNCE_1		=4,
	BLOCK_BOUNCE_2		=5,
	BLOCK_JUMP_1		=6,
	BLOCK_JUMP_2		=7,
	BLOCK_PORTAL_1		=8,
	BLOCK_PORTAL_2		=9,
	BLOCK_TRANSLATION_1	=10,
	BLOCK_TRANSLATION_2	=11,
	CHERRIES			=12,
	CHERRY				=13,
	LINE_1				=14,
	LINE_2				=15,
	LINE_3				=16,
	LINE_4				=17,
	LINE_5				=18,
	LINE_END			=19,
	LINE_POP			=20,
	MAN_DOWN_1			=21,
	MAN_DOWN_2			=22,
	MAN_EAT_1			=23,
	MAN_JUMP_1			=24,
	MAN_OOF_1			=25,
	MAN_RUN_1			=26,
	MAN_STAND_1			=27,
	MAN_UP_1			=28,
	END					=29
	};
	
	//name& operator++(name& a);
	
	std::map<name, TiledImage> images;
	std::map<name, TiledTexture*> textures;
	
	ImageRef()
	{
		images.insert(		std::pair<name, TiledImage>(BG_1, 
								TiledImage(find("bg_1.png"), 
								TileParams(sf::Vector2u(256, 256)))));

		images.insert(		std::pair<name, TiledImage>(BG_2,
								TiledImage(find("bg_2.png"),
								TileParams(sf::Vector2u(800,600)))));

		images.insert(		std::pair<name, TiledImage>(BG_3,
								TiledImage(find("bg_3.png"),
								TileParams(sf::Vector2u(97, 600)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_2,
								TiledImage(find("block_2.png"),
								TileParams(sf::Vector2u(32, 32)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_BOUNCE_1,
								TiledImage(find("block_bounce_1.png"),
								TileParams(sf::Vector2u(32, 30)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_BOUNCE_2,
								TiledImage(find("block_bounce_2.png"),
								TileParams(sf::Vector2u(32, 30)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_JUMP_1,
								TiledImage(find("block_jump_1.png"),
								TileParams(sf::Vector2u(32, 5)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_JUMP_2,
								TiledImage(find("block_jump_2.png"),
								TileParams(sf::Vector2u(32, 5)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_PORTAL_1,
								TiledImage(find("block_portal_1.png"),
								TileParams(sf::Vector2u(32, 32)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_PORTAL_2,
								TiledImage(find("block_portal_2.png"),
								TileParams(sf::Vector2u(32, 32)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_TRANSLATION_1,
								TiledImage(find("block_translation_1.png"),
								TileParams(sf::Vector2u(32, 32)))));

		images.insert(		std::pair<name, TiledImage>(BLOCK_TRANSLATION_2,
								TiledImage(find("block_translation_2.png"),
								TileParams(sf::Vector2u(32, 32)))));

		images.insert(		std::pair<name, TiledImage>(CHERRIES,
								TiledImage(find("cherries.png"),
								TileParams(sf::Vector2u(24, 29)))));

		images.insert(		std::pair<name, TiledImage>(CHERRY,
								TiledImage(find("cherry.png"),
								TileParams(sf::Vector2u(126, 16)))));

		images.insert(		std::pair<name, TiledImage>(LINE_1,
								TiledImage(find("line_1.png"),
								TileParams(sf::Vector2u(8, 8)))));

		images.insert(		std::pair<name, TiledImage>(LINE_2,
								TiledImage(find("line_2.png"),
								TileParams(sf::Vector2u(8, 8)))));

		images.insert(		std::pair<name, TiledImage>(LINE_3,
								TiledImage(find("line_3.png"),
								TileParams(sf::Vector2u(8, 8)))));

		images.insert(		std::pair<name, TiledImage>(LINE_4,
								TiledImage(find("line_4.png"),
								TileParams(sf::Vector2u(8, 8)))));

		images.insert(		std::pair<name, TiledImage>(LINE_5,
								TiledImage(find("line_5.png"),
								TileParams(sf::Vector2u(8, 8)))));

		images.insert(		std::pair<name, TiledImage>(LINE_END,
								TiledImage(find("line_end.png"),
								TileParams(sf::Vector2u(32, 32)))));

		images.insert(		std::pair<name, TiledImage>(LINE_POP,
								TiledImage(find("line_pop.png"),
								TileParams(sf::Vector2u(15, 16)))));

		images.insert(		std::pair<name, TiledImage>(MAN_DOWN_1,
								TiledImage(find("man_down_1.png"),
								TileParams(sf::Vector2u(29, 28),
										sf::Vector2u(15, 13)))));

		images.insert(		std::pair<name, TiledImage>(MAN_DOWN_2,
								TiledImage(find("man_down_2.png"),
								TileParams(sf::Vector2u(17, 19),
										sf::Vector2u(9, 13)))));

		images.insert(		std::pair<name, TiledImage>(MAN_EAT_1,
								TiledImage(find("man_eat_1.png"),
								TileParams(sf::Vector2u(63, 32)))));

		images.insert(		std::pair<name, TiledImage>(MAN_JUMP_1,
								TiledImage(find("man_jump_1.png"),
								TileParams(sf::Vector2u(17, 31),
										sf::Vector2u(9, 13)))));

		images.insert(		std::pair<name, TiledImage>(MAN_OOF_1,
								TiledImage(find("man_oof_1.png"),
								TileParams(sf::Vector2u(18, 28)))));

		images.insert(		std::pair<name, TiledImage>(MAN_RUN_1,
								TiledImage(find("man_run_1.png"),
								TileParams(sf::Vector2u(26, 32)))));

		images.insert(		std::pair<name, TiledImage>(MAN_STAND_1,
								TiledImage(find("man_stand_1.png"),
								TileParams(sf::Vector2u(17, 31)))));

		images.insert(		std::pair<name, TiledImage>(MAN_UP_1,
								TiledImage(find("man_up_1.png"),
								TileParams(sf::Vector2u(17, 11),
										sf::Vector2u(9, 4)))));
	}

	bool loadTextures()
	{
		name i(BG_1);
		
		while (i != END)
		{ 
			textures.insert(std::pair<name, TiledTexture*>(i, new TiledTexture()));
			textures[i]->loadFromImage(images[i]);
			textures[i]->loadTiles(images[i].tiles);
			i = static_cast<name>(i + 1);
		}
	}
	
	TiledTexture* get(name n)
	{
		return textures[n];
	}
	
	std::string find(const std::string file) const { return "images/" + file; }
	
	~ImageRef()
	{
		name i(BG_1);
		
		while (i != END)
		{ 
			delete textures[i];
			i = static_cast<name>(i + 1);
		}
	}
};

#endif //IMAGEREF_H