// Generated by dia2code
#ifndef STATE__POSITION__H
#define STATE__POSITION__H


namespace state {

  /// class Position - 
  class Position {
    // Attributes
  private:
    int x;
    int y;
    // Operations
  public:
    Position ();
    Position (int x, int y);
    ~Position ();
    int getX () const;
    int getY () const;
    void setX (const int x);
    void setY (const int y);
    // Setters and Getters
  };

};

#endif
