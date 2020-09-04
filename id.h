#ifndef ID_H
#define ID_H


class ID
{
private:
    static int s_nextID; // Here's the declaration for a static member

public:
     static int getNextID(); // Here's the declaration for a static function
     static void set_zero();


private:
    static int s_nextID_real; // Here's the declaration for a static member

public:
     static int getNextID_real(); // Here's the declaration for a static function
     static void set_zero_real();
};

//int ID::s_nextID{ 1 };

#endif // ID_H
