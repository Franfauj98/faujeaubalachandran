// Generated by dia2code
#ifndef RENDER__MAPCREATOR__H
#define RENDER__MAPCREATOR__H

#include <SFML/Graphics.hpp>
#include <string>

namespace sf {
  class Texture;
  class VertexArray;
  class Transformable;
  class Drawable;
}


namespace render {

  /// class MapCreator - 
  class MapCreator : public sf::Transformable, public sf::Drawable {
    // Attributes
  private:
    sf::Texture texture;
    sf::VertexArray quads;
    // Operations
  public:
    void loadTexture (const std::string& imageFile);
    void initQuads (int size);
    void setSpriteLocation (int size, int x, int y, int form);
    void setSpriteTexture (int size, const int* tiles, int form, int x, int y);
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    // Setters and Getters
  };

};

#endif