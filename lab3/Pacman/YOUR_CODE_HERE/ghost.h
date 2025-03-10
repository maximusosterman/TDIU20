
class Ghost
{

public:

    Ghost(Pacman& pacman) :
      color(),
      scatter_point(),
      chase_point(),
      position(),
      pacman{pacman} {};
    virtual ~Ghost() {};

    std::string get_color() const;
    Point get_scatter_point() const;
    Point get_chase_point() const;

    void set_position(Point const &position);
    Point get_position() const;

    virtual void set_chase_point(bool scatter) = 0;


protected:
   std::string color;
   Point scatter_point;
   Point chase_point;

   Point position;

   Pacman& pacman;
};

class Blinky : public Ghost
{

public:

    explicit Blinky(Pacman& pacman);
    ~Blinky() {};

    bool is_angry();
    void set_angry(bool bool_in);

    void set_chase_point(bool scatter = false) override;

private:
    bool angry = false;
    void set_scatter_point();


};

class Clyde : public Ghost
{

public:

    explicit Clyde(Pacman& pacman);

    ~Clyde() {};

    void set_chase_point(bool scatter = false) override;

private:
    Point get_clyde_chase_point();
    int get_steps_from_pacman();



};

class Pinky : public Ghost
{

public:
    explicit Pinky(Pacman& pacman);
    ~Pinky() {};

    void set_chase_point(bool scatter = false) override;
};
