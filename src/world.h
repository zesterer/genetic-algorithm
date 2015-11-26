#include <SFML/Graphics.hpp>

namespace Genetic
{
	class World
	{
		public:
			sf::RenderWindow window;
			
			World();
			int run();
	};
}
